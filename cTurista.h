#pragma once
#include <iostream>
#include <string.h>
#include "cAzafata.h"
#include "cPasajero.h"
#include "cCodigos.h"

using namespace std;
class cTurista :public cPasajero
{
public:
	cTurista(string nombre_Apellido,string dni,string profesion,enum_estado estado);
	~cTurista();
	string Saludar();
	static int contador_pasajero_TU;
	friend ostream& operator<<(ostream& out, const cTurista& per);
	friend class cAvion;
};

ostream& operator<<(ostream& out, const cTurista& per);


