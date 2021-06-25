#include "cMarshall.h"
#include "cPasajero.h"

cMarshall::cMarshall(cPersona* persona):cTripulacion(persona)
{
}

cMarshall::~cMarshall()
{
}


string cMarshall::Detener(cPasajero* pasajero)
{
	if (pasajero->get_estado() == loco)
	{
		pasajero->set_estado(detenido);
		string aux = "Marshall ha detenido a pasajero, sus privilegios seran suspendidos";
		aux += "El pasajero detenido es:  " + pasajero->Saludar();
		return aux;
	}
	
}

