#pragma once
#include "ResponseComponent.h"

class ResponseComponentCompositor:public ResponseComponent
{
protected:
	virtual void mark(int n) = 0 {};
public:
	ResponseComponentCompositor(const COORD c) :ResponseComponent(c) {};
	bool beetween(int p, int x1, int x2) {
		return (p >= x1&&p <= x2);
	}

	
	virtual ~ResponseComponentCompositor() = 0 {};
};

