#include "TextBox.h"

TextBox::TextBox(int width, string str ) :Label(width, str){
	this->_focus = true;
	this->_showcruser = true;
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
			 double labelX = Label::getCoord().X ;
			 double totalCoord = labelX + labelSize;//end label

			 if (x <= totalCoord && x > labelX && labelSize != 0)
				 c.X = x;
			 else if (x > totalCoord)
				 c.X = totalCoord ;
			 else if(this->GetValue().length() == 0)
				 c.X = Label::getCoord().X + 2;
			 c.Y = Label::getHeight() + Label::getCoord().Y - 2;
			 Graphics g = Graphics::getInstance();
			 g.setCursorPosition(c);
		}
	}
}

void TextBox::keyDown(WORD code, char c) {

	Graphics g = Graphics::getInstance();
	COORD position = g.getCursorPosition();	
	int pos = position.X;

	if (Label::inArea(position)) {
			switch (code) {

			case VK_LEFT:
				if (pos - Label::getCoord().X - 1  > 0) {
					position.X -= 1;
					g.setCursorPosition(position);
				}
				break;

			case VK_RIGHT:
			{
				double labelSize = Label::GetValue().size();
				double labelX = Label::getCoord().X;
				double totalCoord = labelX + labelSize ;

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
					if (code >= 32 && code <= 176 && this->GetValue().length() + 2 < this->getWidth()) {
						 {
							string s = this->GetValue();
							s.insert(pos-this->getCoord().X -1 ,1,c);
							this->setValue(s);

							if(pos < Label::getCoord().X + this->GetValue().length())
								position.X += 1;

							g.setCursorPosition(position);
						}
						
					}

					//for backspace
					else if (code == 8) {
						string s = "";
						pos -= this->getCoord().X + 1;
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
