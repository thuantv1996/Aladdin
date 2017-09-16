#include "MyDirect.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MyDirect direct;

	direct.setWidth(800);
	direct.setHeight(600);
	direct.setIsFullScreen(true);
	direct.InitWindown(hInstance, nCmdShow);
	direct.InitD3D(direct.hWnd);
	direct.Run();

	return 1;
}