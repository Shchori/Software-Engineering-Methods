#pragma once
#include "ConsoleComponent.h"
#include <Windows.h>
#include <stdio.h>
#include <string>

using namespace std;

class ResponseComponent : public ConsolComponent
{
private:
	virtual void print();
public:
	ResponseComponent(const COORD c) :ConsolComponent(c) {};
	virtual bool inArea(COORD c)=0;
	virtual int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	virtual int keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD);
	virtual string getString() { return "h"; };
};
