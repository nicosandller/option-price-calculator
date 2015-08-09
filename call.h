#pragma once
#include "option.h"

class Call : public Option
{
public:
	
	Call(void);
	Call(double strike, double expiry, double spot);
	virtual double payoff() override;
};

