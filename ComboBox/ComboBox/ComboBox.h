#pragma once
#include "ResponseComponentCompositor.h"
#include <Windows.h>
#include <string>
#define FRAME_SIZE 2;
using namespace std;

class ComboBox : public ResponseComponentCompositor {

public:
	ComboBox(const int size, const COORD coord, string context[]);
	bool inArea(COORD c);
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD);
	~ComboBox();

private:
	int size;
	int length;
	string *buffer;
	int current;
	int _mark;
	void mark(int n) {};
	void print();
};

