/*#pragma once
#include <windows.h>
//#include "Button.h"
class Button;

struct MouseListener
{
	virtual void MousePressed(Button &b, int x, int y, bool isLeft) = 0;
};

struct subMouseListner :MouseListener {
	
	 void MousePressed(Button &b, int x, int y, bool isLeft)override {
		 COORD c_mouse{ x,y }; //the corrent pos of the mouse
		 if (b.inArea(c_mouse) && isLeft) {
			 b.pressCorrect();
		 }
	}
};
/*

class subMouseListner: public MouseListener
{
public:
	subMouseListner();
	virtual void MousePressed(Button &b, int x, int y, bool isLeft);
	~subMouseListner();
};*/

