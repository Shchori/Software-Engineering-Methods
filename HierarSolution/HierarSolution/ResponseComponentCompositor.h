#pragma once
#include "ResponseComponent.h"

class ResponseComponentCompositor:public ResponseComponent
{
private:
	int _mark;
public:
	void mark(int n) { this->_mark = n; };
	virtual ~ResponseComponentCompositor ()= 0;
};