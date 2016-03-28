#pragma once
#include <Windows.h>
#include <string>
#include "ConsolComponent.h"
#define FRAME_SIZE 2;
using namespace std; 

class TextBox : public ConsolComponent
{
public:
	TextBox(const int size ,const COORD coord, HANDLE consol, string context);
	bool inArea(COORD c);
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output,COORD);
	~TextBox();
private:
	int size;
	string buffer;
	COORD c;
	HANDLE consol;
	void refresh();
};

