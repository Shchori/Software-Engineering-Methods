#include "Lable.h"


Lable::Lable(string s, int width):IControl(3, width+2, BorderType::None,false, true, false, Color::White, Color::Black),str("")
{
	this->SetValue(s);

}

Lable::~Lable()
{
}

void Lable::draw()
{
	if (this->getVisability()&&this->_isCoordSet()) {
		IControl::draw();
		Graphics g = Graphics::getInstance();
		g.write(this->getCoord().X + 1, this->getCoord().Y + 1, str);
	}
}
