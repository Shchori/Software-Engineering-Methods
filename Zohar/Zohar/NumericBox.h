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


class NumericBox 
{
protected:
	Plus_Struct p;
	Minus_Struct m;


public:
	NumericBox(int width, int min,int max, short int b_width, short int lable_width,COORD c):b_plus("+" ,b_width),b_minus("-",b_width),label(to_string(min),b_width),coord(c){
		/*COORD tmp;
		b_plus.setCoord(c);
		tmp = { c.X + lable_width,c.Y };
		label.setCoord(tmp);
		tmp = { tmp.X + b_width,c.Y};
		b_minus.setCoord(tmp);*/
	//	this->draw();
		//Plus_Struct p;
		
		BorderType b = BorderType::Double;
		Panel panel(10, 20);
		panel.setBorder(b);
		panel.AddControl(b_plus, c.X, c.Y);
		panel.AddControl(label, c.X + lable_width, c.Y);
		panel.AddControl(b_minus, c.X + lable_width + b_width, c.Y);

	}
	
	~NumericBox();
	void draw();
	void addEvent();
	
	
private:
	Button b_plus;
	Button b_minus;
	Label label;
	COORD coord;

};

