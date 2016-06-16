#pragma once
#include "Label.h"
#include "Event.h"

using namespace std;
class TextBox : public Label, public Event
{
	string value;
	int dataLen;
	int currPosition;
public:
	TextBox(int width);
	void draw();
	void SetValue(string value);
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output);
	~TextBox();
};

