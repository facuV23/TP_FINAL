#pragma once
#include "cTripulacion.h"
#include <iostream>
#include <string.h>


class cCoPiloto :public cTripulacion
{public:
	cCoPiloto(cPersona*persona);
	~cCoPiloto();
	string Comunicar_Torre();
	
};

