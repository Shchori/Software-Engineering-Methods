#include "Panel.h"

//bool Panel::firstPanel = false;

Panel::Panel(int height, int width) :IControl(height, width + 2)
{
	/*if (!firstPanel)
		firstPanel = true;
	COORD c = {0,0};
	IControl::setCoord(c);*/
}

void Panel::AddControl(IControl& control, int left, int top)
{
	COORD panelCoord = { this->getCoord().X,this->getCoord().Y };
	COORD topLeftCoord = { panelCoord.X +left, panelCoord.Y + top };
	COORD topRightCoord = { topLeftCoord.X + control.getWidth(), topLeftCoord.Y };
	COORD bottomLeftCoord = { topLeftCoord.X , topLeftCoord.Y + control.getHeight() };
	COORD bottomRightCoord = { topLeftCoord.X + control.getWidth() ,
							  topLeftCoord.Y + control.getHeight() };

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

	if (true)
	{
		control.setCoord(topLeftCoord);
		// non - relative -> with offset:
		// the exact Coord acording to the full screen

		senInLocation(control);
	}

	else
		printf("There is no place for this control");

}

void Panel::draw() {
	IControl::draw(); 
	for (int i = 0; i < _innerPanels.size(); i++)
		(*_innerPanels[i]).draw();
}

//----------------------------------------------------------------

void Panel::senInLocation(IControl& control) {

	IControl* temp;
	int current, index = 0;
	int controlX = control.getCoord().X;

	vector<IControl*> tempVec;

	for (int i = 0; i < _innerPanels.size(); i++) {
		current = (*_innerPanels[i]).getCoord().X;
		if (controlX < current) {
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


