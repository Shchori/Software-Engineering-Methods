#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>
#include "IControl.h"
#include "Label.h"
#include "Graphics.h"
#include "Button.h"
#include "NumericBox.h"

using namespace std;



struct myStruct :MouseListener
{
	void MousePressed(Button &b, int x, int y, bool isLeft) {
		cout << "h";
	}

};


int main() {

	COORD c = { 2,2 };
	string str = "+";
	Button b(str, 1);
	b.setCoord(c);
	b.draw();
	myStruct _mystruct;
	b.AddListener(_mystruct);
	b.mouseEvent(2, 2);

	COORD c2 = { 4,4};
	NumericBox numericbox(10, 0, 100, 1, 2, c2);
	numericbox.draw();
	numericbox.addEvent();
	cout << "\n\n\n";
	system("PAUSE");
	return 0;
}
	