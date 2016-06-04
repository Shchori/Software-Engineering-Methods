#include "RadioList.h"


RadioList::RadioList(int height, int width, vector<string> options):IControl(height, width, BorderType::None, Color::White, Color::Black, false, true, false), selected_index(-1)
{
	this->options = options;
}

void RadioList::draw() {

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
