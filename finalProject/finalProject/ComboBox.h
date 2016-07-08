#pragma once
#include "Panel.h" 
#include "Label.h"
#include "button.h"
#include "RadioList.h"

class ComboBox: public Panel{
private:
	class radioListForComboBox :public RadioList {
	public:
		radioListForComboBox(int height, int width, vector<string> options) :RadioList(height, width, options){};
		void setSelectedIndex(int index) {
			RadioList::setSelectedIndex(index);
			this->_visability = false;
		};
	};
	Label value;
	radioListForComboBox radio;
	Button openB;
	bool open;
public:
	ComboBox(int width, vector<string> options);
};

