#pragma once
#include "ConsoleComponent.h"
#include <Windows.h>
#include <stdio.h>
#include <string>


using namespace std;

class Lable : public ConsolComponent {

private:

	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	string text;

public:

	Lable(string txt, COORD pos = currPosition, DWORD color = currColor);
	~Lable();
	void SetCursorPosition(HANDLE h, COORD pos);
	void Draw();
	virtual inline string getString() { return text; };

	static COORD currPosition; // if we'll want to add runtime lable - in the future
	static DWORD currColor;
};

