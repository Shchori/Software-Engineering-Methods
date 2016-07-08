#pragma once
#include "RadioList.h"

class CheckList :
	public RadioList
{
private:
	int* selectedIndexes;
public:
	CheckList(int height, int width, vector<string> options);
	void setSelectedIndex(int index);
	vector<string> getSelectedIndexes();
	void clearSelection();
	~CheckList();
};

