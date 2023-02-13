
/**
 * 논리형 변수를 문자열로 변환합니다.
 * @param booleanValue  논리형 변수
 * @param trueName      참일 경우의 이름
 * @param falseName     거짓일 경우의 이름
 * @param str
 * @param maxlen
 */
stock void qufnrTools_BooleanToString ( bool booleanValue, const char[] trueName, const char[] falseName, char[] str, int maxlen ) {
    Format ( str, maxlen, booleanValue ? trueName : falseName );
}

/**
 * Add comma to string
 * 
 * @param buffer
 * @param maxlen
 * @param position
 */
stock void qufnrTools_AddCommaToString ( char[] buffer, int maxlen, int position ) {
    static char strTemp[64];
    FormatEx ( strTemp, position + 1, "%s", buffer ), Format ( strTemp, sizeof ( strTemp ), "%s,", strTemp ), Format ( strTemp, sizeof ( strTemp ), "%s%s", strTemp, buffer[position] ), FormatEx ( buffer, maxlen, "%s", strTemp );
}

/**
 * Numeric formatting
 *
 * @param number
 * @param buffer
 * @param maxlen
 */
stock void qufnrTools_NumberFormat ( int number, char[] buffer, int maxlen ) {
    bool bNegative = number < 0 ? true : false;
    if ( bNegative )    number *= -1;
    FormatEx ( buffer, maxlen, "%d", number );
    for ( int i = strlen ( buffer ) - 3; i > 0; i -= 3 )
        qufnrTools_AddCommaToString ( buffer, maxlen, i );
    if ( bNegative )
        Format ( buffer, maxlen, "-%s", buffer );
}

#if defined __cstrike_include
    /**
     * String to team index (CS:S, CS:GO Only)
     *
     * @param str        Name of team string
     * @return CS_TEAM_*
     */
    stock int qufnrTools_StringToTeamIndex ( const char[] str ) {
        if ( StrEqual ( str, "ct", false ) )        return CS_TEAM_CT;
        else if ( StrEqual ( str, "t", false ) )    return CS_TEAM_T;
        else    return CS_TEAM_NONE;
    }
#endif

/**
 * 텍스트로 프로그레스 바를 그립니다.
 * @note 참고자료: https://geundung.dev/43
 *
 * @param current       현재 진행되는 수
 * @param maximum       진행되는 수의 최대 값
 * @param length        프로그레스 바 블록 갯수
 * @param progress
 * @param charLength
 */
stock void qufnrTools_DrawTextProgressbar ( int current, int maximum, int length = 20, char[] progress, int charLength ) {
    const char sBar = '-';
    const char sBlank = ' ';
    
    strcopy ( progress, charLength, "[" );

    PrintToServer ( "current / maximum: %d / %d", current, maximum );

    float flTick = 100.0 / length;
    PrintToServer ( "flTick: %f", flTick );
    int nBarCount;
    float flPercent;
    flPercent = qufnrTools_GetPercentage ( float ( current ), float ( maximum ) );
    nBarCount = RoundToZero ( flPercent / flTick );
    PrintToServer ( "flPercent: %f", flPercent );
    PrintToServer ( "nBarCount: %d", nBarCount );

    for ( int i = 0; i < length; i ++ ) {
        if ( nBarCount > i )
            Format ( progress, charLength, "%s%c", progress, sBar );
        else
            Format ( progress, charLength, "%s%c", progress, sBlank );
    }
    Format ( progress, charLength, "%s]", progress );
}