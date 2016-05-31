#pragma once
#include <stdio.h>
#include <string>
#include <windows.h>


using namespace std;

class myEvent {

public:
	virtual int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output) = 0;
	virtual int keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD) = 0;


};
