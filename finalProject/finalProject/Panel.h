#pragma once
#include "constants.h" //include all project constants
#include<Windows.h>
#include <vector>
#include "Graphics.h"
#include "border.h"
#include "IControl.h"

using namespace std;

class Panel : public IControl {
protected:
	vector<IControl*> _innerPanels;
	void setInLocation(IControl& control);
	
	public:
		Panel(int height, int width);
		void addControl(IControl& control, int left, int top);
		void draw();
		void setCoord(COORD c);

		virtual void _setLayer(int layer) {
			IControl::_setLayer(layer);
			for (int i = 0; i < _innerPanels.size(); i++) {
				_innerPanels[i]->_setLayer(layer);
			}
		}
		void setVisability(bool visability) {
			IControl::setVisability(visability);
			for (int i = 0; i < _innerPanels.size(); i++) {
				_innerPanels[i]->setVisability(visability);
			}
		}
		void setBackgroundColor(Color background) {
			IControl::setBackgroundColor(background);
			for (int i = 0; i < _innerPanels.size(); i++) {
				_innerPanels[i]->setBackgroundColor(background);
			}
		}
		void setForegroundColor(Color Color) {
			IControl::setForegroundColor(Color);
			for (int i = 0; i < _innerPanels.size(); i++) {
				_innerPanels[i]->setForegroundColor(Color);
			}
		}
		vector<IControl*> getAllControls();
		virtual ~Panel() {};


};