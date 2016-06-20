#pragma once
#include "Event.h"
#include <vector>
class CheckBox : public Event
{
	int* selectedIndexes;
public:
	CheckBox(int height, int width, vector<string> options);
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output);
	~CheckBox();
};

