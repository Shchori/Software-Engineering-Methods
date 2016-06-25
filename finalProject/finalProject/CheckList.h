#pragma once
#include "RadioList.h"
#include <vector>
class CheckList : public RadioList
{
	int* selectedIndexes;
public:
	CheckList(int height, int width, vector<string> options);
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output);
	~CheckList();
};

