#include "Button.h"



Button::Button(string str,int width):Lable(str,width){}


Button::~Button()
{
}

int Button::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output)
{


	return 0;
}

int Button::keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD)
{
	return 0;
}



