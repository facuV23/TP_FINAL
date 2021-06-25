#include "cEjecutivo.h"
#include "MisfuncionesRandom.h"

int cEjecutivo::contador_pasajeros_ejecutiva = 0;
cEjecutivo::cEjecutivo(string nombre_Apellido, string dni, string profesion, enum_estado estado):cPasajero(estado, nombre_Apellido,dni,profesion)
{
	mi_codigo = cCodigos::FormarCodigo(this);
    contador_pasajeros_ejecutiva++;
}

cEjecutivo::~cEjecutivo()
{
    contador_pasajeros_ejecutiva--;
}

string cEjecutivo::Accionar()
{
    srand(time(NULL));
    try {
        if (this->estado != detenido) {
            switch (rand() % 3)
            {
            case 0:
                return "Durmiendo";
                break;
            case 1: 
                return "Se levanta y va al banio";
                break;
            case 2: return "Esta trabajando en la notebook";
                break;
            }
        }
        else
            throw exception("Pasajero esta detenido, sus privilegios estan suspendidos");
    }
    catch (exception& e)
    {
        
            switch (rand() % 2)
            {
            case 0: this->estado = normal;
                return "Pasajero no esta mas detenido";
                break;
            case 1: this->estado = detenido;
                return "Pasajero sigue detenido";
                break;
            }
       
    }
}


string cEjecutivo::Saludar()
{
    string aux = this->mi_codigo->Getcodigos();
    string aux1 = "Hola, mi codigo es:" + aux;
    return aux1;
}


