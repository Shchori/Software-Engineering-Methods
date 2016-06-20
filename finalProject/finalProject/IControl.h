#pragma once
#include "constants.h" //include all project constants
#include<Windows.h>
#include "Graphics.h"
#include "border.h"

using namespace std;

class IControl {
private:
	COORD _coord;
	bool _CoordSet;
	int _layer;
	static IControl* focused;
protected:
	static void setFocused(IControl* c);
	IControl(int height, int width) ;
	unsigned int height;
	unsigned int width;
	BorderType _borderType;
	Color _foregroundColor;
	Color _backGroundColor;
	Graphics g;
	bool _showcruser;
	bool _cursorVisability;
	bool _foucus;
	void drawBorder();
	bool _isCoordSet() { return _CoordSet; };
	void _setLayer(int layer) { _layer = layer; };
	int _getLayer() { return _layer; };
public:
	bool isFoucus() { return _foucus; };
	virtual int getHeight() { return height + 2; };
	virtual int getWidth() { return width + 2; };
	void setVisability(bool visability) { _cursorVisability = visability; };//of the cursor
	bool getVisability() { return _cursorVisability; };//of the cursor
	BorderType getBorder() { return _borderType; };
	void setBorder(BorderType border) { _borderType = border; draw(); };
	void setBackgroundColor(Color background) { _backGroundColor = background; }
	Color getBackgroundColor() { return _backGroundColor; }
	void setForegroundColor(Color Color) { _foregroundColor = Color; }
	Color getForegroundColor() { return _foregroundColor; };
	virtual COORD getCoord() { 	return _coord; };
	void setCoord(COORD c);
	virtual void draw() = 0;
	virtual bool inArea(COORD c);
	bool beetween(int p, int x1, int x2);
	void clearScreen() { g.clearScreen(); }
	void show() { this->setVisability(true); };
	void hide() { this->setVisability(false); };
	inline virtual ~IControl() {};

};
