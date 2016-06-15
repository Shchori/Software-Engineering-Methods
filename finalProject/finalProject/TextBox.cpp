#include "TextBox.h"

TextBox::TextBox(int width) : IControl(width, 1) {
	value.resize(width);

	dataLen = -1;
	currPosition = -1;
	g.moveTo(1, 1);
	COORD c;
	c.X = getCoord().X + 1;
	c.Y = getCoord().Y+1;

	setCoord(c);
	g.setCursorVisibility(true);
}

void TextBox::SetText(char value) {
	string s(1, value);
	g.write(s);
	g.moveTo(getCoord().X+1, getCoord().Y);
	COORD c;
	c.X = getCoord().X + 1;
	c.Y = getCoord().Y;
	setCoord(c);
}

string TextBox::GetText() {
	string s = string(value.begin(), value.end());
	return s;
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

int TextBox::mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output) {
	COORD c = mer.dwMousePosition;
	cout << "mouse";
	if (c.X < dataLen && c.Y == getCoord().Y) {
		g.moveTo(c.X, c.Y);
		setCoord(c);
	}else if(c.Y == getCoord().Y){
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
			break;
		case VK_LEFT:
			if (getCoord().X > dataLen) {
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
			if (dataLen != width-1) {
				dataLen++;
				currPosition++;
				/*g.moveTo(getCoord().X + 1, getCoord().Y);
				COORD c;
				c.X = getCoord().X + 1;
				c.Y = getCoord().Y;
				setCoord(c);*/
				value.at(dataLen) = ker.uChar.AsciiChar;
				SetText(ker.uChar.AsciiChar);
			}
			break;
		}
	}
	return 0;
}

TextBox::~TextBox(){
}
