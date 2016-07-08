#include "RadioList.h"

void RadioList::addControl(IControl& control, int left, int top) {
	Panel::addControl(control, left, top);
}

RadioList::RadioList(int height, int width, vector<string> options) :Panel(height, width), selectedIndex(-1),size(options.size()), ops(options.size(), Label(width - 3, "")), btn(options.size(), RadioListButton(this))
{
	g.setCursorVisibility(false);
	for (int i = 0; i < size; ++i) {
		COORD c1 = { 1, i };
		COORD c2 = { 6, i };
		ops[i].setValue(options[i]);
		btn[i].setIndex(i);
		addControl(btn[i], c1.X, c1.Y);
		addControl(ops[i], c2.X, c2.Y);
	}

}

void RadioList::draw() {
	for (int i = 0; i < size; ++i) {
			ops[i].setBackgroundColor(this->getBackgroundColor());
			ops[i].setForegroundColor(this->getForegroundColor());
	}
	Panel::draw();
}

int RadioList::getSelectedIndex() {
	return selectedIndex+1;
}

void RadioList::setSelectedIndex(int index) {
	//for users the index starts from 1
	index--;
	//if nothing has selected
	if (selectedIndex == -1) {
		selectedIndex = index;
		btn[selectedIndex].setValue("(X)");
	}
	else {
		//if clicked selected Index
		if(selectedIndex == index) {
			btn[selectedIndex].setValue("( )");
			selectedIndex = -1;
		}
		else {//if click new index
			btn[selectedIndex].setValue("( )");
			btn[index].setValue("(X)");
			selectedIndex = index;
		}
		
	}
}

void RadioList::clearSelection() {
	if (selectedIndex >= 0) btn[selectedIndex].setValue("( )");
	this->selectedIndex = -1;
};


string RadioList::getValue()
{
	if (selectedIndex < 0) return "";
	return this->ops[selectedIndex].GetValue();
}

RadioList::~RadioList()
{
	for (int i = 0; i < btn.size();i++) {
		btn[i].deleteEventListener();
	}
	
}
