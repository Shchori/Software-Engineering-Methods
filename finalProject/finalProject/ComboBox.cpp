#include "ComboBox.h"


ComboBox::ComboBox(int width,vector<string> options):Panel(1,width),value(width - 3,""),radio(options.size()*3,width,options), openB("V",1),open(false){
	radio.setVisability(false);
	this->addControl(value, 0, 0);
	this->addControl(openB, width - 3,0);
}


