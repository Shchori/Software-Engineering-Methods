#pragma once
#include"Label.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>
#include "button.h"
#include "Panel.h"


struct Minus_Struct :public MouseListener
{
	Label* l;
	void setLabel(Label & label) {
		l = &label;
	}
	void MousePressed(Button &b, int x, int y, bool isLeft) {
		int value;
		COORD c = { x,y };
		if (b.inArea(c) && isLeft)
		{
			value = atoi(l->GetValue().c_str());
			value--;
			if (value>=0)
			{ 
				(*l).SetValue(to_string(value));
				(*l).draw();
			}
			
		}

	}
};

struct Plus_Struct :public MouseListener
{
	Label* l;
	void setLabel(Label & label) {
		l = &label;
	}
	void MousePressed(Button &b, int x, int y, bool isLeft) {
		int value;
		COORD c = { x,y };
		if (b.inArea(c) && isLeft)
		{
			value = atoi(l->GetValue().c_str());
			value++;
			if (value <= 100) {
				(*l).SetValue(to_string(value));
				(*l).draw();
			}
		}

	}
};


class NumericBox :public Panel
{
protected:
	Plus_Struct p;
	Minus_Struct m;


public:
	NumericBox(int height,int width,int min,int max, short int b_width, short int lable_width,COORD c_panel):Panel(height,width),b_plus("+" ,b_width),b_minus("-",b_width),label(to_string(min),b_width),panel_c(c_panel){
		coord = { 4,4 };
		COORD tmp;
		b_plus.setCoord(coord);
		tmp = { coord.X + lable_width,coord.Y };
		label.setCoord(tmp);
		tmp = { tmp.X + b_width,coord.Y};
		b_minus.setCoord(tmp);
	
		/*BorderType b = BorderType::Double;
		Panel panel(10, 20);
		panel.setCoord(panel_c);
		panel.setBorder(b);
		panel.AddControl(b_plus, coord.X, coord.Y);
		panel.AddControl(label, coord.X + lable_width+1, coord.Y);
		panel.AddControl(b_minus, coord.X + lable_width + b_width +5, coord.Y);*/
		setCoord(panel_c);
		AddControl(b_plus, coord.X, coord.Y);
		AddControl(label, coord.X + lable_width + 1, coord.Y);
		AddControl(b_minus, coord.X + lable_width + b_width + 5, coord.Y);

		
	}
	
	~NumericBox();
	void draw();
	void addEvent(string eventType);
	
	
private:
	Button b_plus;
	Button b_minus;
	Label label;
	COORD coord;
	COORD panel_c;

};

