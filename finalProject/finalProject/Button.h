#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>
#include "IControl.h"
#include "Label.h"
#include "Graphics.h"
#include "IControlResponser.h"

class Button;

struct MouseListener
{
	virtual void MousePressed(Button &b, int x, int y, bool isLeft) = 0;
	
};





class Button :public Label,public IControlResponser
{
protected:
	struct MouseListener *event;
	
public:
	Button(string str, int width);
	~Button();
	void AddListener(MouseListener &listener);
	void draw();
	virtual void mousePressed(int x, int y, bool isLeftPressed=true);
	virtual void keyDown(WORD code, char c);

};