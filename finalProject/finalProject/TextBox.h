#pragma once
#include "IControl.h"
class TextBox : public IControl
{
	string value;
public:
	TextBox(int width, string val="");
	void SetText(string value);
	string GetText();
	void SetForeground(Color color);
	void SetBackground(Color color);
	void SetBorder(BorderType border);
	virtual void draw();
	virtual int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	virtual int keyPress(KEY_EVENT_RECORD ker, HANDLE output);
	~TextBox();
};

