#pragma once
#include "priceengine.h"

class BlackScholes : public PriceEngine
{
public:
	BlackScholes(double optionType, double strike, double expiry, double spot, double r, double Vol);
	virtual double price() override;
};

