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
	COORD c = { left,top };
	bool res, flag = false;

	for (int i = 0; i < _innerPanels.size(); i++) 
	{
		res = (*_innerPanels[i]).inArea(c);
		if (res)
			flag = true;
	}

	if (!flag)
	{
		COORD c2 = control.getCoord();
		if (c2.X == NULL) {
				control.setCoord(c);
		}				
		_innerPanels.push_back(&control);
		control.draw();
	}

	else
		printf("There is no plase for this control");

}
