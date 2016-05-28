#pragma once
#include "constants.h" //include all project constants
#include<Windows.h>

class IControl {
private:
	unsigned int height;
	unsigned int width;
	BorderType _borderType;
	ForegroundColor _forergroundColor;
	BackgroundColor _backgroundColor;
	COORD _coord;
	bool _showcruser;
	bool _visability;
protected:
public:
	void setVisability(bool show) { _visability = show; };
	bool getVisability() { return _visability; };
	BorderType getBorder() { return _borderType };
	void setBorder(BorderType border) { _borderType = border; };
	void setForegroundColor(ForegroundColor foregoround) { _forergroundColor = foregoround; };
	ForegroundColor getForegroundColor() { return _forergroundColor; }
	void setBackgroundColor(BackgroundColor backgroundColor) { _backgroundColor = backgroundColor; };
	BackgroundColor getBackgroundColor() { return _backgroundColor; };
	COORD getCoord() { return _coord; };
	void setCoord(COORD c) { _coord = c; };
	virtual void draw() {		};
	//virtual bool inArea(COORD c) {};
	void show() { this->setVisability(true); };
	void hide() { this->setVisability(false); };

};