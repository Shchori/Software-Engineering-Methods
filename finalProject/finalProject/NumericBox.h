#pragma once
#include <iostream>
#include <vector>
#include "Panel.h"
#include "Label.h"
#include "Button.h"

using namespace std;

class NumericBox : public Panel, public IControlResponser
{
private:
	Button _plus;
	Button _minus;
	Label _val;
	int _minVal;
	int _maxVal;
	int _currentVal;

public:
	NumericBox(int height, int width, int minVal, int maxVal);
	int getValue() { return _currentVal; }
	void setValue(int value);
	void draw() { Panel::draw(); }
	void mousePressed(int x, int y);
	void keyDown(WORD code, char c) {}
	virtual ~NumericBox(){}
};