#include "ComboBox.h"
#include <cstdio>
#include <string>
using namespace std;

# include <stdio.h>



ComboBox::ComboBox(const int size, const COORD coord, string context[]) : ResponseComponentCompositor(coord), size(size)
{
	this->buffer = context;
	this->_mark = 1;
	COORD temp = coord;
	this->length = 0;
	for (int i = 0; i < size; ++i) {
		if (this->length < context[i].length()) this->length = context[i].length();
	}
	this->_mark = 0;
	this->current = 0;
	print();
}
bool beetween(int p, int x1, int x2) {
	return (p >= x1&&p <= x2);
}
bool ComboBox::inArea(COORD c)
{
	int x = GetCoord().X, y = GetCoord().Y;
	return beetween(c.X, x, x + this->length + 2) && beetween(c.Y, y, y + size + 4);
}

int ComboBox::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output)
{
	COORD c = mer.dwMousePosition;
	if (inArea(c)) {
		if (beetween(c.X, GetCoord().Y, GetCoord().Y + 3)) {
			this->current = 1;
		}
		else {
			this->current = c.Y - GetCoord().Y - 3;
			_mark = current;
		}
		this->print();
	}
	return 0;
}

int ComboBox::keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD c)
{
	int pos = c.X - (GetCoord().X + 1);
	COORD temp = c;
	switch (ker.wVirtualKeyCode) {
	case VK_UP:
		if (current > 0) this->_mark -= 1;
		print();
		break;
	case VK_DOWN:
		if (current < this->size) this->_mark += 1;
		print();
		break;
	case VK_RETURN:
		this->current = _mark;
		print();
		break;
	}
	return 0;

}


void ComboBox::print() {
	COORD temp = GetCoord();
	SetConsoleCursorPosition(GetConsole(), temp);
	DWORD wAttr = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(GetConsole(), wAttr);
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	GetConsoleScreenBufferInfo(GetConsole(), &cbi);
	DWORD wAttr2 = cbi.wAttributes | BACKGROUND_RED;
	SetConsoleTextAttribute(GetConsole(), wAttr2);
	SetConsoleCursorPosition(GetConsole(), temp);
	printf("%c", 0xC9);
	printf("%s", string(this->length, 0xCD).c_str());
	printf("%c", 0xBB);
	temp.Y += 1;
	SetConsoleCursorPosition(GetConsole(), temp);
	printf("%c", 0xBA);
	printf(buffer[this->current].data());
	printf("%s", string(this->length - buffer[current].length(), ' ').c_str());
	printf("%c", 0xBA);
	temp.Y += 1;
	SetConsoleCursorPosition(GetConsole(), temp);
	printf("%c", 0xB9);
	printf("%s", string(this->length, 0xCD).c_str());
	printf("%c", 0xCC);
	temp.Y += 1;
	SetConsoleCursorPosition(GetConsole(), temp);
	for (int i = 0; i < size; i++)
	{
		if (i == _mark) {
			CONSOLE_SCREEN_BUFFER_INFO cbi;
			GetConsoleScreenBufferInfo(GetConsole(), &cbi);
			DWORD temp = cbi.wAttributes;
			DWORD wAttr = FOREGROUND_INTENSITY | BACKGROUND_GREEN;
			SetConsoleTextAttribute(GetConsole(), wAttr);
			printf("%c", 0xBA);
			printf(buffer[i].data());
			printf("%s", string(this->length - buffer[i].length(), ' ').c_str());
			printf("%c", 0xBA);
			SetConsoleTextAttribute(GetConsole(), temp);
		}
		else {
			printf("%c", 0xBA);
			printf(buffer[i].data());
			printf("%s", string(this->length - buffer[i].length(), ' ').c_str());
			printf("%c", 0xBA);
		}
		temp.Y += 1;
		SetConsoleCursorPosition(GetConsole(), temp);

	}

	printf("%c", 0xC8);
	printf("%s", string(this->length, 0xCD).c_str());
	printf("%c", 0xBC);
	SetConsoleCursorPosition(GetConsole(), GetCoord());
}

ComboBox::~ComboBox() {}
