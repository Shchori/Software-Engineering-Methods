#include "Panel.h"

bool Panel::firstPanel = false;

Panel::Panel(int height, int width) :IControl(height, width + 2, BorderType::None, false, true, false, Color::White, Color::Black)
{
	if (!firstPanel)
		firstPanel = true;
	COORD c = {0,0};
	IControl::setCoord(c);
}

void Panel::AddControl(IControl& control, int left, int top)
{
	COORD panelCoord = { this->getCoord().X,this->getCoord().Y };
	COORD topLeftCoord = { panelCoord.X +left, panelCoord.Y + top };
	COORD topRightCoord = { topLeftCoord.X, topLeftCoord.Y + control.getWidth() };
	COORD bottomLeftCoord = { topLeftCoord.X + control.getHeight(), topLeftCoord.Y };
	COORD bottomRightCoord = { topLeftCoord.X + control.getHeight(),
							  topLeftCoord.Y + control.getWidth() };

	bool res, flag = false;

	for (int i = 0; i < _innerPanels.size() && !(flag); i++) 
	{
		res = (*_innerPanels[i]).inArea(topLeftCoord);
		if (res) { flag = true; break; }
		res = (*_innerPanels[i]).inArea(topRightCoord);
		if (res) { flag = true; break; }
		res = (*_innerPanels[i]).inArea(bottomLeftCoord);
		if (res) { flag = true; break; }
		res = (*_innerPanels[i]).inArea(bottomRightCoord);
		if (res) { flag = true; break; }
	}

	if (!flag)
	{
		COORD c2 = control.getCoord();
		if (c2.X == NULL) {
				control.setCoord(topLeftCoord); 
				// non - relative:
				// the exact Coord acording to the full screen

		}				
		_innerPanels.push_back(&control);
		control.draw();
	}

	else
		printf("There is no plase for this control");

}
