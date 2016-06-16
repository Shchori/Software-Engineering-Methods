#include "TextBox.h"

TextBox::TextBox(int width):Label(width) {
	currPosition = 0;
	dataLen = 0;
	value.resize(width);
}

void TextBox::draw() {
	Label::draw();
	g.setCursorVisibility(true);
}

void TextBox::SetValue(string value) {
	Label::SetValue(value);
	dataLen += value.length();
}

int TextBox::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output) {
	COORD c = mer.dwMousePosition;
	if (inArea(c))
		if (!beetween(c.X, getCoord().X, getCoord().X + value.length())) {
			c.X = getCoord().X + value.length() + 1;
		}
	c.Y = getCoord().Y + 1;
	g.moveTo(c.X, c.Y);
	return 0;
}

int TextBox::keyPress(KEY_EVENT_RECORD ker, HANDLE output) {
	POINT p;
	GetCursorPos(&p);
	// if key was pressed in the textbox
	if (ker.bKeyDown && p.x==getCoord().X && p.y>=getCoord().Y && p.y<=width) {
		//checks the key value
		switch (ker.wVirtualKeyCode) {
		case VK_BACK:// backspace
			if (currPosition > 0) {
				p.x --;
				g.moveTo(p.x, p.y);
				if (currPosition <= dataLen) {
					string sub = "";
					for (int i = currPosition + 1; i <= dataLen; i++) {
						sub += (this->value[i]);
						this->value[i] = this->value[i + 2];
					}
					this->value[dataLen] = ' ';
					sub += " ";
					g.write(sub);
					currPosition--;
					dataLen--;
				}
			}
			break;
		case VK_LEFT:
			if (currPosition > 0) {
				g.moveTo(p.x - 1, p.y);
				currPosition--;
			}
			break;
		case VK_RIGHT:
			if (currPosition < dataLen) {
				g.moveTo(p.x + 1, p.y);
				currPosition++;
			}
			break;
		case VK_DOWN:case VK_TAB:
			break;
		case VK_UP:
			break;
		case VK_SPACE: case VK_RETURN:
			break;
		case VK_LBUTTON:break;
		default:
			char k = ker.uChar.AsciiChar;
			if (dataLen<width) {
				string s = "";
				s += k;
				currPosition++;
				dataLen++;
				if (currPosition == dataLen) {
					this->value[dataLen] = k;
					g.write(s);
				}
				else if (currPosition < dataLen) {
					string subS;
					for (int i = dataLen; i >= currPosition; i--) {
						this->value[i] = this->value[i - 1];
					}
					this->value[currPosition] = k;
					string sub = "";
					for (int i = currPosition; i < dataLen + 1; i++) {
						sub += (this->value[i]);
					}
					g.write(sub);

				}
				g.moveTo(p.x + 1, p.y);

			}
			break;
		}
	}
	return 0;
}

TextBox::~TextBox() {}
