#include "NumericBox.h"






NumericBox::~NumericBox()
{
}

void NumericBox::draw()
{
	b_plus.setBorder(BorderType::Double);
	b_minus.setBorder(BorderType::Double);
	label.setBorder(BorderType::Double);
	label.setBackgroundColor(Color::White);
	label.setForegroundColor(Color::Black);
	b_plus.draw();
	label.draw();
	b_minus.draw();
}

void NumericBox::addEvent(string eventType)
{
	if (eventType == "plus") {
		p.setLabel(label);
		b_plus.AddListener(p);
		b_plus.mouseEvent(this->getCoord().X+coord.X, this->getCoord().Y+coord.Y);//i need to cng this to mouse position
	}
	if (eventType == "minus") {
		m.setLabel(label);
		b_minus.AddListener(m);
		b_minus.mouseEvent(b_minus.getCoord().X, b_minus.getCoord().Y);//i need to cng this to mouse position
	}
}
