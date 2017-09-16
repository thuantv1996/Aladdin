#include "Enemy_1.h"



Enemy_1::Enemy_1()
{
}
Enemy_1::~Enemy_1()
{
	if (this->Folow != nullptr)
	{
		free(this->Folow);
		this->Folow = nullptr;
	}
	if (Status != nullptr)
	{
		free(Status);
		Status = nullptr;
	}
}

Enemy_1::Enemy_1(float x, float y, float speed, float rotate, GameplayObject* folow)
{
	this->box.x = x;
	this->box.y = y;
	this->speed = speed;
	this->rotate = rotate;
	this->Folow = folow;
}
void Enemy_1::InitFrame(ListFrame* lstFrame)
{
	Status = lstFrame;
}

bool Enemy_1::Init(LPDIRECT3DDEVICE9 device)
{
	this->device = device;
	this->FileNameImage = "Src//Transparent//Enemy.png";
	sprite->Init(device, FileNameImage, 498*2, 1053*2);
	return true;
}
void Enemy_1::Draw(float time)
{
	sprite->Draw(time, &rect, pDraw);
}
void Enemy_1::Update(float time)
{
	// xét folow
	if (Folow)
	{
		if (Folow->getRight() <= this->getRight())
		{
			this->Direct = -1;//di chuyen sang trái
			if (this->getRight() - Folow->getRight()<=100 && CurentStatus!=TAKE_DAME)// nếu cách nhau không quá 100px thì tấn công
			{
				Attack();
			}
		}else
		if (Folow->getLeft() >= this->getLeft())
		{
			this->Direct = 1;//di chuyen sang Phải
			if (Folow->getLeft()- this->getLeft() <= 100 && CurentStatus != TAKE_DAME)// nếu cách nhau không quá 100px thì tấn công
			{
				Attack();
			}
		}
	}
	// cap nhap thong tin
	box.vx *= Direct;
	box.x += box.vx*time;
	// lay frame
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
	rect.right = Status[CurentStatus].frame[FrameCurent].x + Status[CurentStatus].frame[FrameCurent].width;
	rect.bottom = Status[CurentStatus].frame[FrameCurent].y + Status[CurentStatus].frame[FrameCurent].height;
	// lấy vị trí vẽ
	pDraw.x = box.x - Status[CurentStatus].frame[FrameCurent].padding.left;
	pDraw.y = box.y - Status[CurentStatus].frame[FrameCurent].padding.top;
	pDraw.z = 0;
}

void Enemy_1::Go()
{
	this->CurentStatus = GO;
}
void Enemy_1::Attack()
{
	this->CurentStatus = ATTACK;
}
void Enemy_1::Take_Dame()
{
	this->CurentStatus = TAKE_DAME;
}
void Enemy_1::Die()
{
	this->CurentStatus = DIE;
}