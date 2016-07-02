#include "CheckList.h"


CheckList::CheckList(int height, int width, vector<string> options):RadioList(height, width,  options){ 
	selectedIndexes = new int[options.size()];
};

int* CheckList::getSelectedIndexes() {
	return selectedIndexes;
}

void CheckList::setSelectedIndex(int index) {
	selectedIndexes[ index - 1] = 1- selectedIndexes[index-1];
	(selectedIndexes[index - 1])? btn[selectedIndex].setValue("(X)") : btn[selectedIndex].setValue("( )");
}

CheckList::~CheckList()
{
};
