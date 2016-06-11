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
protected:
	IControl(unsigned int height, unsigned int width, BorderType borderType, bool showcruser, bool visability, bool foucusColor, Color foregroundColor, Color backGroundColor) ;
	unsigned int height;
	unsigned int width;
	BorderType _borderType;
	Color _foregroundColor;
	Color _backGroundColor;
	bool _showcruser;
	bool _cursorVisability;
	bool _foucus;
	void drawBorder();
	bool _isCoordSet() { return _CoordSet; };
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
	COORD getCoord() { 	return _coord; };
	void setCoord(COORD c);
	virtual void draw();
	virtual bool inArea(COORD c);
	void show() { this->setVisability(true); };
	void hide() { this->setVisability(false); };
	inline virtual ~IControl() {};

};
