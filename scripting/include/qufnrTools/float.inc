/**
 * 확률을 계산합니다.
 *
 * @param prob
 * @return 확률안에 들었다면 true를 반환합니다.
 */
stock bool qufnrTools_Probability ( float prob ) {
    if ( prob > 0.0 && prob <= 100.0 ) {
        float flRandom = GetRandomFloat ( 0.000000, 1.000000 );
        float flRealChance = prob / 100.0;
        return ( flRandom <= flRealChance );
    }
    return false;
}

/**
 * 두 수의 퍼센트 값을 반환합니다.
 *
 * @param current       현재 값
 * @param maxNum        최대 값
 */
stock float qufnrTools_GetPercentage ( float current, float maxNum ) {
    return ( current / maxNum * 100.0 );
}