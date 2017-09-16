#include "GameplayObject.h"

GameplayObject::GameplayObject()
{
	sprite = new GameSprite(0, 0);
}

//GameplayObject::GameplayObject(float x, float y, float width, float height, std::string name, float speed, float rotate)
//{
//	this->box.x=x;
//	this->box.y = y;
//	this->box.width = width;
//	this->box.height = height;
//	this->speed = speed;
//	this->rotate = rotate;
//	this->box.vx = speed*cos(rotate);
//	this->box.vy = speed*sin(rotate);
//	this->name = name;
//	sprite = new GameSprite(x,y);
//}

bool GameplayObject::Init(LPDIRECT3DDEVICE9 device)
{
	this->device = device;
	return sprite->Init(this->device, "CharRacTer//AladdinSprite.png", box.width, box.height);
}

void GameplayObject::Update(float time)
{

}

void GameplayObject::Draw(float time)
{
	if (sprite && sprite->isInit())
	{
		sprite->Draw(time,NULL,D3DXVECTOR3(box.x,box.height,0));
	}
}

GameplayObject::~GameplayObject()
{
	if (sprite)
	{
		delete sprite;
	}
}

BOX GameplayObject::getBox(){ return box; }
float GameplayObject::getLeft(){ return box.x; }
float GameplayObject::getRight(){ return box.x + box.width; }
float GameplayObject::getTop(){ return box.y; }
float GameplayObject::getBottom(){ return box.y + box.height; }
void GameplayObject::setRotate(float r){ rotate = r; setSpeed(speed); }
void GameplayObject::setWidth(float w){ box.width = w; }
void GameplayObject::setHeight(float h){ box.height = h; }
void GameplayObject::setPosition(int x, int y)
{
	box.x = x;
	box.y = y;
}
void GameplayObject::setSpeed(float s)
{
	speed = s;
	box.vx = speed*cos(rotate);
	box.vy = speed*sin(rotate);
}
IdObject GameplayObject::getTypeId(){ return TypeId; }
