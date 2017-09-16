#pragma once
#include"GameplayObject.h"
#include"InputGame.h"
#include"Frame.h"
#include<iostream>
using namespace std;
enum AladdinStatus
{
	CHO_1,
	CHO_2,
	CHO_3

};
class Aladdin:GameplayObject, public InputGame
{
	//thuộc tính character
	string FileNameImage;
	AladdinStatus CurentStatus;
	int Direct;
	// danh sách frame cho từng trạng thái
	ListFrame* Status;
	// vùng vẽ
	RECT rect;
	//vị trí vẽ
	D3DXVECTOR3 pDraw;
	// frame hiện tại
	int FrameCurent;
	// các thuộc tính hỗ trợ
	int CurentDelay;

	
	HWND Windown;
	HINSTANCE hInstance;
public:
	Aladdin();
	Aladdin(float x, float y, float speed, float rotate, HWND hWnd, HINSTANCE hInstance);
	void InitFrame(ListFrame*);
	~Aladdin();

	bool Init(LPDIRECT3DDEVICE9 device);
	void Draw(float time);
	void Update(float time);

	void Cho_1();
	void Cho_2();
	void Cho_3();
};

