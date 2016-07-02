#include "ComboBox.h"


ComboBox::ComboBox(int height, int width,vector<string> options):RadioList(height, width, options) {
	for (int i = 0; i < options.size(); i++) {

	}
}


ComboBox::~ComboBox()
{
}
