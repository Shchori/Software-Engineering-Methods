#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
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
	virtual int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	virtual int keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD);


};