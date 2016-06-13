#pragma once
//#include "constants.h" //include all project constants
#include<Windows.h>
#include "Graphics.h"
#include "border.h"

class IControl {
private:
	COORD _coord;
	bool _CoordSet;
protected:
	IControl(unsigned int height, unsigned int width, BorderType borderType, Color foregroundColor, Color backGroundColor, bool showcruser, bool visability, bool foucus);
	unsigned int height;
	unsigned int width;
	BorderType _borderType;
	Color _foregroundColor;
	Color _backGroundColor;
	bool _showcruser;
	bool _visability;
	bool _foucus;
	virtual void drawBorder();
	bool _isCoordSet() { return _CoordSet; };
public:
	bool isFoucus() { return _foucus; };
	virtual int getHeight() { return height + 2; };
	virtual int getWidth() { return width + 2; };
	void setVisability(bool show) { _visability = show; };
	bool getVisability() { return _visability; };
	BorderType getBorder() { return _borderType; };
	void setBorder(BorderType border) { _borderType = border; };
	void setBackgroundColor(Color background) { _backGroundColor = background; };
	Color getBackgroundColor() { return _backGroundColor; }
	void setForegroundColor(Color Color) { _foregroundColor = Color; };
	Color getForegroundColor() { return _foregroundColor; };
	COORD getCoord() { return _coord; };
	void setCoord(COORD c) {
		this->_CoordSet = true;
		_coord = c;
	};
	virtual void draw() = 0;
	virtual bool inArea(COORD c);
	void show() { this->setVisability(true); };
	void hide() { this->setVisability(false); };

};