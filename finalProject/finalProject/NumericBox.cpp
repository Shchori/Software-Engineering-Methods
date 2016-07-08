#include "NumericBox.h"



struct Minus_Struct :public MouseListener
{
private:
	NumericBox *_box;
	
public:
	Minus_Struct(NumericBox &box) :_box(&box) {}

	void mousePressed(Button &b, int x, int y, bool isLeft) {
		COORD c = { x,y };
		if (b.inArea(c) && isLeft)
		{
			this->_box->setValue(_box->getValue() - 1);
		}

	}
};

typedef struct Plus_Struct :public MouseListener
{
private:
	NumericBox *_box;
public:
	Plus_Struct(NumericBox &box) :_box(&box) {}

	void mousePressed(Button &b, int x, int y, bool isLeft) {
		COORD c = { x,y };
		if (b.inArea(c) && isLeft)
		{
			this->_box->setValue(_box->getValue() + 1);
		}

	}
}plusListener;

NumericBox::NumericBox(int width, int minVal, int maxVal) :Panel(1, width),_plus("+",1), _minus("-",1),_val(4,""){
	_minVal = minVal;
	_maxVal = maxVal;
	_currentVal = minVal;
	setValue(minVal);

	BorderType b = BorderType::Single;
	_minus.setBorder(b);
	_plus.setBorder(b);
	Panel::setBorder(b);

	Plus_Struct * plus = new plusListener(*this);
	_plus.AddListener(*plus);

	Minus_Struct * minus = new Minus_Struct(*this);
	_minus.AddListener(*minus);

	addControl(_plus, 0, 0);
	addControl(_val, ((int)(width/2)) - 1, 0);
	addControl(_minus, width + 1, 0);
	//each numericBox - the width at least 8

	this->_setLayer(0);	
}

void NumericBox::setValue(int value) {
	if (value >= _minVal && value <= _maxVal) {
		_currentVal = value;
		_val.setValue(to_string(value));
	}
}

/*void NumericBox::mousePressed(int x, int y) {
	COORD c = { x,y };
	if (_plus.inArea(c)) {
		_plus.mousePressed(x, y, TRUE);
	}
	else if (_minus.inArea(c)) {
		_minus.mousePressed(x, y, TRUE);
	}
}*/
