/**
 * origin(위치)에서 앞쪽으로 units 만큼 이동한 값을 반환합니다.
 *
 * @param origin
 * @param angles
 * @param units
 * @param output
 */
stock void qufnrTools_AddInFrontOf ( float origin[3], float angles[3], float units, float output[3] ) {
    float vecVec[3];
    vecVec = angles;
    GetAngleVectors ( vecVec, vecVec, NULL_VECTOR, NULL_VECTOR );
    
    output[0] = origin[0] + ( vecVec[0] * units );
    output[1] = origin[1] + ( vecVec[1] * units );
    output[2] = origin[2] + ( vecVec[2] * units );
}

/**
 * Vector를 초기화합니다.
 *
 * @param vectors
 */
stock void qufnrTools_ClearVectors ( float output[3] ) {
    output[0] = 0.000000;
    output[1] = 0.000000;
    output[2] = 0.000000;
}