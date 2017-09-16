#pragma once
#include<iostream>
using namespace std;
#include<d3d9.h>
#include"MyWindow.h"
#include"MyGraphics.h"
class MyDirect : public MyWindow
{
private:
	//Con tro doi tuong direct
	LPDIRECT3D9 d3d;
	/*con tro doi tuong directDivice de luu tru cac thong tin ve phan cung
	  nhu: Man hinh, card do hoa, vv... */ 
	LPDIRECT3DDEVICE9 d3ddv;
	//doi tuong graphics
	MyGraphics graphics;

public:
	void InitD3D(HWND);
	void Render_frame();
	void CleanD3D();
	void Paint();
	MyDirect();
	~MyDirect();
};

