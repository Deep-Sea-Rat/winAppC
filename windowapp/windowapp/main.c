#include <windows.h>
#include "winproc.h"
HISTANCE h;

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hpi, LPSTR cmdline,int ss) {
	(void)hpi;
	(void)cmdline;
	WNDCLASS wc; 
	wc.style=0; 
	wc.lpfnWndProc=MainWinProc;
	wc.cbClsExtra=wc.cbWndExtra=0; 
	wc.hInstance=hInst;
	wc.hIcon=LoadIcon(hInst, "My_Icon");
	wc.hCursor = LoadCursor(hInst, "My_Cursor");
	wc.hbrBackground=CreateSolidBrush(RGB(115, 134, 219)); 
	wc.lpszMenuName="My_Menu"; 
	wc.lpszClassName="Example MainWnd Class";
	if (!RegisterClass(&wc)) 
		return FALSE;

	HWND hMainWnd = CreateWindow(
	"Example MainWnd Class",
	"Omg", 
	WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT, 
	CW_USEDEFAULT, 
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	NULL, 
	NULL,
	hInst, 
	NULL);
	if (!hMainWnd) 
		return FALSE;
	
	ShowWindow(hMainWnd,ss); 
	UpdateWindow(hMainWnd);

	MSG msg;
	while (GetMessage(&msg,NULL,0,0)) { 
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	} 
	
	return msg.wParam;
}