#pragma once
#include <iostream>
#include <vector>
#include "Panel.h"
#include "Label.h"

using namespace std;

class RadioList: public Panel
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
	~RadioList();
};

