#include "TextBox.h"
#include <cstdio>
#include <string>
using namespace std;

# include <stdio.h>



TextBox::TextBox(const int size, const COORD coord,string context) : ResponseComponent(coord), size(size)
{
	
	this->buffer = context;
	COORD temp = coord;

	DWORD wAttr = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(GetConsole(), wAttr);
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	GetConsoleScreenBufferInfo(GetConsole(), &cbi);
	DWORD wAttr2 = cbi.wAttributes | BACKGROUND_RED;
	SetConsoleTextAttribute(GetConsole(), wAttr2);
	SetConsoleCursorPosition(GetConsole(), temp);
	printf("%c", 0xC9);
	printf("%s", string(size, 0xCD).c_str());
	printf("%c", 0xBB);
	temp.Y += 1;
	SetConsoleCursorPosition(GetConsole(), temp);
	printf("%c", 0xBA);
	printf("%s", string(size, ' ').c_str());
	printf("%c", 0xBA);
	temp.Y += 1;
	SetConsoleCursorPosition(GetConsole(), temp);
	printf("%c", 0xC8);
	printf("%s", string(size, 0xCD).c_str());
	printf("%c", 0xBC);
	temp = GetCoord();
	temp.Y += 1;
	temp.X += 1 + context.length();
	SetConsoleCursorPosition(GetConsole(), temp);
	print();
}

bool beetween(int p, int x1, int x2) {
	return (p >= x1&&p <= x2);
}

bool TextBox::inArea(COORD c)
{
	int x = GetCoord().X, y = GetCoord().Y;
	return beetween(c.X, x, x + this->size + 2) && beetween(c.Y, y, y + 2);
}

int TextBox::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output)
{
	COORD c = mer.dwMousePosition;
	if (inArea(c))
		if (!beetween(c.X, GetCoord().X, GetCoord().X + buffer.length())) {
			c.X = GetCoord().X + buffer.length() + 1;
		}
	c.Y = GetCoord().Y + 1;
	SetConsoleCursorPosition(output, c);
	return 0;
}

int TextBox::keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD c)
{
	int pos = c.X - (GetCoord().X + 1);
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
			print();
		}
		else if (k == 8 && pos > 0) {
			string s = "";
			for (int i = 0; i < buffer.length(); i++) {
				if (i == pos - 1) continue;
				s += buffer[i];

			}
			buffer.assign(s);
			temp.X -= 1;
			SetConsoleCursorPosition(output, temp);
			print();
		}
		break;
	}
	return 0;

}


void TextBox::print() {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetConsole(), &info);
	COORD temp1 = info.dwCursorPosition, start = GetCoord();
	start.X += 1;
	start.Y += 1;
	SetConsoleCursorPosition(GetConsole(), start);
	printf("%s", string(size, ' ').c_str());
	SetConsoleCursorPosition(GetConsole(), start);
	printf("%s", buffer.c_str());
	SetConsoleCursorPosition(GetConsole(), temp1);

}

TextBox::~TextBox() {}