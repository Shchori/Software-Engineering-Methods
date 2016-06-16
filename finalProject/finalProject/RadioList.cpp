#include "RadioList.h"


RadioList::RadioList(int height, int width, vector<string> options):IControl(height, width),selectedIndex(-1)
{
	this->options = options;
}

void RadioList::draw() {
	Graphics graphics = Graphics::getInstance();
	Border* border=NULL;
	
	if (getVisability()) {
		switch (getBorder()) {
		case BorderType::Single:
			break;
		case BorderType::Double:
			break;
		}
	}

	for (auto i : options){
		graphics.write(this->getCoord().X + 1, this->getCoord().Y + 1, i);
	}
	

}

bool RadioList::inArea(COORD c) {
	return true;
}

size_t RadioList::GetSelectedIndex() {
	return 1;
}

void RadioList::SetSelectedIndex(size_t index) {

}

RadioList::~RadioList()
{
}
