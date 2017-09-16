#pragma once
#include"Phisical.h"
#include "GameplayObject.h"
class CColision
{
public:
	static bool mColision(GameplayObject obj1, GameplayObject obj2);
	static float mSweptAABB(GameplayObject obj1, GameplayObject obj2, float &normalx, float &normaly);
	CColision();
	~CColision();
};

