#pragma once
#include<Windows.h>
#include"GraphicsDevice.h"
#include"GameTime.h"
#include"Camera.h"
#include"Aladdin.h"
#include"box.h"
#include"InfoCharacter.h"
class Game
{
private:
	HWND windown;
	HINSTANCE hInstance;
public:
	Game();
	~Game();
	bool Init(HWND hWnd, HINSTANCE instance);
	void Run();
	void Update(float time);
	void Draw(float time);
public:
	InfoCharacter info_character;
	//list player
	 Aladdin *o;
	//list monter
	//device
	GraphicsDevice *Graphics;
	//time
	GameTime *Time;
	//camera
	Camera *camera;

	D3DXVECTOR2 p;

	
};

