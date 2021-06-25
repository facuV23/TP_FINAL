#include "cTurista.h"
#include "cCodigos.h"
int cTurista::contador_pasajero_TU = 0;
cTurista::cTurista(string nombre_Apellido, string dni, string profesion, enum_estado estado):cPasajero(estado, nombre_Apellido,dni,profesion)
{
	mi_codigo = cCodigos::FormarCodigo(this);
	contador_pasajero_TU++;
}
cTurista::~cTurista()
{
	contador_pasajero_TU--;
}
string  cTurista::Saludar()
{
	string aux = this->mi_codigo->Getcodigos();
	string aux1 = "Hola,  mi codigo es:" + aux;
	return aux1;
}

ostream& operator<<(ostream& out, const cTurista& per)
{
	cPasajero& p = (cPasajero&)per;
	out << p;
	out << "Codigo: " << per.mi_codigo->Getcodigos();
	return out;

}
