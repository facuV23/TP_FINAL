#pragma once
#include <iostream>
#include <string.h>
#include "cTripulacion.h"

class cPasajero;
class cMarshall :public cTripulacion
{
public:
	cMarshall(cPersona* persona);
	~cMarshall();
	
	string Detener(cPasajero* pasajero);
};
