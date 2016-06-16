#include "RadioList.h"


RadioList::RadioList(int height, int width, vector<string> options):Panel(height, width),selectedIndex(-1),ops(width)
{
	ops.resize(options.size());
	for (int i = 0; i < options.size();i++) {
		ops[i].SetValue(options[i]);
		AddControl(ops[i],width, height);
	}

}

void RadioList::draw() {
	
	Panel::draw();
	

}

bool RadioList::inArea(COORD c) {
	return true;
}

size_t RadioList::GetSelectedIndex() {
	return 1;
}

void RadioList::SetSelectedIndex(size_t index) {

}

RadioList::~RadioList()
{
}
