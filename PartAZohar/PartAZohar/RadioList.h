#pragma once
#include <Windows.h>
#include <string>
#define FRAME_SIZE 2;
using namespace std;

class RadioList
{
public:
	RadioList(const int size, const COORD coord, HANDLE consol, string context[]);
	bool inArea(COORD c);
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD);
	~RadioList();
private:
	int size;
	int length;
	string *buffer;
	COORD c;
	HANDLE consol;
	int current;
	int mark;
	void refresh();
};

