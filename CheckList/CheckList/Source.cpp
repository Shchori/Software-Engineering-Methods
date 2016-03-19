#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include "CheckList.h"

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

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		printf("SetConsoleMode");

	while (true) {
		CheckList* list = new CheckList(7, 7);
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
			//	KeyEventProc(irInBuf[i].Event.KeyEvent);
				keyEventHandler(irInBuf[i].Event.KeyEvent, arrSize);
				break;

			case MOUSE_EVENT: // mouse input 
				//MouseEventProc(irInBuf[i].Event.MouseEvent);
				mouseEventHandler(irInBuf[i].Event.MouseEvent);
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				//ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
				break;

			case FOCUS_EVENT:  // disregard focus events 

			case MENU_EVENT:   // disregard menu events 
				break;

			default:
				printf("Unknown event type");
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
				list->selectItem(labels[i]);
			}
			else {
				list->setCheckList(labels[i]);
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
			choose++;
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			printf("right button press \n");
		}
		else
		{
			printf("button press\n");
		}
		break;
	case DOUBLE_CLICK:
		printf("double click\n");
		break;
	case MOUSE_HWHEELED:
		printf("horizontal mouse wheel\n");
		break;
	case MOUSE_MOVED:
		printf("mouse moved\n");
		break;
	case MOUSE_WHEELED:
		printf("vertical mouse wheel\n");
		break;
	default:
		printf("unknown\n");
		break;
	}
}