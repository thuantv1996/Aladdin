#pragma once
#include<Windows.h>
class GameTime
{
public:
	float curentTime;
	float totalTime;
	bool Init();
	void Update();
	GameTime();
	~GameTime();
private:
	float start;
	float frequency;
};

