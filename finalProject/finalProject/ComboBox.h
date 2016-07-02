#pragma once
#include "RadioList.h"
class ComboBox :
	public RadioList
{
public:
	ComboBox(int height, int width, vector<string> options);
	~ComboBox();
};

