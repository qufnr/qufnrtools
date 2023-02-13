
#define CS_SLOT_6	5

static char WEAPON_NAME_ARRAY[55][3][64] = {
	{ "weapon_glock", "Glock-18", "2" }
	, { "weapon_hkp2000", "P2000", "3" }
	, { "weapon_usp_silencer", "USP-S", "3" }
	, { "weapon_usp", "USP-S", "3" }
	, { "weapon_p250", "P250", "3" }
	, { "weapon_p228", "P228", "3" }
	, { "weapon_fiveseven", "Five-SeveN", "3" }
	, { "weapon_deagle", "Desert Eagle", "3" }
	, { "weapon_cz75a", "CZ75-Auto", "3" }
	, { "weapon_revolver", "R8 Revolver", "3" }
	, { "weapon_tec9", "Tec-9", "2" }
	, { "weapon_elite", "Dual Berettas", "3" }
	, { "weapon_mp9", "MP9", "3" }
	, { "weapon_mac10", "MAC-10", "2" }
	, { "weapon_tmp", "TMP", "3" }
	, { "weapon_mp7", "MP7", "3" }
	, { "weapon_ump45", "UMP-45", "3" }
	, { "weapon_p90", "P90", "3" }
	, { "weapon_bizon", "PP-Bizon", "3" }
	, { "weapon_mp5sd", "MP5SD", "3" }
	, { "weapon_mp5navy", "MP5", "3" }
	, { "weapon_famas", "FAMAS", "3" }
	, { "weapon_galil", "Galil", "2" }
	, { "weapon_galilar", "Galil AR", "2" }
	, { "weapon_m4a1", "M4A4", "3" }
	, { "weapon_m4a1_silencer", "M4A1-S", "3" }
	, { "weapon_ak47", "AK-47", "2" }
	, { "weapon_scar20", "SCAR-20", "3" }
	, { "weapon_sg550", "SG 550", "2" }
	, { "weapon_g3sg1", "G3SG1", "2" }
	, { "weapon_ssg08", "SSG-08", "3" }
	, { "weapon_awp", "AWP", "3" }
	, { "weapon_sg553", "SG 553", "2" }
	, { "weapon_sg552", "SG 552", "2" }
	, { "weapon_aug", "AUG", "3" }
	, { "weapon_nova", "Nova", "3" }
	, { "weapon_m3", "M3", "3" }
	, { "weapon_xm1014", "XM1014", "3" }
	, { "weapon_mag7", "MAG-7", "3" }
	, { "weapon_sawedoff", "Sawed-Off", "2" }
	, { "weapon_m249", "M249", "3" }
	, { "weapon_negev", "Negev", "3" }
	, { "weapon_flashbang", "Flashbang Grenade", "3" }
	, { "weapon_smokegrenade", "Smoke Grenade", "3" }
	, { "weapon_decoy", "Decoy Grenade", "3" }
	, { "weapon_molotov", "Molotov", "3" }
	, { "weapon_incgrenade", "Incendiary Grenade", "3" }
	, { "weapon_tagrenade", "Tactical Awareness Grenade", "3" }
	, { "weapon_healthshot", "Medi-Shot", "3" }
	, { "weapon_snowball", "SnowBall", "3" }
	, { "weapon_hammer", "Hammer", "3" }
	, { "weapon_axe", "Axe", "3" }
	, { "weapon_spanner", "Spanner", "3" }
	, { "weapon_knife", "Knife", "3" }
	, { "weapon_knifegg", "Golden Knife", "3" }
};

enum WeaponAmmo {
    ammo_338mag_max,
    ammo_357sig_max,
	ammo_357sig_min_max,
	ammo_357sig_p250_max,
	ammo_357sig_small_max,
    ammo_45acp_max,
    ammo_50AE_max,
    ammo_556mm_box_max,
    ammo_556mm_max,
	ammo_556mm_small_max,
    ammo_57mm_max,
    ammo_762mm_max,
    ammo_9mm_max,
    ammo_buckshot_max
}

static const char s_szWeaponAmmo[][] = {
	"ammo_338mag_max",
	"ammo_357sig_max",
	"ammo_357sig_min_max",
	"ammo_357sig_p250_max",
	"ammo_357sig_small_max",
	"ammo_45acp_max",
	"ammo_50AE_max",
	"ammo_556mm_box_max",
	"ammo_556mm_max",
	"ammo_556mm_small_max",
	"ammo_57mm_max",
	"ammo_762mm_max",
	"ammo_9mm_max",
	"ammo_buckshot_max"
};

static ConVar s_hWeaponAmmo[14];
static const WeaponAmmo g_nAmmoIndex[] = {
    ammo_50AE_max,
    ammo_50AE_max,
    ammo_9mm_max,
    ammo_57mm_max,
    ammo_9mm_max,
    ammo_357sig_max,
    ammo_357sig_max,
	ammo_357sig_min_max,
    ammo_9mm_max,

    ammo_762mm_max,
    ammo_762mm_max,
    ammo_556mm_max,
    ammo_556mm_max,
    ammo_556mm_max,
	ammo_556mm_small_max,
    ammo_556mm_max,

    ammo_buckshot_max,
    ammo_buckshot_max,
    ammo_buckshot_max,
    ammo_buckshot_max,

    ammo_9mm_max,
    ammo_45acp_max,
    ammo_9mm_max,
    ammo_9mm_max,
    ammo_9mm_max,
    ammo_57mm_max,
    ammo_45acp_max,

    ammo_338mag_max,
    ammo_762mm_max,
    ammo_762mm_max,
    ammo_762mm_max,

    ammo_556mm_box_max,
    ammo_556mm_box_max
};

static const char s_szWeaponName[][] = {
    "weapon_deagle",
	"weapon_revolver",
    "weapon_elite",
    "weapon_fiveseven",
    "weapon_glock",
    "weapon_hkp2000",
    "weapon_p250",
	"weapon_usp_silencer",
    "weapon_tec9",

    "weapon_ak47",
    "weapon_aug",
    "weapon_famas",
    "weapon_galilar",
    "weapon_m4a4",
	"weapon_m4a1_silencer",
    "weapon_sg556",

    "weapon_mag7",
    "weapon_nova",
    "weapon_sawedoff",
    "weapon_xm1014",

    "weapon_bizon",
    "weapon_mac10",
    "weapon_mp7",
	"weapon_mp5sd",
    "weapon_mp9",
    "weapon_p90",
    "weapon_ump45",

    "weapon_awp",
    "weapon_g3sg1",
    "weapon_scar20",
    "weapon_ssg08",

    "weapon_m249",
    "weapon_negev"
};

static int s_iMaxClipSize[] = {
	7,
	7,
	30,
	20,
	20,
	13,
	13,
	12,
	18,
	
	30,
	30,
	25,
	30,
	30,
	25,
	30,
	
	7,
	8,
	7,
	7,
	
	64,
	30,
	30,
	30,
	30,
	50,
	25,
	
	10,
	20,
	20,
	10,
	
	100,
	150
}

enum WeaponGetType {
	WeaponGetType_Param = 0,
	WeaponGetType_Active
}

const Weapon INVALID_WEAPON = view_as <Weapon> ( INVALID_ENT_REFERENCE );

methodmap Weapon < Entity {

	/**
	 * Weapon의 생성자 입니다. 무기의 index 값을 선언할 때 사용합니다.
	 * @param getType		생성자에서 무기 index를 가져오는 타입을 설정합니다. WeaponGetType_Param은 사용자 측에서 특정된 값을 가져올 때 사용하고, WeaponGetType_Active는 param에 들어갈 클라이언트의 Active Weapon의 index 값을 받아옵니다.
	 * @param param			getType에 대한 값을 받아오는 매개변수입니다.
	 */
	public Weapon ( WeaponGetType getType, int param ) {
		switch ( getType ) {
			case WeaponGetType_Param: {
				if ( !IsValidEntity ( param ) )
					return INVALID_WEAPON;
				return view_as <Weapon> ( EntIndexToEntRef ( param ) );
			}
			case WeaponGetType_Active: {
				int nActiveWeapon = GetEntPropEnt ( param, Prop_Data, "m_hActiveWeapon" );
				if ( !IsValidEntity ( nActiveWeapon ) )
					return INVALID_WEAPON;
				return view_as <Weapon> ( EntIndexToEntRef ( nActiveWeapon ) );
			}
			default:	return view_as<Weapon> ( -1 );
		}
	}

	/**
	 * 무기가 유효한지 유무를 반환합니다.
	 */
	public bool isValid () {
		Entity weaponEntity = Entity ( this.index );
		if ( !weaponEntity.isEdict () )
			return false;
		return weaponEntity.isClassnameMatches ( "weapon_", true );
	}

	/**
	 * Clip1을 반환합니다.
	 */
	property int clip1 {
		public get () {
			return GetEntProp ( this.index, Prop_Send, "m_iClip1" );
		}

		public set ( int param ) {
			SetEntProp ( this.index, Prop_Send, "m_iClip1", param );
		}
	}

	/**
	 * Clip2를 반환합니다.
	 */
	property int clip2 {
		public get () {
			return GetEntProp ( this.index, Prop_Send, "m_iClip2" );
		}

		public set ( int param ) {
			SetEntProp ( this.index, Prop_Send, "m_iClip2", param );
		}
	}

	/** 
	 * Returns primary ammo type
	 */
	property int primaryAmmoType {
		public get () {
			return GetEntProp ( this.index, Prop_Data, "m_iPrimaryAmmoType" );
		}

		public set ( int param ) {
			SetEntProp ( this.index, Prop_Data, "m_iPrimaryAmmoType", param );
		}
	}

	/**
	 * Returns secondary ammo type
	 */
	property int secondaryAmmoType {
		public get () {
			return GetEntProp ( this.index, Prop_Data, "m_iSecondaryAmmoType" );
		}

		public set ( int param ) {
			SetEntProp ( this.index, Prop_Data, "m_iSecondaryAmmoType", param );
		}
	}

	/**
	 * 재장전 중인지 유무를 반환합니다.
	 */
	property bool isReloading {
		public get () {
			return view_as <bool> ( GetEntProp ( this.index, Prop_Data, "m_bInReload" ) );
		}
	}
}

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

/**
 * 무기 클래스 이름을 구합니다.
 *
 * @param weapon		무기 인덱스 값
 * @param buffer
 * @param maxlen
 * @return		무기 클래스 이름을 구했을 경우 true를 반환합니다.
 */
stock bool qufnrTools_GetWeaponClassname ( int weapon, char[] buffer, int maxlen ) {
	if ( GetEdictClassname ( weapon, buffer, maxlen ) ) {
		int iIndexOfWeapon = GetEntProp ( weapon, Prop_Send, "m_iItemDefinitionIndex" );
		switch ( iIndexOfWeapon ) {
			case 23:	strcopy ( buffer, maxlen, "weapon_mp5sd" );
			case 60:	strcopy ( buffer, maxlen, "weapon_m4a1_silencer" );
			case 61: 	strcopy ( buffer, maxlen, "weapon_usp_silencer" );
			case 63: 	strcopy ( buffer, maxlen, "weapon_cz75a" );
		}
		
		return true;
	}
	
	return false;
}

stock int qufnrTools_GivePlayerItem ( int client, const char[] item, int iSubType = 0 ) {
	int iResult = -1;
	for ( int i; i < sizeof WEAPON_NAME_ARRAY; i ++ ) {
		if ( StrEqual ( item, WEAPON_NAME_ARRAY[i][0] ) ) {
			int iTeam = GetEntProp ( client, Prop_Send, "m_iTeamNum" );
			SetEntProp ( client, Prop_Send, "m_iTeamNum", StringToInt ( WEAPON_NAME_ARRAY[i][2] ) );
			iResult = GivePlayerItem ( client, WEAPON_NAME_ARRAY[i][0], iSubType );
			SetEntProp ( client, Prop_Send, "m_iTeamNum", iTeam );
			break;
		}
	}
	
	return iResult;
}

stock void qufnrTools_GetClientWeaponReserveAmmo ( int weapon, int& primaryAmmo = -1, int &secondaryAmmo = -1 ) {
	if ( primaryAmmo != -1 )
		primaryAmmo = GetEntProp ( weapon, Prop_Send, "m_iPrimaryReserveAmmoCount" );
	if ( secondaryAmmo != -1 )
		secondaryAmmo = GetEntProp ( weapon, Prop_Send, "m_iSecondaryReserveAmmoCount" );
}

stock void qufnrTools_SetClientWeaponReserveAmmo ( int weapon, int primaryAmmo = -1, int secondaryAmmo = -1 ) {
	if ( primaryAmmo != -1 )
		SetEntProp ( weapon, Prop_Send, "m_iPrimaryReserveAmmoCount", primaryAmmo );
	if ( secondaryAmmo != -1 )
		SetEntProp ( weapon, Prop_Send, "m_iSecondaryReserveAmmoCount", secondaryAmmo );
}

/**
 * 무기의 Ammo 값을 구합니다.
 * @param client
 * @param weapon
 * @return 해당 무기의 Ammo 값.
 */
stock int qufnrTools_GetWeaponSecondaryAmmo ( int client, int weapon = 0 ) {
	if ( weapon <= 0 )
		return -1;
	
	static int iAmmoOffs;
	iAmmoOffs = FindSendPropInfo ( "CCSPlayer", "m_iAmmo" );
	
	int iAmmoType = GetEntProp ( weapon, Prop_Data, "m_iPrimaryAmmoType" );
	return GetEntData ( client, iAmmoOffs + ( iAmmoType * 4 ) );
}

/**
 * 무기의 Clip1 최대 값을 구합니다.
 * @param weapon
 * @return 해당 무기 Clip1 최대 값
 */
stock int qufnrTools_GetWeaponClipMax ( int weapon = 0 ) {
	if ( weapon <= 0 )
		return -1;
	
	int iIndex = qufnrTools_WeaponToIndex ( weapon );
	if ( iIndex == -1 )
		return -1;
	
	return qufnrTools_GetClip1Max ( iIndex );
}

/**
 * 무기의 Ammo 최대 값을 구합니다.
 * @param weapon
 * @return 해당 무기 Ammo 최대 값
 */
stock int qufnrTools_GetWeaponAmmoMax ( int weapon = 0 ) {
	if ( weapon <= 0 )
		return -1;
		
	int iIndex = qufnrTools_WeaponToIndex ( weapon );
	if ( iIndex == -1 )
		return -1;
	
	qufnrTools_FindAmmoMaxCvar ();
	
	return qufnrTools_GetAmmoMax ( iIndex );
}

#if defined __cstrike_include_enable

/**
 * 무기의 슬롯 위치를 구합니다.
 * @param weapon
 * @return 무기 슬롯 값
 */
	stock int qufnrTools_GetWeaponSlot ( int weapon ) {
		CSWeaponID idx = CS_ItemDefIndexToID ( GetEntProp ( weapon, Prop_Send, "m_iItemDefinitionIndex" ) );
		if ( idx != CSWeapon_NONE ) {
			if ( idx == CSWeapon_P228 || idx == CSWeapon_GLOCK ||
				idx == CSWeapon_ELITE || idx == CSWeapon_USP ||
				idx == CSWeapon_DEAGLE || idx == CSWeapon_TEC9 ||
				idx == CSWeapon_HKP2000 || idx == CSWeapon_P250 ||
				idx == CSWeapon_USP_SILENCER  || idx == CSWeapon_CZ75A ||
				idx == CSWeapon_REVOLVER || idx == CSWeapon_FIVESEVEN )
				return CS_SLOT_SECONDARY;
			else if ( idx == CSWeapon_KNIFE_GG || idx == CSWeapon_KNIFE ||
				idx == CSWeapon_KNIFE_T || idx == CSWeapon_KNIFE_GHOST ||
				idx == CSWeapon_KNIFE_FLIP || idx == CSWeapon_KNIFE_GUT ||
				idx == CSWeapon_KNIFE_KARAMBIT || idx == CSWeapon_KNIFE_M9_BAYONET ||
				idx == CSWeapon_KNIFE_TATICAL || idx == CSWeapon_KNIFE_FALCHION ||
				idx == CSWeapon_KNIFE_SURVIVAL_BOWIE || idx == CSWeapon_KNIFE_BUTTERFLY ||
				idx == CSWeapon_KNIFE_PUSH || idx == CSWeapon_KNIFE_URSUS ||
				idx == CSWeapon_KNIFE_GYPSY_JACKKNIFE || idx == CSWeapon_KNIFE_STILETTO ||
				idx == CSWeapon_KNIFE_WIDOWMAKER || idx == CSWeapon_BAYONET ||
				idx == CSWeapon_FISTS || idx == CSWeapon_MELEE ||
				idx == CSWeapon_AXE || idx == CSWeapon_HAMMER ||
				idx == CSWeapon_SPANNER )
				return CS_SLOT_KNIFE;
			else if ( idx == CSWeapon_MOLOTOV || idx == CSWeapon_DECOY ||
				idx == CSWeapon_INCGRENADE || idx == CSWeapon_TAGGRENADE ||
				idx == CSWeapon_FIREBOMB || idx == CSWeapon_DIVERSION ||
				idx == CSWeapon_FRAGGRENADE || idx == CSWeapon_SNOWBALL ||
				idx == CSWeapon_HEGRENADE || idx == CSWeapon_SMOKEGRENADE ||
				idx == CSWeapon_FLASHBANG )
				return CS_SLOT_GRENADE;
			else if ( idx == CSWeapon_C4 || idx == CSWeapon_BREACHCHARGE ||
				idx == CSWeapon_BUMPMINE )
				return CS_SLOT_C4;
			else if ( idx == CSWeapon_SHIELD || idx == CSWeapon_HEALTHSHOT )
				return CS_SLOT_6;
			else if ( idx == CSWeapon_KEVLAR || idx == CSWeapon_ASSAULTSUIT ||
				idx == CSWeapon_NIGHTVISION || idx == CSWeapon_DEFUSER )
				return -1;
			else
				return CS_SLOT_PRIMARY;
		}
		
		return -1;
	}

#endif

/**
 * 무기를 가지고 있는지 채크합니다.
 * @param client
 * @param classname 무기 이름
 * @return 무기를 가지고 있다면 true를 반환합니다.
 */
stock bool qufnrTools_HasWeapon ( int client, const char[] classname ) {
	int iIndex;
	int iWeapon;
	char sName[32];
	while ( ( iWeapon = qufnrTools_GetNextWeapon ( client, iIndex ) ) != -1 ) {
		qufnrTools_GetWeaponClassname ( iWeapon, sName, sizeof sName );
		if ( StrEqual ( sName, classname ) )
			return true;
	}
	return false;
}

stock void qufnrTools_KillWeapons ( int client ) {
	int iIndex;
	int iWeapon;
	while ( ( iWeapon = qufnrTools_GetNextWeapon ( client, iIndex ) ) != -1 ) {
		AcceptEntityInput ( iWeapon, "Kill" );
	}
}

stock int qufnrTools_GetNextWeapon ( int client, int& weaponIndex ) {
	static int iWeaponOffset = -1;
	if ( iWeaponOffset == -1 )
		iWeaponOffset = FindDataMapInfo ( client, "m_hMyWeapons" );
	int iOffset = iWeaponOffset + ( weaponIndex * 4 );
	int iWeapon;
	while ( weaponIndex < 48 ) {
		weaponIndex ++;
		iWeapon = GetEntDataEnt2 ( client, iOffset );
		if ( IsValidEdict ( iWeapon ) )
			return iWeapon;
		iOffset += 4;
	}
	return -1;
}




static int qufnrTools_WeaponToIndex ( int weapon ) {
	static char szClassname[32];
	qufnrTools_GetWeaponClassname ( weapon, szClassname, sizeof szClassname );
	for ( int i; i < sizeof s_szWeaponName; i ++ )
		if ( !strcmp ( s_szWeaponName[i], szClassname ) )
			return i;
	return -1;
}

static void qufnrTools_FindAmmoMaxCvar () {
	if ( s_hWeaponAmmo[0] == null )
		for ( int i; i < sizeof s_hWeaponAmmo; i ++ )
			s_hWeaponAmmo[i] = FindConVar ( s_szWeaponAmmo[i] );
}

static int qufnrTools_GetAmmoMax ( int index ) {
	return s_hWeaponAmmo[g_nAmmoIndex[index]].IntValue;
}

static int qufnrTools_GetClip1Max ( int index ) {
	return s_iMaxClipSize[index];
}