
const Player INVALID_PLAYER = view_as <Player> ( INVALID_ENT_REFERENCE );

methodmap Player < Entity {

	/**
	 * 플레이어 메소드맵의 생성자 입니다.
	 *
	 * @param param 클라이언트 인덱스 값
	 * @return		클라이언트가 유효하지 않다면 INVALID_PLAYER를 반환합니다.
	 * @note		Player 메소드맵에서 플레이어의 클라이언트 인덱스 값을 반환하려면 Entity에서 상속받은 Player.index property를 사용합니다. 
	 */
	public Player ( int param ) {
		if ( !( param > 0 && param <= MaxClients ) || !IsClientInGame ( param ) )
			return INVALID_PLAYER;
		return view_as <Player> ( EntIndexToEntRef ( param ) );
	}
	
	/**
	 * 플레이어의 유저 아이디 값을 반환합니다.
	 *
	 * @return 플레이어 유저 아이디 값
	 */
	public int getUserId () {
		return GetClientUserId ( this.index );
	}
	
	/**
	 * 플레이어의 시리얼 값을 반환합니다.
	 *
	 * @return 플레이어 시리얼 값
	 */
	public int getSerial () {
		return GetClientSerial ( this.index );
	}
	
	/**
	 * Returns if a player is connected.
	 *
	 * @return		True if player is connected to the server, false otherwise.
	 */
	public bool isConnected () {
		return IsClientConnected ( this.index );
	}
	
    /** 
     * Returns if a player has entered the game. 
	 *
     * @return                True if player has entered the game, false otherwise. 
     * @error                Invalid client index. 
     */
	public bool inGame () {
		return IsClientInGame ( this.index );
	}
	
    /** 
     * Returns if a client is timing out 
	 *
     * @return                True if client is timing out, false otherwise. 
     * @error                Invalid client index, client not connected, or fake client. 
     */
	public bool isTimingOut () {
		return IsClientTimingOut ( this.index );
	}
	
    /** 
     * Returns if a player is in the "kick queue" (i.e. the client will be kicked  
     * shortly and thus they should not appear as valid). 
     * 
     * @return                True if in the kick queue, false otherwise. 
     * @error                Invalid client index. 
     */
	public bool inKickQueue () {
		return IsClientInKickQueue ( this.index );
	}

    /** 
     * Returns if a player has been authenticated. 
     * 
     * @return                True if player has been authenticated, false otherwise. 
     */ 
	public bool isAuthorized () {
		return IsClientAuthorized ( this.index );
	}
	
    /** 
     * Returns if the client is alive or dead. 
     * 
     * Note: This function was originally in SDKTools and was moved to core. 
     * 
     * @return                True if the client is alive, false otherwise. 
     * @error                Invalid client index, client not in game, or no mod support. 
     */ 
	public bool isAlive () {
		return IsPlayerAlive ( this.index );
	}
	
    /** 
     * Returns if a player is a fake client. 
     * 
     * @return                True if player is a fake client, false otherwise. 
     */ 
	public bool isFake () {
		return IsFakeClient ( this.index );
	}

    /** 
     * Returns if a certain player is the SourceTV bot. 
     * 
     * @return                True if player is the SourceTV bot, false otherwise. 
     */ 
	public bool isSourceTV () {
		return IsClientSourceTV ( this.index );
	}

	public bool isGOTV () {
		return this.isSourceTV ();
	}

    /** 
     * Returns if a certain player is the Replay bot. 
     * 
     * @return                True if player is the Replay bot, false otherwise. 
     */ 
	public bool isReplay () {
		return IsClientReplay ( this.index );
	}

    /** 
     * Returns if a certain player is an observer/spectator. 
     * 
     * @return                True if player is an observer, false otherwise. 
     */ 
	public bool isObserver () {
		return IsClientObserver ( this.index );
	}
	
	/**
	 * 플레이어가 유효한지 채크합니다.
	 *
	 * @return 유효할 경우 true를 반환합니다.
	 */
	public bool isValid () {	//	Overriding Entity.isValid ()
		return qufnrTools_IsValidClient ( this.index );
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Sets the client to an inactive state waiting for a new map
	 */
	public void inactivate () {
		InactivateClient ( this.index );
	}

	/**
	 * Reconnect a client without dropping the netchannel
	 */
	public void reconnect () {
		ReconnectClient ( this.index );
	}

	/**
	 * Retrieves a client's AdminId.
	 */
	property AdminId adminId {
		public get () {
			return GetUserAdmin ( this.index );
		}
	}

	/**
	 * 관리자인지 채크합니다.
	 */
	public bool isAdmin () {
		return ( this.adminId != INVALID_ADMIN_ID );
	}

	/**
	 * 팀 번호 값을 반환합니다.
	 * @note 클라이언트의 팀 인덱스 값을 바꾸는 것입니다, 실제로는 반영되지 않습니다.
	 */
	property int teamNum {
		public get () {
			return GetEntProp ( this.index, Prop_Send, "m_iTeamNum" );
		}

		public set ( int param ) {
			SetEntProp ( this.index, Prop_Send, "m_iTeamNum", param );
		}
	}

	/**
	 * 팀을 반환합니다.
	 */
	property int team {
		public get () {
			return GetClientTeam ( this.index );
		}
	}
	
	/**
	 * 체력을 반환합니다.
	 */
	property int health {
		public get () {
			return GetEntProp ( this.index, Prop_Data, "m_iHealth" );
		}
		
		public set ( int param ) {
			SetEntProp ( this.index, Prop_Data, "m_iHealth", param );
		}
	}
	
	/**
	 * 최대 체력을 반환합니다.
	 */
	property int maxHealth {
		public get () {
			return GetEntProp ( this.index, Prop_Data, "m_iMaxHealth" );
		}
		
		public set ( int param ) {
			SetEntProp ( this.index, Prop_Data, "m_iMaxHealth", param );
		}
	}
	
	/**
	 * 아머(방탄복) 값을 반환합니다.
	 */
	property int armor { 
		public get () {
			return GetEntProp ( this.index, Prop_Data, "m_ArmorValue" );
		}
		
		public set ( int param ) {
			SetEntProp ( this.index, Prop_Data, "m_ArmorValue", param );
		}
	}
	
	/**
	 * 헬멧 유무를 반환합니다.
	 * 헬멧을 가지고 있다면 true, 아니면 false를 반환합니다.
	 */
	property bool helmat {
		public get () {
			return ( GetEntProp ( this.index, Prop_Send, "m_bHasHelmet" ) > 0 );
		}
		
		public set ( bool param ) {
			SetEntProp ( this.index, Prop_Send, "m_bHasHelmet", param ? 1 : 0 );
		}
	}
	
	/**
	 * 이동속도를 반환합니다.
	 */
	property float laggedMovement {
		public get () {
			return GetEntDataFloat ( this.index, FindSendPropInfo ( "CBasePlayer", "m_flLaggedMovementValue" ) );
		}
		
		public set ( float param ) {
			SetEntDataFloat ( this.index, FindSendPropInfo ( "CBasePlayer", "m_flLaggedMovementValue" ), param );
		}
	}
	
	/**
	 * 중력을 반환합니다.
	 */
	property float gravity {
		public get () {
			return GetEntityGravity ( this.index );
		}
		
		public set ( float param ) {
			SetEntPropFloat ( this.index, Prop_Data, "m_flGravity", param );
		}
	}
	
	/**
	 * 달러 값을 반환합니다.
	 */
	property int account {
		public get () {
			return GetEntProp ( this.index, Prop_Send, "m_iAccount" );
		}
		
		public set ( int param ) {
			SetEntProp ( this.index, Prop_Send, "m_iAccount", param );
		}
	}
	
	/**
	 * 최고 속도 값을 반환합니다.
	 */
	property int maxSpeed {
		public get () {
			return GetEntProp ( this.index, Prop_Send, "m_flMaxspeed" );
		}

		public set ( int param ) {
			SetEntProp ( this.index, Prop_Send, "m_flMaxspeed", param );
		}
	}

	/**
	 * 베이스 벨록시티 값을 가져옵니다.
	 */
	public int getBaseVelocity ( float vel[3] ) {
		GetEntPropVector ( this.index, Prop_Send, "m_vecBaseVelocity", vel );
	}

	/**
	 * 베이스 벨록시티 값을 설정합니다.
	 */
	public void setBaseVelocity ( const float vel[3] ) {
		SetEntPropVector ( this.index, Prop_Send, "m_vecBaseVelocity", vel );
	}

	/**
	 * 벨록시티 값을 가져옵니다.
	 */
	public void getVelocity ( float vel[3] ) {
		SetEntPropFloat ( this.index, Prop_Send, "m_vecVelocity[0]", vel[0] );
		SetEntPropFloat ( this.index, Prop_Send, "m_vecVelocity[1]", vel[1] );
		SetEntPropFloat ( this.index, Prop_Send, "m_vecVelocity[2]", vel[2] );
	}

	/** 
	 * 벨록시티 값을 설정합니다.
	 */
	public void setVelocity ( const float vel[3] ) {
		SetEntPropFloat ( this.index, Prop_Send, "m_vecVelocity[0]", vel[0] );
		SetEntPropFloat ( this.index, Prop_Send, "m_vecVelocity[1]", vel[1] );
		SetEntPropFloat ( this.index, Prop_Send, "m_vecVelocity[2]", vel[2] );
	}

	/**
	 * Gets player's Move Type.
	 */
	property MoveType moveType {
		public get () {
			return GetEntityMoveType ( this.index );
		}

		public set ( MoveType param ) {
			SetEntityMoveType ( this.index, param );
		}
	}
	
	/**
	 * returns get flags
	 */
	property int flags {
		public get () {
			return GetEntityFlags ( this.index );
		}

		public set ( int flags ) {
			SetEntityFlags ( this.index, flags );
		}
	}

	/**
	 * Get's a users current pressed buttons
	 */
	property int buttons {
		public get () {
			return GetClientButtons ( this.index );
		}
		
		public set ( int btn ) {
			this.setProp ( Prop_Data, "m_nButtons", btn );
		}
	}

	/**
	 * 팀을 바꿉니다.
	 */
	public void changeTeam ( int team ) {
		ChangeClientTeam ( this.index, team );
	}

	#if defined __cstrike_include
		/**
		 * 팀을 변경합니다.
		 */
		public void switchTeam ( int team ) {
			CS_SwitchTeam ( this.index, team );
		}

		/**
		 * 스폰합니다.
		 */
		public void respawn () {
			CS_RespawnPlayer ( this.index );
		}
	#endif

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//															Vector Functions
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * 위치 앵글을 구합니다.
	 */
	public void getAbsAngles ( float ang[3] ) {
		GetClientAbsAngles ( this.index, ang );
	}

	/**
	 * 오리진 백터 값을 구합니다.
	 */
	public void getAbsOrigin ( float vec[3] ) {
		GetClientAbsOrigin ( this.index, vec );
	}

	/**
	 * Returns the client's eye position.
	 */
	public void getEyePosition ( float pos[3] ) {
		GetClientEyePosition ( this.index, pos );
	}

	/**
	 * Returns the client's eye angles.
	 */
	public bool getEyeAngles ( float ang[3] ) {
		return GetClientEyeAngles ( this.index, ang );
	}

	/**
	 * Sets a client's "viewing entity."
	 */
	public void setViewEntity ( Entity entity ) {
		SetClientViewEntity ( this.index, entity.index );
	}

	/**
	 * Returns the entity a client is aiming at.
	 */
	public int getAimTarget ( bool only_clients = false ) {
		return GetClientAimTarget ( this.index, only_clients );
	}

	/**
	 * 속도를 반환합니다.
	 */
	public float getSpeed () {
		float flVel[3];
		this.getPropVector ( Prop_Data, "m_vecVelocity", flVel );
		return SquareRoot ( flVel[0] * flVel[0] + flVel[1] * flVel[1] + flVel[2] * flVel[2] );
	}

	/**
	 * 수평 속도를 반환합니다.
	 */
	public float getHorizontalSpeed () {
		float flVel[3];
		this.getPropVector ( Prop_Data, "m_vecVelocity", flVel );
		return SquareRoot ( flVel[0] * flVel[0] + flVel[1] * flVel[1] );
	}

	/**
	 * 수직 속도를 반환합니다.
	 */
	public float getVerticalSpeed () {
		float flVel[3];
		this.getPropVector ( Prop_Data, "m_vecVelocity", flVel );
		return SquareRoot ( flVel[2] * flVel[2] );
	}

	/**
	 * 속력(Velocity)를 반환합니다.
	 */
	public float getVelocitySpeed () {
		float flVel[3];
		this.getPropVector ( Prop_Data, "m_vecVelocity", flVel );
		return GetVectorLength ( flVel );
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * 인증 문자열을 반환합니다. (Steam ID)
	 */
	public bool getAuthId ( AuthIdType authType, char[] auth, int maxlen, bool validate ) {
		return GetClientAuthId ( this.index, authType, auth, maxlen, validate );
	}

	/**
	 * Returns the client's average packet choke, values go from 0 to 1 (for percentages).
	 */
	public float getAvgChoke ( NetFlow flow ) {
		return GetClientAvgChoke ( this.index, flow );
	}

	/**
	 * Returns the client's data flow in byte/sec.
	 */
	public float getAvgData ( NetFlow flow ) {
		return GetClientAvgChoke ( this.index, flow );
	}

	/** 
	 * Returns the client's average packet latency in seconds.
	 */
	public float getAvgLatency ( NetFlow flow ) {
		return GetClientAvgLatency ( this.index, flow );
	}

	/**
	 * Returns the client's current latency (RTT), more accurate than GetAvgLatency but jittering.
	 */
	public float getLatency ( NetFlow flow ) {
		return GetClientLatency ( this.index, flow );
	}

	/** 
	 * 최대 크기 사이즈를 반환합니다.
	 */
	public void getMaxs ( float vec[3] ) {
		GetClientMaxs ( this.index, vec );
	}

	/**
	 * 최소 크기 사이즈를 반환합니다.
	 */
	public void getMins ( float vec[3]) {
		GetClientMins ( this.index, vec );
	}

	/** 
	 * Returns the client's average packet loss, values go from 0 to 1 (for percentages).
	 */
	public float getAvgLoss ( NetFlow flow ) {
		return GetClientAvgLoss ( this.index, flow );
	}

	/**
	 * Returns the client's average packet frequency in packets/sec.
	 */
	public float getAvgPackets ( NetFlow flow ) {
		return GetClientAvgPackets ( this.index, flow );
	}

	/**
	 * Returns the client's send data rate in bytes/sec.
	 */
	property int dataRate {
		public get () {
			return GetClientDataRate ( this.index );
		}
	}

	/**
	 * 사망 횟수를 반환합니다.
	 */
	property int death {
		public get () {
			return GetClientDeaths ( this.index );
		}
	}

	/**
	 * frag 횟수를 반환합니다.
	 */
	property int frag {
		public get () {
			return GetClientFrags ( this.index );
		}
	}

	#if defined __cstrike_include

		/**
		 * 어시스트 횟수를 반환합니다. (CS:GO Only)
		 */
		property int assist {
			public get () {
				return CS_GetClientAssists ( this.index );
			}

			public set ( int param ) {
				CS_SetClientAssists ( this.index, param );
			}
		}

		/**
		 * 점수를 반환합니다. (CS:GO Only)
		 */
		property int contributionScore {
			public get () {
				return CS_GetClientContributionScore ( this.index );
			}

			public set ( int param ) {
				CS_SetClientContributionScore ( this.index, param );
			}
		}

		/**
		 * 클랜 태그를 반환합니다.
		 */
		public int getClanTag ( char[] buffer, int size ) {
			return CS_GetClientClanTag ( this.index, buffer, size );
		}

		/**
		 * 클랜 태그를 설정합니다.
		 */
		public void setClanTag ( const char[] tag ) {
			CS_SetClientClanTag ( this.index, tag );
		}
	
	#endif

	/**
	 * Returns the client's connection time in seconds.
	 */
	property float connTime {
		public get () {
			return GetClientTime ( this.index );
		}
	}

	/**
	 * Retrieves values from client replicated keys.
	 */
	public bool getInfo ( const char[] key, char[] value, int maxlen ) {
		return GetClientInfo ( this.index, key, value, maxlen );
	}

	/**
	 * IP를 가져옵니다.
	 */
	public bool getIP ( char[] ip, int maxlen, bool remport ) {
		return GetClientIP ( this.index, ip, maxlen, remport );
	}

	/**
	 * 이름을 설정합니다.
	 */
	public void setName ( const char[] name ) {
		SetClientName ( this.index, name );
	}

	/**
	 * 이름을 구합니다.
	 */
	public bool getName ( char[] name, int maxlen ) {
		return GetClientName ( this.index, name, maxlen );
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * 모델을 설정합니다.
	 */
	public void setModel ( const char[] model ) {
		SetEntityModel ( this.index, model );
	}

	/**
	 * 모델을 구합니다.
	 */
	public void getModel ( char[] model, int maxlen ) {
		GetClientModel ( this.index, model, maxlen );
	}

	#if defined __cstrike_include

		/**
		 * 모델을 업데이트합니다. (CS:S, CS:GO Only)
		 */
		public void updateModel () {
			CS_UpdateClientModel ( this.index );
		}

	#endif

	/**
	 * 손 모델을 설정합니다. (CS:GO, L4D2 Only) 
	 */
	public int setArmsModel ( const char[] model, int maxlen ) {
		return this.setPropString ( Prop_Send, "m_szArmsModel", model, maxlen );
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//														Weapon & Item Functions
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * 아이템을 줍니다.
	 */
	public void giveItem ( const char[] item ) {
		GivePlayerItem ( this.index, item );
	}

	/**
	 * 무기를 착용합니다.
	 */
	public void equipWeapon ( int weapon ) {
		EquipPlayerWeapon ( this.index, weapon );
	}

	/**
	 * 무기를 구합니다.
	 */
	public void getWeapon ( char[] weapon, int maxlen ) {
		GetClientWeapon ( this.index, weapon, maxlen );
	}

	/**
	 * 무기 슬롯의 아이템을 구합니다.
	 */
	public int getSlotItem ( int slot ) {
		return GetPlayerWeaponSlot ( this.index, slot );
	}

	/**
	 * Removes a player's item.
	 */
	public bool removeItem ( int item ) {
		return RemovePlayerItem ( this.index, item );
	}

	/**
	 * 슬롯의 아이템을 삭제합니다.
	 */
	public void removeSlotItem ( int slot ) {
		if ( this.getSlotItem ( slot ) != -1 )
			this.removeItem ( this.getSlotItem ( slot ) );
	}
	
	/**
	 * Active Weapon을 반환합니다.
	 */
	property int activeWeapon {
		public get () {
			return this.getPropEnt ( Prop_Data, "m_hActiveWeapon" );
		}

		public set ( int param ) {
			this.setPropEnt ( Prop_Data, "m_hActiveWeapon", param );
		}
	}

	/**
	 * Get primary ammo
	 * @param index			Weapon index
	 */
	public int getPrimaryAmmo ( int index ) {
		Weapon weapon = Weapon ( WeaponGetType_Param, index );
		int nAmmoType = weapon.primaryAmmoType;
		if ( nAmmoType == -1 )
			return -1;
		return this.getProp ( Prop_Send, "m_iAmmo", _, nAmmoType );
	}

	/**
	 * Set primary ammo
	 */
	public int setPrimaryAmmo ( int index, int amount ) {
		Weapon weapon = Weapon ( WeaponGetType_Param, index );
		int nAmmoType = weapon.primaryAmmoType;
		if ( nAmmoType != -1 )
			SetEntProp ( this.index, Prop_Send, "m_iAmmo", amount, _, nAmmoType );
	}

	/**
	 * Get secondary ammo
	 * @param index			Weapon index
	 */
	public int getSecondaryAmmo ( int index ) {
		Weapon weapon = Weapon ( WeaponGetType_Param, index );
		int nAmmoType = weapon.secondaryAmmoType;
		if ( nAmmoType == -1 )
			return -1;
		return GetEntProp ( this.index, Prop_Send, "m_iAmmo", _, nAmmoType );
	}

	/**
	 * Set secondary ammo
	 */
	public int setSecondaryAmmo ( int index, int amount ) {
		Weapon weapon = Weapon ( WeaponGetType_Param, index );
		int nAmmoType = weapon.secondaryAmmoType;
		if ( nAmmoType != -1 )
			SetEntProp ( this.index, Prop_Send, "m_iAmmo", amount, _, nAmmoType );
	}

	/**
	 * 무기 오프셋 값을 반환합니다.
	 */
	property int weaponOffset {
		public get () {
			return FindDataMapInfo ( this.index, "m_hMyWeapons" );
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * 언어를 반환합니다.
	 */
	property int language {
		public get () {
			return GetClientLanguage ( this.index );
		}

		public set ( int param ) {
			SetClientLanguage ( this.index, param );
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//																Menu Functions
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Cancels a menu on a client. This will only affect non-external menus.
	 */
	public bool cancelMenu ( bool autoIgnore, Handle hStyle ) {
		return CancelClientMenu ( this.index, autoIgnore, hStyle );
	}

	/**
	 * Returns whether a client is viewing a menu.
	 */
	public MenuSource getMenu ( Handle hStyle ) {
		return GetClientMenu ( this.index, hStyle );
	}

	/**
	 * Returns whether a client is in the pool of clients allowed to participate in the current vote.
	 * This is determined by the client list passed to VoteMenu().
	 */
	property bool isInVotePool {
		public get () {
			return IsClientInVotePool ( this.index );
		}
	}

	/**
	 * Redraws the current vote menu to a client in the voting pool.
	 */
	public bool redrawVoteMenu ( bool revotes ) {
		return RedrawClientVoteMenu ( this.index, revotes );
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//															Command Functions
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Executes a client command.  Note that this will not work on clients unless
	 * they have cl_restrict_server_commands set to 0.
	 *
	 * @param fmt           Format of the client command.
	 * @param ...           Format parameters
	 * @error               Invalid client index, or client not connected.
	 */
	public void command ( const char[] fmt, any ... ) {
		static char strBuffer[256];
		VFormat ( strBuffer, sizeof strBuffer, fmt, 2 );
		ClientCommand ( this.index, strBuffer );
	}

	/**
	 * Executes a client command on the server without being networked.
	 *
	 * FakeClientCommand() overwrites the command tokenization buffer.  This can 
	 * cause undesired effects because future calls to GetCmdArg* will return 
	 * data from the FakeClientCommand(), not the parent command.  If you are in 
	 * a hook where this matters (for example, a "say" hook), you should use 
	 * FakeClientCommandEx() instead.
	 *
	 * @param fmt           Format of the client command.
	 * @param ...           Format parameters
	 * @error               Invalid client index, or client not connected.
	 */
	public void fakeCommand ( const char[] fmt, any ... ) {
		static char strBuffer[256];
		VFormat ( strBuffer, sizeof strBuffer, fmt, 3 );
		FakeClientCommand ( this.index, "%s", strBuffer );
	}

	/**
	 * Executes a client command on the server without being networked.  The 
	 * execution of the client command is delayed by one frame to prevent any 
	 * re-entrancy issues that might surface with FakeClientCommand().
	 *
	 * @param fmt           Format of the client command.
	 * @param ...           Format parameters
	 * @error               Invalid client index, or client not connected.
	 */
	public void fakeCommandEx ( const char[] fmt, any ... ) {
		static char strBuffer[256];
		VFormat ( strBuffer, sizeof strBuffer, fmt, 3 );
		FakeClientCommandEx ( this.index, "%s", strBuffer );
	}

	/**
	 * Executes a KeyValues client command on the server without being networked.
	 *
	 * @param kv            KeyValues data to be sent.
	 * @error               Invalid client index, client not connected,
	 *                      or unsupported on current game.
	 */
	public void fakeCommandKeyValues ( KeyValues kv ) {
		FakeClientCommandKeyValues ( this.index, kv );
	}

	/**
	 * Sets a convar value on a fake client
	 */
	public void setFakeConVar ( const char[] cvar, const char[] value ) {
		SetFakeClientConVar ( this.index, cvar, value );
	}

	/**
	 * Returns whether a client has access to a given command string.  The string 
	 * can be any override string, as overrides can be independent of 
	 * commands.  This feature essentially allows you to create custom 
	 * flags using the override system.
	 *
	 * @param command       Command name.  If the command is not found, the default 
	 *                      flags are used.
	 * @param flags         Flag string to use as a default, if the command or override 
	 *                      is not found.
	 * @param override_only If true, SourceMod will not attempt to find a matching 
	 *                      command, and it will only use the default flags specified.
	 *                      Otherwise, SourceMod will ignore the default flags if 
	 *                      there is a matching admin command.
	 * @return              True if the client has access, false otherwise.
	 */
	public bool checkCommandAccess ( const char[] command, int flags, bool override_only = false ) {
		return CheckCommandAccess ( this.index, command, flags, override_only );
	}

	/**
	 * Starts a query to retrieve the value of a client's console variable.
	 *
	 * @param client        Player index.
	 * @param cvarName      Name of client convar to query.
	 * @param callback      A function to use as a callback when the query has finished.
	 * @param value         Optional value to pass to the callback function.
	 * @return              A cookie that uniquely identifies the query. 
	 *                      Returns QUERYCOOKIE_FAILED on failure, such as when used on a bot.
	 */
	public QueryCookie queryConVar ( const char[] cvarName, ConVarQueryFinished callback, any value = 0 ) {
		return QueryClientConVar ( this.index, cvarName, callback, value );
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//														Printing Message Functions
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Sends a message to a client's console.
	 *
	 * @param client        Client index.
	 * @param format        Formatting rules.
	 * @param ...           Variable number of format parameters.
	 * @error               If the client is not connected an error will be thrown.
	 */
	public void sendConsole ( const char[] format, any ... ) {
		static char strBuffer[1024];
		SetGlobalTransTarget ( this.index );
		VFormat ( strBuffer, sizeof strBuffer, format, 3 );
		PrintToConsole ( this.index, strBuffer );
	}

	/**
	 * 플레이어에게 채팅 메세지를 보냅니다.
	 *
	 * @param format		메세지 포멧
	 * @param ...			메세지 파라메터
	 * @noreturn
	 */
	public void sendChat ( const char[] format, any ... ) {
		char buffer[254];
		
		SetGlobalTransTarget ( this.index );
		VFormat ( buffer, sizeof buffer, format, 3 );
		qufnrTools_PrintToChat ( this.index, "%s", buffer );
	}
	
	/**
	 * 플레이어에게 커멘드 리플라이를 보냅니다.
	 *
	 * @param format		메세지 포멧
	 * @param ...			메세지 파라메터
	 * @noreturn
	 */
	public void sendReply ( const char[] format, any ... ) {
		char buffer[254];
		
		SetGlobalTransTarget ( this.index );
		VFormat ( buffer, sizeof buffer, format, 3 );
		qufnrTools_ReplyToCommand ( this.index, "%s", buffer );
	}
	
	/**
	 * 플레이어에게 힌트 텍스트를 보냅니다.
	 *
	 * @param format		메세지 포멧
	 * @param ...			메세지 파라메터
	 * @noreturn
	 */
	public void sendHintText ( const char[] format, any ... ) {
		char buffer[254];
		
		SetGlobalTransTarget ( this.index );
		VFormat ( buffer, sizeof buffer, format, 3 );
		PrintHintText ( this.index, "%s", buffer );
	}
	
	/**
	 * 플레이어에게 센터 텍스트를 보냅니다.
	 *
	 * @param format		메세지 포멧
	 * @param ...			메세지 파라메터
	 * @noreturn
	 */
	public void sendCetnerText ( const char[] format, any ... ) {
		char buffer[254];
		
		SetGlobalTransTarget ( this.index );
		VFormat ( buffer, sizeof buffer, format, 3 );
		PrintCenterText ( this.index, "%s", buffer );
	}
	
	/**
	 * 플레이어에게 힌트 텍스트를 보냅니다. (CS:GO Only)
	 *
	 * @param format		메세지 포멧
	 * @param ...			메세지 파라메터
	 * @noreturn
	 */
	public void sendCSGOHintText ( const char[] format, any ... ) {
		char buffer[254];
		
		SetGlobalTransTarget ( this.index );
		VFormat ( buffer, sizeof buffer, format, 3 );
		qufnrTools_PrintHintText ( this.index, "%s", buffer );
	}
	
	/**
	 * 플레이어에게 센터 텍스트를 보냅니다. (CS:GO Only)
	 *
	 * @param format		메세지 포멧
	 * @param ...			메세지 파라메터
	 * @noreturn
	 */
	public void sendCSGOCetnerText ( const char[] format, any ... ) {
		char buffer[254];
		
		SetGlobalTransTarget ( this.index );
		VFormat ( buffer, sizeof buffer, format, 3 );
		qufnrTools_PrintCenterText ( this.index, "%s", buffer );
	}

	/**
	 * 플레이어에게 KeyHintText를 보냅니다.
	 *
	 * @param fmt			메세지 포멧
	 * @param ...			메세지 파라메터
	 */
	public void sendKeyHintText ( const char[] fmt, any ... ) {
		Handle hMessage = StartMessageOne ( "KeyHintText", this.index );
		if ( hMessage != null ) {
			char szBuffer[1024];
			SetGlobalTransTarget ( this.index );
			VFormat ( szBuffer, sizeof szBuffer, fmt, 3 );
			if ( GetUserMessageType () == UM_Protobuf ) {
				Protobuf pb = UserMessageToProtobuf ( hMessage );
				pb.AddString ( "hints", szBuffer );
			}
			else {
				BfWrite bf = UserMessageToBfWrite ( hMessage );
				bf.WriteByte ( 1 );
				bf.WriteString ( szBuffer );
			}
		}

		EndMessage ();
	}

	/**
	 * 플레이어에게 허드 텍스트를 보냅니다.
	 *
	 * @param channel		허드 채널
	 * @param format		메세지 포멧
	 * @param ...			메세지 파라메터
	 */
	public void sendHudText ( int channel, const char[] format, any ... ) {
		char szBuffer[254];

		SetGlobalTransTarget ( this.index );
		VFormat ( szBuffer, sizeof szBuffer, format, 4 );
		qufnrTools_ShowHudText ( this.index, channel, "%s", szBuffer );
	}

	/**
	 * 플레이어에게 싱크 허드 텍스트를 보냅니다.
	 *
	 * @param syncHndl		싱크 핸들
	 * @param format		메세지 포멧
	 * @param ...			메세지 파라메터
	 */
	public void sendSyncHudText ( Handle syncHndl, const char[] format, any ... ) {
		char szBuffer[254];
		
		SetGlobalTransTarget ( this.index );
		VFormat ( szBuffer, sizeof szBuffer, format, 4 );
		qufnrTools_ShowSyncHudText ( this.index, syncHndl, "%s", szBuffer );
	}

	/**
	 * Send SayText2
	 */
	public void sendSayText2 ( int target = 0, bool wantsToChat = false, const char[] fmt, any ... ) {
		char szBuffer[192];
		VFormat ( szBuffer, sizeof szBuffer, fmt, 5 );
		StrCat ( szBuffer, sizeof szBuffer, "\n" );
		Handle hMessage = StartMessageOne ( "SayText2", target, USERMSG_RELIABLE | USERMSG_BLOCKHOOKS );
		if ( GetFeatureStatus ( FeatureType_Native, "GetUserMessageType" ) == FeatureStatus_Available && GetUserMessageType () == UM_Protobuf ) {
			Protobuf pb = UserMessageToProtobuf ( hMessage );
			if ( pb != null ) {
				pb.SetInt ( "ent_idx", this.index );
				pb.SetBool ( "chat", wantsToChat );
				pb.SetString ( "msg_name", szBuffer );
				pb.AddString ( "params", "" );
				pb.AddString ( "params", "" );
				pb.AddString ( "params", "" );
				pb.AddString ( "params", "" );
			}
		}
		else {
			BfWrite bf = UserMessageToBfWrite ( hMessage );
			bf.WriteByte ( this.index );
			bf.WriteByte ( wantsToChat );
			bf.WriteString ( szBuffer );
		}

		EndMessage ();
	}

	/**
	 * Send SayText2 to all players
	 */
	public void sendSayText2ToAll ( bool wantsToChat = false, const char[] fmt, any ... ) {
		char szBuffer[254];
		Player pServerPlayers; int i;
		FIND_ALL_PLAYERS ( i ) {
			if ( VALID_PLAYER_IN_FOR ( i, pServerPlayers ) && !pServerPlayers.isFake () ) {
				SetGlobalTransTarget ( pServerPlayers.index );
				VFormat ( szBuffer, sizeof szBuffer, fmt, 4 );
				this.sendSayText2 ( pServerPlayers.index, wantsToChat, "%s", szBuffer );
			}
		}
	}

	/**
	 * Send SayText2 to teams
	 */
	public void sendSayText2ToTeam ( int team, bool wantsToChat = false, const char[] fmt, any ... ) {
		char szBuffer[254];
		Player pTeamPlayers; int i;
		FIND_ALL_PLAYERS ( i ) {
			if ( VALID_PLAYER_IN_FOR ( i, pTeamPlayers ) && !pTeamPlayers.isFake () && pTeamPlayers.team == team ) {
				SetGlobalTransTarget ( pTeamPlayers.index );
				VFormat ( szBuffer, sizeof szBuffer, fmt, 5 );
				this.sendSayText2 ( pTeamPlayers.index, wantsToChat, "%s", szBuffer );
			}
		}
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//																	Sound Function
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	public void fadeVolume ( float percent, float outtime, float holdtime, float intime ) {
		FadeClientVolume ( this.index, percent, outtime, holdtime, intime );
	}

	/**
	 * Wrapper to emit sound to one client.
	 *
	 * @param sample        Sound file name relative to the "sound" folder.
	 * @param entity        Entity to emit from.
	 * @param channel       Channel to emit with.
	 * @param level         Sound level.
	 * @param flags         Sound flags.
	 * @param volume        Sound volume.
	 * @param pitch         Sound pitch.
	 * @param speakerentity Unknown.
	 * @param origin        Sound origin.
	 * @param dir           Sound direction.
	 * @param updatePos     Unknown (updates positions?)
	 * @param soundtime     Alternate time to play sound for.
	 * @error               Invalid client index.
	 */
	public void playSound ( const char[] sample,
							int entity = SOUND_FROM_PLAYER,
							int channel = SNDCHAN_AUTO,
							int level = SNDLEVEL_NORMAL,
							int flags = SND_NOFLAGS,
							float volume = SNDVOL_NORMAL,
							int pitch = SNDPITCH_NORMAL,
							int speakerentity = -1,
							const float origin[3] = NULL_VECTOR,
							const float dir[3] = NULL_VECTOR,
							bool updatePos = true,
							float soundtime = 0.0 ) {
		EmitSoundToClient ( this.index, sample, entity, channel, level, flags, volume, pitch, speakerentity, origin, dir, updatePos, soundtime );
	}

	/**
	 * Wrapper to emit a game sound to one client.
	 *
	 * Game sounds are found in a game's scripts/game_sound.txt or other files
	 * referenced from it
	 *
	 * Note that if a game sound has a rndwave section, one of them will be returned
	 * at random.
	 *
	 * @param gameSound     Name of game sound.
	 * @param entity        Entity to emit from.
	 * @param flags         Sound flags.
	 * @param speakerentity Unknown.
	 * @param origin        Sound origin.
	 * @param dir           Sound direction.
	 * @param updatePos     Unknown (updates positions?)
	 * @param soundtime     Alternate time to play sound for.
	 * @error               Invalid client index.
	 */
	public bool playGameSound ( const char[] gameSound,
								int entity = SOUND_FROM_PLAYER,
								int flags = SND_NOFLAGS,
								int speakerentity = -1,
								const float origin[3] = NULL_VECTOR,
								const float dir[3] = NULL_VECTOR,
								bool updatePos = true,
								float soundtime = 0.0 ) {
		EmitGameSoundToClient ( this.index, gameSound, entity, flags, speakerentity, origin, dir, updatePos, soundtime );
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Disconnects a client from the server as soon as the next frame starts.
	 *
	 * Note: Originally, KickClient() was immediate.  The delay was introduced 
	 * because despite warnings, plugins were using it in ways that would crash. 
	 * The new safe version can break cases that rely on immediate disconnects, 
	 * but ensures that plugins do not accidentally cause crashes.
	 *
	 * If you need immediate disconnects, use KickClientEx().
	 *
	 * Note: IsClientInKickQueue() will return true before the kick occurs.
	 *
	 * @param format        Optional formatting rules for disconnect reason.
	 *                      Note that a period is automatically appended to the string by the engine.
	 * @param ...           Variable number of format parameters.
	 * @error               Invalid client index, or client not connected.
	 */
	public void kick ( const char[] format = "", any ... ) {
		static char strBuffer[192];
		VFormat ( strBuffer, sizeof strBuffer, format, 3 );
		KickClient ( this.index, "%s", strBuffer );
	}

	/**
	 * Immediately disconnects a client from the server.
	 *
	 * Kicking clients from certain events or callbacks may cause crashes.  If in 
	 * doubt, create a short (0.1 second) timer to kick the client in the next 
	 * available frame.
	 *
	 * @param format        Optional formatting rules for disconnect reason.
	 *                      Note that a period is automatically appended to the string by the engine.
	 * @param ...           Variable number of format parameters.
	 * @error               Invalid client index, or client not connected.
	 */
	public void kickEx ( const char[] format = "", any ... ) {
		static char strBuffer[192];
		VFormat ( strBuffer, sizeof strBuffer, format, 3 );
		KickClientEx ( this.index, "%s", strBuffer );
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//															Misc Functions
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Display overlay to player.
	 */
	public void showOverlay ( const char[] overlay ) {
		int nFlags = GetCommandFlags ( "r_screenoverlay" ) & ( ~FCVAR_CHEAT );
		SetCommandFlags ( "r_screenoverlay", nFlags );
		char szTemp[256];
		Format ( szTemp, sizeof szTemp, "%s", overlay );
		ReplaceString ( szTemp, sizeof szTemp, "materials/", "" );
		if ( IsDecalPrecached ( szTemp ) )
			PrecacheDecal ( szTemp, true );
		this.command ( "r_screenoverlay \"%s\"", szTemp );
	}

	/** 
	 * Clear overlay to player.
	 */
	public void clearOverlay () {
		int nFlags = GetCommandFlags ( "r_screenoverlay" ) & ( ~FCVAR_CHEAT );
		SetCommandFlags ( "r_screenoverlay", nFlags );
		this.command ( "r_screenoverlay \"\"" );
	}

	/**
	 * Fov 값을 반환합니다.
	 */
	property int fov {
		public get () {
			return this.getProp ( Prop_Send, "m_iFOV" );
		}
		
		public set ( int param ) {
			this.setProp ( Prop_Send, "m_iFOV", param );
		}
	}

	/**
	 * Default Fov 값을 반환합니다.
	 */
	property int defaultFov {
		public get () {
			return this.getProp ( Prop_Send, "m_iDefaultFOV" );
		}

		public set ( int param ) {
			this.setProp ( Prop_Send, "m_iDefaultFOV", param );
		}
	}

	/**
	 * 허드를 숨깁니다.
	 */
	public void setHideHud ( int flags ) {
		this.setProp ( Prop_Send, "m_iHideHUD", flags );
	}

	/**
	 * 숨긴 허드의 값을 반환합니다.
	 */
	public int getHideHud () {
		return this.getProp ( Prop_Send, "m_iHideHUD" );
	}

	/**
	 * 사다리에 올라 타있는지 유무를 반환합니다.
	 */
	public bool isOnLadder () {
		return ( this.moveType == MOVETYPE_LADDER );
	}

	/**
	 * Override the receiver's ability to listen to the sender.
	 *
	 * @param iSender       The sender index.
	 * @param override      The override of the receiver's ability to listen to the sender.
	 * @return              True if successful otherwise false.
	 */
	public bool setListenOverride ( int iSender, ListenOverride override ) {
		return SetListenOverride ( this.index, iSender, override );
	}

	/**
	 * Retrieves the override of the receiver's ability to listen to the sender.
	 *
	 * @param iSender       The sender index.
	 * @return              The override value.
	 */
	public ListenOverride getListenOverride ( int iSender ) {
		return GetListenOverride ( this.index, iSender );
	}

	/**
	 * Set the client listening flags.
	 */
	property int listeningFlags {
		public get () {
			return GetClientListeningFlags ( this.index );
		}

		public set ( int flags ) {
			SetClientListeningFlags ( this.index, flags );
		}
	}

	/**
	 * 음성채팅을 차단해제 합니다.
	 */
	public void unmute () {
		this.listeningFlags = VOICE_NORMAL;
	}

	/**
	 * 음성채팅을 차단합니다.
	 */
	public void mute () {
		this.listeningFlags = VOICE_MUTED;
	}

	/**
	 * 특정 Target에 대한 음성채팅 차단을 해제합니다.
	 */
	public void privateUnmute ( Player target ) {
		this.setListenOverride ( target.index, Listen_Yes );
	}

	/** 
	 * 특정 Target에 대한 음성을 차단합니다.
	 */
	public void privateMute ( Player target ) {
		this.setListenOverride ( target.index, Listen_No );
	}

	/**
	 * 플레이어 이름이 일치한지 유무를 반환합니다.
	 *
	 * @param name
	 * @param caseSensitive
	 * @param partialMatch
	 * @return	해당 조건으로 이름이 일치하면 true를 반환합니다.
	 */
	public bool isNameMatches ( const char[] name, bool caseSensitive = true, bool partialMatch = false ) {
		return qufnrTools_IsClientNameMatches ( this.index, name, caseSensitive, partialMatch );
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//															Vector Function
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	/** 
	 * Get client's aim target entity.
	 */
	public Entity getAimEntity () {
		Entity result = INVALID_ENTITY;
		float flAngles[3], flOrigin[3];
		this.getEyeAngles ( flAngles );
		this.getEyePosition ( flOrigin );

		Handle hTraceRay = TR_TraceRayFilterEx ( flOrigin, flAngles, MASK_SHOT, RayType_Infinite, qufnrTools_TraceRayFilterIgnorePlayer, this.index );
		if( TR_DidHit ( hTraceRay ) ) {
			result = Entity ( TR_GetEntityIndex ( hTraceRay ) );
		}
		delete hTraceRay;
		
		return result;
	}

	/** 
	 * Get client's aim target player.
	 */
	public Player getAimPlayer () {
		Player result = Player ( -1 );
		float flAngles[3], flOrigin[3];
		this.getEyeAngles ( flAngles );
		this.getEyePosition ( flOrigin );

		Handle hTraceRay = TR_TraceRayFilterEx ( flOrigin, flAngles, MASK_SHOT, RayType_Infinite, qufnrTools_TraceRayFilterPlayer, this.index );
		if( TR_DidHit ( hTraceRay ) ) {
			result = Player ( TR_GetEntityIndex ( hTraceRay ) );
		}
		delete hTraceRay;
		
		return result;
	}

	/**
	 * 클라이언트의 에임이 가르키는 엔티티와의 거리를 구합니다.
	 *
	 * @param maxtracedistance		클라이언트와 엔티티의 거리
	 * @return 거리안에 들어오면 true, 아니면 false를 반환합니다.
	 */
	public bool getAimEntityDistance ( float maxtracedistance ) {
		float flPos[3], flAng[3];
		this.getEyePosition ( flPos );
		this.getEyeAngles ( flAng );
		Handle hTraceRay = TR_TraceRayFilterEx ( flPos, flAng, MASK_SOLID, RayType_Infinite, qufnrTools_TraceRayFilterIgnorePlayer, this.index );
		if ( TR_DidHit ( hTraceRay ) ) {
			float flEnd[3];
			TR_GetEndPosition ( flEnd, hTraceRay );
			TR_GetPlaneNormal ( hTraceRay, flEnd );

			GetVectorAngles ( flAng, flAng );

			if ( maxtracedistance >= GetVectorDistance ( flPos, flEnd ) ) {
				delete hTraceRay;
				return true;
			}
			delete hTraceRay;
		}
		return false;
	}

	/**
	 * 클라이언트의 특정 거리 안에 해당 타겟이 존재하는지 유무를 반환합니다.
	 *
	 * @param target
	 * @param distance
	 * @param nearestDistance
	 * @return 해당 거리 안에 타겟이 있다면 true를 반환합니다.
	 */
	public bool isTargetInNearest ( int target, float distance = 50.0, float &nearestDistance = 0.0 ) {
		Player pTarget = Player ( target );
		if ( pTarget != INVALID_PLAYER && pTarget.isValid () && pTarget.index != this.index ) {
			static float vecEye[2][3];
			this.getEyePosition ( vecEye[0] );
			pTarget.getEyePosition ( vecEye[1] );
			
			if ( GetVectorDistance ( vecEye[0], vecEye[1] ) <= distance ) {
				static float vecVec[3], vecAng[3];
				MakeVectorFromPoints ( vecEye[0], vecEye[1], vecVec );
				GetVectorAngles ( vecVec, vecAng );
				Handle hTraceRay = TR_TraceRayFilterEx ( vecEye[0], vecAng, MASK_SOLID, RayType_Infinite, qufnrTools_TraceRayFilterPlayer, this.index );
				if ( TR_DidHit ( hTraceRay ) ) {
					if ( TR_GetEntityIndex ( hTraceRay ) == pTarget.index ) {
						delete hTraceRay;
						return true;
					}
				}
				delete hTraceRay;
			}
		}

		return false;
	}

	/**
	 * 특정 거리 안에 가까운 타겟 한 명을 구합니다.
	 *
	 * @param distance
	 * @param only_enemy		타겟을 적군으로만 찾을 경우 true로 합니다.
	 * @return Nearby to one client index from distance.
	 */
	public int getNearestTarget ( float distance = 50.0, bool only_enemy = false ) {
		int nIndex = -1;
		
		Player pTarget;
		int i;
		FIND_ALL_PLAYERS ( i ) {
			if ( VALID_PLAYER_IN_FOR ( i, pTarget ) && pTarget.isValid () && pTarget.isAlive () && pTarget.index != this.index ) {
				if ( ( only_enemy ? pTarget.team != this.team : true ) && this.isTargetInNearest ( pTarget.index, distance ) ) {
					nIndex = pTarget.index;
					break;
				}
			}
		}

		return nIndex;
	}

	/**
	 * 타겟이 바라보는 앵글 내에 보이는지 유무를 반환합니다.
	 * @note 이 함수는 벽이나 특정 사물 뒤에 있어도 degree 내에 보이면 true를 반환합니다.
	 *
	 * @param target		Index of target value.
	 * @param degree		Degree of view angle.
	 * @param negative_angles	No description
	 * @return	타겟이 앵글 내에 보인다면 true를 반환합니다.
	 */
	public bool isTargetInSight ( int target, float degree = 90.0, bool negative_angles = false ) {
		if ( degree < 0.0 ) 
			return false;
		
		Player pTarget = Player ( target );
		if ( pTarget == INVALID_PLAYER || !pTarget.isValid () )
			return false;
		
		if ( degree > 360.0 )
			degree = 360.0;
		
		float vecPos[2][3];
		float vecAngVec[3];
		float vecTargetVec[3];
		float flResultAngle;
		
		this.getEyeAngles ( vecAngVec );
		vecAngVec[0] = vecAngVec[2] = 0.0;
		GetAngleVectors ( vecAngVec, vecAngVec, NULL_VECTOR, NULL_VECTOR );
		NormalizeVector ( vecAngVec, vecAngVec );
		
		if ( negative_angles )
			NegateVector ( vecAngVec );

		this.getAbsOrigin ( vecPos[0] );
		pTarget.getAbsOrigin ( vecPos[1] );

		
		vecPos[0][2] = vecPos[1][2] = 0.0;
		MakeVectorFromPoints ( vecPos[0], vecPos[1], vecTargetVec );
		NormalizeVector ( vecTargetVec, vecTargetVec );

		flResultAngle = RadToDeg ( ArcCosine ( GetVectorDotProduct ( vecTargetVec, vecAngVec ) ) );

		if ( flResultAngle <= degree / 2 )
			return true;
		return false;
	}

	/**
	 * 타겟이 특정 거리 내에 있는지 유무를 반환합니다.
	 *
	 * @param target		타겟 인덱스 값
	 * @param distance		타겟 과의 거리
	 * @param height_check	높이 채크
	 * @return 타겟이 특정 거리 내에 있다면 true를 반환합니다.
	 */
	public bool isTargetInRange ( int target, float distance = 50.0, bool height_check = true ) {
		Player pTarget = Player ( target );
		if ( pTarget == INVALID_PLAYER || !pTarget.isValid () )
			return false;
		
		float vecPos[2][3];
		float flResultDistance;

		this.getAbsOrigin ( vecPos[0] );
		pTarget.getAbsOrigin ( vecPos[1] );

		if ( height_check )
			vecPos[0][2] = vecPos[1][2] = 0.0;
			
		flResultDistance = GetVectorDistance ( vecPos[0], vecPos[1] );
		
		if ( distance > 0 ) {
			if ( distance >= flResultDistance )
				return true;
		}
		return false;
	}

	/**
	 * 클라이언트 기준으로 타겟이 앵글과 거리 안에 있는지 유무를 반환합니다.
	 *
	 * @param target		Index of target value.
	 * @param degree		보이는 각도
	 * @param distance		타겟과의 거리
	 * @param height_check	높이 채크
	 * @param negative_angles	No dsecription
	 * @return	해당 조건으로 타겟이 있다면 true를 반환합니다.
	 */
	public bool isTargetInSightRange ( int target, float degree = 90.0, float distance = 50.0, bool height_check = true, bool negative_angles = false ) {
		if ( degree < 0.0 )
			return false;

		Player pTarget = Player ( target );
		if ( pTarget == INVALID_PLAYER || !pTarget.isValid () )
			return false;

		if ( degree > 360.0 )
			degree = 360.0;
		
		float vecPos[2][3];
		float vecAngVec[3];
		float vecTargetVec[3];
		float flResultAngle;
		float flResultDistance;
		
		this.getEyeAngles ( vecAngVec );
		vecAngVec[0] = vecAngVec[2] = 0.0;
		GetAngleVectors ( vecAngVec, vecAngVec, NULL_VECTOR, NULL_VECTOR );
		NormalizeVector ( vecAngVec, vecAngVec );
		
		if ( negative_angles )
			NegateVector ( vecAngVec );

		this.getAbsOrigin ( vecPos[0] );
		pTarget.getAbsOrigin ( vecPos[1] );

		if ( height_check && distance > 0 )
			flResultDistance = GetVectorDistance ( vecPos[0], vecPos[1] );
		
		vecPos[0][2] = vecPos[1][2] = 0.0;
		MakeVectorFromPoints ( vecPos[0], vecPos[1], vecTargetVec );
		NormalizeVector ( vecTargetVec, vecTargetVec );

		flResultAngle = RadToDeg ( ArcCosine ( GetVectorDotProduct ( vecTargetVec, vecAngVec ) ) );

		if ( flResultAngle <= degree / 2 ) {
			if ( distance > 0 ) {
				if ( !height_check )
					flResultDistance = GetVectorDistance ( vecPos[0], vecPos[1] );

				if ( distance >= flResultDistance )
					return true;
				else
					return false;
			}
			else
				return true;
		}
		return false;
	}

	/**
	 * 클라이언트가 바라보고 있는 위치를 구합니다.
	 *
	 * @param end					Result client eye end position.
	 * @return		바라보는 시점이 있다면 true, 없으면 false를 반환합니다.
	 */
	public bool getEndPosition ( float end[3] ) {
		float flStart[3], flAngles[3];
		this.getEyePosition ( flStart );
		this.getEyeAngles ( flAngles );
		TR_TraceRayFilter ( flStart, flAngles, MASK_SOLID, RayType_Infinite, qufnrTools_TraceRayFilterIgnorePlayer, this.index );
		if ( TR_DidHit ( null ) ) {
			TR_GetEndPosition ( end, null );
			return true;
		}
		return false;
	}
};

/**
 * 클라이언트가 유효한지 유무를 반환합니다.
 *
 * @param client		Index of client.
 * @return 	클라이언트가 유효하면 true를 반환합니다.
 */
stock bool qufnrTools_IsValidClient ( int client ) {
	return ( client > 0 && client <= MaxClients &&
			IsClientInGame ( client ) &&
			!IsClientSourceTV ( client ) &&
			!IsClientReplay ( client ) );
}

/** 
 * Gets all players from in game
 * @return Player counts
 */
stock int qufnrTools_GetPlayers () {
	int nResult = 0;
	Player player = INVALID_PLAYER;
	int i = 1;
	FIND_ALL_PLAYERS ( i ) {
		if ( ( player = Player ( i ) ) != INVALID_PLAYER )
			nResult ++;
	}
	return nResult;
}

/** 
 * Gets all alive players in game
 * @return Alive player counts
 */
stock int qufnrTools_GetAlivePlayers () {
	int nResult = 0;
	Player player;
	int i = 1;
	FIND_ALL_PLAYERS ( i ) {
		player = Player ( i );
		if ( ( player = Player ( i ) ) != INVALID_PLAYER && player.isAlive () )
			nResult ++;
	}
	return nResult;
}

/**
 * Gets all dead players in game
 * @return Dead player counts
 */
stock int qufnrTools_GetDeadPlayers () {
	int nResult = 0;
	Player player;
	int i = 1;
	FIND_ALL_PLAYERS ( i ) {
		if ( ( player = Player ( i ) ) != INVALID_PLAYER && !player.isAlive () )
			nResult ++;
	}
	return nResult;
}

/**
 * Gets bot players in game
 *
 * @param ignoreSourceTV	true로 설정할 경우 카운팅에서 SourceTV는 제외됩니다.
 */
stock int qufnrTools_GetBots ( bool ignoreSourceTV = true ) {
	int nResult = 0;
	Player player;
	int i = 1;
	FIND_ALL_PLAYERS ( i ) {
		if ( ( player = Player ( i ) ) != INVALID_PLAYER && player.isFake () && ( ignoreSourceTV ? !player.isSourceTV () : true ) )
			nResult ++;
	}
	return nResult;
}

/**
 * Gets alive bot players in game
 */
stock int qufnrTools_GetAliveBots () {
	int nResult = 0;
	Player player;
	int i = 1;
	FIND_ALL_PLAYERS ( i ) {
		if ( ( player = Player ( i ) ) != INVALID_PLAYER && player.isFake () && player.isAlive () )
			nResult ++;
	}
	return nResult;
}

/**
 * Gets dead bot players in game
 *
 * @param ignoreSourceTV	true로 설정할 경우 카운팅에서 SourceTV는 제외됩니다.
 */
stock int qufnrTools_GetDeadBots ( bool ignoreSourceTV = true ) {
	int nResult = 0;
	Player player;
	int i = 1;
	FIND_ALL_PLAYERS ( i ) {
		if ( ( player = Player ( i ) ) != INVALID_PLAYER && player.isFake () && ( ignoreSourceTV ? !player.isSourceTV () : true ) && !player.isAlive () )
			nResult ++;
	}
	return nResult;
}

/**
 * Gets team players
 */
stock int qufnrTools_GetTeamPlayers ( int team ) {
	int nResult = 0;
	Player player;
	int i = 1;
	FIND_ALL_PLAYERS ( i ) {
		if ( ( player = Player ( i ) ) != INVALID_PLAYER && player.team == team )
			nResult ++;
	}
	return nResult;
}

/**
 * Gets team players (Extended parameters)
 * @param team		Filter team index
 * @param onlyPlayer	Checking player only (ignore fake clients)
 * @param onltAlive		Checking alive player only (ignore dead players)
 */
stock int qufnrTools_GetTeamPlayersEx ( int team, bool onlyPlayer = false, bool onlyAlive = false ) {
	int nResult = 0;
	Player player;
	int i = 1;
	FIND_ALL_PLAYERS ( i ) {
		if ( ( player = Player ( i ) ) != INVALID_PLAYER && player.team == team && ( onlyPlayer ? !player.isFake () : true ) && ( onlyAlive ? player.isAlive () : true ) )
			nResult ++;
	}
	return nResult;
}

/** 
 * 무작위로 플레이어중 한명을 선택합니다.
 * @random		
 */
stock int qufnrTools_GetRandomPlayerIndex ( bool onlyAlive = false, int team = -1 ) {
	static int iClients[MAXPLAYERS + 1] = { -1, ... };
	static int nCounts;
	nCounts = 0;
	int i = 1;
	FIND_ALL_PLAYERS ( i ) {
		if ( i <= MaxClients && IsClientInGame ( i ) ) {
			if ( onlyAlive ? ( IsPlayerAlive ( i ) ) : true &&
				team != -1 ? ( GetClientTeam ( i ) == team ) : true ) {
				iClients[nCounts] = i;
				nCounts ++;
			}
		}
	}

	if ( nCounts > 0 )
		return iClients[GetRandomInt ( 1, nCounts ) - 1];
	
	return iClients[0];
}

/**
 * center에서 가장 가까운 플레이어 인덱스를 반환합니다.
 */
stock int qufnrTools_GetClosestPlayer ( float center[3], int ignoreEntity = -1, int onlyTeam = -1 ) {
	static float vOrigin[3];
	static float flDistance[2] = { 0.0, 0.0 };
	static int iClosestEntity = -1;

	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( IsClientInGame ( i ) &&
			GetEntSendPropOffs ( i, "m_vecOrigin" ) != -1 &&
			( ignoreEntity != -1 ? i != ignoreEntity : true ) &&
			( onlyTeam != -1 ? GetClientTeam ( i ) == onlyTeam : true ) ) {
			GetEntPropVector ( i, Prop_Send, "m_vecOrigin", vOrigin );
			flDistance[0] = GetVectorDistance ( center, vOrigin, true );
			if ( flDistance[0] < flDistance[1] || flDistance[1] == 0.0 ) {
				flDistance[1] = flDistance[0];
				iClosestEntity = i;
			}
		}
	}

	return iClosestEntity;
}

/**
 * 플레이어 이름이 일치한지 유무를 반환합니다.
 *
 * @param client
 * @param name
 * @param caseSensitive
 * @param partialMatch
 * @return	해당 조건으로 이름이 일치하면 true를 반환합니다.
 */
stock bool qufnrTools_IsClientNameMatches ( int client, const char[] name, bool caseSensitive = true, bool partialMatch = false ) {
	static char sName[32];
	GetClientName ( client, sName, sizeof sName );
	return ( partialMatch ? StrContains ( sName, name, caseSensitive ) != -1 : StrEqual ( sName, name, caseSensitive ) )
}