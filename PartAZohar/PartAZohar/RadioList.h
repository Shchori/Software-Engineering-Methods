#pragma once
#include<iostream>

#include <stdio.h>
#include <stdlib.h> 

class RadioList
{
private:
	int _cord1;
	int _cord2;
public:
	RadioList();
	RadioList(int cord1, int cord2) :_cord1(cord1), _cord2(cord2){};
	void PrintClass();
	~RadioList();
};

