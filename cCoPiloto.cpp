#include "cCoPiloto.h"

cCoPiloto::cCoPiloto(cPersona* persona):cTripulacion(persona)
{
}

cCoPiloto::~cCoPiloto()
{
}

string  cCoPiloto::Comunicar_Torre()
{
	string aux;
	srand(time(NULL));
	switch (rand()%2)
	{
	case 0:aux="pista libre";
		return aux;
		break;
	case 1: aux="Pista ocupada, espere nuestro aviso";
		return aux;
		break;

	}
}
