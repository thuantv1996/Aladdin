#pragma once
#include<d3d.h>
#include<iostream>
using namespace std;
struct Frame
{
	// các thuộc tính
	int x;// tọa độ x vùng vẽ
	int y;// tọa độ y vùng vẽ
	int width;// chiều rộng vùng vẽ
	int height;// chiều cao vùng vẽ
	RECT padding;// khoảng cách tới nhân vật
	/*
	* Biến padding đại diện cho khoảng cách rìa vùng vẽ tới nhân vật
	* mục đích là đễ vẽ chính xác hơn
	*/
	int TimeDelay;// so lan lap
	/*
	* Bien TimeDelay quy dinh toc do nhanh cham cua chuyen dong
	*/
};
struct ListFrame
{
	int number;
	Frame* frame;
};

