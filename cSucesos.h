#pragma once
#include <iostream>
#include <string.h>
#include "cPersona.h"
using namespace std;
class cSucesos
{
    string Tiempo;
    string que_paso;
    cPersona* persona;
public:

    cSucesos(cPersona* persona, string que_paso, string Tiempo);
    ~cSucesos();
    friend ostream& operator<<(ostream& out, const cSucesos& suc);//para cuando tengamos que listar todos los sucesos ocurridos
    string toString();
    void imprimir();
};

ostream& operator<<(ostream& out, const cSucesos& suc);