#ifndef GAMESPRITE_H
#define GAMESPRITE_H
#pragma once
#include<d3d9.h>
#include<d3dx9.h>
#include<string>
class GameSprite
{
public:
	// method
	GameSprite(int x,int y);
	~GameSprite();
	bool Init(LPDIRECT3DDEVICE9 device,std::string fileName,int width,int height);
	bool isInit();
	virtual void Draw(float time, RECT *rect, D3DXVECTOR3 position);
	void ReSetTranform();
	void Flip(int w, int h, D3DXVECTOR3 position);
private:
	D3DXVECTOR3 position;
	LPDIRECT3DTEXTURE9 tex;
	LPD3DXSPRITE sprite;
	D3DCOLOR color;
	bool initialized;
	D3DXMATRIX Matrix;
};
#endif

