#include "NumericBox.h"



struct Minus_Struct :public MouseListener
{
private:
	NumericBox *_box;
	Minus_Struct(NumericBox &box) :_box(&box) {}
public:
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

NumericBox::NumericBox(int height, int width, int minVal, int maxVal) :Panel(height, width),_plus("+",3), _minus("-",3),_val(4,""){
	_minVal = minVal;
	_maxVal = maxVal;
	_currentVal = minVal;
	setValue(minVal);

	Plus_Struct * plus = new plusListener(*this);
	_plus.AddListener(*plus);

	Minus_Struct * minus = new Minus_Struct(*this);
	_minus.AddListener(*minus);

	addControl(_plus, 0, 0);
	addControl(_val, 4, 0);
	addControl(_minus, 9, 0);

	this->_setLayer(0);	
}

void NumericBox::setValue(int value) {
	if (value >= _minVal && value <= _maxVal) {
		_currentVal = value;
		_val.setValue(to_string(value));
	}
}

void NumericBox::mousePressed(int x, int y) {

}
