#pragma once
#include <windows.h>

class ConsolComponent
{
public:
	virtual bool inArea(COORD c) { return 0; };
	virtual int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output) { return 0; };
	virtual int keyPress(KEY_EVENT_RECORD ker, HANDLE output,COORD c) = 0 ;
};
