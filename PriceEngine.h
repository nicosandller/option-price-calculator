#pragma once
class PriceEngine
{
private:
      double spot;
      double strike;
      double r;
      double Vol;
      double expiry;
	  int optionType; // optionType = 1 si es Call/ = -1 si es Put. (Para invertir el signo de Black Scholes).
public:
	  //Constructores.
	  PriceEngine(void);
	  PriceEngine(int optionType, double strike, double expiry, double spot, double r, double Vol);
	    
	  //Getters.
	  double getRiskfree();
	  double getVol();
	  double getStrike();
	  double getSpot();
	  double getExpiry();
	  int getOptionType();
	  //Precio como metodo virtual.
	  virtual double price();
};


