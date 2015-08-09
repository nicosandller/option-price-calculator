#pragma once
#include "PriceEngine.h"

class MonteCarlo: public PriceEngine
{
public:
	MonteCarlo(int optionType, double strike, double expiry, double spot, double r, double Vol);
	virtual double price() override;
};

