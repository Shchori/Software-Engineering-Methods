#include "ComboBox.h"

ComboBox::ComboBox(int width,vector<string> options):Panel(3,width),value(width - 4,""),radio(options.size(),width,options), openB("V",1),open(false){
	listener = new openBoxListener(*this);
	openB.AddListener(*listener);
	radio.setVisability(false);
	this->addControl(value, 1, 1);
	this->addControl(openB, width - 2,1);
	radio.setBorder(BorderType::Single);
	value.setBorder(BorderType::Single);
	openB.setBorder(BorderType::Single);
	this->_setLayer(1);
}
void ComboBox::draw()
{
	this->value.setValue(radio.getValue());
	Panel::draw();
	if (open) {
		radio.setForegroundColor(this->getForegroundColor());
		radio.setBackgroundColor(this->getBackgroundColor());
		radio.draw();
	}
}
void ComboBox::setCoord(COORD c)
{
	Panel::setCoord(c);
	c.Y += 4;
	this->radio.setCoord(c);
}
vector<IControl*> ComboBox::getAllControls()
{
		vector<IControl*> tempVec, result;
	result = Panel::getAllControls();
	if (open) {
		tempVec = radio.getAllControls();
		result.insert(result.end(), tempVec.begin(), tempVec.end());
		}
	return result;
}



