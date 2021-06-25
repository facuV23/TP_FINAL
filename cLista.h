
#pragma once
#include <iostream>
#include <string.h>

using namespace std;

#define TMAX 100
template<class T1>

class cLista
{
private:
    T1** lista;
    int CA, TAM;
    void Redimencionalizar();
public:
    cLista(int T = TMAX);
    ~cLista();
    
    void Insertar(T1* P);			
    T1* Quitar(T1*p);		
    void Eliminar(T1*t);
    
    void Listar();
    void listarS();
    int get_CA();
  
    T1* BuscarProfesion(string profesion);
    T1* BuscarClave(string clave);
    int BuscarAtPos(T1* p);
  
    template<class T2>
    T2* BuscarTemplate(string DNI);
    //template<class T2>
    T1* BuscarCodigo(const string clave);
   

    template<class T2>
    T2* BuscarPrimerTemplate();
    
    //METODOS USANDO SOBRECARGA
    void operator+(T1* a);
    T1* operator-(T1* p);
    T1* operator[](int pos);
    bool operator==( const T1& d);

};
template<class T1>

inline bool cLista<T1>::operator==( const T1& d)
{
    return  this==&d;
}

template<class T1>

T1* cLista<T1>::BuscarProfesion(string profesion)
{
    for (int i = 0; i < CA; i++)
    {
        if (lista[i]->GetProfesion()== profesion)
        {
            return lista[i];
            break;
        }
    }
    return NULL;
}

template<class T1>
int cLista<T1>::get_CA()
{
    return CA;
}

template<class T1>
inline void cLista<T1>::Redimencionalizar()
{
    T1** lista_auxiliar;
    TAM = TAM + 100;
    lista_auxiliar = new T1 * [TAM];
    for (int i = 0; i < CA; i++)
    {
        lista_auxiliar[i] = lista[i];
    }
    for (int i = CA; i < TAM; i++)
    {
        lista_auxiliar[i] = NULL;
    }

    delete[]lista;
    lista = lista_auxiliar;
}

template<class T1>
cLista<T1> ::cLista(int T)
{
    TAM = T;
    CA = 0;
    lista = new T1*[T];
    for (int i = 0; i < T; i++)
    {
        lista[i] = NULL;
    }


}
template<class T1>
cLista<T1> ::~cLista()
{
    if (lista != NULL)
    {
        for (int i = 0; i <CA; i++)
        {
            if (lista[i] != NULL)
                delete lista[i];
        }
        delete[] lista;
    }
}
template<class T1>
void cLista<T1> ::Insertar(T1* p)
{
    int a = BuscarAtPos(p);
    if (CA < TAM && a==-1)
        lista[CA++] = p;
    else {
        Redimencionalizar();
        lista[CA++] = p;
    }

}
template<class T1>
T1* cLista<T1>::Quitar(T1*p)
{
    T1* aux = p;
    int a = BuscarAtPos(p);
    if (a != -1 && a < CA)
    {
        lista[a] = NULL;
        for (int i = a; i < CA; i++)
        {
            lista[i] = lista[i + 1];
        }
        CA--;
        return aux;
        lista[CA] = NULL;
    }
    return nullptr;
}
template <class T1>
T1*cLista<T1>::operator-(T1* p)
{
    T1* aux = p;
    if (int pos = BuscarAtPos(p)<CA)
    {
        lista[pos] = NULL;
        for (int i = pos; i < CA; i++)
        {
            lista[i] = lista[i + 1];
        }
        CA--;
        return aux;
    }
    return NULL;

}
template<class T1>
void cLista<T1>::Eliminar(T1* t)
{
    T1* aux = Quitar(t);
    if (aux != NULL)
    {
        delete aux;
        return;
    }

}
template <class T1>
T1* cLista<T1>::BuscarClave(string clave)
{
 
    for (int i = 0; i < CA; i++)
    {
        if (lista[i]->GetClave() == clave)
        {
            return lista[i];
            break;
        }
    }
   

}
template <class T1>
int cLista<T1>::BuscarAtPos(T1* p)
{
    
        for (int i = 0; i < CA; i++)
        {
            if (lista[i]==p)
            {
                return i;
                break;
            }
        }
        return -1;
}


template<class T1>
void cLista<T1>::operator+(T1* a)
{
    if (CA < TAM && BuscarAtPos(a)==-1)
        lista[CA++]=a;
    else
    {
        Redimencionalizar();
        lista[CA++] = a;
    }
}

template<class T1>
T1* cLista<T1>:: operator[](int pos)
{
    if(pos<CA)
        return lista[pos];
    else
        return NULL;
}
template <class T1>
void cLista<T1>::Listar()
{
    for (int i = 0; i < CA; i++)
    {
        cout << "\n" << *lista[i];

    }
}

template<class T1>
inline void cLista<T1>::listarS()
{
    for (int i = 0; i < CA; i++)
    {
        lista[i]->imprimir();

    }
    
}


template<class T1>
template<class T2>
inline T2* cLista<T1>::BuscarTemplate(string clave)
{
    for (int i = 0; i < CA; ++i) 
    {
        if ((*lista[i]) == clave) {
            T2* aux = dynamic_cast<T2*>(lista[i]);
            if (aux != NULL)
                return aux;
        }
    }
    return NULL;
}

template<class T1>
inline T1* cLista<T1>::BuscarCodigo(const string clave)
{

    for (int i = 0; i < CA; i++)
    {
        if (clave.compare(lista[i]->Getcodigos())==0)
        {
            return lista[i];
            break;
        }
    }
    return NULL;
}

template<class T1>
template<class T2>
inline T2* cLista<T1>::BuscarPrimerTemplate()
{
	for (int i = 0; i < CA; ++i)
	{
		T2* aux = dynamic_cast<T2*>(lista[i]);
		if (aux != NULL)
			return aux;
	}
	return NULL;
}
