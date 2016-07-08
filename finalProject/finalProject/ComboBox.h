#pragma once
#include "Panel.h" 
#include "Label.h"
#include "button.h"
#include "RadioList.h"

struct openBoxListener;
class ComboBox: public Panel{
private:
	class radioListForComboBox :public RadioList {
	public:
		radioListForComboBox(int height, int width, vector<string> options) :RadioList(height, width, options){};
		void setSelectedIndex(int index) {
			RadioList::setSelectedIndex(index);
			this->setVisability(false);
		};
	};
	Label value;
	radioListForComboBox radio;
	Button openB;
	bool open;
	openBoxListener *listener;
protected:
	void addControl(IControl& control, int left, int top) {
		Panel::addControl(control, left, top);
	}
public:
	ComboBox(int width, vector<string> options);
	void setOpen(bool open) { radio.setVisability(open); this->open = open; };
	bool getOpen() { return open; };
	void draw();
	void setCoord(COORD c);
	vector<IControl*> getAllControls();
	int getSelectedIndex() { return this->radio.getSelectedIndex(); };
	void setSelectedIndex(int index) { radio.setSelectedIndex(index); };
};


struct openBoxListener :public MouseListener
{
private:
	ComboBox *_box;

public:
	openBoxListener(ComboBox &box) :_box(&box) {}

	void mousePressed(Button &b, int x, int y, bool isLeft) {
		COORD c = { x,y };
		if (b.inArea(c) && isLeft)
		{
			this->_box->setOpen(!_box->getOpen());
		}

	}
};
