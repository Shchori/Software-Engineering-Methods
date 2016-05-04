#pragma once
#include "ResponseComponent.h"

class ResponseComponentCompositor:public ResponseComponent
{
private:
public:
	virtual void mark(int n)=0;
	virtual ~ResponseComponentCompositor ()= 0;
};