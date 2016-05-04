#pragma once
#include <Windows.h>
#include <string>
#include "ResponseComponent.h"
#define FRAME_SIZE 2;
using namespace std;

class TextBox : public ResponseComponent
{
public:
	TextBox(const int size, const COORD coord, string context) ;
	bool inArea(COORD c);
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD);
	inline virtual string getString() { return  buffer; };
	~TextBox();

private:
	int size;
	string buffer;
	void print();
};
