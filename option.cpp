#include "stdafx.h"
#include <iostream>
#include "option.h"
using namespace std;


Option::Option()
{
	strike = 2;
	expiry = 2;
	spot = 4;
};

//En el .cpp armamos el constructor:
Option::Option(double strike , double expiry, double spot){

	this->strike = strike;
	this->expiry = expiry;
	this->spot = spot;
	this->price = 0;


};

double Option::getStrike()
	{
		return this->strike;
	};

void Option::setStrike(double x)
	{
		strike = x;
	};

double Option::getSpot()
	{
		return this->spot;
	};

void Option::setSpot(double x)
	{
		spot = x;
	};


double Option::payoff(){ return 0; };
