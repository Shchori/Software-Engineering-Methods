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
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			if (getCoord().X<mer.dwMousePosition.X&& mer.dwMousePosition.X<=getCoord().X) {
				for (int i = 0; i < ops.size(); i++) {
					if (getCoord().Y + i <= mer.dwMousePosition.Y && mer.dwMousePosition.Y < getCoord().Y + i + 1) {
						
						if (selectedIndex == -1) {
							selectedIndex = i;
						}

						btn[selectedIndex].SetValue("( )");
						btn[i].SetValue("(X)");
						selectedIndex = i;
					}
				}
			}
			
		}
	}
}

int RadioList::keyPress(KEY_EVENT_RECORD ker, HANDLE output) {
	return 1;
}

RadioList::~RadioList()
{
}
