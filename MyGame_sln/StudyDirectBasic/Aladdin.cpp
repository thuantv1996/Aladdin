#include "Aladdin.h"



Aladdin::Aladdin()
{
}
Aladdin::Aladdin(float x, float y, float speed, float rotate, HWND hWnd, HINSTANCE Instance)
{
	this->box.x = x;
	this->box.y = y;
	// width, height giả định
	this->box.width = 35;
	this->box.height = 50;
	this->speed = speed;
	this->rotate = rotate;
	sprite = new GameSprite((int)x, (int)y);
	// direct =0 (phải) direct=1(trải)
	CurentStatus = CHO_1;
	CurentDelay = 0;
	FrameCurent = 0;
	Direct = 0;
	Windown = hWnd;
	hInstance = Instance;
	InitKeyboard(hInstance, Windown);
}
Aladdin::~Aladdin()
{
}
void Aladdin::InitFrame(ListFrame* lstAladdin)
{
	Status = lstAladdin;
}

bool Aladdin::Init(LPDIRECT3DDEVICE9 device)
{
	this->device = device;
	this->FileNameImage = "Src//Aladdin//Aladdin.png";
	sprite->Init(device, FileNameImage, 2242, 5436);
	return true;
}
void Aladdin::Update(float time)
{
	if (++CurentDelay >= Status[CurentStatus].frame[FrameCurent].TimeDelay)
	{
		if (++FrameCurent >= Status[CurentStatus].number)
		{
			FrameCurent = 0;
		}
		CurentDelay = 0;
	}
	// lấy vùng vẽ
	rect.top = Status[CurentStatus].frame[FrameCurent].y;
	rect.left = Status[CurentStatus].frame[FrameCurent].x;
	rect.right = Status[CurentStatus].frame[FrameCurent].x+ Status[CurentStatus].frame[FrameCurent].width;
	rect.bottom = Status[CurentStatus].frame[FrameCurent].y+ Status[CurentStatus].frame[FrameCurent].height;
	// lấy vị trí vẽ
	pDraw.x = box.x - Status[CurentStatus].frame[FrameCurent].padding.left;
	pDraw.y = box.y - Status[CurentStatus].frame[FrameCurent].padding.top;
	pDraw.z = 0;
}
void Aladdin::Draw(float time) 
{
	sprite->Draw(time, &rect, pDraw);
}

void Aladdin::Cho_1()
{
	CurentStatus = CHO_1;
}
void Aladdin::Cho_2()
{
	CurentStatus = CHO_2;
}
void Aladdin::Cho_3()
{
	CurentStatus = CHO_3;
}
