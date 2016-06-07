#pragma once
#include "constants.h" //include all project constants
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
	BorderType borderType;
	Color foregroundColor;
	Color backGroundColor;
	bool showcruser;
	bool visability;
	bool foucus;
	virtual void drawBorder();
	bool isCoordSet() { return _CoordSet; };
public:
	bool isFoucus() { return foucus; };
	virtual int getHeight() { return height + 2; };
	virtual int getWidth() { return width + 2; };
	void setVisability(bool show) { visability = show; };
	bool getVisability() { return visability; };
	BorderType getBorder() { return borderType; };
	void setBorder(BorderType border) { borderType = border; };
	void setBackgroundColor(Color background) { backGroundColor = background; };
	Color getBackgroundColor() { return backGroundColor; }
	void setForegroundColor(Color Color) { foregroundColor = Color; };
	Color getForegroundColor() { return foregroundColor; };
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
