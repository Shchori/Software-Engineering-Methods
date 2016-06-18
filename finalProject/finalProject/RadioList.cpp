#include "RadioList.h"


RadioList::RadioList(int height, int width, vector<string> options):Panel(height, width),selectedIndex(-1),ops(options.size(),Label(width,"")), btn(options.size(),Button("( )", 3))
{
	for (int i = 0; i < options.size();i++) {
		ops[i].SetValue(options[i]);
	}

}

void RadioList::draw() {
	for (int i = 0; i < ops.size(); i++) {
		AddControl(btn[i], getCoord().X, getCoord().Y + i);
		AddControl(ops[i], getCoord().X+4, getCoord().Y+i);
	}
	Panel::draw();

	g.setCursorVisibility(false);
	

}

size_t RadioList::GetSelectedIndex() {
	return selectedIndex;
}

void RadioList::SetSelectedIndex(size_t index) {
	selectedIndex = index;
}

int RadioList::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output) {
	return 1;
}

int RadioList::keyPress(KEY_EVENT_RECORD ker, HANDLE output) {
	return 1;
}

RadioList::~RadioList()
{
}
