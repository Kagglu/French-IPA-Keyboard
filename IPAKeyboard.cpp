#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

HINSTANCE hInst;
HWND output;

static TCHAR szWindowClass[] = _T("French IPA Keyboard");
static TCHAR szTitle[] = _T("French IPA Keyboard");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
) {
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassExW(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("IPA Keyboard"),
			NULL);

		return 1;
	}

	hInst = hInstance;

	HWND hWnd = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 100,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	output = CreateWindow(
		L"EDIT",  // Predefined class; Unicode assumed 
		L"",      // Button text 
		WS_BORDER | WS_VISIBLE | WS_CHILD,  // Styles 
		10,         // x position 
		10,         // y position 
		350,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)0,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);
	
	HWND mButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"m",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		40,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU) 'm',      // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);
	
	HWND pButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"p",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		70,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'p',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND bButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"b",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		100,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'b',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND fButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"f",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		130,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'f',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND vButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"v",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		160,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'v',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND nButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"n",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		40,         // x position 
		40,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'n',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND tButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"t",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		40,         // x position 
		70,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'t',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND dButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"d",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		40,         // x position 
		100,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'d',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND sButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"s",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		40,         // x position 
		130,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'s',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND zButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"z",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		40,         // x position 
		160,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'z',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND lButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"l",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		40,         // x position 
		190,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'l',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND ʃButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"ʃ",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		70,         // x position 
		130,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)643,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND ʒButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"ʒ",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		70,         // x position 
		160,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)439,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND ɲButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"ɲ",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		100,         // x position 
		40,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)626,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND jButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"j",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		100,         // x position 
		190,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'j',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND ɥButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"ɥ",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		100,         // x position 
		220,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)613,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND ŋButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"ŋ",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		130,         // x position 
		40,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)331,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND kButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"k",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		130,         // x position 
		70,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'k',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND gButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"g",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		130,         // x position 
		100,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'g',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND ʁButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"ʁ",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		130,         // x position 
		190,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)641,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND wButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"w",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		130,         // x position 
		220,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'w',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND iButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"i",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		220,         // x position 
		40,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'i',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND eButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"e",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		220,         // x position 
		70,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'e',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND εButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"ε",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		220,         // x position 
		100,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)400,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND aButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"a",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		220,         // x position 
		130,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'a',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND yButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"y",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		250,         // x position 
		40,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'y',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND øButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"ø",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		250,         // x position 
		70,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)248,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND œButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"œ",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		250,         // x position 
		100,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)339,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND əButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"ə",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		280,         // x position 
		100,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)601,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND uButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"u",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		310,         // x position 
		40,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'u',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND oButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"o",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		310,         // x position 
		70,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)'u',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND ɔButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"ɔ",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		310,         // x position 
		100,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)596,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND ɑButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"ɑ",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		310,         // x position 
		130,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)593,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND nasalButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"~",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		220,         // x position 
		190,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)771,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND spaceButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"_",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		250,         // x position 
		190,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)' ',       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	HWND backButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"<",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		280,         // x position 
		190,         // y position 
		25,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)8,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindowEx failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}
	LPCSTR fontName = new CHAR[11];
	fontName = "KaggluFont";
	HFONT newFont = CreateFontA(20, 9, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, fontName);
	if (newFont != NULL) {
		SendMessage(hWnd, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(output, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(mButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(pButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(bButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(fButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(vButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(nButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(tButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(dButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(sButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(zButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(lButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(vButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(ʃButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(ʒButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(ɲButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(jButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(ɥButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(ŋButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(kButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(gButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(ʁButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(wButton, WM_SETFONT, (WPARAM)newFont, TRUE);

		SendMessage(iButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(eButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(εButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(aButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(yButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(øButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(œButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(əButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(uButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(oButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(ɔButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(ɑButton, WM_SETFONT, (WPARAM)newFont, TRUE);

		SendMessage(nasalButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		SendMessage(spaceButton, WM_SETFONT, (WPARAM)newFont, TRUE);
		//SendMessage(backButton, WM_SETFONT, (WPARAM)newFont, TRUE);
	} else {
		while (TRUE) {

		}
	}
	SetWindowPos(hWnd, NULL, 0, 0, 400, 300, NULL);

	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(
	_In_ HWND   hWnd,
	_In_ UINT   message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {
	//PAINTSTRUCT ps;
	//HDC hdc; 
	//TCHAR greeting[] = _T("wow you are really stupid");


	switch (message)
	{
	case WM_PAINT:
		//hdc = BeginPaint(hWnd, &ps);
		//TextOut(hdc, 5, 5, greeting, _tcslen(greeting));
		//EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) != 0) {
			PostMessage(output, WM_CHAR, LOWORD(wParam), 0);
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}
