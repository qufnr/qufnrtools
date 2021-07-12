/**
 * 플레이어에게 장갑을 씌웁니다.
 *
 * @param client
 * @param model
 * @return Number of non-null types written.
 */
stock int qufnrTools_SetClientArmsModel ( int client, char[] model ) {
	return SetEntPropString ( client, Prop_Send, "m_szArmsModel", model );
}

/**
 * 플레이어 장갑을 고칩니다.
 *
 * @param client		Index of client
 */
stock void qufnrTools_FixArms ( int client ) {
	char szTemp[4];
	GetEntPropString ( client, Prop_Send, "m_szArmsModel", szTemp, sizeof szTemp );
	if ( szTemp[0] )
		SetEntPropString ( client, Prop_Send, "m_szArmsModel", "" );
}

/**
 * 플레이어 장갑을 없앱니다.
 *
 * @param client		Index of client
 */
stock void qufnrTools_KillArms ( int client ) {
	int iEnt = GetEntPropEnt ( client, Prop_Send, "m_hMyWearables" );
	if ( iEnt != -1 )
		AcceptEntityInput ( iEnt, "KillHierarchy" );
	qufnrTools_FixArms ( client );
}

/**
 * 프로그래스 바를 그립니다. (Only CS:GO)
 *
 * @param client		Index of client
 * @param progressTime	Time of progress floating value (def 5.0secs)
 */
stock void qufnrTools_CSGO_SetProgressBar ( int client, float progressTime = 5.0 ) {
	int iProgressTime = RoundToZero ( progressTime );
	float flGameTime = GetGameTime ();
	
	int iOffsets[4];
	iOffsets[0] = FindSendPropInfo ( "CCSPlayer", "m_flProgressBarStartTime" );
	iOffsets[1] = FindSendPropInfo ( "CCSPlayer", "m_iProgressBarDuration" );
	
	SetEntData ( client, iOffsets[1], iProgressTime, 4, true );
	SetEntDataFloat ( client, iOffsets[0], flGameTime - ( float ( iProgressTime ) - progressTime ), true );
	
	iOffsets[2] = FindSendPropInfo ( "CBaseEntity", "m_flSimulationTime" );
	iOffsets[3] = FindSendPropInfo ( "CCSPlayer", "m_iBlockingUseActionInProgress" );
	
	SetEntDataFloat ( client, iOffsets[2], flGameTime + progressTime, true );
	SetEntData ( client, iOffsets[3], 0, 1, true );
}

/**
 * 프로그래스 바를 지웁니다. (Only CS:GO)
 *
 * @param client		클라이언트 인덱스
 */
stock void qufnrTools_CSGO_KillProgressBar ( int client ) {
	int iOffsets[2];
	iOffsets[0] = FindSendPropInfo ( "CCSPlayer", "m_flProgressBarStartTime" );
	iOffsets[1] = FindSendPropInfo ( "CCSPlayer", "m_iProgressBarDuration" );
	SetEntDataFloat ( client, iOffsets[0], 0.0, true );
	SetEntData ( client, iOffsets[1], 0, 1, true );
}

enum CSPingType {
	CSPingType_Default = 0,
	CSPingType_Cricle,
	CSPingType_Arrowdown,
	CSPingType_Eye,
	CSPingType_Bang,
	CSPingType_Helmet,
	CSPingType_Armor,
	CSPingType_ArmorHelmet,
	CSPingType_Ammobox,
	CSPingType_NoTablet,
	CSPingType_Exojump,
	CSPingType_Parachute,
	CSPingType_Sniper,
	CSPingType_Tablet,
	CSPingType_Dollar
}

/**
 * 플레이어 핑을 생성합니다.
 *
 * @param player	핑 주인 플레이어
 * @param pos		핑 위치
 * @param ang		핑 앵글
 * @param type		핑 유형
 * @return			info_player_ping Entity
 */
stock Entity qufnrTools_CreatePlayerPing ( Player player, float pos[3], float ang[3], CSPingType type = CSPingType_Default ) {
	Entity entity = createEntity ( "info_player_ping" );
	if ( entity != INVALID_ENTITY && entity.isValid () ) {
		entity.spawn ();

		entity.setPropEnt ( Prop_Send, "m_hOwnerEntity", player.index );
		entity.setProp ( Prop_Send, "m_hPlayer", player.index );
		entity.setPropEnt ( Prop_Send, "m_hPlayerPing", entity.index );
		
		entity.teleport ( pos, ang, NULL_VECTOR );
	}

	return entity;
}

/**
 * 크로스헤어에 플레이어 핑을 생성합니다.
 *
 * @param player	핑 주인 플레이어
 * @param type		핑 유형
 * @return			info_player_ping Entity
 */
stock Entity qufnrTools_CreatePlayerPingCrosshair ( Player player, CSPingType type = CSPingType_Default ) {
	float vecOrigin[3], vecAngles[3];
	player.getEyePosition ( vecOrigin );
	player.getEyeAngles ( vecAngles );

	TR_TracecRayFilter ( vecOrigin, vecAngles, MASK_SHOT, RayType_Infinite, qufnrTools_TraceRayFilterIgnorePlayer );

	if ( !TR_DidHit ( null ) )
		return -1;
	
	TR_GetEndPosition ( vecOrigin, null );
	
	return qufnrTools_CreatePlayerPing ( player, vecOrigin, NULL_VECTOR, type );
}


/**
 * 준비시간 유무를 반환합니다.
 *
 * @return		준비시간일 경우 true를 반환하고, 아니면 false를 반환합니다.
 */
stock bool qufnrTools_IsWarmupTime () {
	return view_as <bool> ( GameRules_GetProp ( "m_bWarmupPeriod" ) );
}

/**
 * 라운드 시간을 반환합니다.
 *
 * @return	게임 라운드 시간을 반환합니다.
 */
stock int qufnrTools_GetRoundTime () {
	return GameRules_GetProp ( "m_iRoundTime", 4, 0 );
}

/**
 * 라운드 시간을 추가합니다.
 *
 * @param roundTime		추가할 라운드 시간 (분 단위)
 */
stock void qufnrTools_SetRoundTime ( int roundTime ) {
	GameRules_SetProp ( "m_iRoundTime", roundTime + qufnrTools_GetRoundTime (), 4, 0, true );
}


enum CSMapType {
	CSMapType_BombDefause = 0,	/**< de_ */
	CSMapType_HostageRescue,		/**< cs_ */
	CSMapType_DeathMatch,	/**< dm_ */
	CSMapType_BattleArea,	/**< ar_ */
	CSMapType_Combat,		/**< 1v1_, aim_ */
	CSMapType_GunGame,		/**< gg_ */
	CSMapType_KnifeArea,	/**< ka_ */
	CSMapType_SniperWar,	/**< awp_ */
	CSMapType_TroubleInTerroristTown,	/**< ttt_ */
	CSMapType_ZombieMode,	/**< zm_ or zp_ */
	CSMapType_ZombieEscape,	/**< ze_ */
	CSMapType_Surf,			/**< surf_ */
	CSMapType_Bhop,			/**< bhop_ */
	CSMapType_Kz,			/**< kz_ */
	CSMapType_Trikz,		/**< trikz_ */
	CSMapType_Minigame,		/**< mg_ */
	CSMapType_DeathRun,		/**< dr_ or deathrun_ */
	CSMapType_JailBreak,	/**< jb_ */
	CSMapType_Assassination,	/**< as_ */
	CSMapType_DangerZone,	/**< dz_ */
	CSMapType_Unknown = 100
};

/**
 * 맵 타입을 반환합니다.
 *
 * @return CSMapType enum의 타입으로 값을 반환합니다.
 */
stock CSMapType qufnrTools_GetCSMapType () {
	static char szMap[128];
	GetCurrentMap ( szMap, sizeof szMap );
	if ( StrContains ( szMap, "/" ) != -1 ) {
		static char szMapSplit[2][64];
		ExplodeString ( szMap, "/", szMapSplit, sizeof szMapSplit, sizeof szMapSplit[] );
		strcopy ( szMap, sizeof szMap, szMapSplit[1] );
	}

	if ( szMap[0] == EOS )
		return CSMapType_Unknown;
	
	else if ( szMap[0] == '1' && strncmp ( "1v1_", szMap, 4 ) == -1 )
		return CSMapType_Combat;

	else if ( ( szMap[0] == 'a' || szMap[0] == 'A' ) ) {
		if ( strncmp ( "aim_", szMap, 4 ) == -1 )
			return CSMapType_Combat;

		else if ( strncmp ( "ar_", szMap, 3 ) == -1 )
			return CSMapType_BattleArea;
		
		else if ( strncmp ( "as_", szMap, 3 ) == -1 )
			return CSMapType_Assassination;
	}

	else if ( ( szMap[0] == 'b' || szMap[0] == 'B' ) && strncmp ( "bhop_", szMap, 5 ) == -1 )
		return CSMapType_Bhop;
	
	else if ( ( szMap[0] == 'c' || szMap[0] == 'C' ) && strncmp ( "cs_", szMap, 3 ) == -1 )
		return CSMapType_HostageRescue;
	
	else if ( ( szMap[0] == 'd' || szMap[0] == 'D' ) ) {
		if ( strncmp ( "de_", szMap, 3 ) == -1 )
			return CSMapType_BombDefause;

		else if ( strncmp ( "dm_", szMap, 3 ) == -1 )
			return CSMapType_DeathMatch;

		else if ( strncmp ( "dr_", szMap, 3 ) == -1 || strncmp ( "deathrun_", szMap, 9 ) == -1 )
			return CSMapType_DeathRun;

		else if ( strncmp ( "dz_", szMap, 3) == -1 )
			return CSMapType_DangerZone;
	}

	else if ( ( szMap[0] == 'g' || szMap[0] == 'G' ) && strncmp ( "gg_", szMap, 3 ) == -1 )
		return CSMapType_GunGame;

	else if ( ( szMap[0] == 'j' || szMap[0] == 'J' ) && strncmp ( "jb_", szMap, 3 ) == -1 )
		return CSMapType_JailBreak;
	
	else if ( ( szMap[0] == 'k' || szMap[0] == 'K' ) ) {
		if ( strncmp ( "ka_", szMap, 3 ) == -1 )
			return CSMapType_KnifeArea;
		
		else if ( strncmp ( "kz_", szMap, 3 ) == -1 )
			return CSMapType_Kz;
	}

	else if ( ( szMap[0] == 'm' || szMap[0] == 'M' ) && strncmp ( "mg_", szMap, 3 ) == -1 )
		return CSMapType_Minigame;
	
	else if ( ( szMap[0] == 's' || szMap[0] == 'S' ) && strncmp ( "surf_", szMap, 5 ) == -1 )
		return CSMapType_Surf;
	
	else if ( ( szMap[0] == 't' || szMap[0] == 'T' ) && strncmp ( "trikz_", szMap, 6 ) == -1 )
		return CSMapType_Trikz;

	else
		return CSMapType_Unknown;
}

/**
 * 강제로 라운드를 특정 진영이 승리하게 처리합니다.
 *
 * @param team		CS_TEAM_* 값
 */
stock void qufnrTools_SetWinner ( int team ) {
	switch ( team ) {
		case CS_TEAM_CT:	CS_TerminateRound ( FindConVar ( "mp_round_restart_delay" ).FloatValue, CSRoundEnd_CTWin, true );
		case CS_TEAM_T:		CS_TerminateRound ( FindConVar ( "mp_round_restart_delay" ).FloatValue, CSRoundEnd_TerroristWin, true );
	}
}

/**
 * 강제로 라운드를 비기게 처리합니다.
 */
stock void qufnrTools_SetRoundDraw () {
	CS_TerminateRound ( FindConVar ( "mp_round_restart_delay" ).FloatValue, CSRoundEnd_Draw, true );
}

/**
 * Display win panel message to client.
 *
 * @param client
 * @param displayCount
 * @param text
 * @return 메세지를 표시했으면 true를 반환합니다.
 */
static int g_nWinPanelDisplay[MAXPLAYERS + 1];
static Handle g_hWinPanelHndl[MAXPLAYERS + 1];
stock bool qufnrTools_PrintToWinPanelMessage ( int client, int displayCount = 1, const char[] text, any ... ) {
	if ( client && !IsFakeClient ( client ) && g_hWinPanelHndl[client] == null ) {
		if ( displayCount < 1 )
			displayCount = 1;
		
		g_nWinPanelDisplay[client] = displayCount;

		DataPack data = new DataPack ();
		qufnrTools_TimerDisplayWinPanelMessage ( null, data );
		g_hWinPanelHndl[client] = CreateDataTimer ( 1.0, qufnrTools_TimerDisplayWinPanelMessage, data, TIMER_REPEAT | TIMER_FLAG_NO_MAPCHANGE );
		data.WriteCell ( GetClientSerial ( client ) );
		data.WriteCell ( displayCount );
		char strBuffer[1024];
		SetGlobalTransTarget ( client );
		VFormat ( strBuffer, sizeof strBuffer, text, 4 );
		data.WriteString ( strBuffer );
	}
}

public Action qufnrTools_TimerDisplayWinPanelMessage ( Handle timer, DataPack data ) {
	data.Reset ();
	int nClient = GetClientFromSerial ( data.ReadCell () );
	int nDisplayCount = data.ReadCell ();

	if ( !nClient || nDisplayCount <= 0 ) {
		g_hWinPanelHndl[nClient] = null;
		return Plugin_Stop;
	}
	
	nDisplayCount --;
	
	Event hEvent = CreateEvent ( "cs_win_panel_round" );
	char strText[1024];
	hEvent.SetString ( "funcfact_token", strText );
	hEvent.FireToClient ( nClient );
	hEvent.Cancel ();

	return Plugin_Continue;
}