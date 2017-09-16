#pragma once
#include"Frame.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class InfoCharacter
{
private:
	ListFrame* lstAladdin;
public:
	InfoCharacter();
	~InfoCharacter();
	void ReadInfo();
	void ReadAladdin();
	ListFrame* GetListAladdin();
};

