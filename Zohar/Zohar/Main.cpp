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

	/*COORD c = { 2,2 };
	string str = "+";
	Button b(str, 1);
	b.setCoord(c);
	b.draw();
	myStruct _mystruct;
	b.AddListener(_mystruct);
	b.mouseEvent(2, 2);*/
	BorderType b = BorderType::Double;
	string plus = "plus";
	string minus = "minus";
	COORD c2 = { 4,4};
	COORD numeric_c = { 0,0 };
	NumericBox numericbox(10,20,0,100, 1, 4, numeric_c);
	numericbox.setBorder(b);
	//numericbox.setCoord(numeric_c);

	numericbox.draw();

	numericbox.addEvent(plus);
	numericbox.addEvent(plus);
	numericbox.addEvent(minus);

	cout << "\n\n\n\n\n\n\n";
	system("PAUSE");
	return 0;
}
	