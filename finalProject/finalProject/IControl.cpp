#include "IControl.h"

IControl* IControl::focused = NULL;

void IControl::setFocused(IControl* c) {
	if (c) {
		if(IControl::focused) IControl::focused->_focus = false;
		c->_focus = true;
		IControl::focused = c;
	}
}


IControl::IControl(int height, int width):
	height(height),width(width),_backGroundColor(Color::Black),_showcruser(false),
		 _cursorVisability(true), _focus(false), _borderType(BorderType::None), _foregroundColor(Color::White), g(Graphics::getInstance())
{

	this->_CoordSet = false;
	this->_layer = 0;
}


void IControl::drawBorder() {
	if (this->_borderType != BorderType::None) {
		g = Graphics::getInstance();
		Border* b=NULL;
		switch (this->_borderType)
		{
		case(BorderType::Double) :
			b = new DoubleBorder();
			
		case(BorderType::Single) :
			b = new SingleBorder();
			break;

		}

		g.write(this->_coord.X, this->_coord.Y, string(1, b->topLeftCorner));
		g.write(string(this->width, b->horizontal));
		g.write(string(1, b->topRightCorner));
		for (int i = 1; i <= this->height-2; i++)
		{
			g.write(this->_coord.X , this->_coord.Y+i, string(1, b->vertical));
			g.write(string(this->width, ' '));
			g.write(string(1, b->vertical));
		}
		g.write(this->_coord.X , this->_coord.Y + this->height-1, string(1, b->bottomLeftCorner));
		g.write(string(this->width, b->horizontal));
		g.write(string(1, b->bottomRightCorner));
		delete b;
	}

}

void IControl::draw() {
	if (_cursorVisability || this->_isCoordSet()) {
		g.setCursorVisibility(this->_cursorVisability);
		g.setBackground(this->_backGroundColor);
		g.setForeground(this->_foregroundColor);
		g.updateConsoleAttributes();
		this->drawBorder();
	}

};

bool IControl::beetween(int p, int x1, int x2) {
	return (p >= x1&&p <= x2);
}

bool IControl::inArea(COORD c)
{
	int x = this->getCoord().X, y = this->getCoord().Y;
	return beetween(c.X, x, x + width) && beetween(c.Y, y, y + this->height);
}


void IControl::setCoord(COORD c) {
	this->_CoordSet = true;
	_coord = c;
}
