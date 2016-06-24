#pragma once
#include "IControl.h"
#include <vector>
#include <iostream>
using namespace std;
class TextBox : public IControl
{
	vector<char> value;
	int dataLen;
	int currPosition;
public:
	TextBox(int width);
	void SetText(char value);
	string GetText();
	virtual void draw();
	virtual int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	virtual int keyPress(KEY_EVENT_RECORD ker, HANDLE output);
	~TextBox();
};