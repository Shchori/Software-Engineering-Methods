#include "NumericBox.h"






NumericBox::~NumericBox()
{
}

void NumericBox::draw()
{
	b_plus.setBorder(BorderType::Double);
	b_minus.setBorder(BorderType::Double);
	lable.setBackgroundColor(Color::White);
	lable.setForegroundColor(Color::Black);
	b_plus.draw();
	lable.draw();
	b_minus.draw();
}
