#pragma once
#include "cTripulacion.h"
#include <iostream>
#include <string.h>
#include "cAzafata.h"
#include "cCoPiloto.h"
class cPiloto :public cCoPiloto
{public:
	cPiloto(cPersona*persona);
	~cPiloto();
	string Pilotear();
    string LlamarAzafata(cAzafata* azafata);
	friend ostream& operator<<(ostream& out, const cPiloto& per);
};

ostream& operator<<(ostream& out, const cPiloto& per);