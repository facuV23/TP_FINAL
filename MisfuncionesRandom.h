#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
#include <time.h>
#include <math.h>
#include <random>   

#define cant_codigos_definitiva 250
#define bebidaSA 7
#define bebidaCA 4
#define comida 10
#define PROFESIONES 22
#define N_A 100

using namespace std;
void shuffle(int* array,int n);

string relojito();
string mi_dni();


class Toolbox {

public:
	const static string anuncios[];
	const static string dolor[];
	const static string preguntas[];
	const static string respuestas[];
	const static string bebidas[];
	const static string comidas[];
	const static string nombresyapellidos[];
	const static string profesiones[];
};