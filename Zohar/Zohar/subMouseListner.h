#pragma once
#include "Button.h"

struct MouseListener
{
	virtual void MousePressed(Button &b, int x, int y, bool isLeft) = 0;
};

class subMouseListner: public MouseListener
{
public:
	subMouseListner();
	virtual void MousePressed(Button &b, int x, int y, bool isLeft);
	~subMouseListner();
};

