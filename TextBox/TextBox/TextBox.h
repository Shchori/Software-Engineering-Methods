#pragma once
#include <Windows.h>
class TextBox
{
public:
	TextBox(const int size, const COORD coord);
	~TextBox();
private:
	int size;
	char * buffer;
	COORD c;
};

