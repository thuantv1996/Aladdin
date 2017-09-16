﻿#include "GameTime.h"


GameTime::GameTime()
{
}

bool GameTime::Init()
{
	LARGE_INTEGER i;
	// lấy tần số. Tần số hệ thống là không đổi.
	if (!QueryPerformanceFrequency(&i))
	{
		return false;
	}
	this->frequency = (float)(i.QuadPart);
	this->curentTime = 0;
	this->totalTime = 0;
	//lấy số lần đếm
	QueryPerformanceCounter(&i);
	this->start = (float)(i.QuadPart);
}

void GameTime::Update()
{
	LARGE_INTEGER i;
	QueryPerformanceCounter(&i);
	curentTime = ((float)(i.QuadPart)-start)/frequency;
	totalTime += curentTime;
	start = (float)(i.QuadPart);

}

GameTime::~GameTime()
{
}
