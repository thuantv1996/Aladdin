#pragma once
#include"GameplayObject.h"
#include"Frame.h"

enum Enemy_1_Status
{
	GO,
	ATTACK,
	TAKE_DAME,
	DIE
};
class Enemy_1 :
	public GameplayObject
{
private:
	string FileNameImage;
	Enemy_1_Status CurentStatus;
	int Direct;
	ListFrame* Status;
	RECT rect;
	D3DXVECTOR3 pDraw;
	int FrameCurent;
	int CurentDelay;
	GameplayObject* Folow;
public:
	Enemy_1();
	Enemy_1(float x, float y, float speed, float rotate, GameplayObject* folow);
	~Enemy_1();
	void InitFrame(ListFrame*);
public :
	bool Init(LPDIRECT3DDEVICE9 device);
	void Draw(float time);
	void Update(float time);
public:
	void Go();
	void Attack();
	void Take_Dame();
	void Die();
};

