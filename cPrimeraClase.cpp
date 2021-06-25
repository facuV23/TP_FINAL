#include "cPrimeraClase.h"
#include "MisfuncionesRandom.h"

int cPrimeraClase::contador_pasajeros_PC = 0;
cPrimeraClase::cPrimeraClase(string nombre_Apellido, string profesion, string dni, enum_estado estado):cPasajero(estado, nombre_Apellido,dni, profesion)
{
	mi_codigo = cCodigos::FormarCodigo(this);
	contador_pasajeros_PC++;
}

cPrimeraClase::~cPrimeraClase()
{
	contador_pasajeros_PC--;
}

string cPrimeraClase::LlamarAzafata(cAzafata* Azafata)
{
	try {
		if (this->estado != detenido)
		{
			srand(time(NULL));
			switch (rand() % 3)
			{
			case 0: cPasajero::LlamarAzafata(Azafata);
				break;
			case 1: Azafata->Servicio_comida("", "champagne");
				return "Tomando champagne";
				break;
			case 2: Azafata->Masajista(this);
				return "En sesion de masajes";
				break;
			}
		}

		else throw exception("Pasajero esta detenido, sus privilegios estan suspendidos");
	}
		catch (...)
		{
			switch (rand() % 2)
			{
			case 0: this->estado = normal;
				return "Pasajero no esta mas detenido";
				break;
			case 1: return "Pasajero sigue detenido";
				break;
			}
		}
}

string cPrimeraClase::Accionar()
{
	try {

		if (this->estado != detenido)
		{
			srand(time(NULL));
			switch (rand() % 3)
			{
			case 0: return cPasajero::Accionar();
				break;
			case 1:
				return "trabajando en la computadora";
				break;
			}
		}
		else throw exception("Pasajero esta detenido, sus privilegios estan suspendidos");
	}
	catch (...)
	{
		switch (rand() % 2)
		{
		case 0: this->estado = normal;
			return "Pasajero no esta mas detenido";
			break;
		case 1: return "Pasajero sigue detenido";
			break;
		}
	}

}

string cPrimeraClase::Saludar()
{
	string aux = this->mi_codigo->Getcodigos();
	string aux1 = "HOLA, MI CODIGO ES: " + aux;
	return aux1;
}


ostream& operator<<(ostream& out, const cPrimeraClase& per)
{
	cPasajero* p = (cPasajero*)&per;
	out <<* p<<endl;
	out << "MI CODIGO ES:" << per.mi_codigo->Getcodigos()<<endl;
	return out;
	delete p;
}
