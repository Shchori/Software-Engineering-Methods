#include "TextBox.h"
#include <cstdio>
#include <string>
using namespace std;

# include <stdio.h>



TextBox::TextBox(const int size ,const COORD coord,HANDLE consol, string context):size(size),c(coord),consol(consol)
{

	this->buffer = context;
	COORD temp = coord;
	
	DWORD wAttr = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(consol, wAttr);
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	GetConsoleScreenBufferInfo(consol, &cbi);
	DWORD wAttr2 = cbi.wAttributes | BACKGROUND_RED;
	SetConsoleTextAttribute(consol, wAttr2);
	SetConsoleCursorPosition(consol, temp);
	printf("%c", 0xC9);
	printf("%s", string(size,0xCD ).c_str());
	printf("%c", 0xBB);
	temp.Y += 1;
	SetConsoleCursorPosition(consol, temp);
	printf("%c", 0xBA);
	printf("%s", string(size, ' ').c_str());
	printf("%c", 0xBA);
	temp.Y += 1;
	SetConsoleCursorPosition(consol, temp);
	printf("%c", 0xC8);
	printf("%s", string(size, 0xCD).c_str());
	printf("%c", 0xBC);
	temp = c;
	temp.Y += 1;
	temp.X += 1+context.length();
	SetConsoleCursorPosition(consol, temp);
	refresh();
}

bool beetween(int p,int x1, int x2) {
	return (p>=x1&&p<=x2);
}

bool TextBox::inArea(COORD c)
{
	int x = this->c.X, y = this->c.Y;
	return beetween(c.X,x,x+this->size+2)&&beetween(c.Y, y, y + 2);
}

int TextBox::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output)
{	
	COORD c = mer.dwMousePosition;
	if(inArea(c))
		if (!beetween(c.X,this->c.X, this->c.X + buffer.length())) {
			c.X =this->c.X+ buffer.length()+1;
		}
		c.Y = this->c.Y + 1;
		SetConsoleCursorPosition(output,c);
	return 0;
}

int TextBox::keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD c)
{
	int pos = c.X - (this->c.X + 1);
	COORD temp = c;
	switch (ker.wVirtualKeyCode) {
	case VK_LEFT:
		if (pos > 0) {
			temp.X -= 1;
			SetConsoleCursorPosition(output, temp);
		}
		break;
	case VK_RIGHT:
	{
		if (pos < buffer.length()) {
			temp.X += 1;
			SetConsoleCursorPosition(output, temp);
		}
	}
	break;
	case VK_UP:     break;
	case VK_DOWN:   break;

	default:


		char k = ker.uChar.AsciiChar;
		if (k >= 32 && k <= 176 && buffer.length()<this->size) {
			string s = "";
			s += k;
			buffer.insert(pos, s);
			temp.X += 1;
			SetConsoleCursorPosition(output, temp);
			refresh();
		}
		else if (k == 8 && pos > 0) {
			string s = "";
			for (int i = 0; i < buffer.length(); i++) {
				if (i == pos-1) continue;
				s += buffer[i];

			}
			buffer.assign(s);
			temp.X -= 1;
			SetConsoleCursorPosition(output, temp);
			refresh();
		}
		break;
	}
	return 0;

}


void TextBox::refresh() {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(this->consol, &info);
	COORD temp1 = info.dwCursorPosition,start=this->c;
	start.X += 1;
	start.Y += 1;
	SetConsoleCursorPosition(consol, start);
	printf("%s", string(size, ' ').c_str());
	SetConsoleCursorPosition(consol, start);
	printf("%s", buffer.c_str());
	SetConsoleCursorPosition(consol,temp1);
	
}

TextBox::~TextBox(){}