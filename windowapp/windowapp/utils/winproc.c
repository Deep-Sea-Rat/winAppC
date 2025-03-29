#include <windows.h>
#define ID_MYBUTTON 1
#define ID_MYBUTTON2 14
#define ID_MYBUTTON3 15

BOOL CALLBACK DigProc(HWND hw, UINT msg, WPARAM wp, LPARAM lp)
{
	(void)lp;
	switch(msg){
		case WM_COMMAND:
			switch(LOWORD(wp)){					
				case 2:
					EndDialog(hw, wp);
					return TRUE;
			}
	}
	return FALSE;
}
char buf[256] = " ";

LRESULT CALLBACK MainWinProc(HWND hw, UINT msg, WPARAM wp, LPARAM lp) {
	HFONT myFont;
	HWND Button1;
	HWND Button2;
	HWND Button3;
	HWND window;
	switch (msg) {
	case WM_CREATE:
		myFont = CreateFont(0, 0, 0, 0, FW_MEDIUM, TRUE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, 
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_ROMAN, "MyFont");
		
		Button1 = CreateWindow(
		"button", 
		"blin", 
		WS_CHILD | 
		BS_PUSHBUTTON | 
		WS_VISIBLE, 
		50, 
		50,
		200,
		40,
		hw, 
		(HMENU)ID_MYBUTTON, 
		NULL, 
		NULL);
		
		Button2 = CreateWindow (
		"button", 
		"oladush", 
		WS_CHILD | 
		BS_PUSHBUTTON | 
		WS_VISIBLE, 
		270, 
		50,
		200,
		40,
		hw, 
		(HMENU)ID_MYBUTTON2, 
		NULL, 
		NULL);
		
		Button3 = CreateWindow (
		"button", 
		"syrnik", 
		WS_CHILD | 
		BS_PUSHBUTTON | 
		WS_VISIBLE, 
		490, 
		50,
		200,
		40,
		hw, 
		(HMENU)ID_MYBUTTON3, 
		NULL, 
		NULL);
		
		SendMessage(Button1,WM_SETFONT,(WPARAM)myFont,TRUE);
		SendMessage(Button2,WM_SETFONT,(WPARAM)myFont,TRUE);
		SendMessage(Button3,WM_SETFONT,(WPARAM)myFont,TRUE);
		
		return 0;
	case WM_COMMAND:
		if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON)) 
			MessageBox(hw, "blin", "Amogus", MB_OK|MB_ICONWARNING);
		
		if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON2)) 
			MessageBox(hw, "oda oladush", "Sugoma", MB_OK|MB_ICONWARNING);
		
		if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON3)) 
			MessageBox(hw, "syrnik lyubimka", "Я хз", MB_OK|MB_ICONWARNING);
		
		if (HIWORD(wp)==0) {
			char buf[256];
			switch (LOWORD(wp)) {
				case 6:
					PostQuitMessage(0);
				case 1:
					break;
				case 14:
					break;
				case 15:
					break;
				case 13:
					DialogBox(NULL, "AboutApp", hw, (DLGPROC)DigProc);
					break;
				case 9:
					window = CreateDialog(NULL, "FellDlg1", hw, (DLGPROC)DigProc);
					ShowWindow(window, SW_SHOW);
					break;
				case 10:
					window = CreateDialog(NULL, "FellDlg2", hw, (DLGPROC)DigProc);
					ShowWindow(window, SW_SHOW);
					break;
				case 11:
					window = CreateDialog(NULL, "FellDlg3", hw, (DLGPROC)DigProc);
					ShowWindow(window, SW_SHOW);
					break;
				case 7:
					window = CreateDialog(NULL, "Copy", hw, (DLGPROC)DigProc);
					ShowWindow(window, SW_SHOW);
					break;
				case 8:
					window = CreateDialog(NULL, "Past", hw, (DLGPROC)DigProc);
					ShowWindow(window, SW_SHOW);
					break;
				default:
					wsprintf(buf, "Код команды: %d", LOWORD(wp));
					window = CreateDialog(NULL, "proba", hw, (LOWORD(wp));
					//MessageBox(hw, buf, "Сообщение", MB_OK|MB_ICONINFORMATION);
					
					//window = CreateDialog(NULL, "My_Menu", hw, (LOWORD(wp));
					//ShowWindow(window, SW_SHOW);
			}
		}
		return 0;
	case WM_DESTROY:
		
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hw,msg,wp,lp);
}
