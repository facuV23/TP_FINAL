//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <string.h>
#include <string>
#include <time.h>
#include <math.h>
#include <windows.h>
#include<stdio.h>
#include<conio.h>
#include "cAvion.h"
#include "cCodigos.h"
#include "cSucesos.h"
#include "cPersona.h"
#include "cPasajero.h"
#include "cPrimeraClase.h"
#include "cEjecutivo.h"
#include "cTurista.h"
#include "cTripulacion.h"
#include "cLista.h"

#include "MisfuncionesRandom.h"



using namespace std;
int main()
{
	cAvion* a = new cAvion("EZS 1012");
	a->Simular();
	delete a;
	system("pause");
	return 0;
}


