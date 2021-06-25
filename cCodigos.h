#pragma once
#include <iostream>
#include <string>

#define TU 850
#define BS 80
#define PC 70
#define filasPC 7 //fila 0-7 sin incluir 7 PC, primeras filas reservadas para PC y asi con todas las categorias
#define filasBS 8 //fila 7-16 sin incluir 16 tenemos BS
#define filaTU 16 //fila 16-99 tenemos TU
#define filasmax 100
//cada categoria tiene asignada filas, aleatoreamente se determina un asiento y fila para el marshalll en base 
//se hace el codigo del resto de los pasajeros
class cPersona;
using namespace std;
class cCodigos
{
	static int f_pc;
	static int f_tu;
	static int f_bs;
	static int f_marshall;
	static char aa_pc;
	static char aa_tu;
	static char aa_bs;
	static char aa_marshall;
	string Mi_codigo;
	
public:
	cCodigos(string c=" ");
	~cCodigos();
	string Getcodigos()const;
	static cCodigos* FormarCodigo(cPersona*persona);
	bool operator==(const string& der);
};

