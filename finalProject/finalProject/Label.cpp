#include "Label.h"

Label::Label():IControl(1,1)
{
}

Label::Label(int width) :IControl(3, width + 2)
{
}

Label::~Label()
{
}

void Label::draw()
{
	if (this->getVisability() && this->_isCoordSet()) {
		IControl::draw();
		g.write(this->getCoord().X + 1, this->getCoord().Y + 1, str);
	}
}
