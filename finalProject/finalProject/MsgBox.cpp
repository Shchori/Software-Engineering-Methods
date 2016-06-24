#include "MsgBox.h"


MsgBox::MsgBox(int height, int width) :Panel(height, width), btns(2, Button("", 5)), text(width, "")
{
	BorderType b = BorderType::Single;
	btns[0].setValue("OK");
	btns[1].setValue("Cancel");

	btns[0].setBorder(b);
	btns[1].setBorder(b);

	COORD c1 = { (width/2)-8,height-5 };
	COORD c2 = { (width/2)+2,height-5 };
	COORD c3 = { 2,1 };
	btns[0].setCoord(c1);
	btns[1].setCoord(c2);
	text.setCoord(c3);
	addControl(text, text.getCoord().X, text.getCoord().Y);

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

void MsgBox::draw() {

	Panel::draw();

	g.setCursorVisibility(false);
}


MsgBox::~MsgBox()
{
}