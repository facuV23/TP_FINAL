#pragma once
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <string>
#include <time.h>
#include <math.h>
#include <string.h>
#include "cPasajero.h"
#include "cCoPiloto.h"
#include "cTripulacion.h"
#include "cAzafata.h"
#include "cCodigos.h"
#include "cPiloto.h"
#include "cSucesos.h"
#include "cEjecutivo.h"
#include "cTurista.h"
#include "cPrimeraClase.h"
#include "cLista.h"
#include "MisfuncionesRandom.h"

#define CANT_PASAJEROS 1000
#define CANT_POSIBLES_CODIGOS 1000
#define CANT_CODIGOS_DEFINITIVA 500
#define CANT_TRIPULACION 6
#define COUNTER_ITERACIONES 20
#define CANT_SUCESOS 1000
using namespace std;
class cAvion
{private:
	const string Numero_vuelo;
	
	cLista<cTripulacion> lista_tripulacion = cLista<cTripulacion>(CANT_TRIPULACION);
	cLista<cSucesos> lista_sucesos=cLista<cSucesos>(CANT_SUCESOS); 
	cLista<cCodigos> lista_codigos = cLista<cCodigos>(CANT_POSIBLES_CODIGOS);
	cLista<cPasajero>lista_pasajeros = cLista<cPasajero>(CANT_PASAJEROS);
	
	static int cont_sucesos;
	static int  counter;
public:
	cAvion(string Num_vuelo=" ");
	~cAvion();
	void Simular();//es la funcion que simula el viaje en avion, interactuando todas las clases
	cAzafata* Elegir_Azafata();// chequea azafata que este libre y la devuelve
	void Chequear_Preembarque();//forma la lista codigo definitiva
	void Cargar_Pasajeros();
	void Cargar_Tripulacion();
	void Cargar_Suceso(cPersona* presona, string que_hizo, string tiempo);
	void Cargar_codigo();
	//friend class Exception_codigo_invalido;
};
