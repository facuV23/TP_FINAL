#include "cPiloto.h"
#include "MisfuncionesRandom.h"

cPiloto::cPiloto(cPersona* persona):cCoPiloto(persona)
{
}

cPiloto::~cPiloto()
{
}

string cPiloto::Pilotear()
{
	string aux;
	srand(time(nullptr));
	switch (rand() % 3)
	{
	case 0: aux = "Hay turbulencias, POR FAVOR AJUSTEN SUS CINTURONES Y SIGAN LAS INDICACIONES DE LAS AZAFATAS"; 
		return aux;
		break;
	case 1: aux = "fallo en el motor, ESTAMOS EN CAIDA LIBRE, NOS ESTAMOS COMUNICANDO CON LA TORRE";
		this->Comunicar_Torre();
	
		return aux;
		break;
	case 2: aux = "todo normal";
		return aux;
		break;
	}
}

string cPiloto::LlamarAzafata(cAzafata* azafata)
{
	srand(time(NULL));
	return azafata->Servir_Pilotos(this, Toolbox::comidas[rand() % comida], Toolbox::bebidas[rand() % (bebidaCA + bebidaSA)]);
}


ostream& operator<<(ostream& out, const cPiloto& per)
{
	cPersona* p = (cPersona*)&per;
	out << *p;
	return out;
}
