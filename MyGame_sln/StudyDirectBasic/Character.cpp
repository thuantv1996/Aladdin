#pragma once
#include "Character.h"

Character::Character()
{
}

Character::Character(float x, float y, float speed, float rotate,HWND hWnd,HINSTANCE Instance)
{
	TypeId = CHARACTER;
	this->box.x = x;
	this->box.y = y;
	this->box.width = WIDTH;
	this->box.height = HEIGHT;
	this->speed = speed;
	this->rotate = rotate;
	/*this->box.vx = speed*cos(rotate);
	this->box.vy = speed*sin(rotate);*/
	sprite = new GameSprite((int)x,(int) y);
	StatusChange = true;
	DelayMax = 10;
	CurentStatus = CLIMB_UP;
	Direct = 0;
	isAttack = false;
	isClimb = false;
	isJum = false;
	MaxVelocityJum = 11.0f;
	Windown = hWnd;
	hInstance = Instance;
	InitKeyboard(hInstance, Windown);
}

bool Character::Init(LPDIRECT3DDEVICE9 device)
{
		this->device = device;
		FileNameImage[0] = "CharRacTer//_turn_back.png";
		FileNameImage[1] = "CharRacTer//_walking.png";
		FileNameImage[2] = "CharRacTer//_climb_up.png";
		FileNameImage[3] = "CharRacTer//_climb_down.png";
		FileNameImage[4] = "CharRacTer//_climb_up_attack.png";
		FileNameImage[5] = "CharRacTer//_climb_down_attack.png";
		FileNameImage[6] = "CharRacTer//_sit_down.png";
		FileNameImage[7] = "CharRacTer//_sit_down_attack.png";
		FileNameImage[8] = "CharRacTer//_standing_attack.png";
		FileNameImage[9] = "CharRacTer//_take_damage.png";
		FileNameImage[10] = "CharRacTer//_walking.png";
		FileNameImage[11] = "CharRacTer//_climb_up.png";
		FileNameImage[12] = "CharRacTer//_climb_down.png";
		FrameNumber[0] = 1;
		FrameNumber[1] = 4;
		FrameNumber[2] = 2;
		FrameNumber[3] = 2;
		FrameNumber[4] = 3;
		FrameNumber[5] = 3;
		FrameNumber[6] = 1;
		FrameNumber[7] = 3;
		FrameNumber[8] = 3;
		FrameNumber[9] = 1;
		FrameNumber[10] = 1;
		FrameNumber[11] = 1;
		FrameNumber[12] = 1;
		Stop();
		FrameCurent = 0;
		CurentDelay = 0;
		return true;
}

void Character::Turn()
{
	// viết đoạn mã chuyễn trạng thái

	StatusChange = false;
	CurentStatus = TURN;
	sprite->Init(device, FileNameImage[CurentStatus], 60, 66);
	box.height = HEIGHT;
}
void Character::Walking()
{
	// viết đoạn mã chuyễn trạng thái
	StatusChange = false;
	CurentStatus = WALKING;
	sprite->Init(device, FileNameImage[CurentStatus], 240, 132);
	box.height = HEIGHT;
}
void Character::ClimbUp()
{
	// viết đoạn mã chuyễn trạng thái
	StatusChange = false;
	CurentStatus = CLIMB_UP;
	sprite->Init(device, FileNameImage[CurentStatus], 120, 132);
	box.height = HEIGHT;
}
void Character::ClimbDown()
{
	// viết đoạn mã chuyễn trạng thái
	StatusChange = false;
	CurentStatus = CLIMB_DOWN;
	sprite->Init(device, FileNameImage[CurentStatus], 120, 132);
	box.height = HEIGHT;
}
void Character::ClimbUpAttack()
{
	// viết đoạn mã chuyễn trạng thái
	StatusChange = false;
	CurentStatus = CLIMB_UP_ATTACK;
	sprite->Init(device, FileNameImage[CurentStatus], 180, 132);
	box.height = HEIGHT;
}
void Character::ClimbDownAttack()
{
	// viết đoạn mã chuyễn trạng thái
	StatusChange = false;
	CurentStatus = CLIMB_DOWN_ATTACK;
	sprite->Init(device, FileNameImage[CurentStatus], 180, 132);
	box.height = HEIGHT;
}
void Character::SitDown()
{
	// viết đoạn mã chuyễn trạng thái
	StatusChange = false;
	CurentStatus = SIT_DOWN;
	sprite->Init(device, FileNameImage[CurentStatus], 60, 132);
	box.height = HEIGHT_DOWN;
}
void Character::SitdownAttack()
{
	// viết đoạn mã chuyễn trạng thái
	StatusChange = false;
	CurentStatus = SIT_DOWN_ATTACK;
	sprite->Init(device, FileNameImage[CurentStatus], 180, 132);
	box.height = HEIGHT_DOWN;
}
void Character::StandingAttack()
{
	// viết đoạn mã chuyễn trạng thái
	StatusChange = false;
	CurentStatus = STANDING_ATTACK;
	sprite->Init(device, FileNameImage[CurentStatus], 180, 132);
	box.height = HEIGHT;
}
void Character::TakeDamage()
{
	// viết đoạn mã chuyễn trạng thái
	StatusChange = false;
	CurentStatus = TAKE_DAMAGE;
	sprite->Init(device, FileNameImage[CurentStatus], 60, 132);
	box.height = HEIGHT;
}
void Character::Stop()
{
	if (isClimb && Direct == 0)
	{
		StatusChange = false;
		CurentStatus = CLIMB_DOWN_STOP;
		sprite->Init(device, FileNameImage[CurentStatus], 120, 132);
		box.height = HEIGHT;
		box.vx = 0;
		box.vy = 0;
		return;
	}
	if (isClimb && Direct==1)
	{
		StatusChange = false;
		CurentStatus = CLIMB_UP_STOP;
		sprite->Init(device, FileNameImage[CurentStatus], 120, 132);
		box.height = HEIGHT;
		box.vx = 0;
		box.vy = 0;
		return;
	}
	StatusChange = false;
	CurentStatus = STOP;
	sprite->Init(device, FileNameImage[CurentStatus], 240, 132);
	box.height = HEIGHT;
	box.vx = 0;
	box.vy = 0;
	return;

}
void Character::AfterAttack()
{
	if (CurentStatus == SIT_DOWN_ATTACK)
	{
		SitDown();
	}
	else
		Stop();
}
void Character::Jum()
{
	SitDown();
}

bool Character::GetPressV()
{
	return vPress;
}

void Character::Update(float time)
{
	// thực hiện update vị trí
	/*Xét trường hợp nhảy*/
	if (isJum)
	{
		// nếu đang nhảy lên
		if (box.vy < 0)
		{
			VelocityJum += 0.5f;
			box.vy = VelocityJum - MaxVelocityJum;
		}
		// nếu đang rơi
		if (box.vy >= 0)
		{
			VelocityJum -= 0.5;
			box.vy =MaxVelocityJum- VelocityJum;
		}
		// xử lý va chạm với gạch hoặc cầu thang
		if (box.y > 300)
		{
			Stop();
			box.y = 300;
			isJum = false;
		}
		
	}
	box.x += box.vx;
	box.y += box.vy;
	// thực hiện update frame
	if (++CurentDelay >= DelayMax)
	{
		if (++FrameCurent >= FrameNumber[CurentStatus])
		{
			// khi đang tấn công
			if (isAttack)
			{
				isAttack = false;
				AfterAttack();
			}	
			FrameCurent = 0;
		}
		CurentDelay = 0;
	}
	// Lấy vùng vẽ
	rect.left = 60 * FrameCurent;
	rect.top = 0;
	rect.right = rect.left + 60;
	rect.bottom = rect.top + 66;
	//if (Direct == 1)// left
	//{
	//	rect.top = 66;
	//	rect.bottom = 132;
	//}
}

void Character::Draw(float time)
{
	Update(time);

	if (sprite && sprite->isInit())
	{

		if (CurentStatus == SIT_DOWN || CurentStatus == SIT_DOWN_ATTACK)
		{
			if (Direct == 1)
			{
				sprite->Flip(60, 66, D3DXVECTOR3(box.x - 20, box.y, 0));
				sprite->Draw(time, &rect, D3DXVECTOR3(box.x - 20, box.y, 0));
				sprite->ReSetTranform();
			}
			else
				sprite->Draw(time, &rect, D3DXVECTOR3(box.x - 20, box.y, 0));
		}
		else
		{

			if (Direct == 1)
			{
				sprite->Flip(60, 66, D3DXVECTOR3(box.x - 20, box.y, 0));
				sprite->Draw(time, &rect, D3DXVECTOR3(box.x - 20, box.y, 0));
				sprite->ReSetTranform();
			}
			else
				sprite->Draw(time, &rect, D3DXVECTOR3(box.x - 20, box.y, 0));
		}

	}
}

void Character::OnKeyDown(int KeyCode)
{
	switch (KeyCode)
	{
	case DIK_LEFT:
		// nếu đang tấn công thì bỏ qua
		if (isAttack)
		{
			break;
			return;
		}
		//chuyển hướng sang trái
		Direct = 0;
		// nếu đang đứng yên thì cho di chuyển
		if (CurentStatus == STOP)
		{
			box.vx = -speed*cos(0);
			Walking();
		}
		// nếu đang leo cầu thang thì cho di chuyển xuống
		if (CurentStatus == CLIMB_DOWN_STOP || CurentStatus == CLIMB_UP_STOP)
		{
			box.vx = -speed*cos(PI / 4);
			box.vy = speed*sin(PI / 4);
			ClimbDown();
		}
		break;
	case DIK_RIGHT:
		// nếu đang tấn công thì bỏ qua
		if (isAttack)
		{
			break;
			return;
		}
		//chuyển hướng sang phải
		Direct = 1;
		// nếu đang đứng yên thì cho di chuyển
		if (CurentStatus == STOP)
		{
			box.vx = speed*cos(0);
			Walking();
		}
		// nếu đang leo cầu thang thì cho di chuyển lên
		if (CurentStatus == CLIMB_DOWN_STOP || CurentStatus == CLIMB_UP_STOP)
		{
			box.vx = speed*cos(PI / 4);
			box.vy = -speed*sin(PI / 4);
			ClimbUp();
		}
		break;
	case DIK_DOWN:
		if (isAttack || isJum || isClimb)
		{
			break;
			return;
		}
		SitDown();
		break;
	case DIK_UP:
		if (isAttack || isJum || isClimb)
		{
			break;
			return;
		}
		Jum();
		box.vy = -0.1f;
		VelocityJum = 0;
		isJum = true;
		break;
	case DIK_SPACE:
		// nếu đang trên cầu thang và hướng sang trái
		if (isClimb && Direct == 0)
		{
			ClimbDownAttack();
		}
		else
		// nếu đang trên cầu thang và hướng sang phải
		if (isClimb && Direct == 1)
		{
			ClimbUpAttack();
		}
		else
		// nếu đang ngồi
		if (CurentStatus == SIT_DOWN)
		{
			SitdownAttack();
		}
		else
		// nếu đang đứng
		{
			StandingAttack();
		}
		box.vx = 0;
		isAttack = true;
		break;
	case DIK_V:
		if (isAttack || isJum || isClimb)
		{
			break; 
			return;
		}
		// nếu nhấn v thì vPress = true
		vPress = true;
		/* Nếu như xảy ra va chạm với cầu thang lên hoặc xuống
		mà lúc đó isClimb=false và vPress=true thì cho lên hoặc xuống cầu thang
		nếu isClimb=true mà xảy ra va chạm với cầu thang xuống hoặc lên thì cho is Climb=false;
		*/
		
		break;

	}
}

void Character::OnKeyUp(int KeyCode)
{
	switch (KeyCode)
	{
	case DIK_LEFT:
		Stop();
		break;
	case DIK_RIGHT:
		Stop();
		break;
	case DIK_DOWN:
		Stop();
		break;
	case DIK_SPACE:
		if (isAttack)
		{
			break;
			return;
		}
		AfterAttack();
		break;
	case DIK_V:
		vPress = false;
	}
}

void Character::Colision(GameplayObject *o)
{
}

Character::~Character()
{
}
