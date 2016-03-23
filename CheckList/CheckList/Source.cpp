#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include "CheckList.h"
#define COOR_X 7
#define COOR_Y 7
using namespace std;

HANDLE hStdin;
DWORD fdwSaveOldMode;

int choose = 0;
int* selected;


void keyEventHandler(KEY_EVENT_RECORD ker, int arrSize);
void mouseEventHandler(MOUSE_EVENT_RECORD mer);

int main(int argc, char *argv[]) {
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	string labels[] = {"check" ,  "hi" , "bye" };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int arrSize = sizeof(labels) / sizeof(labels[0]);
	INPUT_RECORD irInBuf[128];
	selected = new int[arrSize]();

	//init selections
	for (int i = 0; i < arrSize; i++) {
		selected[i] = 0;
	}

	DWORD cNumRead, fdwMode, i;
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		printf("GetStdHandle");

	// Save the current input mode, to be restored on exit. 

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		printf("GetConsoleMode");

	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hStdin, fdwMode))
		printf("SetConsoleMode");

	while (true) {
		CheckList list(COOR_X, COOR_Y);
		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
			printf("ReadConsoleInput");

		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				keyEventHandler(irInBuf[i].Event.KeyEvent, arrSize);
				break;

			case MOUSE_EVENT: // mouse input 
				mouseEventHandler(irInBuf[i].Event.MouseEvent);
				break;
			}
		}

		//prints all inputs
		for (int i = 0; i < arrSize; i++) {
			//checks if it's the input i chose and color it
			if (i == choose) {
				GetConsoleScreenBufferInfo(h, &cbi);

				DWORD wAttr2 =  (BACKGROUND_BLUE |BACKGROUND_RED|BACKGROUND_GREEN| BACKGROUND_INTENSITY);
				SetConsoleTextAttribute(h, wAttr2);
			}
			//checks if input number i was selected
			if (selected && selected[i] == 1) {
				list.selectItem(labels[i]);
			}
			else {
				list.setCheckList(labels[i]);
			}

			if (i == choose) {
				WORD Attributes = cbi.wAttributes | FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(h, Attributes);
			}
		}
	}

	return 0;
}

void keyEventHandler(KEY_EVENT_RECORD ker, int arrSize) {
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
			selected[choose] = (selected[choose])? 0 : 1 ;
			break;
		case VK_LBUTTON:
			selected[choose] = (selected[choose]) ? 0 : 1;
		default:
			break;
		}
	}
	
}

void mouseEventHandler(MOUSE_EVENT_RECORD mer) {
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			if (COOR_X<=mer.dwMousePosition.X&& COOR_X+2>= mer.dwMousePosition.X) {
				if (COOR_Y <= mer.dwMousePosition.Y&& COOR_Y + 1 >= mer.dwMousePosition.Y) {
					selected[0] = (selected[0]) ? 0 : 1;
				}
				else if (COOR_Y + 1 < mer.dwMousePosition.Y&& COOR_Y + 2 >= mer.dwMousePosition.Y) {
					selected[1] = (selected[1]) ? 0 : 1;
				}
				else if (COOR_Y +2 < mer.dwMousePosition.Y&& COOR_Y + 3 >= mer.dwMousePosition.Y) {
					selected[2] = (selected[2]) ? 0 : 1;
				}
					
			}
		}
	}
}