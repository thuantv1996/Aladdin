#include "MyDirect.h"


MyDirect::MyDirect()
{
	d3d = NULL;
	d3ddv = NULL;
}

void MyDirect::InitD3D(HWND hWnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);// khoi tao doi tuong
	D3DPRESENT_PARAMETERS paramester;// chua thong tin thiet bi
	ZeroMemory(&paramester, sizeof(D3DPRESENT_PARAMETERS));//lam sach bo nho cua doi tuong
	if (!isFullScreen)
	{
		paramester.Windowed = TRUE;//cua so khong phai fullscreen
	}
	else
	{
		paramester.Windowed = FALSE;
	}
	paramester.SwapEffect = D3DSWAPEFFECT_DISCARD;
	paramester.hDeviceWindow = hWnd;//chi dinh cua so su dung
	paramester.BackBufferHeight = this->Height;
	paramester.BackBufferWidth = this->Width;
	d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &paramester, &d3ddv);

	graphics.init_Graphit(this->d3ddv);
}

//Phuong thuc ve mot frame
void MyDirect::Render_frame()
{
	d3ddv->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(1, 0, 0, 0), 1.0f, 0);
	d3ddv->BeginScene();
	// begin render
	graphics.Draw(this->d3ddv);
	//end render
	d3ddv->EndScene();
	//render 
	d3ddv->Present(NULL, NULL, NULL, NULL);
}

void MyDirect::CleanD3D()
{
	this->d3ddv->Release();
	this->d3d->Release();
}

void MyDirect::Paint(){
	this->Render_frame();
}

MyDirect::~MyDirect()
{
}
