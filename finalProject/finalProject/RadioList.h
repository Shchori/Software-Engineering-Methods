#pragma once
#include <iostream>
#include <vector>
#include "IControl.h"

using namespace std;

class RadioList: public IControl
{
private:
	size_t selectedIndex;
	vector<string> options;
public:
	RadioList(int height, int width, vector<string> options);
	void draw();
	bool inArea(COORD c);
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);
	~RadioList();
};

