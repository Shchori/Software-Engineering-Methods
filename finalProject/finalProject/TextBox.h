#pragma once
#include "IControl.h"
#include "IControlResponser.h"
#include "Label.h"
#include <vector>
#include <iostream>

using namespace std;

class TextBox : public Label, public IControlResponser
{
private:

public:          
	TextBox(int width, string str);
	void draw();
	void keyDown(WORD code, char c);
	void mousePressed(int x, int y, bool isLeftPressed);
	virtual  ~TextBox() {}
};