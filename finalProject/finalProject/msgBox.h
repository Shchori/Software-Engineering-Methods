#pragma once
#include "Panel.h"
#include "Button.h"
#include "Label.h"

class MsgBox: public Panel
{
	vector<Button> btns;
	Label text;
public:
	MsgBox(int height, int width);
	void setText(string text);
	string getText();
	void draw();
	~MsgBox();
};

