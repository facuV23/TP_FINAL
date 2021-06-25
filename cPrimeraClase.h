#pragma once
#include <iostream>
#include <string.h>
#include "cAzafata.h"
#include "cPasajero.h"

using namespace std;
class cPrimeraClase : public cPasajero
{
public:
	cPrimeraClase(string nombre_Apellido, string profesion, string dni, enum_estado estado);
	~cPrimeraClase();
     string LlamarAzafata(cAzafata* Azafata);
	 string Accionar();
	 string Saludar();
	 static int contador_pasajeros_PC;
	 friend ostream& operator<<(ostream& out, const cPrimeraClase& per);
	 friend class cAvion;
};

ostream& operator<<(ostream& out, const cPrimeraClase& per);
