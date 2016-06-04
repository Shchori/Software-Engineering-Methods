#pragma once
#include "IControl.h"
class Label :public IControl
{
protected:
	string str;
public:

	Label(string s, int width);
	~Label();
	void SetValue(string value) {if(value.length()< this->width) str = value; };
	string GetValue(){return str;};
	void draw();
};

