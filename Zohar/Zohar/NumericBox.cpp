#include "NumericBox.h"






NumericBox::~NumericBox()
{
}

void NumericBox::draw()
{
	b_plus.setBorder(BorderType::Double);
	b_minus.setBorder(BorderType::Double);
	label.setBackgroundColor(Color::White);
	label.setForegroundColor(Color::Black);
	label.setBorder(BorderType::Double);
	b_plus.draw();
	label.draw();
	b_minus.draw();
}

void NumericBox::addEvent()
{
	p.setLabel(label);
	b_plus.AddListener(p);
	b_plus.mouseEvent(coord.X, coord.Y);
	p.setLabel(label);
	b_plus.AddListener(p);
	b_plus.mouseEvent(coord.X, coord.Y);
	m.setLabel(label);
	b_minus.AddListener(m);
	b_minus.mouseEvent(coord.X, coord.Y);
}
