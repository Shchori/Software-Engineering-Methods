#include "TextBox.h"

TextBox::TextBox(int width) : IControl(width, 1) {
	value.resize(width);

	dataLen = -1;
	currPosition = -1;
	g.moveTo(1, 1);
	COORD c;
	c.X = getCoord().X + 1;
	c.Y = getCoord().Y + 1;

	setCoord(c);
	g.setCursorVisibility(true);
}

void TextBox::SetText(char value) {
	COORD c;
	string s(1, value);

	if (currPosition == dataLen) {
		this->value.at(dataLen) = value;
		g.write(s);
	}
	else if (currPosition < dataLen) {
		string subS;
		for (int i = dataLen; i >= currPosition; i--) {
			this->value[i] = this->value[i - 1];
		}
		this->value[currPosition] = value;
		string sub = "";
		for (int i = currPosition; i < dataLen + 1; i++) {
			sub += (this->value[i]);
		}
		g.write(sub);

	}
	g.moveTo(getCoord().X + 1, getCoord().Y);
	c.X = getCoord().X + 1;
	c.Y = getCoord().Y;
	setCoord(c);
}

string TextBox::GetText() {
	string s = string(value.begin(), value.end());
	return s;
}

void TextBox::draw() {
	drawBorder();
}

int TextBox::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output) {
	COORD c = mer.dwMousePosition;
	cout << "mouse";
	if (c.X < dataLen && c.Y == getCoord().Y) {
		g.moveTo(c.X, c.Y);
		setCoord(c);
	}
	else if (c.Y == getCoord().Y) {
		g.moveTo(width, c.Y);
	}
	else {
		g.setCursorVisibility(false);
	}
	c.Y = getCoord().Y + 1;
	return 0;
}


int TextBox::keyPress(KEY_EVENT_RECORD ker, HANDLE output) {
	COORD c;
	// if key was pressed
	if (ker.bKeyDown) {
		//checks the key value
		switch (ker.wVirtualKeyCode) {
		case VK_BACK:// backspace
			if (currPosition > -1 && dataLen > -1) {
				c.X = getCoord().X-1 ;
				c.Y = getCoord().Y;
				g.moveTo(c.X, c.Y);

				if (currPosition <= dataLen) {
					string sub = "";
					for (int i = currPosition+1; i <= dataLen; i++) {
						sub += (this->value[i]);
						this->value[i-1] = this->value[i];
					}
					this->value[currPosition] = ' ';
					sub += " ";
					g.write(sub);
					setCoord(c);
					
				}
				currPosition--;
				dataLen--;
				g.moveTo(c.X, c.Y);

			}
			break;
		case VK_LEFT:
			if (currPosition>-1) {
				c.X = getCoord().X - 1;
				c.Y = getCoord().Y;
				g.moveTo(c.X, c.Y);
				setCoord(c);
				currPosition--;
			}

			break;
		case VK_RIGHT:
			if (currPosition < dataLen) {
				c.X = getCoord().X + 1;
				c.Y = getCoord().Y;
				g.moveTo(c.X, c.Y);
				setCoord(c);
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
			width = 20;
			//cout << "width:" << width << " " << currData;
			if (dataLen != width - 1) {
				dataLen++;
				currPosition++;
				/*g.moveTo(getCoord().X + 1, getCoord().Y);
				COORD c;
				c.X = getCoord().X + 1;
				c.Y = getCoord().Y;
				setCoord(c);*/
				//value.at(dataLen) = ker.uChar.AsciiChar;
				SetText(ker.uChar.AsciiChar);
			}
			break;
		}
	}
	return 0;
}

TextBox::~TextBox() {
}