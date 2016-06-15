#include "TextBox.h"

TextBox::TextBox(int width):IControl(width,1) {
	g.setCursorVisibility(true);
}
void TextBox::SetText(string value) {
	this->value = value;
}
string TextBox::GetText() {
	return value;
}
void TextBox::draw() {
	if (getVisability()) {
		drawBorder();
		g.write(GetText());
	}
}

int TextBox::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output) {
	return 0;
}

int TextBox::keyPress(KEY_EVENT_RECORD ker, HANDLE output) {
	POINT p;
	GetCursorPos(&p);
	// if key was pressed
	if (ker.bKeyDown) {
		//checks the key value
		switch (ker.wVirtualKeyCode) {
		case VK_BACK:// backspace
			break;
		case VK_LEFT:
			g.moveTo(p.x - 1, p.y);
			break;
		case VK_RIGHT:
			break;
		case VK_DOWN:case VK_TAB:
			break;
		case VK_UP:
			break;
		case VK_SPACE: case VK_RETURN:
			break;
		case VK_LBUTTON:break;
		default:
			break;
		}
	}
	return 0;
}
