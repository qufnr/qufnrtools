
/**
 * 타이머 Handle을 확실하게 죽입니다.
 *
 * @param hndl      Timer Handle
 */
stock void qufnrTools_KillTimer ( Handle hndl ) {
    if ( hndl != null ) {
        KillTimer ( hndl );
        hndl = null;
    }
}