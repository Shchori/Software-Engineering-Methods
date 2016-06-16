#include "CheckBox.h"


CheckBox::CheckBox(int height, int width, vector<string> options)
{
}


int CheckBox::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output) {
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			if (getCoord().X <= mer.dwMousePosition.X&& getCoord().x + 2 >= mer.dwMousePosition.X) {
				if (getCoord().Y <= mer.dwMousePosition.Y&& getCoord().Y + 1 >= mer.dwMousePosition.Y) {
					selectedIndexes[0] = (selectedIndexes[0]) ? 0 : 1;
				}
				else if (getCoord().Y + 1 < mer.dwMousePosition.Y&& getCoord().Y + 2 >= mer.dwMousePosition.Y) {
					selectedIndexes[1] = (selectedIndexes[1]) ? 0 : 1;
				}
				else if (getCoord().Y + 2 < mer.dwMousePosition.Y&& getCoord().Y + 3 >= mer.dwMousePosition.Y) {
					selectedIndexes[2] = (selectedIndexes[2]) ? 0 : 1;
				}

			}
		}
	}
	
	return 1;
}

int CheckBox::keyPress(KEY_EVENT_RECORD ker, HANDLE output) {
	return 1;
}


CheckBox::~CheckBox()
{
}
