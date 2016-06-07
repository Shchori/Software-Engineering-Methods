#include "IControl.h"

void IControl::draw() {
	Graphics g = Graphics::getInstance();
	if (visability || this->isCoordSet()) {
		g.setCursorVisibility(this->visability);
		g.setBackground(this->backGroundColor);
		g.setForeground(this->foregroundColor);
		this->drawBorder();
	}

};
IControl::IControl(
	unsigned int height,
	unsigned int width,
	BorderType borderType,
	Color foregroundColor,
	Color backGroundColor,
	bool showcruser,
	bool visability,
	bool foucus
	) :height(height), width(width), borderType(borderType), foregroundColor(foregroundColor),
	backGroundColor(backGroundColor), showcruser(showcruser), visability(visability), foucus(foucus)
{
	this->_CoordSet = false;
}
void IControl::drawBorder() {
	if (this->borderType != BorderType::None) {
		Graphics g = Graphics::getInstance();
		Border* b = NULL;
		switch (this->borderType)
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
		for (int i = 1; i <= this->height - 2; i++)
		{
			g.write(this->_coord.X, this->_coord.Y + i, string(1, b->vertical));
			g.write(string(this->width, ' '));
			g.write(string(1, b->vertical));
		}
		g.write(this->_coord.X, this->_coord.Y + this->height - 1, string(1, b->bottomLeftCorner));
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