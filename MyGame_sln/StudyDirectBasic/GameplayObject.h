#pragma once
#include"GameSprite.h"
#include"InputGame.h"
#include <cmath>
#include"box.h"

#define M_PI 3.1415926535897932384626433832795

enum IdObject{
	CHARACTER,
	CLIMB
};

class GameplayObject
{
//Methods
public:
	GameplayObject();
	virtual bool Init(LPDIRECT3DDEVICE9 device);
	virtual void Update(float time);
	virtual void Draw(float time);
	~GameplayObject();
// Attributes
protected:
	IdObject TypeId;//TypeId Object
	LPDIRECT3DDEVICE9 device;
	BOX box;// Hộp xét va chạm
	GameSprite *sprite;// hình ảnh
	float speed;// vận tốc
	float rotate;// độ xoay
public:
	BOX getBox();
	float getLeft();
	float getRight();
	float getTop();
	float getBottom();
	void setSpeed(float s);
	void setRotate(float r);
	void setPosition(int x, int y);
	void setWidth(float w);
	void setHeight(float h);
	IdObject getTypeId();
};

