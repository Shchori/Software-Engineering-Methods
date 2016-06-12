#include "IControl.h"

void IControl::draw() {
	Graphics g = Graphics::getInstance();
	if (_cursorVisability ||this->_isCoordSet()) {
		g.setCursorVisibility(this->_cursorVisability);
		g.setBackground(this->_backGroundColor);
		g.setForeground(this->_foregroundColor);
		g.updateConsoleAttributes();
		this->drawBorder();
	}

};
IControl::IControl(
	unsigned int height,
	unsigned int width,
	BorderType borderType,
	bool showcruser,
	bool visability,
	bool foucus,
	Color foregroundColor,
	Color backGroundColor
		):height(height),width(width),_backGroundColor(backGroundColor),_showcruser(showcruser),
		 _cursorVisability(visability), _foucus(foucus), _borderType(borderType), _foregroundColor(foregroundColor)
{
	this->_CoordSet = false;
}


void IControl::drawBorder() {
	if (this->_borderType != BorderType::None) {
		Graphics g = Graphics::getInstance();
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

bool beetween(int p, int x1, int x2) {
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
