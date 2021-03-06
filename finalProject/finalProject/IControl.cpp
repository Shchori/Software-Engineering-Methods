#include "IControl.h"

IControl* IControl::focused = NULL;

IControl::IControl(int height, int width) :
	height(height), width(width), _backGroundColor(Color::Black), _showcruser(false),
	_visability(true), _focus(false), _borderType(BorderType::None), _foregroundColor(Color::White), g(Graphics::getInstance())
{

	this->_CoordSet = false;
	this->_setLayer(0);
}

void IControl::drawBorder() {
	if (this->_borderType != BorderType::None) {
		g = Graphics::getInstance();
		Border* b=NULL;
		switch (this->_borderType)
		{
		case(BorderType::Double) :
			b = new DoubleBorder();
			break;
		case(BorderType::Single) :
			b = new SingleBorder();
			break;

		}

		g.write(this->_coord.X, this->_coord.Y, string(1, b->topLeftCorner));
		g.write(string(this->width, b->horizontal));
		g.write(string(1, b->topRightCorner));
		for (int i = 0; i < this->height; i++)
		{
			g.write(this->_coord.X , this->_coord.Y+i+1, string(1, b->vertical));
			g.write(string(this->width, ' '));
			g.write(string(1, b->vertical));
		}
		g.write(this->_coord.X , this->_coord.Y + this->height+1, string(1, b->bottomLeftCorner));
		g.write(string(this->width, b->horizontal));
		g.write(string(1, b->bottomRightCorner));
		delete b;
	}

}

void IControl::setFocused(IControl* c) {
	if (c) {
		IControl::focused = c;
	}
}

void IControl::setCoord(COORD c) {
	this->_CoordSet = true;
	_coord = c;
}

void IControl::draw() {
	if (_visability || this->_isCoordSet()) {
		g.setCursorVisibility(this->_showcruser);
		if (IControl::focused == this) {
			g.setBackground(this->_foregroundColor);
			g.setForeground(this->_backGroundColor);
		}
		else {
			g.setBackground(this->_backGroundColor);
			g.setForeground(this->_foregroundColor);
		}
		g.updateConsoleAttributes();
		this->drawBorder();
	}

};

bool IControl::inArea(COORD c)
{
	int x = this->getCoord().X, y = this->getCoord().Y;
	return beetween(c.X, x, x + this->getWidth() - 1) && beetween(c.Y, y, y + this->getHeight() - 1);
}

bool IControl::beetween(int p, int x1, int x2) {
	return (p >= x1&&p <= x2);
}

vector<IControl*> IControl::getAllControls() {
	vector<IControl*> tempVec;
	if (this->_focus)tempVec.push_back(this);
	return tempVec;
}