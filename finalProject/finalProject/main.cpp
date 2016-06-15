#pragma once
#include "constants.h" //include all project constants
#include<Windows.h>
#include "border.h"
#include <vector>
#include "Graphics.h"
#include "border.h"
#include "IControl.h"
#include "Label.h"
#include "Panel.h"
#include "TextBox.h"
#include <iostream>
#include "Button.h"
#include "NumericBox.h"
using namespace std;
void main() {

	/*BorderType b = BorderType::Double;
	Label t("jj", 4);
	COORD f = { 15, 17 };
	t.setCoord(f);
	t.setBorder(b);

	Label text("hey", 4);
	COORD c = { 2,3 };
	text.setCoord(c);
	text.setBorder(b);


	Panel main(25, 30);
	main.setBorder(b);
	main.AddControl(t, t.getCoord().X, t.getCoord().Y);
	main.AddControl(text, text.getCoord().X, text.getCoord().Y);
	//main.draw();

	string plus = "plus";
	string minus = "minus";
	COORD numeric_c = { 6,7 };
	NumericBox numericbox(10, 20, 0, 100, 1, 4, numeric_c);
	numericbox.setBorder(b);
	main.AddControl(numericbox, numericbox.getCoord().X, numericbox.getCoord().Y);

	numericbox.draw();

	main.draw();


	numericbox.addEvent(plus);
	numericbox.addEvent(plus);
	numericbox.addEvent(minus);


	//getchar();
	*/
	HANDLE hStdin;
	DWORD fdwSaveOldMode;

	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;

	// Get the standard input handle. 

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE) {
		printf("GetStdHandle");
		exit(0);
	}

	// Save the current input mode, to be restored on exit. 

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode)) {
		printf("GetConsoleMode");
		exit(0);
	}


	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode)) {
		printf("SetConsoleMode");
		exit(0);
	}


	// Loop to read and handle the next 100 input events.
	COORD c = { 7, 7 };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	TextBox box(20);
	while (true)
	{
		// Wait for the events. 

		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			200,         // size of read buffer 
			&cNumRead)) // number of records read 
		{
			printf("ReadConsoleInput");
			exit(0);
		}


		// Dispatch the events to the appropriate handler. 

		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				box.keyPress(irInBuf[i].Event.KeyEvent, h);
				break;

			case MOUSE_EVENT: // mouse input 
				cout << "mouse";
				box.mouseEvent(irInBuf[i].Event.MouseEvent, h);
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
	}

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);
	
	getchar();

}