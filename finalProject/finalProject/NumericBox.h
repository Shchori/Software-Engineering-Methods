#pragma once
#include <iostream>
#include <vector>
#include "Panel.h"
#include "Label.h"
#include "Button.h"

using namespace std;

class NumericBox : public Panel
{
private:
	Button _plus;
	Button _minus;
	Label _val;
	MouseListener* _plusP;
	MouseListener* _minusP;
	int _minVal;
	int _maxVal;
	int _currentVal;

public:
	NumericBox(int width, int minVal, int maxVal);
	int getValue() { return _currentVal; }
	void setValue(int value);
	void draw() { Panel::draw(); }
	virtual ~NumericBox(){
		delete _minusP;
		delete _plusP;
	}
};