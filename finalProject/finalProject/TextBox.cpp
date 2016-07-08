#include "TextBox.h"

TextBox::TextBox(int width, string str ) :Label(width, str){
	this->_focus = true;
}

void TextBox::draw() {
	Label::draw();
}

void TextBox::mousePressed(int x, int y, bool isLeftPressed) {
	IControl::setFocused(this);
	if(isLeftPressed) {
		COORD c = { x,y };
		if (Label::inArea(c)) {

			 double labelSize = Label::GetValue().size();
			 double labelX = Label::getCoord().X;
			 double totalCoord = labelX + labelSize;

			 if (x > totalCoord) c.X = totalCoord;
			 c.Y = Label::getHeight() + Label::getCoord().Y - 2;
			 Graphics g = Graphics::getInstance();
			 g.setCursorPosition(c);
		}
	}
}

void TextBox::keyDown(WORD code, char c) {

	Graphics g = Graphics::getInstance();
	COORD position = g.getCursorPosition();	
	int pos = position.X-1;

	if (Label::inArea(position)) {
			switch (code) {

			case VK_LEFT:
				if (pos > 1) {
					position.X -= 1;
					g.setCursorPosition(position);
				}
				break;

			case VK_RIGHT:
			{
				double labelSize = Label::GetValue().size();
				double labelX = Label::getCoord().X;
				double totalCoord = labelX + labelSize - 1;

				if (pos < totalCoord) {
					position.X += 1;
					g.setCursorPosition(position);
				}
			}
			break;
			case VK_UP:     break;
			case VK_DOWN:   break;

			default:
					//insert char in the middle of the string
					if (code >= 32 && code <= 176 && this->GetValue().length() < this->getWidth()) {
						string s = this->GetValue();
						s.insert(pos,1,c);
						this->setValue(s);

						if(pos != Label::getCoord().X + this->GetValue().length() - 1)
							position.X += 1;
						else
							position.X = Label::getCoord().X - 1;
						g.setCursorPosition(position);
					}

					//for backspace
					else if (code == 8) {
						string s = "";
						for (int i = 0; i < pos; i++) {
							s += this->GetValue()[i];
						}
						for(int i=pos+1; i<this->GetValue().length();i++)
							s += this->GetValue()[i];

						this->setValue(s);

						if(pos!=0)
						   position.X -= 1;
						else
							position.X = Label::getCoord().X + 1;

						g.setCursorPosition(position);

					}
					break;
			}
		}

}
