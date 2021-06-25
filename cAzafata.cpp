#include "cAzafata.h"
#include "MisfuncionesRandom.h"
#include "cAvion.h"
#include "cPrimeraClase.h"

#include "cPasajero.h"
#include "cPiloto.h"

int cAzafata::contador_azafata = 0;
cAzafata::cAzafata(cPersona* persona, bool estado, cLista<cPasajero>& listap):cTripulacion(persona), listap(listap)
{
	this->estado = estado;
	this->contador_azafata++;
}

cAzafata::~cAzafata()
{
	contador_azafata--;
}

string cAzafata::Informar_Pasajeros(cPasajero* pasajero, string pregunta)
{
	for (int i = 0; i < 6; i++)
	{
		if (pregunta == Toolbox::preguntas[i])
		{
			return Toolbox::respuestas[i];
			break;
		}
	}
}

string cAzafata::Servir_Pilotos(cTripulacion* piloto,string com,string bebida)
{
	string aux;               
	
	try {
		for (int i = 0; i < comida; i++)
		{
			if (com== Toolbox::comidas[i])
			{

				 aux = "Azafata llevando  " + com + "  a piloto";
				break;
			}

		}
	
		for (int i = 0; i < bebidaSA; i++)
		{
			if (bebida== Toolbox::bebidas[i])
			{
				 aux += "Azafata llevando  " + bebida + "  a piloto";
				return aux;
				break;
			}
			else throw exception("Pilotos no pueden consumir alcohol");
		}
	}
	catch (...)
	{
		bebida = Toolbox::bebidas[0];
		aux += "Azafata llevando " + bebida + " a piloto";
		return aux;
	}
}

string cAzafata::Servicio_comida(string com, string bebida)
{
	string aux;
	for (int i = 0; i < comida; i++)
	{
		if (com == Toolbox::comidas[i])
		{

			aux = "Azafata llevando" + com + "a pasajero";
			break;
		}

	}
	for (int i = 0; i < bebidaSA + bebidaCA; i++)
		{
			if (bebida == Toolbox::bebidas[i])
			{
				aux += "  Azafata llevando  " + bebida + "  a pasajero";
				
				break;
			}
			
	}
	
	return aux;
}

string cAzafata:: Atender(cPasajero* pasajero, string que_pasa)
{
	//primero veo si encuentro medico, busco el médico en la lista, llamao a la sobrecarga y le paso el ptr
	//agregar un buscar por profesion en la cLista
	cPasajero* aux= listap.BuscarProfesion("Doctor");

	try {
		if (aux != NULL)
		{
			return "Pasajero " + pasajero->Saludar() + " esta siendo atendido por el medico " + aux->Saludar();
		}
		else
			throw exception("No tenemos un médico, pasajero fallecio");
	}
	catch (...)
	{
		listap.Eliminar(pasajero);
		return " Pasajero fallecio, no encontramos un medico para salvarlo";
	}
	
}



string cAzafata::Masajista(cPasajero* pasajero)
{
	string aux;
	cPrimeraClase* pc = dynamic_cast<cPrimeraClase*>(pasajero);
	try {
		if (pc != NULL)
		{
			aux = "Azafata haciendo masajes";
			return aux;
		}
		else throw exception("El pasajero no es primera clase, no puede hacerse masajes");
	}
	catch (...)
	{
		aux = "Pasajero vuelva a la zona de su categoria";
		return aux;
	}
}

void cAzafata::set_estado(bool estado)
{
	estado = estado;
}



ostream& operator<<(ostream& out, const cAzafata& per)
{
	cTripulacion* t = (cTripulacion*)&per;
	out << *t;
	string aux;
	switch (per.estado)
	{
	case true:aux = "libre";
		break;
	case false: aux = "ocupada";
		break;
	}
	out << "Estado azafata:" <<aux;
	return out;
}


















