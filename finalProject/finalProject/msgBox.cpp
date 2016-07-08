#include "MsgBox.h"

void MsgBox::addControl(IControl& control, int left, int top) {
	Panel::addControl(control, left, top);
}

MsgBox::MsgBox(int height, int width, string str, string title) :Panel(height, width), text(width, str), title(width,title), btns(2, MsgBoxButton(this))
{
	BorderType b = BorderType::Single;
	btns[0].setValue("OK");
	btns[1].setValue("Cancel");

	if (height < 5) {
		height = 5;
		setHeight(5);
	}
	
	btns[0].setCoord((width / 2) - 8, height - 2);
	btns[1].setCoord((width / 2) + 2, height - 2);
	this->title.setCoord(width/2-(title.length())/2, 0);
	this->title.setForegroundColor(Color::Red);
	text.setCoord(2, 1);

	addControl(this->title, this->title.getCoord().X, this->title.getCoord().Y);
	addControl(text,text.getCoord().X, text.getCoord().Y);

	for (int i = 0; i < 2; i++) {
		addControl(btns[i], btns[i].getCoord().X, btns[i].getCoord().Y);
		btns[i].setBorder(b);
	}
	setBorder(b);
	this->_setLayer(2);
}

void MsgBox::setText(string text) {
	this->text.setValue(text);
}

string MsgBox::getText() {
	return text.GetValue();
}

void MsgBox::setTitle(string title) {
	this->title.setValue(title);
}

string MsgBox::getTitle() {
	return title.GetValue();
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

MsgBox::~MsgBox(){
}