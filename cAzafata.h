#pragma once
#include <iostream>
#include <string.h>
#include "cTripulacion.h"
#include "cLista.h"

class cPiloto;
class cAvion;
class cPasajero;
class cAzafata :public cTripulacion
{private:
	bool estado;
	cLista<cPasajero>& listap;
	static int contador_azafata;
public:
	cAzafata( cPersona*persona,bool estado, cLista<cPasajero>& listap);
	~cAzafata();
	string Informar_Pasajeros(cPasajero* pasajero,string pregunta);
	string Servir_Pilotos(cTripulacion* piloto, string com,string bebida);
	string Servicio_comida(string com,string bebida);
	string Atender(cPasajero* pasajero,string que_pasa);
	string Masajista(cPasajero* pasajero);
	void set_estado(bool estado);

	friend ostream& operator<<(ostream& out, const cAzafata& per);
	friend class cAvion;
};

ostream& operator<<(ostream& out, const cAzafata& per);


