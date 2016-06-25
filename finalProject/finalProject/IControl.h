#pragma once
#include "constants.h" //include all project constants
#include<Windows.h>
#include "Graphics.h"
#include "border.h"
#include <vector>
using namespace std;

class IControl {
private:
	COORD _coord;
	bool _CoordSet;
	int _layer;
	static IControl* focused;
protected:
	IControl(int height, int width) ;
	unsigned int height;
	unsigned int width;
	BorderType _borderType;
	Color _foregroundColor;
	Color _backGroundColor;
	Graphics g;
	bool _showcruser;
	bool _cursorVisability;
	bool _focus;
	void drawBorder();
	bool _isCoordSet() { return _CoordSet; };
	void _setLayer(int layer) { _layer = layer; };
	
public:
	static void setFocused(IControl* c);
	static IControl* getFocused() { return IControl::focused; };
	bool isFocus() { return _focus; };
	virtual int getHeight() { return (_borderType==BorderType::None)?height:height + 2; };
	virtual int getWidth() { return (_borderType == BorderType::None) ? width : width + 2; };
	void setVisability(bool visability) { _cursorVisability = visability; };//of the cursor
	bool getVisability() { return _cursorVisability; };//of the cursor
	BorderType getBorder() { return _borderType; };
	void setBorder(BorderType border) { _borderType = border; draw(); };
	void setBackgroundColor(Color background) { _backGroundColor = background; }
	Color getBackgroundColor() { return _backGroundColor; }
	void setForegroundColor(Color Color) { _foregroundColor = Color; }
	Color getForegroundColor() { return _foregroundColor; };
	virtual COORD getCoord() { 	return _coord; };
	virtual void setCoord(COORD c);
	virtual void setCoord(int x, int y) { COORD c = { x,y }; this->setCoord(c); };
	virtual void draw() = 0;
	virtual bool inArea(COORD c);
	bool beetween(int p, int x1, int x2);
	void show() { this->setVisability(true); };
	void hide() { this->setVisability(false); };
	int getLayer() { return _layer; };
	inline virtual ~IControl() {};
	virtual vector<IControl*> getAllControls();
};
