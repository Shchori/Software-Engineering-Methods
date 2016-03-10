#include "TextBox.h"
#include <cstdio>
#include <string>
using namespace std;





TextBox::TextBox(const int size, const COORD coord)
{
	this->size = size;
	this->c = coord;
	COORD temp = coord;
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, temp);
	printf("%c", 0xC9);
	printf("%s", string(size,0xCD ).c_str());
	printf("%c", 0xBB);
	temp.Y += 1;
	SetConsoleCursorPosition(output, temp);
	printf("%c", 0xBA);
	printf("%s", string(size, ' ').c_str());
	printf("%c", 0xCA);
	temp.Y += 1;
	SetConsoleCursorPosition(output, temp);
	printf("%c", 0xB8);
	printf("%s", string(size, 0xCD).c_str());
	printf("%c", 0xBC);


}

TextBox::~TextBox()
{
}
