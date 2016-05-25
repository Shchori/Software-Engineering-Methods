#pragma once
#include <windows.h>
#include <stdio.h>

namespace control {
	void controler();
	VOID ErrorExit(LPSTR lpszMessage);
	void KeyEventProc(KEY_EVENT_RECORD, HANDLE output);
	void MouseEventProc(MOUSE_EVENT_RECORD, HANDLE output);
	void ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
}