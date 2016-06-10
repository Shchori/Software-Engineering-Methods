#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>
#include "IControl.h"
#include "Lable.h"
#include "Graphics.h"
#include "Button.h"
#include "subMouseListner.h"
#include "NumericBox.h"

using namespace std;
/*HANDLE hStdin;
DWORD fdwSaveOldMode;

VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD, HANDLE, Button&,Lable& );
VOID MouseEventProc(MOUSE_EVENT_RECORD, HANDLE, Button&,Lable&);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
*/



int main() {

	COORD c = { 2,2 };
	//COORD c1 = { 0,0 };
	//string str = "OK";
	NumericBox numericbox(10, 0, 100, 1, 6, c);
	numericbox.draw();

	system("PAUSE");
	return 0;
}
	