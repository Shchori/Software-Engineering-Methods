#include "RadioList.h"


RadioList::RadioList(int height, int width, vector<string> options) :Panel(height, width), selectedIndex(-1), ops(options.size(), Label(width - 5, "")), btn(options.size(), RadioListButton(this))
{
	for (int i = 0; i < options.size(); ++i) {
		COORD c1 = { 0, i * 1 };
		COORD c2 = { 6, i * 1 };
		ops[i].setValue(options[i]);
		ops[i].setCoord(c2);
		btn[i].setCoord(c1);
		addControl(btn[i], btn[i].getCoord().X, btn[i].getCoord().Y);
		addControl(ops[i], ops[i].getCoord().X, ops[i].getCoord().Y);
	}

}

void RadioList::draw() {

	Panel::draw();

	g.setCursorVisibility(false);
}

int RadioList::getSelectedIndex() {
	return selectedIndex;
}

void RadioList::setSelectedIndex(int index) {
	btn[selectedIndex].setValue("( )");
	btn[index].setValue("(X)");
	selectedIndex = index;
}

int RadioList::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output) {
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			if (getCoord().X<mer.dwMousePosition.X&& mer.dwMousePosition.X <= getCoord().X + 3) {
				for (int i = 0; i < btn.size(); i++) {
					if (getCoord().Y + i <= mer.dwMousePosition.Y && mer.dwMousePosition.Y < getCoord().Y + i + 1) {

						if (selectedIndex == -1) {
							selectedIndex = i;
						}

						int selected = GetSelectedIndex();
						btn[selectedIndex].setValue("( )");
						btn[i].setValue("(X)");
						selectedIndex = i;
					}
				}
			}

		}
	}
	return 0;
}

int RadioList::keyPress(KEY_EVENT_RECORD ker, HANDLE output) {
	return 1;
}

RadioList::~RadioList()
{
}
