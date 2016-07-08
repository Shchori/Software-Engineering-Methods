#include "RadioList.h"


RadioList::RadioList(int height, int width, vector<string> options) :Panel(height, width), selectedIndex(-1),size(options.size()), ops(options.size(), Label(width - 3, "")), btn(options.size(), RadioListButton(this))
{
	g.setCursorVisibility(false);
	for (int i = 0; i < size; ++i) {
		COORD c1 = { 1, i * 2 + 1 };
		COORD c2 = { 6, i * 2 + 1 };
		ops[i].setValue(options[i]);
		btn[i].setIndex(i);
		btn[i].mousePressed(3, 2, true);
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


void RadioList::addControl(IControl& control, int left, int top) {
	Panel::addControl(control, left, top);
}

int RadioList::getSelectedIndex() {
	return selectedIndex+1;
}

void RadioList::setSelectedIndex(int index) {
	if(selectedIndex >= 0)btn[selectedIndex].setValue("( )");
	selectedIndex = index-1;
	btn[selectedIndex].setValue("(X)");
}

string RadioList::getValue()
{
	return this->ops[selectedIndex].GetValue();
}
void RadioList::clearSelection(){
	if (selectedIndex >= 0) btn[selectedIndex].setValue("( )");
	this->selectedIndex = -1;
};

RadioList::~RadioList()
{
	for (int i = 0; i < btn.size();i++) {
		btn[i].deleteEventListener();
	}
	
}
