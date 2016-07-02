#include "CheckList.h"


CheckList::CheckList(int height, int width, vector<string> options):RadioList(height, width,  options){ 
	selectedIndexes = new int[options.size()];
};

vector<string> CheckList::getSelectedIndexes() {
	vector<string> selected;
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
	selectedIndexes[ index - 1] = 1- selectedIndexes[index-1];
	(selectedIndexes[index - 1])? btn[selectedIndex].setValue("(X)") : btn[selectedIndex].setValue("( )");
}

CheckList::~CheckList()
{
	delete selectedIndexes;
};
