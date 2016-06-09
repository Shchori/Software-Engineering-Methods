#include "Button.h"



Button::Button(string str,int width):Lable(str,width){}


Button::~Button()
{
}
/*
bool beetween(int p, int x1, int x2) {
	return (p >= x1&&p <= x2);
}*/

int Button::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output, Lable& lable)
{
	int value;
	string l = lable.GetValue();
	COORD c = mer.dwMousePosition;
	if (inArea(c)) {
		if (str == "+") {
			value = atoi(l.c_str()); //convert to int
			value++; //inc
			lable.SetValue(to_string(value));
			lable.draw();
		}
		if (str == "-") {
			value = atoi(l.c_str()); //convert to int
			value--; //inc
			lable.SetValue(to_string(value));
		}
	}
	//{
		//if (beetween(c.Y,getCoord().Y + 1, getCoord().Y + this->width)) {
		//	this->current = c.Y - getCoord().Y - 1;
		//}
		//this->print();
	//}

	return 0;
}

int Button::keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD)
{
	return 0;
}


