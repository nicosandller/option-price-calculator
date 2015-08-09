#include "StdAfx.h"
#include "Put.h"
#include "option.h"



Put::Put(void)
{
};


Put::Put(double strike, double expiry, double spot) : Option(strike,expiry,spot)
	{
	};

double Put::payoff()
	{
		double po = getStrike() - getSpot();
		if(po>0)
			{
			return po;
			};
			return 0;
		//return max(spot-getStrike(),0);
	};
