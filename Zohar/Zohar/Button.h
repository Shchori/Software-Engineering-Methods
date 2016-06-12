#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include "subMouseListner.h"
#include <windows.h>
#include "IControl.h"
#include "Lable.h"
#include "Graphics.h"
#include "Event.h"





class Button :public Event,public Lable
{
	
public:
	Button(string str, int width);
	~Button();
	void SetValue(string str) { Lable::SetValue(str); }
	void AddListener(MouseListener &listener);
	Button& getInstence() { return *this; }
	void pressCorrect();
	void draw();
	virtual int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output,Lable& lable);
	virtual int keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD);
	//void MouseEventProc(MOUSE_EVENT_RECORD mer, HANDLE h);

};