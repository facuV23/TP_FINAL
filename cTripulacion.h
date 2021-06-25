#pragma once
#include <iostream>
#include <string.h>
#include "cPersona.h"
class cTripulacion : public cPersona
{
public:
	cTripulacion(cPersona*persona);
	virtual ~cTripulacion();
	string Saludar();
	friend ostream& operator<<(ostream& out, const cTripulacion& per);
	bool operator==(const cTripulacion& tripulacion) { return this->dni == tripulacion.dni; };
};

ostream& operator<<(ostream& out, const cTripulacion& per);