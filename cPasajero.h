#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
#include "cPersona.h"
#include "cMarshall.h"
#include "cAzafata.h"
#include "cCodigos.h"
using namespace std;
enum enum_estado {normal,loco,detenido, herido};
class cPasajero : public cPersona
{
protected:
	cCodigos* mi_codigo; 
	enum_estado estado;
public:
	
	cPasajero(enum_estado miestado, string nombre_Apellido, string dni,string profesion);
    ~cPasajero();
	virtual string LlamarAzafata(cAzafata* Azafata);
	virtual string Accionar();
	virtual string Reaccionar(); 
	string Saludar();
	string get_profesion()const ;
	cCodigos* GetCodigo()const;
	string Getcodigos() const;
	enum_estado get_estado() const;
	void set_estado(enum_estado estado);
	friend ostream& operator<<(ostream& out, const cPasajero& pas);
	friend class cAvion;
	bool operator==(const cPasajero& pasajero) { return this->dni == pasajero.dni; };

};
ostream& operator<<(ostream& out, const cPasajero& pas);