#include "ComboBox.h"


ComboBox::ComboBox(int width,vector<string> options):Panel(3,width),master("",width),selectedIndex(0){

	for (int i = 0; i < options.size(); i++) {
		this->options[i].setValue(options[i]);
		addControl(this->options[i],getCoord().X,i);
	}

}

void ComboBox::setSelectedIndex(int index) {
	this->selectedIndex = index-1;
	master = options[selectedIndex];
}

int ComboBox::getSelectedIndex() {
	return this->selectedIndex;
}

ComboBox::~ComboBox()
{
}
