#include "StdAfx.h"
#include "call.h"
#include "option.h"


Call::Call(void)
{
};

Call::Call(double strike, double expiry, double spot) : Option(strike,expiry,spot)
	{
	};

double Call::payoff()
	{
		double po = getSpot() - getStrike();
		if(po>0)
			{
			return po;
			};
			return 0;
		//return max(spot-getStrike(),0);
	};