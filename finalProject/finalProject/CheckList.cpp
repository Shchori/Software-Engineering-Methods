#include "CheckList.h"


CheckList::CheckList(int height, int width, vector<string> options):RadioList( height, width, options)
{
	selectedIndexes = new int[options.size()];
}


int CheckList::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output) {
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			if (getCoord().X < mer.dwMousePosition.X&& mer.dwMousePosition.X <= getCoord().X + 3) {
				for (int i = 0; i < btn.size(); i++) {
					if (getCoord().Y + i <= mer.dwMousePosition.Y && mer.dwMousePosition.Y < getCoord().Y + i + 1) {
						selectedIndexes[i] = (selectedIndexes[i]) ? 0 : 1;
					}
					if (selectedIndexes[i]) {
						btn[i].setValue("[X]");
					}
					else {
						btn[i].setValue("[ ]");
					}
				}
			}
		}
	}
	
	return 1;
}



CheckList::~CheckList()
{
	delete selectedIndexes;
}
