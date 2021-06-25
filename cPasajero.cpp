#include "cPasajero.h"
#include <time.h>
#include <ctime>
#include "MisfuncionesRandom.h"
#include "cAzafata.h"

cPasajero::cPasajero(enum_estado miestado, string nombre_Apellido, string dni, string profesion):cPersona(nombre_Apellido,profesion,dni)
{
    estado = miestado;
    mi_codigo = NULL;
}

cPasajero::~cPasajero()
{
}

string cPasajero::LlamarAzafata(cAzafata* Azafata)
{
    srand(time(NULL));
    string pregunta,comidas1,bebidas;
    try {
        if (this->estado != detenido) {//si no esta detenido
            switch (rand() % 3)
            {
            case 0:
                Azafata->set_estado(false); // azafata ocupada
                comidas1 = Toolbox::comidas[rand() % 10]; //comidas declaardas en mis funcionesrandom
                bebidas = Toolbox::bebidas[rand() % 11];
                Azafata->Servicio_comida(comidas1, bebidas);
                Azafata->set_estado(true); //azafata desocupada
                return "Pidio comida "+comidas1 + bebidas ;
                break;
            case 1:
                Azafata->set_estado(false); // azafata ocupada
                pregunta = Toolbox::preguntas[rand() % 7];//preguntas  declaardas en mis funcionesrandom
                Azafata->Informar_Pasajeros(this, pregunta);
                Azafata->set_estado(true);// azafata desocupada
                return "Pregunto: " + pregunta;
                break;
            case 2:
                Azafata->set_estado(false);// azafata ocupada
                pregunta = Toolbox::dolor[rand() % 5];
                pregunta+= " " +Azafata->Atender(this, pregunta);
                Azafata->set_estado(true);// azafata desocupada
                return "Tiene: " + pregunta;
                break;
            }
        }
        else throw exception("Pasajero esta detenido, sus privilegios estan suspendidos"); //si esta detenido
    }
    catch (...)
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

string cPasajero::Accionar()
{
    srand(time(NULL));
    try {
        if(this->estado != detenido)//si no esta detenido
            switch (rand() % 2)
            {
            case 0:// dormir();
                return "Pasajero durmiendo";
                break;
            case 1: return "Pasajero se levanta y va al banio";
                break;
            }
    else throw exception("Pasajero esta detenido, sus privilegios estan suspendidos");
    }
    catch (...)
    {
        switch (rand() % 2)
        {
        case 0: this->estado = normal;
            break;
        case 1: this->estado = detenido;
            break;
        }
    }
  
}

string cPasajero::Reaccionar() //cambio de estado 
{
  
            switch (estado)
            {
            case normal: this->estado = loco;
               
                return "pasajero loco";
                break;
            case loco: this->estado = normal;
                return "pasajero se tranquilizo";
                break;
            }
  
  
}

string cPasajero::Saludar()
{
    return string();
}

cCodigos* cPasajero::GetCodigo() const
{
    return mi_codigo;
}

string cPasajero::Getcodigos() const
{
    return mi_codigo->Getcodigos();
}

string cPasajero::get_profesion()const
{
    return profesion;
}


enum_estado cPasajero::get_estado() const 
{
    return estado;
}

void cPasajero::set_estado(enum_estado estado)
{
    estado = estado;
}

ostream& operator<<(ostream& out, const cPasajero& pas)
{
    cPersona& per = (cPersona&)pas;
    out << per;
    string aux;
    switch (pas.estado)
    {
    case loco: aux = "loco";
    break;
    case normal: aux = "normal";
        break;
    case detenido: aux="detenido";
        break;
    }
    out << "\t"<<"Codigo:  " << pas.mi_codigo->Getcodigos()<<"\t" << "Estado: " << aux;
    return out;
}
