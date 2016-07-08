#pragma once

#include "Panel.h"
#include <Windows.h>
#include "Graphics.h"
#include "IControlResponser.h"

typedef IControl Control;

class EventEngine
{
private:
	void moveFocus(Control &main, Control *focused);
	Graphics _graphics;// output handle
	HANDLE _console;// input handle
	DWORD _consoleMode;//current mode
public:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	void run(Control &c);
	~EventEngine() {};
};