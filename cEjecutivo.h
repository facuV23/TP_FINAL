#pragma once
#include <iostream>
#include <string.h>
#include "cAzafata.h"
#include "cPasajero.h"

using namespace std;
class cEjecutivo :public cPasajero
{	
public:
	cEjecutivo(string nombre_Apellido,string dni,string profesion, enum_estado estado);
	~cEjecutivo();
	string Accionar();
	string Saludar();
	static int contador_pasajeros_ejecutiva;
	friend class cAvion;
};

