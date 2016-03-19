#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include "CheckList.h"

using namespace std;

HANDLE hStdin;
DWORD fdwSaveOldMode;

int main(int argc, char *argv[]) {
	CheckList* list = new CheckList(7, 7);
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &cbi);

	DWORD wAttr2 = cbi.wAttributes | BACKGROUND_GREEN;
	SetConsoleTextAttribute(h, wAttr2);

	list->setCheckList("check");

	GetConsoleScreenBufferInfo(h, &cbi);

	DWORD a = cbi.wAttributes &  ~(BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	SetConsoleTextAttribute(h, a);
	
	list->setCheckList("hi");
	list->setCheckList("bye");



}