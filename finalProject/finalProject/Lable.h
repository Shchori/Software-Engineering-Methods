#pragma once
#include "IControl.h"
class Lable :public IControl
{
protected:
	string str;
public:

	Lable(string s, int width);
	~Lable();
	void SetValue(string value) {if(value.length()< this->width) str = value; };
	string GetValue(){return str;};
	void draw();
};

