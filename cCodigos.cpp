#pragma once
#include "cCodigos.h"
#include "cPrimeraClase.h"
#include "cTurista.h"
#include "cEjecutivo.h"

char cCodigos::aa_marshall = rand()%(75-64)+64;//letra entre A y J
char cCodigos::aa_pc = 'A'; 
char cCodigos::aa_tu = 'A';
char cCodigos::aa_bs = 'A';
int cCodigos::f_marshall = rand()%filasmax;
int cCodigos::f_pc = 0;
int cCodigos::f_bs = filasBS;
int cCodigos::f_tu = filaTU;
cCodigos::cCodigos(string c)
{
	Mi_codigo = c;
}

cCodigos::~cCodigos()
{

}

string cCodigos::Getcodigos()const
{
	return Mi_codigo;
}

cCodigos* cCodigos::FormarCodigo(cPersona* persona)
{
	string auxiliar;
	cCodigos* aux = new cCodigos();
	cPrimeraClase* pc = dynamic_cast<cPrimeraClase*>(persona);
	//PRIMERA CLASE
	if (pc != NULL && f_pc < filasPC && pc->contador_pasajeros_PC < PC)
	{
		persona = pc;
		aux->Mi_codigo = "PC-" +persona->dni + "-";
		if (f_pc != f_marshall)
		{
			if (pc != NULL && f_pc < filasPC && pc->contador_pasajeros_PC < PC)
			{
			
				persona = pc;
				aux->Mi_codigo = "PC-" + persona->dni + "-" + to_string(f_pc);
				if (aa_pc > 64 && aa_pc <= 74)
				{
					auxiliar.append(1, aa_pc);
					aux->Mi_codigo += "-" + auxiliar;
				}
				else {
					aa_pc = 65;
					auxiliar.append(1, aa_pc);
					f_pc++;
					aux->Mi_codigo += to_string(f_pc) + "-" + auxiliar;
				}

				aa_pc++;
			}
		}
		else 
		{//filapc=filamarshall
			if (aa_pc >= 65 && aa_pc <= 74 && aa_pc != aa_marshall)
			{
				auxiliar.append(1, aa_pc);
				aux->Mi_codigo += to_string(f_pc) + "-" + auxiliar;

			}
				if (aa_pc == aa_marshall && aa_pc < 74)
				{
					aa_pc = aa_marshall++;
					auxiliar.append(1, aa_pc);
					aux->Mi_codigo += to_string(f_pc) + "-" + auxiliar;
				}
				if (aa_pc == 74 && aa_pc == aa_marshall)
				{
					aa_pc = 65;
					f_pc++;
					auxiliar.append(1, aa_pc);
					aux->Mi_codigo += to_string(f_pc) + "-" + auxiliar;

				}
				if (aa_pc == 74 && aa_pc != aa_marshall)
				{
					f_pc++;
					aa_pc = 65;
					auxiliar.append(1, aa_pc);
					aux->Mi_codigo += to_string(f_pc) + "-" + auxiliar;
					
				}
				aa_pc++;
		}
			
	}
	
	//TURISTA
	cTurista* tu = dynamic_cast<cTurista*>(persona);
	
	
		if (tu != NULL && f_tu < filasmax && tu->contador_pasajero_TU < TU)
		{
			if (f_marshall != f_tu)
			{
				persona = tu;
				aux->Mi_codigo = "TU-" +persona->dni + "-" + to_string(f_tu);
				if (aa_tu >= 65 && aa_tu <= 74)
				{
					auxiliar.append(1, aa_tu);
					aux->Mi_codigo += "-" + auxiliar;
				}
				else {
					aa_tu = 65;
					auxiliar.append(1, aa_tu);
					f_tu++;
					aux->Mi_codigo += to_string(f_tu) + "-" + auxiliar;
				}

				aa_tu++;
			}
			else
			{//filatu=filamarshall
				if (aa_tu >= 65 && aa_tu <= 74 && aa_tu != aa_marshall)
				{
					auxiliar.append(1, aa_tu);
					aux->Mi_codigo += to_string(f_tu) + "-" + auxiliar;

				}
				if (aa_tu == aa_marshall && aa_tu < 74)
				{
					aa_tu = aa_marshall++;
					auxiliar.append(1, aa_tu);
					aux->Mi_codigo += to_string(f_tu) + "-" + auxiliar;
				}
				if (aa_tu == 74 && aa_tu == aa_marshall)
				{
					aa_tu = 65;
					auxiliar.append(1, aa_tu);
					f_tu++;
					aux->Mi_codigo += to_string(f_tu) + "-" + auxiliar;

				}
				if (aa_tu == 74 && aa_tu != aa_marshall)
				{
					f_tu++;
					aa_tu = 64;
					auxiliar.append(1, aa_tu);
					aux->Mi_codigo += to_string(f_tu) + "-" + auxiliar;

				}
				aa_tu++;
			}
		}
	
		cEjecutivo* eje = dynamic_cast<cEjecutivo*>(persona);
		
		if (eje != NULL && f_bs >= filasBS && f_bs < filaTU)
		{
			if (f_marshall != f_bs)
			{
				persona = eje;
				
				aux->Mi_codigo = "BS-" +persona->dni + "-" + to_string(f_bs);
				if (aa_bs >= 65 && aa_bs <= 74)
				{
					auxiliar.append(1, aa_bs);
					aux->Mi_codigo += "-" + auxiliar;
				}
				else {
					aa_bs = 65;
					auxiliar.append(1, aa_bs);
					f_bs++;
					aux->Mi_codigo += "-" + auxiliar;
				}
				aa_bs++;
			}
			else
			{//filatu=filamarshall
				if (aa_bs >= 65 && aa_bs <= 74 && aa_bs != aa_marshall)
				{
					auxiliar.append(1, aa_bs);
					aux->Mi_codigo += to_string(f_bs) + "-" + auxiliar;

				}
				if (aa_bs == aa_marshall && aa_bs < 74)
				{
					aa_bs = aa_marshall++;
					auxiliar.append(1, aa_bs);
					aux->Mi_codigo += to_string(f_bs) + "-" + auxiliar;
				}
				if (aa_bs == 74 && aa_bs == aa_marshall)
				{
					aa_bs = 65;
					f_bs++;
					auxiliar.append(1, aa_bs);
					aux->Mi_codigo += to_string(f_bs) + "-" + auxiliar;

				}
				if (aa_bs == 74 && aa_bs != aa_marshall)
				{
					f_bs++;
					aa_bs = 65;
					auxiliar.append(1, aa_bs);
					aux->Mi_codigo += to_string(f_bs) + "-" + auxiliar;

				}
				aa_bs++;
			}
	    }
	
	
	return aux;

}

bool cCodigos::operator==(const string& der)
{
	return this->Mi_codigo ==der;
}

