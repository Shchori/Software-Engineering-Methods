#include "CheckList.h"

CheckList::CheckList() {
	this->size = sizeof(labels) / sizeof(labels[0]);
}

int CheckList::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output) {
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			if (COOR_X <= mer.dwMousePosition.X&& COOR_X + 2 >= mer.dwMousePosition.X) {
				if (COOR_Y <= mer.dwMousePosition.Y&& COOR_Y + 1 >= mer.dwMousePosition.Y) {
					selected[0] = (selected[0]) ? 0 : 1;
				}
				else if (COOR_Y + 1 < mer.dwMousePosition.Y&& COOR_Y + 2 >= mer.dwMousePosition.Y) {
					selected[1] = (selected[1]) ? 0 : 1;
				}
				else if (COOR_Y + 2 < mer.dwMousePosition.Y&& COOR_Y + 3 >= mer.dwMousePosition.Y) {
					selected[2] = (selected[2]) ? 0 : 1;
				}

			}
		}
	}
}


bool CheckList::inArea(COORD c) {

}

int CheckList::keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD) {
	// if key was pressed
	if (ker.bKeyDown) {
		//checks the key value
		switch (ker.wVirtualKeyCode) {
		case VK_DOWN:case VK_TAB:
			if (choose < arrSize - 1) {
				choose++;
			}
			break;
		case VK_UP:
			if (choose > 0) {
				choose--;
			}
			break;
		case VK_SPACE: case VK_RETURN:
			selected[choose] = (selected[choose]) ? 0 : 1;
			break;
		case VK_LBUTTON:
			selected[choose] = (selected[choose]) ? 0 : 1;
		default:
			break;
		}
	}
}