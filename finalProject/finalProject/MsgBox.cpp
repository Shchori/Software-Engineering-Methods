#include "MsgBox.h"


MsgBox::MsgBox(int height, int width) :Panel(height, width), btns(2, Button("", 6)), text(width, "")
{
	BorderType b = BorderType::Single;
	btns[0].setValue("OK");
	btns[1].setValue("Cancel");

	btns[0].setBorder(b);
	btns[1].setBorder(b);

	COORD c1 = { width / 2 - 4,height - 2 };
	COORD c2 = { width / 2 + 4,height - 2 };

	btns[0].setCoord(c1);
	btns[1].setCoord(c2);

	addControl(text, text.getCoord().X, text.getCoord().Y);

	for (int i = 0; i < 2; i++) {
		addControl(btns[i], btns[i].getCoord().X, btns[i].getCoord().Y);
	}
}

void MsgBox::SetText(string text) {
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