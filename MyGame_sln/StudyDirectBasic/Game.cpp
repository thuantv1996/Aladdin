#include "Game.h"
Game::Game()
{
	Graphics = new GraphicsDevice;
	Time = new GameTime;
	
}

bool Game::Init(HWND hWnd, HINSTANCE instance)
{
	windown = hWnd;
	hInstance = instance;
	info_character.ReadInfo();
	o = new Aladdin(100,100,100,100,this->windown,this->hInstance);
	// initialize Graphics
	if (!Graphics->Init(hWnd, true))
	{
		return false;
	}
	camera = new Camera();
	camera->createCamera(Graphics,800,600, 0, 10);
	o->Init(Graphics->device);
	o->InitFrame(info_character.GetListAladdin());
	if (!Time->Init())
	{
		return false;
	}
	p.x = 400;
	p.y = 300;
	return true;

}

void Game::Run()
{
	Time->Update();
	Update(Time->curentTime);
	Draw(Time->curentTime);
}

void Game::Update(float time)
{
	o->Update(time);
	/*if (GetAsyncKeyState(VK_RIGHT))
	{
		p.x += 3;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		p.x -= 3;
	}*/
	
}

void Game::Draw(float time)
{
	Graphics->Clear(D3DCOLOR_XRGB(0, 0, 255));
	Graphics->Begin();
	if (camera)
	{

		camera->pointCamera(Graphics, D3DXVECTOR3(p.x, p.y, -1), D3DXVECTOR3(p.x, p.y, 0));

	}
	if (o)
	{
		o->Draw(time);
	}
	Graphics->End();
	Graphics->Present();
}

Game::~Game()
{
	if (o)
	{
		delete o;
		o = nullptr;
	}
	if (Graphics)
	{
		delete Graphics;
		Graphics = nullptr;
	}
	if (camera)
	{
		delete camera;
		camera = nullptr;
	}
	if (Time)
	{
		delete Time;
		Time = nullptr;
	}
}
