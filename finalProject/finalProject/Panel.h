#pragma once
#include "constants.h" //include all project constants
#include<Windows.h>
#include <vector>
#include "Graphics.h"
#include "border.h"
#include "IControl.h"

using namespace std;

class Panel: public IControl {
	private:
		vector<IControl*> _innerPanels;

	public:
		Panel(int height, int width);
		void AddControl(IControl& control, int left, int top);
		void draw(){ IControl::draw(); }
		virtual ~Panel() {};

		static bool firstPanel;
};