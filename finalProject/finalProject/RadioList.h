#pragma once
#include <iostream>
#include <vector>
#include "Panel.h"
#include "Label.h"
#include "Button.h"

using namespace std;

class RadioList: public Panel
{
protected:
	int selectedIndex;
	vector<Label> ops;
	vector<Button> btn;
public:
	RadioList(int height, int width, vector<string> options);
	void draw();
	int GetSelectedIndex();
	void SetSelectedIndex(int index);
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output);
	~RadioList();
};

