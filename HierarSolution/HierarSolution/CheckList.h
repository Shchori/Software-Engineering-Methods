#pragma once
#include <Windows.h>
#include <string>
#include "ResponseComponent.h"

class CheckList : public ResponseComponent {
public: 
	CheckList();
	bool inArea(COORD c);
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD);
	inline virtual string getString() { return  buffer; };
protected:
	int size;
	string buffer;
	void print();
	int choose;
	int* selected;
	string labels[] = { "check" ,  "hi" , "bye" };
};