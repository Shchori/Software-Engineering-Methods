#include "RadioList.h"


RadioList::RadioList(int height, int width, vector<string> options):IControl(height, width, BorderType::None, Color::White, Color::Black, false, true, false), selectedIndex(-1)
{
	this->options = options;
}

void RadioList::draw() {
	Graphics graphics = Graphics::getInstance();
	Border* border=NULL;
	
	if (visability) {
		switch (borderType) {
		case BorderType::Single:
			break;
		case BorderType::Double:
			break;
		case BorderType::None:
			break;
		}
	}

	for (auto i : options){
		graphics.write(this->getCoord().X + 1, this->getCoord().Y + 1, i);
	}
	

}

bool RadioList::inArea(COORD c) {

}

size_t RadioList::GetSelectedIndex() {

}

void RadioList::SetSelectedIndex(size_t index) {

}

RadioList::~RadioList()
{
}
