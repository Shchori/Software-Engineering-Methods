#include "TextBox.h"
#include <cstdio>
#include <string>
using namespace std;

# include <stdio.h>



TextBox::TextBox(const int size ,const COORD coord,HANDLE consol, string context):size(size),c(coord),consol(consol)
{
	this->buffer = context;
	COORD temp = coord;
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
	SetConsoleCursorPosition(consol,temp);


}
bool beetween(int p,int x1, int x2) {
	return (p>=x1&&p<=x2);
}
bool TextBox::inArea(COORD c)
{
	int x = this->c.X, y = this->c.Y, length = this->buffer.length();
	return beetween(c.X,x,x+length+2)&&beetween(c.Y, y, y + 2);
}

int TextBox::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output)
{

	SetConsoleCursorPosition(output,mer.dwMousePosition );
	return 0;
}

int TextBox::keyPress(KEY_EVENT_RECORD ker, HANDLE output)
{

	return 0;
}

TextBox::~TextBox()
{
}
