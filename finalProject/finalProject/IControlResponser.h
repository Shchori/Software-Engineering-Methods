#pragma once

class IControlResponser
{
	virtual void keyDown(WORD code, char c) = 0;
	virtual void mousePressed(int x, int y, bool isLeftPressed)=0;
};