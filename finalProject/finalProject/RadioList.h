#pragma once
#include <iostream>
#include <vector>
#include "Panel.h"
#include "Label.h"
#include "Event.h"
using namespace std;

class RadioList: public Panel, public Event
{
private:
	size_t selectedIndex;
	vector<Label> ops;
public:
	RadioList(int height, int width, vector<string> options);
	void draw();
	bool inArea(COORD c);
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output);
	~RadioList();
};

