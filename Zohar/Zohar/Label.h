#pragma once
#include "IControl.h"

using namespace std;

class Label :public IControl
{
protected:
	string str;
public:
	Label(string s, int width);
	~Label();
	void SetValue(string value) { if (value.length()< this->width) str = value; };
	string GetValue() { return str; };
	//Label& GetLable() { return *this; }
	void draw();
};

