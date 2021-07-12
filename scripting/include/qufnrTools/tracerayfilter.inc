
/**
 * 플레이어만 필터합니다.
 */
stock bool qufnrTools_TraceRayFilterPlayer ( int entity, int mask, any data ) {
    return entity > 0 && entity <= MaxClients && entity != data;
}

/**
 * 엔티티만 필터합니다.
 */
stock bool qufnrTools_TraceRayFilterEntity ( int entity, int mask, any data ) {
    return entity > MaxClients && entity != data;
}

/**
 * 플레이어를 제외하고 필터합니다.
 */
stock bool qufnrTools_TraceRayFilterIgnorePlayer ( int entity, int mask ) {
    return !( 1 <= entity <= MaxClients );
}

/**
 * 세계와 엔티티만 필터합니다.
 */
stock bool qufnrTools_TraceRayFilterWorldAndEntity ( int entity, int mask, any data ) {
    return ( ( entity < 1 || entity > MaxClients ) && entity != data );
}