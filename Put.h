#pragma once
#include "option.h"


class Put : public Option
{
public:
	
	Put(void);
	Put(double strike, double expiry, double spot);
	virtual double payoff() override;
};

