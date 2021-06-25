#include "cTripulacion.h"

cTripulacion::cTripulacion(cPersona* persona):cPersona(persona)
{
}

cTripulacion::~cTripulacion()
{
}

string cTripulacion::Saludar()
{
	return "HOLA GRACIAS POR VOLAR CON NOSOTROS, QUE DISFRUTEN SU VUELO";
}

ostream& operator<<(ostream& out, const cTripulacion& per)
{
	cPersona* p = (cPersona*)&per;
	out << *p;
	return out;
}

