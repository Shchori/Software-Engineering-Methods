#pragma once
#include "IControl.h"


class IControlResponser : public IControl
{
	

public:
	IControlResponser(int height, int width):IControl::IControl(height,width) {
		this->_foucus = true;
	};

	virtual ~IControlResponser() =0;

};