#include "Lable.h";

COORD Lable::currPosition = { 2, 2 };
DWORD Lable::currColor = FOREGROUND_GREEN | FOREGROUND_INTENSITY;

Lable::Lable(string txt, COORD pos, DWORD color){

	text = txt;

	console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { 100, FALSE }; // invisibil cursor
	SetConsoleCursorInfo(console, &cci); 

	SetCursorPosition(console, pos);

	GetConsoleScreenBufferInfo(console, &consoleInfo); //info about console	

	SetConsoleTextAttribute(console, color);

	Draw();
}

void Lable::SetCursorPosition(HANDLE h, COORD pos){
	
	if (pos.X > currPosition.X && pos.Y > currPosition.Y)
		setPosition = pos;
	else
		setPosition = currPosition;
	
	GetConsoleScreenBufferInfo(console, &consoleInfo);
	currPosition = consoleInfo.dwCursorPosition;

	SetConsoleCursorPosition(console, setPosition);
}

void Lable::Draw(){
	printf(text.data());
}

Lable::~Lable(){}