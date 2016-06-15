#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>
#include "IControl.h"
#include "Label.h"
#include "Graphics.h"
#include "Event.h"

class Button;

struct MouseListener
{
	virtual void MousePressed(Button &b, int x, int y, bool isLeft) = 0;
};




class Button :public Label
{
protected:
	MouseListener *event;

private:
	bool pressed;
public:
	Button(string str, int width);
	~Button();
	void AddListener(MouseListener &listener);
	void draw();
	virtual int mouseEvent(int x, int y);
	virtual int keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD);
	//void MouseEventProc(MOUSE_EVENT_RECORD mer, HANDLE h);

};