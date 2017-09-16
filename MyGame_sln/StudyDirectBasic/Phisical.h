#pragma once
#include<math.h>
#include<stdio.h>
#include"box.h"
#include<iostream>

///Phương thức xét va chạm
bool Collision(BOX box_1, BOX box_2)
{
	if (box_1.x > box_2.x + box_2.width)
	{
		return false;
	}
	if (box_1.y > box_2.y + box_2.height)
	{
		return false;
	}
	if (box_2.x > box_1.x + box_1.width)
	{
		return false;
	}
	if (box_2.y > box_1.y + box_1.height)
	{
		return false;
	}
	return true;
}

//Hàm kiểm tra sweptAABB
//hàm trả về thời gian va chạm
float SweptAABB(BOX box1, BOX box2, float &normalx, float &normaly)
{
	float xInvEntry, yInvEntry;// khoảng cách gần nhất
	float xInvExit, yInvExit;// khoảng cách xa nhất
	if (box1.vx > 0.0f)
	{
		xInvEntry = box2.x - (box1.x + box1.width);
		xInvExit = (box2.x + box2.width) - box1.x;
	}
	else
	{
		xInvEntry = (box2.x + box2.width) - box1.x;
		xInvExit = box2.x - (box1.x + box1.width);
	}
	if (box1.vy > 0.0f)
	{
		yInvEntry = box2.y - (box1.y + box1.height);
		yInvExit = (box2.y + box2.height) - box1.y;
	}
	else
	{
		yInvEntry = (box2.y + box2.height) - box1.y;
		yInvExit = box2.y - (box1.y + box1.height);
	}
	//tính thời gian va chạm
	float xEntry, yEntry;
	float xExit, yExit;
	if (box1.vx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();;
	}
	else
	{
		xEntry = xInvEntry / box1.vx;// thời gian bắt đầu va chạm theo x
		xExit = xInvExit / box1.vx;// thời gian kết thức va chạm theo x
	}
	if (box1.vy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();;
	}
	else
	{
		yEntry = yInvEntry / box1.vy;// thời gian bắt đầu va chạm theo y
		yExit = yInvExit / box1.vy;// thời gian kết thức va chạm theo y
	}

	// tính thời gian bắt đầu và kết thúc va chạm
	float entryTime = std::fmax(xEntry, yEntry);
	float exitTime = std::fmin(xExit, yExit);

	// xét có va chạm hay không
	if (entryTime > exitTime || xEntry<0.0f&&yEntry<0.0f || xEntry>1.0f || yEntry>1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}
	else
	{
		if (xEntry > yEntry)
		{
			if (xInvEntry < 0.0f)
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		else
		{
			if (yInvEntry < 0.0f)
			{
				normaly = 1.0f;
				normalx = 0.0f;
			}
			else
			{
				normaly = -1.0f;
				normalx = 0.0f;
			}
		}
		return entryTime;
	}
}

//hàm getSweptBroadphaseBox
// hàm trả về một box được tạo nên từ sự di chuyển của một box khác
BOX getSweptBroadphaseBox(BOX box)
{
	BOX BroadphaseBox;
	BroadphaseBox.x = box.vx > 0 ? box.x : box.x + box.vx;
	BroadphaseBox.y = box.vy > 0 ? box.y : box.y + box.vy;
	BroadphaseBox.width = box.vx > 0 ? box.vx + box.width : box.width - box.vx;
	BroadphaseBox.width = box.vy > 0 ? box.vy + box.height : box.height - box.vy;
	return BroadphaseBox;
}

//hàm AABBCheck
// hàm kiểm tra trong 1 đơn vị thồi gian thì giửa 2 box có xảy ra va chạm hay không
bool AABBCheck(BOX box1, BOX box2)
{
	return Collision(getSweptBroadphaseBox(box1), box2);
}
