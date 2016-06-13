#include "TextBox.h"

TextBox::TextBox(int width, string val) :value(val), IControl(width, 1) {
	g.moveTo(1, 1);
	g.setCursorVisibility(true);
	mouseEvent();
}

void TextBox::SetText(string value) {
	g.write(value);
	g.moveTo(value.length(), 1);
}
string TextBox::GetText() {
	return value;
}

void TextBox::SetForeground(Color color) {
	g.setForeground(color);
}

void TextBox::SetBackground(Color color) {
	g.setBackground(color);
}

void TextBox::SetBorder(BorderType border) {
	
}

void TextBox::draw() {
	drawBorder();


}

bool beetween(int p, int x1, int x2) {
	return (p >= x1&&p <= x2);
}

int TextBox::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output) {
	COORD c = mer.dwMousePosition;
	if (inArea(c))
		if (!beetween(c.X, getCoord().X, getCoord().X + value.length())) {
			c.X = getCoord().X + value.length() + 1;
		}
	c.Y = getCoord().Y + 1;
	SetConsoleCursorPosition(output, c);
	return 0;
}


int TextBox::keyPress(KEY_EVENT_RECORD ker, HANDLE output) {
	// if key was pressed
	if (ker.bKeyDown) {
		//checks the key value
		switch (ker.wVirtualKeyCode) {
		case VK_DOWN:case VK_TAB:
			break;
		case VK_UP:
			break;
		case VK_SPACE: case VK_RETURN:
			break;
		case VK_LBUTTON:break;
		default:
			if (value.length() < width) {
				SetText(value += ker.uChar.AsciiChar);
			}
			break;
		}
	}
	return 0;
}

TextBox::~TextBox(){
}
