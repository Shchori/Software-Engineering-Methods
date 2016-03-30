#include "RadioList.h"
#include <cstdio>
#include <string>
using namespace std;

# include <stdio.h>



RadioList::RadioList(const int size, const COORD coord, HANDLE consol, string context[]) :size(size), c(coord), consol(consol)
{
	this->buffer = context;
	this->mark = 1;
	COORD temp = coord;
	this->length = 0;
	for (int i = 0; i < size; ++i) {
		if (this->length < context[i].length()) this->length = context[i].length();
	}
	this->length += 3;
	this->current = 0;
	refresh();
}
bool beetween(int p, int x1, int x2) {
	return (p >= x1&&p <= x2);
}
bool RadioList::inArea(COORD c)
{
	int x = this->c.X, y = this->c.Y;
	return beetween(c.X, x, x + this->length + 5) && beetween(c.Y, y, y + size + 2);
}

int RadioList::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output)
{
	COORD c = mer.dwMousePosition;
	if (inArea(c)) {
		if (beetween(c.Y, this->c.Y+1, this->c.Y+this->size)) {
			this->current = c.Y - this->c.Y-1 ;
		}
		this->refresh();
	}
	return 0;
}

int RadioList::keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD c)
{
	int pos = c.X - (this->c.X + 1);
	COORD temp = c;
	switch (ker.wVirtualKeyCode) {
	case VK_UP:
		if (current > 0) this->current -= 1;
		refresh();
		break;
	case VK_DOWN:
		if (current < this->size-1) this->current += 1;
		refresh();
		break;
	case VK_RETURN:
		this->current = mark;
		refresh();
		break;
	}
	return 0;

}


void RadioList::refresh() {
	COORD temp = this->c;
	SetConsoleCursorPosition(consol, temp);
	DWORD wAttr = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(consol, wAttr);
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	GetConsoleScreenBufferInfo(consol, &cbi);
	DWORD wAttr2 = cbi.wAttributes | BACKGROUND_RED;
	SetConsoleTextAttribute(consol, wAttr2);
	SetConsoleCursorPosition(consol, temp);
	printf("%c", 0xB9);
	printf("%s", string(this->length+3, 0xCD).c_str());
	printf("%c", 0xCC);
	temp.Y += 1;
	SetConsoleCursorPosition(consol, temp);
	for (int i = 0; i < size; i++)
	{
		if (i == current) {
			string tempS = "(X)" + buffer[i];
			CONSOLE_SCREEN_BUFFER_INFO cbi;
			GetConsoleScreenBufferInfo(consol, &cbi);
			DWORD temp = cbi.wAttributes;
			DWORD wAttr = FOREGROUND_INTENSITY | BACKGROUND_GREEN;
			SetConsoleTextAttribute(consol, wAttr);
			printf("%c", 0xBA);
			printf(tempS.data());
			printf("%s", string(this->length - buffer[i].length(), ' ').c_str());
			printf("%c", 0xBA);
			SetConsoleTextAttribute(consol, temp);
		}
		else {
			printf("%c", 0xBA);
			string tempS = "( )" + buffer[i];
			printf(tempS.data());
			printf("%s", string(this->length - buffer[i].length(), ' ').c_str());
			printf("%c", 0xBA);
		}
		temp.Y += 1;
		SetConsoleCursorPosition(consol, temp);

	}

	printf("%c", 0xC8);
	printf("%s", string(this->length+3, 0xCD).c_str());
	printf("%c", 0xBC);
	SetConsoleCursorPosition(consol, this->c);
}

RadioList::~RadioList()
{
}
