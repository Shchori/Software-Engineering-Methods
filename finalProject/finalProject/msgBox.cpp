#include "MsgBox.h"


MsgBox::MsgBox(int height, int width, string str) :Panel(height, width), text(width, str), btns(2, MsgBoxButton(this))
{
	BorderType b = BorderType::Single;
	btns[0].setValue("OK");
	btns[1].setValue("Cancel");

	btns[0].setBorder(b);
	btns[1].setBorder(b);
	setBorder(b);

	btns[0].setCoord((width / 2) - 8, height - 2);
	btns[1].setCoord((width / 2) + 2, height - 2);
	text.setCoord(2, 1);
	addControl(text,text.getCoord().X, text.getCoord().Y);

	for (int i = 0; i < 2; i++) {
		addControl(btns[i], btns[i].getCoord().X, btns[i].getCoord().Y);
	}

	this->_setLayer(2);
}

void MsgBox::setText(string text) {
	this->text.setValue(text);
}

string MsgBox::getText() {
	return text.GetValue();
}

string MsgBox::getPressedValue() {
	return pressedValue;
}
void MsgBox::setPressedValue(string value) {
	pressedValue = value;
}

void MsgBox::draw() {

	Panel::draw();

	g.setCursorVisibility(false);
}

void MsgBox::addControl(IControl& control, int left, int top) {
	Panel::addControl(control, left, top);
}

MsgBox::~MsgBox()
{
}