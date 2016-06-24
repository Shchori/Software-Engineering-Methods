#pragma once
//#include "constants.h" //include all project constants
#include<Windows.h>
#include <vector>
#include "Graphics.h"
#include "border.h"
#include "IControl.h"

using namespace std;

class Panel : public IControl {
private:
	vector<IControl*> _innerPanels;
	void senInIocation(IControl& control);

public:
	Panel(int height, int width);
	void AddControl(IControl& control, int left, int top);
	void draw();
	vector<IControl*> getInnerPanels() { return _innerPanels; }
	virtual ~Panel() {};

	//static bool firstPanel;
};