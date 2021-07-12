
// /**
//  * 파티클을 프리캐시합니다. 
//  * @param pcf       파티클 파일 위치
//  * @param preload   파티클을 미리 로드할 지 여부를 정합니다.
//  * @note            OnMapStart()나, OnServerLoad()에서 미리 파티클을 프리캐싱 합니다. 여기서 첫번째 매개변수는, info_particle_system의 파일 위치를 뜻합니다.
//  */
// stock void qufnrTools_PrecacheParticle ( const char[] pcf, bool preload = false ) {
//     PrecacheGeneric ( pcf, preload );
//     AddFileToDownloadsTable ( pcf );
//     int nTable = FindStringTable ( "EffectDispatch" );
//     bool bLockTable = LockStringTables ( false );
//     AddToStringTable ( nTable, "ParticleEffect" );
//     LockStringTables ( bLockTable );
// }

// /**
//  * 파티클 내부 파티클 효과를 프리캐시합니다.
//  * @param name      Name of info_particle_system
//  * @note            pcf 파일 내의 파티클 이름을 첫 번째 매개변수에 대입합니다. pcf 내부에는 여러개의 info_particle_system 들이 있기 때문에, 하나 하나 따로 프리캐싱 작업을 해야합니다.
//  */
// stock void qufnrTools_PrecacheParticleEffect ( const char[] name ) {
//     int nTable = FindStringTable ( "ParticleEffectNames" );
//     bool bLockTable = LockStringTables ( false );
//     AddToStringTable ( nTable, name );
//     LockStringTables ( bLockTable );
// }

stock int qufnrTools_PrecacheParticle ( const char[] name ) {
    static int iTable = INVALID_STRING_TABLE;
    if ( iTable == INVALID_STRING_TABLE )
        iTable = FindStringTable ( "ParticleEffectNames" );
    
    int iIndex = FindStringIndex ( iTable, name );
    if ( iIndex == INVALID_STRING_INDEX ) {
        bool bSave = LockStringTables ( false );
        AddToStringTable ( iTable, name );
        LockStringTables ( bSave );
        iIndex = FindStringIndex ( iTable, name );
    }
    return iIndex;
}

/**
 * Create info_particle_system entity.
 * @param pos       Dispatch position
 * @param ang       Dispatch angle vector
 * @param name      Name of info_particle_system
 * @param lifeTime  Time duration of the particle effect
 * @param owner     Particle's owner entity index (Integer)
 * @param sendToOwner   Dispaying to only owner entity
 * @param attachment    Enable attachment
 * @param attachName    Name of attachment
 * @return Entity object
 * @note            CreateEntityByName 함수를 사용해서 info_particle_system을 생성하여 파티클의 옵션을 설정하고 소환하는 방식입니다. 이 방식은 CS:GO에서만 테스트되었습니다. 파티클을 소환하기 전에, 파티클이 프리캐싱이 되었는지 확인하세요.
 */
stock Entity qufnrTools_CreateParticle ( float pos[3], float ang[3], const char[] name, float lifeTime = 0.0, int owner = -1, bool sendToOwner = false, bool attachment = false, const char[] attachName = "" ) {
    Entity entity = qufnrTools_CreateEntityByName ( "info_particle_system" );
    if ( entity.index != -1 ) {
        if ( attachment ) {
            if ( owner < 1 ) {
                entity.removeEdict ();
                return null;
            }
            GetEntPropVector ( owner, Prop_Send, "m_vecOrigin", pos );
        }
        entity.teleport ( pos, ang, NULL_VECTOR );

        entity.setKeyValue ( "effect_name", name );
        entity.setKeyValue ( "start_active", "1" );

        if ( attachment && owner != -1 ) {
            SetVariantString ( "!activator" );
            entity.acceptInput ( "SetParent", owner, entity.index, 0 );
            entity.setPropEnt ( Prop_Data, "m_pParent", owner );
            if ( attachName[0] != EOS ) {
                SetVariantString ( attachName );
                entity.acceptInput ( "SetParentAttachment", owner );
            }
        }

        entity.spawn ();
        entity.activate ();
        entity.acceptInput ( "Start" );

        if ( sendToOwner ) {
            entity.ownerEnt = owner;
            SDKHook ( entity.index, SDKHook_SetTransmit, qufnrTools_ParticleSetTransmit );
        }

        entity.fire ( lifeTime > 0.0 ? lifeTime : 3.0 );

        if ( entity.flags & FL_EDICT_ALWAYS )
            entity.flags = ( entity.flags ^ FL_EDICT_ALWAYS );
    }

    return entity;
}

/**
 * Display info_particle_system effects to screen
 * @param target
 * @param name
 * @param lifeTime
 * @return Entity object index
 */
stock Entity qufnrTools_DisplayParticleToScreen ( int target, const char[] name, float lifeTime = 0.0 ) {
    float vecOrigin[3];
    GetEntPropVector ( target, Prop_Send, "m_vecOrigin", vecOrigin );
    return qufnrTools_CreateParticle ( vecOrigin, NULL_VECTOR, name, lifeTime, target, true, true );
}

/**
 * 파티클을 삭제합니다.
 * @param entityReference   엔티티 레페런스 값
 * @noreturn
 */
stock void qufnrTools_RemoveParticle ( int entityReference ) {
    Entity entity = new Entity ( EntRefToEntIndex ( entityReference ) );

    if ( entity.index && entity.index != INVALID_ENT_REFERENCE ) {
        entity.acceptInput ( "Stop" );
        entity.acceptInput ( "Kill" );
    }

    entityReference = INVALID_ENT_REFERENCE;
}

public Action qufnrTools_ParticleSetTransmit ( int entity, int client ) {
    if ( GetEdictFlags ( entity ) & FL_EDICT_ALWAYS )
        SetEdictFlags ( entity, ( GetEdictFlags ( entity ) ^ FL_EDICT_ALWAYS ) );
    if ( ( GetEntPropEnt ( entity, Prop_Send, "m_hOwnerEntity" ) == client ) )
        return Plugin_Continue;
    return Plugin_Stop;
}