#include "Lable.h";

COORD Lable::currPosition = { 2, 2 };
DWORD Lable::currColor = FOREGROUND_GREEN | FOREGROUND_INTENSITY;

Lable::Lable(string txt, COORD pos, DWORD color) :ConsolComponent(pos) {

	text = txt;

	CONSOLE_CURSOR_INFO cci = { 100, FALSE }; // invisibil cursor
	SetConsoleCursorInfo(GetConsole(), &cci);

	SetCursorPosition(GetConsole(), pos);

	GetConsoleScreenBufferInfo(GetConsole(), &consoleInfo); //info about console	

	SetConsoleTextAttribute(GetConsole(), color);

	Draw();
}

void Lable::SetCursorPosition(HANDLE h, COORD pos) {

	if (pos.X > currPosition.X && pos.Y > currPosition.Y)
		SetCoord(pos);
	else
		SetCoord(pos);

	GetConsoleScreenBufferInfo(GetConsole(), &consoleInfo);
	currPosition = consoleInfo.dwCursorPosition;

	SetConsoleCursorPosition(GetConsole(), GetCoord());
}

void Lable::Draw() {
	printf(text.data());
}

Lable::~Lable() {}