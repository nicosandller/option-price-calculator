#include "StdAfx.h"
#include "MonteCarlo.h"
#include "PriceEngine.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include "gbm.h"
#include "call.h"
#include "Put.h"


MonteCarlo::MonteCarlo(int optionType, double strike, double expiry, double spot, double r, double Vol) : PriceEngine(optionType,strike,expiry,spot,r,Vol)
{
};

double MonteCarlo::price()
{
	double sumaPayoff;

	if (getOptionType() == 1){
		for (int i=0; i<=500; i++){
			//Shock aleatorio.
			double RandShock = gaussian_box_muller();

			//Generamos St = Spot*exp((RiskFree - (Vol^2)/2)*Expiry + sqrt(Expiry*1)*Volatilidad*ShockAleatorio);
			double St = getSpot()*exp((getRiskfree()-pow(getVol(),2)/2)*getExpiry() + sqrt(getExpiry())*getVol()*RandShock);
			
			//Payoff de la opcion simulada en t.
			Call Y = Call(getStrike(),getExpiry(),St);
			sumaPayoff += Y.payoff();
		};

	} if(getOptionType() == -1) {
		for (int i=0; i<=500; i++){
			//Shock aleatorio.
			double RandShock = gaussian_box_muller();

			//Generamos St = Spot*exp((RiskFree - (Vol^2)/2)*Expiry + sqrt(Expiry*1)*Volatilidad*ShockAleatorio);
			double St = getSpot()*exp((getRiskfree()-pow(getVol(),2)/2)*getExpiry() + sqrt(getExpiry())*getVol()*RandShock);
			
			//Payoff de la opcion simulada en t.
			Put Z = Put(getStrike(),getExpiry(),St);
			sumaPayoff += Z.payoff();
		};		
		
	}
	//Pricing Montecarlo
		return (sumaPayoff)*exp(-getRiskfree()*getExpiry())/500;
};
