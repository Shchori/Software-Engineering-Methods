#include "Button.h"
using namespace std;


Button::Button(string str, int width) :Label(width, str),event(NULL) { 
	this->_focus = true;
}


Button::~Button()
{
}


void Button::AddListener(MouseListener &listener)
{
	this->event = &listener;

}


void Button::draw()
{
	Label::draw();

}

void Button::mousePressed(int x, int y, bool isLeftPressed)
{
	COORD c{ x,y };
	if (this->event && this->inArea(c)) {
		
		this->event->mousePressed(*this, x, y, true);
		IControl::setFocused(this);
	}
}

void Button::keyDown(WORD code, char c)
{
	if (code == VK_RETURN && event)
	{
		this->event->mousePressed(*this, this->getCoord().X , this->getCoord().Y, true);
	}

}



