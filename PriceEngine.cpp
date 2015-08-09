#include "stdafx.h"
#include <iostream>
#include "StdAfx.h"
#include "PriceEngine.h"


PriceEngine::PriceEngine(void)
{
};

PriceEngine::PriceEngine(int optionType, double strike, double expiry, double spot, double r, double Vol)
{
	this->strike = strike;
	this->expiry = expiry;
	this->spot = spot;
	this->optionType = optionType;
	this->r=r;
	this->Vol=Vol;
};


double PriceEngine::getRiskfree(){
	return this->r;
};

double PriceEngine::getVol(){
	return this->Vol;
};

double PriceEngine::getSpot(){
	return this->spot;
};

double PriceEngine::getStrike(){
	return this->strike;
};

double PriceEngine::getExpiry(){
	return this->expiry;
};

int PriceEngine::getOptionType(){
	return this->optionType;
};



double PriceEngine::price(){
	return 0;
};
