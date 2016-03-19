#include "CheckList.h"



CheckList::CheckList(short x, short y):x(x), y(y)
{
	setConsoleCoor(x, y);
}


void CheckList::setConsoleCoor(short x, short y) {
	COORD c = { x, y };
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, c);
}

void CheckList::setCheckList(string text) {
	y += 1;
	setConsoleCoor(x, y);
	cout << "[ ]\t" << text<<endl;
}



CheckList::~CheckList()
{
}
