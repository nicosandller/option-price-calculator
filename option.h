#pragma once
class Option
{
private:
	double strike;
	double expiry;
	double spot; 
	double price;

public:
	//Estos son los constructores.
	Option();
	Option(double strike , double expiry, double spot); // dejamos afuera a price por que es la variable a definir. Lo que vamos a calcular
	void setStrike(double x);
	double getStrike();
	void setSpot(double x);
	double getSpot();

	//declaramos el payoff como virtual.
	virtual double payoff();

};