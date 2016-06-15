#pragma once
#include "IControl.h"
#include <vector>
#include <iostream>
using namespace std;
class TextBox : public IControl
{
	string value;
	int dataLen;
	int currPosition;
public:
	TextBox(int width);
	void SetText(string value);
	string GetText();
	void draw();
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output);
	~TextBox();
};

