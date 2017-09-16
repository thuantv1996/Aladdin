#include "GameSprite.h"


GameSprite::GameSprite(int x,int y)
{
	position.x = x;
	position.y = y;
	color = D3DCOLOR_ARGB(255, 255, 255, 255);
	initialized = false;
}

GameSprite::~GameSprite()
{
	if (sprite)
	{
		sprite->Release();
		sprite = NULL;
	}
	if (tex)
	{
		tex->Release();
		tex = NULL;
	}
}

bool GameSprite::Init(LPDIRECT3DDEVICE9 device, std::string fileName, int width, int height)
{
	D3DXIMAGE_INFO info;
	HRESULT h = D3DXGetImageInfoFromFile(fileName.c_str(), &info);
	if (!SUCCEEDED(D3DXCreateTextureFromFileEx(device, fileName.c_str(), width, height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, NULL, &tex)))
	{
		MessageBox(NULL, "Tạo texture lỗi! Xem lại fileName!", "Lỗi!", MB_OK);
		return false;
	}
	if (!SUCCEEDED(D3DXCreateSprite(device, &sprite)))
	{
		MessageBox(NULL, "Tạo sprite lỗi! Xem lại fileName!",NULL, MB_OK);
		return false;
	}
	Matrix._11 = position.x;
	Matrix._22 = position.y;
	Matrix._33 = 0;
	initialized = true;
	return true;
}

bool GameSprite::isInit()
{
	return initialized;
}

void GameSprite::Draw(float time,RECT *rect,D3DXVECTOR3 position)
{
	this->position.x = position.x;
	this->position.y = position.y;
	if (sprite && tex)
	{
		sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
		sprite->Draw(tex, rect, NULL, &position, color);
		sprite->End();

	}
}
void GameSprite::ReSetTranform()
{
	sprite->SetTransform(&Matrix);
}
void GameSprite::Flip(int w, int h, D3DXVECTOR3 position)
{
	/*Cách 1: tự định nghĩa ma trận*/
	
	// lấy ra tọa độ của sprite
	sprite->GetTransform(&Matrix);
	D3DXMATRIX MatrixFlip;
	// tạo ma trận đơn vị
	D3DXMatrixIdentity(&MatrixFlip);
	// lật quanh trục y
	MatrixFlip._11 = -1;
	// di chuyển về một lượng bằng gấp đôi khoảng cách từ tâm 
	MatrixFlip._41 = (position.x + w / 2) * 2;
	sprite->SetTransform(&(Matrix*MatrixFlip));
	
	/*Cách 2 direct hổ trợ ma trận*/
	/*
	D3DXMATRIX MatrixFlip;
	D3DXMatrixRotationY(&MatrixFlip, D3DX_PI);
	D3DXMATRIX MatrixTranslate;
	D3DXMatrixTranslation(&MatrixTranslate, (position.x + w / 2) * 2, 0, 0);
	sprite->SetTransform(&(MatrixFlip*MatrixTranslate));
	*/
}