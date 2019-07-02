methodmap Player {
	public Player ( int param ) {
		return view_as <Player> ( param );
	}
	
	/**
	 * 플레이어의 인덱스 값을 반환합니다.
	 *
	 * @return 플레이어 인덱스 값
	 */
	property int index {
		public get () {
			return view_as <int> ( this );
		}
	}
	
	/**
	 * 플레이어의 유저 아이디 값을 반환합니다.
	 *
	 * @return 플레이어 유저 아이디 값
	 */
	property int userId {
		public get () {
			return GetClientUserId ( this.index );
		}
	}
	
	/**
	 * 플레이어의 시리얼 값을 반환합니다.
	 *
	 * @return 플레이어 시리얼 값
	 */
	property int serial {
		public get () {
			return GetClientSerial ( this.index );
		}
	}
	
	/**
	 * Returns if a player is connected.
	 *
	 * @return		True if player is connected to the server, false otherwise.
	 */
	property bool isConnected {
		public get () {
			return IsClientConnected ( this.index );
		}
	}
	
    /** 
     * Returns if a player has entered the game. 
	 *
     * @return                True if player has entered the game, false otherwise. 
     * @error                Invalid client index. 
     */
	property bool inGame {
		public get () {
			return IsClientInGame ( this.index );
		}
	}
	
    /** 
     * Returns if a client is timing out 
	 *
     * @return                True if client is timing out, false otherwise. 
     * @error                Invalid client index, client not connected, or fake client. 
     */ 
	property bool isTimingOut {
		public get () {
			return IsClientTimingOut ( this.index );
		}
	}
	
    /** 
     * Returns if a player is in the "kick queue" (i.e. the client will be kicked  
     * shortly and thus they should not appear as valid). 
     * 
     * @return                True if in the kick queue, false otherwise. 
     * @error                Invalid client index. 
     */ 
	property bool inKickQueue {
		public get () {
			return IsClientInKickQueue ( this.index );
		}
	}
    /** 
     * Returns if a player has been authenticated. 
     * 
     * @return                True if player has been authenticated, false otherwise. 
     */ 
	property bool isAuthorized {
		public get () {
			return IsClientAuthorized ( this.index );
		}
	}
	
    /** 
     * Returns if the client is alive or dead. 
     * 
     * Note: This function was originally in SDKTools and was moved to core. 
     * 
     * @return                True if the client is alive, false otherwise. 
     * @error                Invalid client index, client not in game, or no mod support. 
     */ 
	property bool isAlive {
		public get () {
			return IsPlayerAlive ( this.index );
		}
	}
	
    /** 
     * Returns if a player is a fake client. 
     * 
     * @return                True if player is a fake client, false otherwise. 
     */ 
	property bool isFake {
		public get () {
			return IsFakeClient ( this.index );
		}
	}

    /** 
     * Returns if a certain player is the SourceTV bot. 
     * 
     * @return                True if player is the SourceTV bot, false otherwise. 
     */ 
    property bool IsSourceTV { 
        public get () { 
            return IsClientSourceTV ( this.index ); 
        } 
    } 

    /** 
     * Returns if a certain player is the Replay bot. 
     * 
     * @return                True if player is the Replay bot, false otherwise. 
     */ 
    property bool IsReplay { 
        public get () { 
            return IsClientReplay ( this.index ); 
        } 
    } 

    /** 
     * Returns if a certain player is an observer/spectator. 
     * 
     * @return                True if player is an observer, false otherwise. 
     */ 
    property bool IsObserver { 
        public get () { 
            return IsClientObserver ( this.index ); 
        } 
    } 
	
	/**
	 * 플레이어가 유효한지 채크합니다.
	 *
	 * @return 유효할 경우 true를 반환합니다.
	 */
	property bool isValid {
		public get () {
			return loringlib_IsValidClient ( this.index );
		}
	}
	
	/**
	 * 체력을 반환합니다.
	 */
	property int health {
		public get () {
			return loringlib_GetEntityHealth ( this.index );
		}
		
		public set ( int param ) {
			loringlib_SetEntityHealth ( this.index, param );
		}
	}
	
	/**
	 * 최대 체력을 반환합니다.
	 */
	property int maxHealth {
		public get () {
			return loringlib_GetEntityMaxHealth ( this.index );
		}
		
		public set ( int param ) {
			loringlib_SetEntityMaxHealth ( this.index, param );
		}
	}
	
	/**
	 * 아머(방탄복) 값을 반환합니다.
	 */
	property int armor { 
		public get () {
			return loringlib_GetEntityArmor ( this.index );
		}
		
		public set ( int param ) {
			loringlib_SetEntityArmor ( this.index, param );
		}
	}
	
	/**
	 * 헬멧 유무를 반환합니다.
	 * 헬멧을 가지고 있다면 true, 아니면 false를 반환합니다.
	 */
	property bool helmat {
		public get () {
			return loringlib_HasEntityHelmet ( this.index );
		}
		
		public set ( bool param ) {
			loringlib_SetEntityHelmet ( this.index, param ? 1 : 0 );
		}
	}
	
	/**
	 * 이동속도를 반환합니다.
	 */
	property float laggedMovement {
		public get () {
			return loringlib_GetEntityLaggedmovement ( this.index );
		}
		
		public set ( float param ) {
			loringlib_SetEntityLaggedmovement ( this.index, param );
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
			loringlib_SetEntityGravity ( this.index, param );
		}
	}
	
	/**
	 * 달러 값을 반환합니다.
	 */
	property int account {
		public get () {
			return loringlib_GetEntityAccount ( this.index );
		}
		
		public set ( int param ) {
			loringlib_SetEntityAccount ( this.index, param );
		}
	}
	
	/**
	 * 플레이어에게 채팅 메세지를 보냅니다.
	 *
	 * @param format		메세지 포멧
	 * @param ...			메세지 파라메터
	 * @noreturn
	 */
	public void sendChat ( const char[] format, any ... ) {
		if ( format[0] == EOS )
			qufnrTools_PrintToChat ( this.index, "Hello World" );
		else {
			char buffer[254];
			
			VFormat ( buffer, sizeof buffer, format, 2 );
			qufnrTools_PrintToChat ( this.index, buffer );
		}
	}
	
	/**
	 * 플레이어에게 커멘드 리플라이를 보냅니다.
	 *
	 * @param format		메세지 포멧
	 * @param ...			메세지 파라메터
	 * @noreturn
	 */
	public void sendReply ( const char[] format, any ... ) {
		if ( format[0] == EOS )
			qufnrTools_ReplyToCommand ( this.index, "Hello World" );
		else {
			char buffer[254];
			
			VFormat ( buffer, sizeof buffer, format, 2 );
			qufnrTools_ReplyToCommand ( this.index, buffer );
		}
	}
	
	/**
	 * 플레이어에게 힌트 텍스트를 보냅니다.
	 *
	 * @param format		메세지 포멧
	 * @param ...			메세지 파라메터
	 * @noreturn
	 */
	public void sendHintText ( const char[] format, any ... ) {
		if ( format[0] == EOS )
			PrintHintText ( this.index, "Hello World" );
		else {
			char buffer[254];
			
			SetGlobalTransTarget ( this.index );
			VFormat ( buffer, sizeof buffer, format, 2 );
			PrintHintText ( this.index, buffer );
		}
	}
	
	/**
	 * 플레이어에게 센터 텍스트를 보냅니다.
	 *
	 * @param format		메세지 포멧
	 * @param ...			메세지 파라메터
	 * @noreturn
	 */
	public void sendCetnerText ( const char[] format, any ... ) {
		if ( format[0] == EOS )
			PrintCenterText ( this.index, "Hello World" );
		else {
			char buffer[254];
			
			SetGlobalTransTarget ( this.index );
			VFormat ( buffer, sizeof buffer, format, 2 );
			PrintCenterText ( this.index, buffer );
		}
	}
};