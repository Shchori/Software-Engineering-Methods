#include "ComboBox.h"
#include <cstdio>
#include <string>
using namespace std;

# include <stdio.h>



ComboBox::ComboBox(const int size ,const COORD coord,HANDLE consol, string context[]):size(size),c(coord),consol(consol)
{
	this->buffer = context;
	this->mark = 1;
	COORD temp = coord;
	this->length = 0;
	for (int i = 0; i < size; ++i) {
		if (this->length < context[i].length()) this->length = context[i].length();
	}
	this->mark = 0;
	this->current = 0;
	refresh();
}
bool beetween(int p,int x1, int x2) {
	return (p>=x1&&p<=x2);
}
bool ComboBox::inArea(COORD c)
{
	int x = this->c.X, y = this->c.Y;
	return beetween(c.X,x,x+this->length+2)&&beetween(c.Y, y, y+ size + 4);
}

int ComboBox::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output)
{
	COORD c = mer.dwMousePosition;
	if (inArea(c)) {
		if (beetween(c.X, this->c.Y, this->c.Y + 3)) {
			this->current = 1;
		}
		else {
			this->current = c.Y - this->c.Y - 3;
			mark = current;
		}
		this->refresh();
	}
		return 0;
}

int ComboBox::keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD c)
{
	int pos = c.X - (this->c.X + 1);
	COORD temp = c;
	switch (ker.wVirtualKeyCode) {
	case VK_UP:     
		if (current > 0) this->mark -= 1;
		refresh();
		break;
	case VK_DOWN:  
		if (current < this->size) this->mark += 1;
		refresh();
		break;
	case VK_RETURN:
		this->current = mark;
		refresh();
		break;
	}
	return 0;

}


void ComboBox::refresh() {
	COORD temp = this->c;
	SetConsoleCursorPosition(consol, temp);
	DWORD wAttr = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(consol, wAttr);
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	GetConsoleScreenBufferInfo(consol, &cbi);
	DWORD wAttr2 = cbi.wAttributes | BACKGROUND_RED;
	SetConsoleTextAttribute(consol, wAttr2);
	SetConsoleCursorPosition(consol, temp);
	printf("%c", 0xC9);
	printf("%s", string(this->length, 0xCD).c_str());
	printf("%c", 0xBB);
	temp.Y += 1;
	SetConsoleCursorPosition(consol, temp);
	printf("%c", 0xBA);
	printf("%s", buffer[this->current]);
	printf("%s", string(this->length - buffer[current].length(), ' ').c_str());
	printf("%c", 0xBA);
	temp.Y += 1;
	SetConsoleCursorPosition(consol, temp);
	printf("%c", 0xB9);
	printf("%s", string(this->length, 0xCD).c_str());
	printf("%c", 0xCC);
	temp.Y += 1;
	SetConsoleCursorPosition(consol, temp);
	for (int  i = 0; i < size; i++)
	{
		if (i == mark) {
			CONSOLE_SCREEN_BUFFER_INFO cbi;
			GetConsoleScreenBufferInfo(consol, &cbi);
			DWORD temp= cbi.wAttributes;
			DWORD wAttr =FOREGROUND_INTENSITY | BACKGROUND_GREEN;
			SetConsoleTextAttribute(consol, wAttr);
			printf("%c", 0xBA);
			printf("%s", buffer[i]);
			printf("%s", string(this->length-buffer[i].length(), ' ').c_str());
			printf("%c", 0xBA);
			SetConsoleTextAttribute(consol, temp);
		}
		else {
			printf("%c", 0xBA);
			printf("%s", buffer[i]);
			printf("%s", string(this->length - buffer[i].length(), ' ').c_str());
			printf("%c", 0xBA);
		}
		temp.Y += 1;
		SetConsoleCursorPosition(consol, temp);

	}

	printf("%c", 0xC8);
	printf("%s", string(size, 0xCD).c_str());
	printf("%c", 0xBC);
	SetConsoleCursorPosition(consol, this->c);
}

ComboBox::~ComboBox()
{
}
