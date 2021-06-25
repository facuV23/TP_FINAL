#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
#include "cCodigos.h"
using namespace std;

class cPersona
{
protected:
	string nombre_Apellido;
	string profesion;
	const string dni;
public:
	cPersona(string nombre_Apellido, string profesion, string dni);
	cPersona(const cPersona*p);
	string GetProfesion()const;
	string GetClave() const;
	string getnombre_ape();
	virtual ~cPersona();
	virtual string Saludar();
    friend ostream& operator<<(ostream& out, const cPersona& per);
	friend class cCodigos;
	friend class cAvion;
};

ostream& operator<<(ostream& out, const cPersona& per);