#include "Panel.h"
#include <typeinfo>


Panel::Panel(int height, int width) :IControl(height, width + 2)
{}

void Panel::setCoord(COORD c) {
	COORD old = { this->getCoord().X,  this->getCoord().Y };
	int relativeX, relativeY;
	IControl::setCoord(c);
	for(int i = 0; i < _innerPanels.size(); i++) {
		IControl& control = (*_innerPanels[i]);
		relativeX = control.getCoord().X - old.X;
		relativeY = control.getCoord().Y - old.Y;
		COORD topLeftCoord = { this->getCoord().X + relativeX, this->getCoord().Y + relativeY };
		(*_innerPanels[i]).setCoord(topLeftCoord);
	}
}

void Panel::addControl(IControl& control, int left, int top)
{
	// set the absolute corrd
	COORD panelCoord;
	if (!this->_isCoordSet())
		panelCoord = { 0,0 }; //will stay relative
	else
		panelCoord = { this->getCoord().X,this->getCoord().Y };

	COORD topLeftCoord = { panelCoord.X +left, panelCoord.Y + top };
	COORD topRightCoord = { topLeftCoord.X + control.getWidth()-1, topLeftCoord.Y };
	COORD bottomLeftCoord = { topLeftCoord.X , topLeftCoord.Y + control.getHeight()-1 };
	COORD bottomRightCoord = { topLeftCoord.X + control.getWidth()-1 ,
							  topLeftCoord.Y + control.getHeight()-1 };

	bool res, flag = false;

	res = this->inArea(bottomLeftCoord);
	if (res)
	{
		for (int i = 0; i < _innerPanels.size() && !(flag); i++)
		{
			if (_innerPanels.size() != 0) {
				res = (*_innerPanels[i]).inArea(topLeftCoord);
				if (res) { flag = true; break; }
				res = (*_innerPanels[i]).inArea(topRightCoord);
				if (res) { flag = true; break; }
				res = (*_innerPanels[i]).inArea(bottomLeftCoord);
				if (res) { flag = true; break; }
				res = (*_innerPanels[i]).inArea(bottomRightCoord);
				if (res) { flag = true; break; }
			}
		}
	}
	

	else
	 flag = true;

	if (!flag)
	{
		control.setCoord(topLeftCoord);
		// non - relative -> with offset:
		// the exact Coord acording to the full screen
		setInLocation(control);
	}

}

void Panel::draw() {
	IControl::draw(); 
	for (int i = 0; i < _innerPanels.size(); i++) {
		if ((*_innerPanels[i]).getLayer() == 0)
			(*_innerPanels[i]).draw();
	}
	for (int i = 0; i < _innerPanels.size(); i++) {
		if ((*_innerPanels[i]).getLayer() == 1)
			(*_innerPanels[i]).draw();
	}
	for (int i = 0; i < _innerPanels.size(); i++) {
		if ((*_innerPanels[i]).getLayer() == 2)
			(*_innerPanels[i]).draw();
	}		
}

vector<IControl*> Panel::getAllControls() {
	vector<IControl*> tempVec, result;
	for(int i=0; i < _innerPanels.size(); i++) 
	{
			tempVec = _innerPanels[i]->getAllControls();
			result.insert(result.end(), tempVec.begin(), tempVec.end());
		}
	return result;
}

//----------------------------------------------------------------

void Panel::setInLocation(IControl& control) {

	IControl* temp;
	int currentX, currentY, index = 0;
	int controlX = control.getCoord().X;
	int controlY = control.getCoord().Y;

	vector<IControl*> tempVec;

	for (int i = 0; i < _innerPanels.size(); i++) {
		currentX = (*_innerPanels[i]).getCoord().X;
		currentY = (*_innerPanels[i]).getCoord().Y;
		if (controlY < currentY) {
			index = i;
			break;
		}
		else if (controlX < currentX && controlY > currentY) {
			index = i;
			break;
		}
	}

	for (int i = 0; i < index; i++) 		
			tempVec.push_back(_innerPanels[i]);
	
	tempVec.push_back(&control);

	for (int i = index; i < _innerPanels.size(); i++)
		tempVec.push_back(_innerPanels[i]);

	_innerPanels = tempVec;

}




