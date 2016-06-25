#include "TextBox.h"

TextBox::TextBox(int width, string str = "") :Label(width, str){}

void TextBox::draw() {
	Label::draw();
}

void TextBox::mousePressed(int x, int y, bool isLeftPressed) {
	if(isLeftPressed) {
		COORD c = { x,y };
		if (Label::inArea(c)) {

			 double labelSize = Label::GetValue().size();
			 double labelX = Label::getCoord().X;
			 double totalCoord = labelX + labelSize;

			 if (x > totalCoord) c.X = totalCoord;
			 c.Y = Label::getHeight() + Label::getCoord().Y;
			 Graphics g = Graphics::getInstance();
			 g.SetCursorPosition(c);
		}
	}
}

void TextBox::keyDown(WORD code, char c) {

}
