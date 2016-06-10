#pragma once
#include"Lable.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>
#include "button.h"



class NumericBox
{
public:
	NumericBox(int width,int min,int max, int b_width,int lable_width,COORD c):b_plus("+" ,b_width),b_minus("-",b_width),lable(to_string(min),b_width),coord(c){
		COORD tmp;
		b_plus.setCoord(c);
		tmp = { c.X + lable_width,c.Y };
		lable.setCoord(tmp);
		tmp = { tmp.X + b_width,c.Y};
		b_minus.setCoord(tmp);
	}
	
	~NumericBox();
	void draw();
private:
	Button b_plus;
	Button b_minus;
	Lable lable;
	COORD coord;
};

