#pragma once
#include "RadioList.h"

class CheckList :
	public RadioList
{
private:
	int* selectedIndexes;
public:
	CheckList(int height, int width, vector<string> options);
	int* getSelectedIndexes();
	void setSelectedIndex(int index);
	~CheckList();
};

