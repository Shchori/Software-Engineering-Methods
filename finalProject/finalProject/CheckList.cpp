#include "CheckList.h"


CheckList::CheckList(int height, int width, vector<string> options):RadioList(height, width,  options){
	selectedIndexes = new int[5]();
};

vector<string> CheckList::getSelectedIndexes() {
	vector<string> selected;
	selected.resize(ops.size());
	for (int i = 0; i < ops.size(); i++) {
		selected.push_back(ops[i].GetValue());
	}
	
	return selected;
}

void CheckList::clearSelection() {
	for (int i = 0; i < ops.size(); i++) {
		selectedIndexes[i] = 0;
	}
}

void CheckList::setSelectedIndex(int index) {
	selectedIndex = index - 1;
	selectedIndexes[selectedIndex] = 1- selectedIndexes[selectedIndex];
	(selectedIndexes[selectedIndex])? btn[selectedIndex].setValue("(X)") : btn[selectedIndex].setValue("( )");
}

CheckList::~CheckList()
{
	delete [] selectedIndexes;
};
