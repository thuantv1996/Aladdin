#pragma once
#pragma once
#include<Windows.h>
#include <iostream>
using namespace std;
class MyWindow
{
	//property
protected:
	int Width;
	int Height;
	bool isFullScreen;
public:
	HWND hWnd;
	void setWidth(int width)
	{
		this->Width = width;
	}
	void setHeight(int height)
	{
		this->Height = height;
	}
	void setIsFullScreen(bool p)
	{
		this->isFullScreen = p;
	}
	//method
public:
	//method initialization windows
	bool InitWindown(HINSTANCE hInstance, int nCmdShow);
	static LRESULT CALLBACK MsgProc(HWND ,UINT ,WPARAM ,LPARAM );
	void Run();
	virtual void Paint()=0;
	MyWindow();
	~MyWindow();
};


