#include "cPersona.h"

cPersona::cPersona(string nombre_Apellido, string profesion, string dni):dni(dni)
{
	this->nombre_Apellido = nombre_Apellido;
	this->profesion = profesion;
}

cPersona::cPersona(const cPersona* p):dni(p->dni), nombre_Apellido(p->nombre_Apellido),profesion(p->profesion)
{
}

string cPersona::GetProfesion() const
{
	return profesion;
}

string cPersona::GetClave() const
{
	return dni;
}

string cPersona::getnombre_ape()
{
	return nombre_Apellido;
}

cPersona::~cPersona()
{
}

string cPersona::Saludar()
{
	return string();
}



ostream& operator<<(ostream& out, const cPersona& per)
{
	out << "Nombre:  " << per.nombre_Apellido << "  " << "Profesion:  " << per.profesion;
	return out;
}

