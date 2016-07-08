#pragma once
#include "IControl.h"
class Label :public IControl
{
protected:
	string str;
public:
	Label(int width, string str="");
	virtual void setValue(string value) {if(value.length()<= this->width) str = value; };
	string GetValue(){return str;};
	void draw();
	~Label();
};

