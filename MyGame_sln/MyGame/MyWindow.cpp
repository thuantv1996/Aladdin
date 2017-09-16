#include "MyWindow.h"

// ham tao cua class
MyWindow::MyWindow()
{
}

// khoi tao cua so
bool MyWindow::InitWindown(HINSTANCE hInstance, int nCmdShow)
{
	// create window
	WNDCLASSEX win;
	win.cbSize = sizeof(win);
	win.hInstance = hInstance;
	win.lpfnWndProc = (WNDPROC)MsgProc;
	win.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	win.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	win.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	win.hCursor = LoadCursor(NULL, IDC_ARROW);
	win.lpszClassName = "MyGame";
	win.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	win.cbClsExtra = 0;
	win.cbWndExtra = 0;
	win.lpszMenuName = NULL;
	// register window
	if (!RegisterClassEx(&win))
	{
		return false;
	}
	if (!this->isFullScreen){
		hWnd = CreateWindow("MyGame",
			"My Game",
			WS_OVERLAPPEDWINDOW,
			GetSystemMetrics(SM_CXSCREEN) / 2 - Width / 2,
			GetSystemMetrics(SM_CYSCREEN) / 2 - Height / 2,
			Width,
			Height,
			NULL,
			NULL,
			hInstance,
			(LPVOID*)NULL
			);
	}
	else
	{
		hWnd = CreateWindow("MyGame",
			"My Game",
			WS_OVERLAPPED | WS_POPUP,
			 0,
			 0,
			GetSystemMetrics(SM_CXSCREEN),
			GetSystemMetrics(SM_CYSCREEN),
			NULL,
			NULL,
			hInstance,
			(LPVOID*)NULL
			);
	}
	if (!hWnd)
	{
		return false;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return true;
}

// xu ly thong diep
LRESULT MyWindow::MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_DESTROY:
		{
						   PostQuitMessage(0);
						   return 0;
						   break;
		}	
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

// vong lap game
void MyWindow::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (true)
	{
		while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}	
		if (msg.message == WM_QUIT)
			break;

		// run game in here
		Paint();
	}
}

MyWindow::~MyWindow()
{
}
