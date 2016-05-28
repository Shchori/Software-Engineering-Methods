#pragma once
#include "ResponseComponentCompositor.h"

#include <string>
#define FRAME_SIZE 2;
using namespace std;

class RadioList : public ResponseComponentCompositor
{
public:
	RadioList(const int size, const COORD coord, string context[]);
	bool inArea(COORD c);
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD);
	~RadioList();
private:
	int size;
	int length;
	string *buffer;
	int current;
	int _mark;
	void print();
	void mark(int n) {};
};
