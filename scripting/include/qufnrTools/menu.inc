/**
 * 메뉴 타이틀을 설정합니다.
 *
 * @param menu		Menu Handle
 * @param target	Menu Display Target (Optional)
 * @param format	Menu title format.
 * @param ...		More parameters
 * @noreturn
 */
stock void qufnrTools_SetMenuTitle ( Menu menu, int target = -1, const char[] format, any ... ) {
	if ( menu == null )
		return;
	
	char szBuffer[256];
	
	if ( target != -1 )
		SetGlobalTransTarget ( target );
	VFormat ( szBuffer, sizeof szBuffer, format, 4 );
	qufnrTools_FormatEscapeSequence ( szBuffer, sizeof szBuffer );
	
	menu.SetTitle ( szBuffer );
}

/**
 * 메뉴에 아이템을 추가합니다.
 *
 * @param menu		Menu Handle
 * @param target	Menu Display Target (Optional)
 * @param style		Menu item display style. (Optional)
 * @param info		Menu item info data. (Optional)
 * @param display	Menu display buffer.
 * @param ...		More parameters
 * @noreturn
 */
stock void qufnrTools_AddMenuItem ( Menu menu, int target = -1, int style = ITEMDRAW_DEFAULT, const char[] info, const char[] display, any ... ) {
	if ( menu == null )
		return;
	
	char szBuffer[256];
	
	if ( target != -1 )
		SetGlobalTransTarget ( target );
	VFormat ( szBuffer, sizeof szBuffer, display, 6 );
	qufnrTools_FormatEscapeSequence ( szBuffer, sizeof szBuffer );
	
	menu.AddItem ( info, szBuffer, style );
}

/**
 * 페널 타이틀을 설정합니다.
 *
 * @param panel		Panel Handle
 * @param target	Panel display target (Optional)
 * @param format	Panel title format
 * @param ...		More parameters
 * @noreturn
 */
stock void qufnrTools_SetPanelTitle ( Panel panel, int target = -1, const char[] format, any ... ) {
	if ( panel == null )
		return;
	
	char szBuffer[256];
	
	if ( target != -1 )
		SetGlobalTransTarget ( target );
	VFormat ( szBuffer, sizeof szBuffer, format, 4 );
	qufnrTools_FormatEscapeSequence ( szBuffer, sizeof szBuffer );
	
	panel.SetTitle ( szBuffer );
}

/**
 * 페널에 아이템을 추가합니다.
 *
 * @param panel		Panel Handle
 * @param target	Panel Display Target (Optional)
 * @param style		Panel item display style (Optional)
 * @param format	Panel display contents.
 * @param ...		More parameters
 * @noreturn
 */
stock void qufnrTools_DrawPanelItem ( Panel panel, int target = -1, int style = ITEMDRAW_DEFAULT, const char[] format, any ... ) {
	if ( panel == null )
		return;
	
	char szBuffer[256];
	
	if ( target != -1 )
		SetGlobalTransTarget ( target );
	VFormat ( szBuffer, sizeof szBuffer, format, 5 );
	qufnrTools_FormatEscapeSequence ( szBuffer, sizeof szBuffer );
	
	panel.DrawItem ( szBuffer, style );
}

/**
 * 페널에 텍스트를 추가합니다.
 *
 * @param panel		Panel Handle
 * @param target	Panel Display Target (Optional)
 * @param format	Panel display contents.
 * @param ...		More parameters
 * @noreturn
 */
stock void qufnrTools_DrawPanelText ( Panel panel, int target = -1, const char[] format, any ... ) {
	if ( panel == null )
		return;
	
	char szBuffer[256];
	
	if ( target != -1 )
		SetGlobalTransTarget ( target );
	VFormat ( szBuffer, sizeof szBuffer, format, 4 );
	qufnrTools_FormatEscapeSequence ( szBuffer, sizeof szBuffer );
	
	panel.DrawText ( szBuffer );
}

public int qufnrTools_MenuNoSelect ( Menu menu, MenuAction action, int param1, int param2 ) {
	if ( action == MenuAction_End )
		delete menu;
	return param2;
}