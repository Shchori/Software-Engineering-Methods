#include "Button.h"
using namespace std;


Button::Button(string str, int width) :Label(str, width), pressed(false) {}


Button::~Button()
{
}


void Button::AddListener(MouseListener & listener)
{
	this->event = &listener;

}


void Button::draw()
{
	Label::draw();

}

int Button::mouseEvent(int x, int y)
{
	COORD c{ x,y };
	if (this->inArea(c)) {
		pressed = true;
		this->event->MousePressed(*this, x, y, true);
	}
	return 0;
}

int Button::keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD)
{
	return 0;
}


