#pragma once
#include <iostream>
#include <vector>
#include "Panel.h"
#include "Label.h"
#include "Button.h"

using namespace std;

class RadioList: public Panel
{
private:
	size_t selectedIndex;
	vector<Label> ops;
	vector<Button> btn;
public:
	RadioList(int height, int width, vector<string> options);
	void draw();
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output);
	~RadioList();
};

