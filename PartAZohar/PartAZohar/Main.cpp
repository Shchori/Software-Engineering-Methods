#include <Windows.h>
#include <stdio.h>
#include "RadioList.h"
#include<iostream>
#include<vector>


using namespace std;
HANDLE h;
DWORD fdwSaveOldMode;

VOID ErrorExit(LPSTR);


void main(void) {

	string str[] = { "option1", "option2", "option3", "option4" };
	int size = sizeof(str) / sizeof(str[0]);

	COORD c{ 1, 1 };

	RadioList  radioList(c, str, size);

	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;


	// Get the standard input handle. 

	h = GetStdHandle(STD_INPUT_HANDLE);
	if (h == INVALID_HANDLE_VALUE)
		ErrorExit("GetStdHandle");
	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(h, fdwMode))
		ErrorExit("SetConsoleMode");

	// Loop to read and handle the next 100 input events. 

	while (1)
	{
		// Wait for the events. 

		if (!ReadConsoleInput(
			h,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
			ErrorExit("ReadConsoleInput");

		// Dispatch the events to the appropriate handler. 

		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				radioList.KeyEventProc(irInBuf[i].Event.KeyEvent, str, size);
				break;

			case MOUSE_EVENT: // mouse input 
				radioList.MouseEventProc(irInBuf[i].Event.MouseEvent, str, size);
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				//ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
				break;

			case FOCUS_EVENT:  // disregard focus events 

			case MENU_EVENT:   // disregard menu events 
				break;

			default:
				ErrorExit("Unknown event type");
				break;



			}
		}




		//system("PAUSE");
	}
}

VOID ErrorExit(LPSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);

	// Restore input mode on exit.

	SetConsoleMode(h, fdwSaveOldMode);

	ExitProcess(0);
}
