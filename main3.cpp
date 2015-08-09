// main.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <iostream>
#include "option.h"
#include "call.h"
#include "Put.h"
#include <string>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <cstdlib>
#include "PriceEngine.h"
#include "BlackScholes.h"
#include "MonteCarlo.h"

using namespace std;

int main()
{

	cout << "Bienvenidos al Price Engine para opciones" << endl;

	string line;
	string  type,strike,spot,expiry;
	char* c_type;
	const char* c_strike;
	const char* c_spot;
	const char* c_expiry;
	double dbl_strike,dbl_spot,dbl_expiry;
	double r,Vol,d1,d2;

	//Insertar Volatilidad y Risk Free.
	cout << "Inserte la volatilidad: ";
	cin >> Vol;
	cout << "Inserte la tasa de Risk Free: ";
	cin >> r;


	ifstream input;
	input.open("options.csv");

	//Armo un loop para que vaya leyendo linea por linea el archivo CSV.
	while(input.good()){
		
		//Busco el tipo de opcion y lo guardo en Type. Leo input hasta la primera coma y lo guardo en un string.
		getline(input,type,',');


		//Convierto type de string a const char*
		c_type =new char [type.length()];
		strcpy (c_type,type.c_str());


		//Si es Call que cree una instancia de Call.
		if(strcmp(c_type,"C") == 0){
			
			//convertimos el strike que es un stream en un puntero a un constant character. Despues metemos el puntero a un const char en ATOF() para que devuelva un double).
			getline(input,strike,',');
			const char* c_strike= strike.c_str();
			dbl_strike = atof(c_strike);
	
			getline(input,spot,',');
			const char* c_spot= spot.c_str();
			dbl_spot = atof(c_spot);
			
			getline(input,expiry,'\r');
			const char* c_expiry= expiry.c_str();
			dbl_expiry = atof(c_expiry);
			////////////////////////////////

			//Construimos la Opcion.
			Call A= Call(dbl_strike,dbl_expiry,dbl_spot);
			BlackScholes B= BlackScholes(1,dbl_strike,dbl_expiry,dbl_spot,r,Vol);
			MonteCarlo C= MonteCarlo(1,dbl_strike,dbl_expiry,dbl_spot,r,Vol);
			cout << "CALL| K:" <<dbl_strike << "| S:"<< dbl_spot << "| Price MC:" << C.price() << "| Price BS:" << B.price() <<endl;
		

		} else {
			
			////////
			getline(input,strike,',');
			const char* c_strike= strike.c_str();
			dbl_strike = atof(c_strike);
	
			getline(input,spot,',');
			const char* c_spot= spot.c_str();
			dbl_spot = atof(c_spot);
			
			getline(input,expiry,'\r');
			const char* c_expiry= expiry.c_str();
			dbl_expiry = atof(c_expiry);
	
			Put A= Put(dbl_strike,dbl_expiry,dbl_spot);
			BlackScholes B= BlackScholes(-1,dbl_strike,dbl_expiry,dbl_spot,r,Vol);
			MonteCarlo C= MonteCarlo(-1,dbl_strike,dbl_expiry,dbl_spot,r,Vol);
			cout << "PUT| K:" <<dbl_strike << "| S:"<< dbl_spot << "| Price MC:" << C.price() << "| Price BS:" << B.price() <<endl;
		};

	
	};



	system("pause");
}

