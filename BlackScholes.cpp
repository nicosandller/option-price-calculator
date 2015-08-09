#include "StdAfx.h"
#include "PriceEngine.h"
#include "BlackScholes.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include "cnd.h"


//BlackScholes::BlackScholes(void){};

BlackScholes::BlackScholes(double optionType, double strike, double expiry, double spot, double r, double Vol) : PriceEngine(optionType,strike,expiry,spot,r,Vol)
{
};

double BlackScholes::price()
{
	double d1 = (log(getSpot()/getStrike())+(getRiskfree()-pow(getVol(),2)/2)*(getExpiry()))/(getVol()*sqrt(getExpiry()));
	double d2 = d1-getVol()*sqrt(getExpiry());
	
	//Es Put o Call?
	if(getOptionType() == 1){
		double p = getOptionType()*getSpot()*phi(d1) - getOptionType()*getStrike()*phi(d2)*exp(-getRiskfree()*getExpiry());
	return p;
	}
	else{
		double p = getOptionType()*getSpot()*phi(-d1) - getOptionType()*getStrike()*phi(-d2)*exp(-getRiskfree()*getExpiry());
		return p;
	}
};

