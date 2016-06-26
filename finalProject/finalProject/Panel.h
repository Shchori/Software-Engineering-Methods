#pragma once
#include "constants.h" //include all project constants
#include<Windows.h>
#include <vector>
#include "Graphics.h"
#include "border.h"
#include "IControl.h"

using namespace std;

class Panel: public IControl {
	protected:
		vector<IControl*> _innerPanels;
		void setInLocation(IControl& control);

	public:
		Panel(int height, int width);
		void addControl(IControl& control, int left, int top);
		void draw();
		void setCoord(COORD c);
		vector<IControl*> getAllControls();
		virtual ~Panel() {};

};