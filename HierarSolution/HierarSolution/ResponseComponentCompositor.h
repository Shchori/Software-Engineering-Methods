#pragma once
#include "ResponseComponent.h"

class ResponseComponentCompositor:public ResponseComponent
{
protected:
	virtual void mark(int n)=0;
public:
	ResponseComponentCompositor(const COORD c) :ResponseComponent(c) {};
	
	virtual ~ResponseComponentCompositor ()= 0;
};


ResponseComponentCompositor::~ResponseComponentCompositor(){};