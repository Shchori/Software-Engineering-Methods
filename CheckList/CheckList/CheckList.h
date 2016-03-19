#pragma once
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string>

using namespace std;

class CheckList
{
	HANDLE h;
	short x; 
	short y;

public:
	CheckList(short x, short y);
	void setConsoleCoor(short x , short y);
	void setCheckList(string text);
	~CheckList();
};

