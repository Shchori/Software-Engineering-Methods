#include "RadioList.h"


RadioList::RadioList(int height, int width, vector<string> options) :Panel(height, width), selectedIndex(-1),size(options.size()), ops(options.size(), Label(width - 5, "")), btn(options.size(), RadioListButton(this))
{
	for (int i = 0; i < size; ++i) {
		COORD c1 = { 1, i * 2 + 1 };
		COORD c2 = { 6, i * 2 + 1 };
		ops[i].setValue(options[i]);
		btn[i].setIndex(i);
		btn[i].mousePressed(3, 2, true);
		addControl(btn[i], c1.X, c1.Y);
		addControl(ops[i], c2.X, c2.Y);
		//btn[i].mousePressed(1, 3, true);
	}

}

void RadioList::draw() {
	for (int i = 0; i < size; ++i) {
		if (i != this->selectedIndex) {
			ops[i].setBackgroundColor(this->getBackgroundColor());
			ops[i].setForegroundColor(this->getForegroundColor());
			btn[i].setValue("( )");

		}
		else {
			ops[i].setForegroundColor(this->getBackgroundColor());
			ops[i].setBackgroundColor(this->getForegroundColor());
			btn[i].setValue("(X)");
		}
	}
	Panel::draw();

	g.setCursorVisibility(false);
}

int RadioList::getSelectedIndex() {
	return selectedIndex+1;
}

void RadioList::setSelectedIndex(int index) {
	btn[selectedIndex].setValue("( )");
	selectedIndex = index-1;
	btn[selectedIndex].setValue("(X)");
}

string RadioList::getValue()
{
	return this->ops[selectedIndex].GetValue();
}


RadioList::~RadioList()
{
}
