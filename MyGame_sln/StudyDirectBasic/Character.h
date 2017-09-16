#pragma once
#include"InputGame.h"
#include"GameplayObject.h"
#include<iostream>
using namespace std;
#define WIDTH 20
#define HEIGHT 60
#define HEIGHT_DOWN 45
#define PI 3.14f
// danh sách trạng thái nhân vật
enum Status
{
	TURN,
	WALKING,
	CLIMB_UP,
	CLIMB_DOWN,
	CLIMB_UP_ATTACK,
	CLIMB_DOWN_ATTACK,
	SIT_DOWN,
	SIT_DOWN_ATTACK,
	STANDING_ATTACK,
	TAKE_DAMAGE,
	STOP,
	CLIMB_UP_STOP,
	CLIMB_DOWN_STOP
};
class Character: public GameplayObject, public InputGame
{
private: 
	//thuộc tính character
	string FileNameImage[13];
	Status CurentStatus;
	int Direct;
	// các thuộc tính của 1 Frame
	int FrameNumber[13];
	RECT rect;
	int FrameCurent;
	// các thuộc tính hỗ trợ
	bool StatusChange;
	int CurentDelay;
	int DelayMax;
	// thuộc tính kiểm tra attack
	bool isAttack;
	//thuộc tính kiểm tra nhân vật có ở trên cầu thang hay không
	bool isClimb;
	// thuộc tính kiểm tra nhảy
	bool isJum;
	// thuộc tính kiểm tra tốc độ nhảy
	float MaxVelocityJum;
	float VelocityJum;
	// thuộc tính kiểm tra sự va chạm với cầu thang
	bool vPress;
	// các thuộc tính thiết bị input
	HWND Windown;
	HINSTANCE hInstance;
	// phương thức
	void Turn();
	void Walking();
	void ClimbUp();
	void ClimbDown();
	void ClimbUpAttack();
	void ClimbDownAttack();
	void SitDown();
	void SitdownAttack();
	void StandingAttack();
	void TakeDamage();
	void Stop();
	void AfterAttack();
	void Jum();
public:
	// phương thức
	Character();
	Character(float x, float y, float speed, float rotate, HWND hWnd, HINSTANCE hInstance);
	bool Init(LPDIRECT3DDEVICE9 device);
	void Draw(float time);
	void Update(float time);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);
	bool GetPressV();
	// phuong thuc xu ly va cham
	void Colision(GameplayObject *o);
	~Character();


};

