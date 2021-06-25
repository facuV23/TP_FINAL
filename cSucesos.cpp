#include "cSucesos.h"

cSucesos::cSucesos(cPersona* persona, string que_paso, string Tiempo)
{
	this->persona = persona;
	this->que_paso = que_paso;
	this->Tiempo = Tiempo;

}


cSucesos::~cSucesos()
{
}

string cSucesos::toString()
{
	string aux = "Persona: " + persona->getnombre_ape() + "  Que paso:" + que_paso + "  Aque hora:" + Tiempo;
	return aux;
}

void cSucesos::imprimir()
{
	cout << toString()<<endl;
}


ostream& operator<<(ostream& out, const cSucesos& suc)
{
	out<< "  "<<*suc.persona<<"   "  << " Que paso:  " << suc.que_paso << "    " << " A que hora: " << suc.Tiempo;
	return out;
}
