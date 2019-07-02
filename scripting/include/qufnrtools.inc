#if	defined	_qufnrtools_included
	#endinput
#endif
#define	_qufnrtools_included

#include <loringlib>
#include "include/qufnrTools/player.inc"
#include "include/qufnrTools/menu.inc"

/**
 * @section	색상에 사용되는 값
 */
#define	MAX_CSGO_CHAT_COLORS	16
static char g_strCSGOColors[MAX_CSGO_CHAT_COLORS][2][32] = {
	{ "{default}", "\x01" }
	, { "{dark_red}", "\x02" }
	, { "{team}", "\x03" }
	, { "{green}", "\x04" }
	, { "{white_green}", "\x05" }
	, { "{lime}", "\x06" }
	, { "{red}", "\x07" }
	, { "{gray}", "\x08" }
	, { "{yellow}", "\x09" }
	, { "{sky_blue}", "\x0A" }
	, { "{dark_sky_blue}", "\x0B" }
	, { "{blue}", "\x0C" }
	, { "{sky_blue2}", "\x0D" }
	, { "{purple}", "\x0E" }
	, { "{white_red}", "\x0F" }
	, { "{orange}", "\x10" }
};

static char g_strEscapeSequence[4][2][32] = {
	{ "{newline}", "\n" }
	, { "{block}", "\t" }	//	Only Radio Menu Panel
	, { "{back}", "\b" }
	, { "{return}", "\r" }
};

/**
 * 색깔을 포멧합니다.
 *
 * @param format
 * @param maxlen
 */
stock bool qufnrTools_FormatColor ( char[] format, int maxlen ) {
	if ( GetEngineVersion () != Engine_CSGO ) {
		LogError ( "'qufnrTools_FormatColor()' Function is not supported on this engine." );
		return false;
	}	
	
	int total = 0;
	char buffer[512];
	strcopy ( buffer, sizeof ( buffer ), format );
	
	for ( int i = 0; i < MAX_CSGO_CHAT_COLORS; i ++ )
		total += ReplaceString ( buffer, sizeof ( buffer ), g_strCSGOColors[i][0], g_strCSGOColors[i][1] );
	
	if ( total < 1 )
		return false;
	
	strcopy ( format, maxlen, buffer );
	return true;
}

/**
 * 줄 바꿈을 포멧합니다.
 *
 * @param format
 * @param maxlen
 */
stock bool qufnrTools_FormatEscapeSequence ( char[] format, int maxlen ) {
	if ( GetEngineVersion () != Engine_CSGO ) {
		LogError ( "'qufnrTools_FormatEscapeSequence()' Function is not supported on this engine." );
		return false;
	}	
	
	int total = 0;
	char buffer[512];
	strcopy ( buffer, sizeof ( buffer ), format );
	
	for ( int i = 0; i < sizeof ( g_strEscapeSequence ); i ++ )
		total += ReplaceString ( buffer, sizeof ( buffer ), g_strEscapeSequence[i][0], g_strEscapeSequence[i][1] );
	
	if ( total < 1 )
		return false;
	
	strcopy ( format, maxlen, buffer );
	return true;
}

/**
 * ReplyToCommandEx
 *
 * @param client		클라이언트 값
 * @param format		포멧
 * @param ...			Parameters
 * @noreturn
 */
stock void qufnrTools_ReplyToCommand ( int client, const char[] format, any ... ) {
	if ( GetEngineVersion () != Engine_CSGO ) {
		LogError ( "'qufnrTools_ReplyToCommand()' Function is not supported on this engine." );
		return;
	}	
	
	char buffer[254];
	
	SetGlobalTransTarget ( client );
	VFormat ( buffer, sizeof ( buffer ), format, 3 );
	
	for ( int i = 0; i < MAX_CSGO_CHAT_COLORS; i ++ )
		ReplaceString ( buffer, PLATFORM_MAX_PATH, g_strCSGOColors[i][0], g_strCSGOColors[i][1] );
	
	for ( int x = 0; x < sizeof ( g_strEscapeSequence ); x ++ )
		ReplaceString ( buffer, PLATFORM_MAX_PATH, g_strEscapeSequence[x][0], g_strEscapeSequence[x][1] );
	
	if ( client == 0 )
		PrintToServer ( "%s", buffer );
	
	ReplyToCommand ( client, "%s", buffer );
}

/**
 * 클라이언트에게 채팅을 보냅니다.
 *
 * @param client		클라이언트 값
 * @param format		내용
 * @param ...			포멧 파라메터 값
 * @noreturn
 */
stock void qufnrTools_PrintToChat ( int client, const char[] format, any ... ) {
	if ( GetEngineVersion () != Engine_CSGO ) {
		LogError ( "'qufnrTools_PrintToChat()' Function is not supported on this engine." );
		return;
	}	
	
	char buffer[254];
	
	SetGlobalTransTarget ( client );
	VFormat ( buffer, sizeof ( buffer ), format, 3 );
	
	for ( int i = 0; i < MAX_CSGO_CHAT_COLORS; i ++ )
		ReplaceString ( buffer, PLATFORM_MAX_PATH, g_strCSGOColors[i][0], g_strCSGOColors[i][1] );
	
	for ( int x = 0; x < sizeof ( g_strEscapeSequence ); x ++ )
		ReplaceString ( buffer, PLATFORM_MAX_PATH, g_strEscapeSequence[x][0], g_strEscapeSequence[x][1] );
	
	PrintToChat ( client, "%s", buffer );
}

/**
 * 전체에게 메세지를 보냅니다.
 * @param format		내용
 * @param ...			포멧 파라메터 값
 * @noreturn
 */
stock void qufnrTools_PrintToChatAll ( const char[] format, any ... ) {
	if ( GetEngineVersion () != Engine_CSGO ) {
		LogError ( "'qufnrTools_PrintToChatAll()' Function is not supported on this engine." );
		return;
	}

	char buffer[254];
	
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( loringlib_IsValidClient ( i ) && !IsFakeClient ( i ) ) {
			SetGlobalTransTarget ( i );
			VFormat ( buffer, sizeof ( buffer ), format, 2 );
			qufnrTools_PrintToChat ( i, "%s", buffer );
		}
	}
}

/**
 * 클라이언트에게 hinttext를 보냅니다.
 * @param format		내용
 * @param ...			포멧 파라메터 값
 * @noreturn
 */
stock void qufnrTools_PrintHintText ( int client, const char[] format, any ... ) {
	if ( GetEngineVersion () != Engine_CSGO ) {
		LogError ( "'qufnrTools_PrintHintText()' Function is not supported on this engine." );
		return;
	}
	
	char buffer[254];
	
	SetGlobalTransTarget ( client );
	VFormat ( buffer, sizeof ( buffer ), format, 3 );
	
	for ( int i = 0; i < MAX_CSGO_CHAT_COLORS; i ++ )
		ReplaceString ( buffer, PLATFORM_MAX_PATH, g_strCSGOColors[i][0], g_strCSGOColors[i][1] );
	
	for ( int x = 0; x < sizeof ( g_strEscapeSequence ); x ++ )
		ReplaceString ( buffer, PLATFORM_MAX_PATH, g_strEscapeSequence[x][0], g_strEscapeSequence[x][1] );
	
	PrintHintText ( client, "%s", buffer );
}

/**
 * 전체에게 hinttext를 보냅니다.
 * @param format		내용
 * @param ...			포멧 파라메터 값
 * @noreturn
 */
stock bool qufnrTools_PrintHintTextAll ( const char[] format, any ... ) {
	if ( GetEngineVersion () != Engine_CSGO ) {
		LogError ( "'qufnrTools_PrintHintTextAll()' Function is not supported on this engine." );
		return;
	}

	char buffer[254];
	
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( loringlib_IsValidClient ( i ) && !IsFakeClient ( i ) ) {
			SetGlobalTransTarget ( i );
			VFormat ( buffer, sizeof ( buffer ), format, 2 );
			qufnrTools_PrintHintText ( i, "%s", buffer );
		}
	}
}

/**
 * 클라이언트에게 centertext를 보냅니다.
 * @param format		내용
 * @param ...			포멧 파라메터 값
 * @noreturn
 */
stock void qufnrTools_PrintCenterText ( int client, const char[] format, any ... ) {
	if ( GetEngineVersion () != Engine_CSGO ) {
		LogError ( "'qufnrTools_PrintCenterText()' Function is not supported on this engine." );
		return;
	}
	
	char buffer[254];
	
	SetGlobalTransTarget ( client );
	VFormat ( buffer, sizeof ( buffer ), format, 3 );
	
	for ( int i = 0; i < MAX_CSGO_CHAT_COLORS; i ++ )
		ReplaceString ( buffer, PLATFORM_MAX_PATH, g_strCSGOColors[i][0], g_strCSGOColors[i][1] );
	
	for ( int x = 0; x < sizeof ( g_strEscapeSequence ); x ++ )
		ReplaceString ( buffer, PLATFORM_MAX_PATH, g_strEscapeSequence[x][0], g_strEscapeSequence[x][1] );
	
	PrintCenterText ( client, "%s", buffer );
}

/**
 * 전체에게 centertext를 보냅니다.
 * @param format		내용
 * @param ...			포멧 파라메터 값
 * @noreturn
 */
stock bool qufnrTools_PrintCenterTextAll ( const char[] format, any ... ) {
	if ( GetEngineVersion () != Engine_CSGO ) {
		LogError ( "'qufnrTools_PrintCenterTextAll()' Function is not supported on this engine." );
		return;
	}

	char buffer[254];
	
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( loringlib_IsValidClient ( i ) && !IsFakeClient ( i ) ) {
			SetGlobalTransTarget ( i );
			VFormat ( buffer, sizeof ( buffer ), format, 2 );
			qufnrTools_PrintCenterText ( i, "%s", buffer );
		}
	}
}

/**
 * 서버 관리자에게 PrintToChat을 보냅니다.
 * @param format		내용
 * @param ...			포멧 파라메터 값
 * @return		관리자에게 메세지를 보냈다면 true를 반환합니다.
 */
stock bool qufnrTools_PrintToChatAdmin ( const char[] format, any ... ) {
	char buffer[254];
	bool result = false;
	
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( loringlib_IsValidClient ( i ) && loringlib_IsClientAdmin ( i ) && !IsFakeClient ( i ) ) {
			SetGlobalTransTarget ( i );
			VFormat ( buffer, sizeof buffer, format, 2 );
			qufnrTools_PrintToChat ( i, "%s", buffer );
			
			if ( !result )
				result = true;
		}
	}
	
	return result;
}

/**
 * 서버 관리자에게 PrintToConsole을 보냅니다.
 * @param format		내용
 * @param ...			포멧 파라메터 값
 * @return		관리자에게 메세지를 보냈다면 true를 반환합니다.
 */
stock bool qufnrTools_PrintToConsoleAdmin ( const char[] format, any ... ) {
	char buffer[254];
	bool result = false;
	
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( loringlib_IsValidClient ( i ) && loringlib_IsClientAdmin ( i ) && !IsFakeClient ( i ) ) {
			SetGlobalTransTarget ( i );
			VFormat ( buffer, sizeof buffer, format, 2 );
			PrintToConsole ( i, "%s", buffer );
			
			if ( !result )
				result = true;
		}
	}
	
	return result;
}

/**
 * @section	진행 상태 표시 함수에 사용되는 값들
 */
#define		PROGRESS_BAR_BLOCK		"██"	/**< 채워진 칸 */
#define		PROGRESS_BAR_BLANK		" "	/**< 빈 칸 */
#define		PROGRESS_BAR_LENGTH		10		/**< 칸 갯수 */
#define		PROGRESS_BAR_TICKS		0.1		/**< Progress Bar가 몇 틱마다 실행할지? */
static float g_fClientProgressValue[MAXPLAYERS + 1] = { 0.0, ... };
static float g_fClientProgressTotalValue[MAXPLAYERS + 1] = { 0.0, ... };
static Handle g_hClientProgressBarHandler[MAXPLAYERS + 1] = { null, ... };
static char g_strProgressBarColors[][] = {	/**< Progress Bar 색상 */
	"#CC3D3D"		//	0
	, "#F06161"
	, "#E0844F"
	, "#F29661"
	, "#CCA63D"
	, "#DEB84F"
	, "#C4B73B"
	, "#D6C94D"
	, "#8DB72A"
	, "#7BA518"
	, "#699306"
};

/**
 * 진행 상태(Progress Bar)를 표시합니다.
 * @note	CS:GO에서만 작동합니다. 다른 엔진에서는 표시가 안되거나, 이상이 있을 수 있습니다.
 *
 * @param client		표시할 상대 클라이언트 값
 * @param total_values	전체 값
 * @noreturn
 */
stock void qufnrTools_DisplayProgressBar ( int client, float total_values ) {
	if ( GetEngineVersion () != Engine_CSGO )
		LogMessage ( "'qufnrTools_DisplayProgressBar()' Function is may have some problems on this engine." );
	
	if ( total_values <= 0.0 )
		return;
	
	if ( !loringlib_IsValidClient ( client ) )
		return;
		
	if ( IsFakeClient ( client ) )
		return;
	
	if ( g_hClientProgressBarHandler[client] == null ) {
		g_fClientProgressValue[client] = 0.0;
		g_fClientProgressTotalValue[client] = total_values;
		g_hClientProgressBarHandler[client] = CreateTimer ( PROGRESS_BAR_TICKS, qufnrTools_DisplayProgressBarTimer, client, TIMER_REPEAT );
	}
	
	else {
		KillTimer ( g_hClientProgressBarHandler[client] );
		g_hClientProgressBarHandler[client] = null;
		
		g_fClientProgressValue[client] = 0.0;
		g_fClientProgressTotalValue[client] = total_values;
		g_hClientProgressBarHandler[client] = CreateTimer ( PROGRESS_BAR_TICKS, qufnrTools_DisplayProgressBarTimer, client, TIMER_REPEAT );
	}
}

public Action qufnrTools_DisplayProgressBarTimer ( Handle timer, any client ) {
	if ( !loringlib_IsValidClient ( client ) ) {
		g_hClientProgressBarHandler[client] = null;
		return Plugin_Stop;
	}
		
	if ( IsFakeClient ( client ) ) {
		g_hClientProgressBarHandler[client] = null;
		return Plugin_Stop;
	}
	
	static char progress[64];
	if ( !qufnrTools_DisplayProgressBarCalcul ( g_fClientProgressValue[client], g_fClientProgressTotalValue[client], progress, sizeof ( progress ) ) ) {
		int blocks = qufnrTools_GetProgressBarBlocks ( g_fClientProgressValue[client], g_fClientProgressTotalValue[client] );
		g_fClientProgressValue[client] += 0.1;
		PrintCenterText ( client, "[TIME: %.1f / %.1f] <font color='%s'>%s</font>", g_fClientProgressValue[client], g_fClientProgressTotalValue[client], g_strProgressBarColors[blocks], progress );
	}
	
	else {
		PrintCenterText ( client, "<font color='#ff0000'>！！！</font><font class='fontSize-l'> TIME OVER </font><font color='#ff0000'>！！！</font>" );
		g_fClientProgressValue[client] = 0.0;
		g_fClientProgressTotalValue[client] = 0.0;
		g_hClientProgressBarHandler[client] = null;
		return Plugin_Stop;
	}
	
	return Plugin_Continue;
}

/**
 * 진행 상태(Progress Bar) 표시를 계산합니다.
 *
 * @param values		현재 값
 * @param total_values	전체 값
 * @param buffer		상태 표시 문자열 포멧
 * @param maxlen		포멧 길이
 * @return	최대 값(100%)에 도달 했다면 true, 아니면 false를 반환합니다.
 */
stock bool qufnrTools_DisplayProgressBarCalcul ( float values, float total_values, char[] buffer, int maxlen ) {
	char format[64];
	Format ( format, sizeof ( format ), "" );
	
	float ticks = float ( 100 / PROGRESS_BAR_LENGTH );	//	퍼센트 마다 블록 추가
	
	int blocks;		//	블록 갯수
	float percent;	//	퍼센트
	
	percent = values / total_values * 100.0;	//	퍼센트 계산
	blocks = RoundFloat ( percent / ticks );	//	갯수 계산
	
//	PrintToServer ( "Blocks: %d, Percent: %.2f", blocks, percent );
	
	for ( int i = 0; i < PROGRESS_BAR_LENGTH; i ++ ) {
		if ( blocks > i )
			Format ( format, sizeof ( format ), "%s%s", format, PROGRESS_BAR_BLOCK );
		else
			Format ( format, sizeof ( format ), "%s%s", format, PROGRESS_BAR_BLANK );
	}
	
	Format ( buffer, maxlen, "%s", format );
	
	if ( values <= total_values )
		return false;
	
	return true;
}

/**
 * 진행 상태(Progress Bar)에서 블록 갯수를 구합니다.
 *
 * @param values		현재 값
 * @param total_values	전체 값
 * @return	블록 갯수
 */
stock int qufnrTools_GetProgressBarBlocks ( float values, float total_values ) {
	float ticks = float ( 100 / PROGRESS_BAR_LENGTH );
	int blocks;
	float percent;
	percent = values / total_values * 100.0;
	blocks = RoundFloat ( percent / ticks );
	
	return blocks;
}

#define MAX_HUD_COLORS		12
static int g_iCSGOHudColors[MAX_HUD_COLORS][4] = {
	{ 255, 255, 255, 255 }
	, { 255, 255, 255, 255 }
	, { 150, 200, 255, 255 }
	, { 53, 110, 255, 255 }
	, { 200, 100, 255, 255 }
	, { 255, 41, 36, 255 }
	, { 255, 113, 36, 255 }
	, { 255, 247, 36, 255 }
	, { 62, 255, 36, 255 }
	, { 36, 255, 144, 255 }
	, { 255, 121, 153, 255 }
	, { 213, 226, 134, 255 }
};

static int g_iClientCSGOHudClr[MAXPLAYERS + 1];

/**
 * 진행 상태(Progress Bar)의 색깔을 구합니다.
 *
 * @param values		현재 값
 * @param total_values	전체 값
 * @param format
 * @param format_size
 */
stock void qufnrTools_GetProgressBarColor ( float values, float total_values, char[] format, int format_size ) {
	int colornum = qufnrTools_GetProgressBarBlocks ( values, total_values );
	if ( colornum < 0 )
		colornum = 0;
	if ( colornum > PROGRESS_BAR_LENGTH )
		colornum = PROGRESS_BAR_LENGTH;
	Format ( format, format_size, "%s", g_strProgressBarColors[colornum] );
}

public void qufnrTools_GetClientHudColor ( QueryCookie cookie, int client, ConVarQueryResult result, const char[] name, const char[] value ) {
	if ( StringToInt ( value ) < 0 || StringToInt ( value ) > 11 )
		g_iClientCSGOHudClr[client] = 0;
	else
		g_iClientCSGOHudClr[client] = StringToInt ( value );
}

/**
 * CS:GO의 허드 색상을 구합니다.
 *
 * @param client		Client index.
 */
stock int qufnrTools_GetCSGOHudColor ( int client, int clr[4] ) {
	QueryClientConVar ( client, "cl_hud_color", qufnrTools_GetClientHudColor );
	for ( int i = 0; i < 4; i ++ )
		clr[i] = g_iCSGOHudColors[g_iClientCSGOHudClr[client]][i];
	
	return g_iClientCSGOHudClr[client];
}

static bool g_bClientGameInstructorEnable[MAXPLAYERS + 1];

/**
 * gameinstructor_enable 콘바를 사용하고 있는지 채크합니다.
 *
 * @param client			Client index.
 * @return 사용하고 있을 경우 true, 사용하지 않는다면 false를 반환합니다.
 */
stock bool qufnrTools_IsClientGameInstructorEnable ( int client ) {
	QueryClientConVar ( client, "gameinstructor_enable", qufnrTools_GetGameInstructorEnable );
	return g_bClientGameInstructorEnable[client];
}

public void qufnrTools_GetGameInstructorEnable ( QueryCookie cookie, int client, ConVarQueryResult result, const char[] name, const char[] value ) {
	if ( StringToInt ( value ) >= 1 )	g_bClientGameInstructorEnable[client] = true;
	else	g_bClientGameInstructorEnable[client] = false;
}

/**
 * CS:GO 프로그래스바를 출력합니다.
 *
 * @param client		Client index.
 * @param time			Display time.
 * @return	출력 했을 경우 true를 반환합니다.
 */
stock bool qufnrTools_DisplayProgressBarTime ( int client, int time = 10 ) {
	Handle hGameConf = LoadGameConfigFile ( "qufnrtools.games" );
	
	if ( hGameConf == null ) {
		LogError ( "Game config was not loaded right." );
		return false;
	}
	
	Handle hSetProgressBarTime = null;
	
	StartPrepSDKCall ( SDKCall_Player );
	PrepSDKCall_SetFromConf ( hGameConf, SDKConf_Signature, "CCSPlayer::SetProgressBarTime" );
	PrepSDKCall_AddParameter ( SDKType_PlainOldData, SDKPass_Plain );
	
	if ( !( hSetProgressBarTime = EndPrepSDKCall () ) ) {
		LogError ( "Failed to find \"CCSPlayer::SetProgressBarTime\"." );
		return false;
	}
	
	delete hGameConf;
	
	SDKCall ( hSetProgressBarTime, client, time );
	return true;
}

/**
 * CS:GO 프로그래스바를 숨깁니다.
 *
 * @param client		Client index.
 * @return 숨겼을 경우 true를 반환합니다.
 */
stock bool qufnrTools_KillProgressBarTime ( int client ) {
	return qufnrTools_DisplayProgressBarTime ( client, 0 );
}

static char WEAPON_NAME_ARRAY[54][2][64] = {
	{ "weapon_glock", "Glock-18" }
	, { "weapon_hkp2000", "P2000" }
	, { "weapon_usp_silencer", "USP-S" }
	, { "weapon_usp", "USP-S" }
	, { "weapon_p250", "P250" }
	, { "weapon_p228", "P228" }
	, { "weapon_fiveseven", "Five-SeveN" }
	, { "weapon_deagle", "Desert Eagle" }
	, { "weapon_cz75a", "CZ75-Auto" }
	, { "weapon_revolver", "R8 Revolver" }
	, { "weapon_tec9", "Tec-9" }
	, { "weapon_elite", "Dual Berettas" }
	, { "weapon_mp9", "MP9" }
	, { "weapon_tmp", "TMP" }
	, { "weapon_mp7", "MP7" }
	, { "weapon_ump45", "UMP-45" }
	, { "weapon_p90", "P90" }
	, { "weapon_bizon", "PP-Bizon" }
	, { "weapon_mp5sd", "MP5SD" }
	, { "weapon_mp5navy", "MP5" }
	, { "weapon_famas", "FAMAS" }
	, { "weapon_galil", "Galil" }
	, { "weapon_galilar", "Galil AR" }
	, { "weapon_m4a1", "M4A4" }
	, { "weapon_m4a1_silencer", "M4A1-S" }
	, { "weapon_ak47", "AK-47" }
	, { "weapon_scar20", "SCAR-20" }
	, { "weapon_sg550", "SG 550" }
	, { "weapon_g3sg1", "G3SG1" }
	, { "weapon_ssg08", "SSG-08" }
	, { "weapon_awp", "AWP" }
	, { "weapon_sg553", "SG 553" }
	, { "weapon_sg552", "SG 552" }
	, { "weapon_aug", "AUG" }
	, { "weapon_nova", "Nova" }
	, { "weapon_m3", "M3" }
	, { "weapon_xm1014", "XM1014" }
	, { "weapon_mag7", "MAG-7" }
	, { "weapon_sawedoff", "Sawed-Off" }
	, { "weapon_m249", "M249" }
	, { "weapon_negev", "Negev" }
	, { "weapon_flashbang", "Flashbang Grenade" }
	, { "weapon_smokegrenade", "Smoke Grenade" }
	, { "weapon_decoy", "Decoy Greande" }
	, { "weapon_molotov", "Molotov" }
	, { "weapon_incgrenade", "Incendiary Greande" }
	, { "weapon_tagrenade", "Tactical Awareness Grenade" }
	, { "weapon_healthshot", "Meid-Shot" }
	, { "weapon_snowball", "SnowBall" }
	, { "weapon_hammer", "Hammer" }
	, { "weapon_axe", "Axe" }
	, { "weapon_spanner", "Spanner" }
	, { "weapon_knife", "Knife" }
	, { "weapon_knifegg", "Golden Knife" }
};

/**
 * 무기 클래스 이름을 무기 이름으로 바꿉니다.
 *
 * @param classname		무기 클래스 명
 * @param buffer
 * @param maxlen
 * @noreturn
 */
stock void qufnrTools_WeaponClassnameToAlias ( char[] classname, char[] buffer, int maxlen ) {
	for ( int i = 0; i < sizeof WEAPON_NAME_ARRAY; i ++ ) {
		if ( StrEqual ( classname, WEAPON_NAME_ARRAY[i][0] ) ) {
			strcopy ( buffer, maxlen, WEAPON_NAME_ARRAY[i][1] );
			if ( GetEngineVersion () == Engine_CSS ) {
				if ( StrContains ( classname, "m4a1" ) != -1 )
					strcopy ( buffer, maxlen, "M4A1" );
			}
		}
	}
}