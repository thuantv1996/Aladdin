#include "Colision.h"

bool CColision::mColision(GameplayObject obj1, GameplayObject obj2)
{
	return AABBCheck(obj1.getBox(), obj2.getBox());
}

float CColision::mSweptAABB(GameplayObject obj1, GameplayObject obj2, float &normalx, float &normaly)
{
	return SweptAABB(obj1.getBox(), obj2.getBox(), normalx, normaly);
}

CColision::CColision()
{
}


CColision::~CColision()
{
}
