#include "cAvion.h"

int cAvion::cont_sucesos = 0;
int cAvion::counter = 0;
cAvion::cAvion(string Num_vuelo) :Numero_vuelo(Num_vuelo)
{
}

cAvion::~cAvion()
{
	
	
}
cAzafata* cAvion::Elegir_Azafata()
{
	cAzafata* aux;

	aux = this->lista_tripulacion.BuscarPrimerTemplate<cAzafata>();
		if (aux != NULL && aux->estado == true)
			return aux;
		
		else
		{
			cout<<"Azafatas ocupadas"<<endl;
			return NULL;
		}
		

}
void cAvion::Chequear_Preembarque()
{
	// a modo de simulacion
	
	int i = 0;
	while (i < lista_pasajeros.get_CA())
	{
		try {
			//tenemos q chequear que el codigo de pasajero esté en el avion->lista_codigo

			if (lista_codigos.BuscarCodigo(lista_pasajeros[i]->mi_codigo->Getcodigos()) == NULL)
				throw exception("Codigo de pasajero no se encuentra en la lista");
			i++;
		}
		
		catch (...)
		{
			lista_pasajeros.Eliminar(lista_pasajeros[i]);
		}
		i++;
	 }
}
void cAvion::Simular()
{

	cPiloto* piloto_auxiliar = NULL;
	cCoPiloto* copiloto_auxiliar = NULL;
	cMarshall* marshall_auxiliar = NULL;
	cPersona* personita = NULL;
	cPrimeraClase* pc_aux = NULL;
	cAzafata* azafata_auxiliar = NULL;
	cEjecutivo* eje_aux = NULL;
	cTurista* tur_aux = NULL;

	Cargar_Pasajeros();
	Cargar_Tripulacion();
	Cargar_codigo();
	Chequear_Preembarque();

	//Ya estamos volando, a partir de ahora usamos rand() y cada pasajero hace alguna accion y se registra en suceso
	srand(time(NULL));
	


	string accion;
	//copiloto se encarga de comunicar torre y verficar la salida del avion

	copiloto_auxiliar = this->lista_tripulacion.BuscarPrimerTemplate<cCoPiloto>();
	if (copiloto_auxiliar != NULL)
	{
		personita = copiloto_auxiliar;
		accion = copiloto_auxiliar->Comunicar_Torre();

		Cargar_Suceso(personita, accion, relojito());

	}

	azafata_auxiliar = this->lista_tripulacion.BuscarPrimerTemplate<cAzafata>();

	cout << "\n" << azafata_auxiliar->Saludar() << endl;

	
	marshall_auxiliar = this->lista_tripulacion.BuscarPrimerTemplate<cMarshall>();

	int a[CANT_PASAJEROS];
	for (int i = 0; i < CANT_PASAJEROS; i++)
	{
		a[i] = i;
	}
	shuffle(a, CANT_PASAJEROS);
	
	if (marshall_auxiliar != NULL)
		cout << marshall_auxiliar->GetProfesion() << endl;
	while (counter < COUNTER_ITERACIONES)
	{
		
		srand(time(NULL));
		personita = lista_pasajeros[a[counter]];
		pc_aux = dynamic_cast<cPrimeraClase*>(personita);
		
		if (pc_aux != NULL)
		{
			personita = pc_aux;
			switch (rand() % 3)
			{
			case 0: accion = pc_aux->Accionar();//durmiendo va al banio etc
				Cargar_Suceso(personita, accion, relojito());
				counter++;
				break;
			case 1: accion = pc_aux->Reaccionar();//locura
				if (pc_aux->estado == loco)
				{
					accion = accion + marshall_auxiliar->Detener(pc_aux);
					Cargar_Suceso(marshall_auxiliar, accion, relojito());
					counter++;
				}
				accion = pc_aux->Accionar();
				Cargar_Suceso(personita, accion, relojito());
				counter++;
				break;
			case 2: azafata_auxiliar = Elegir_Azafata();
				if (azafata_auxiliar != NULL)
				{
					accion = pc_aux->LlamarAzafata(azafata_auxiliar);
					Cargar_Suceso(personita, accion, relojito());
					counter++;
					break;
				}
				break;
			 
			}

		}
		eje_aux = dynamic_cast<cEjecutivo*>(personita);
		if (eje_aux != NULL)
		{
			personita = eje_aux;
			switch (rand() % 3)
			{
			case 0:accion = eje_aux->Accionar();
				Cargar_Suceso(personita, accion, relojito());
				counter++;
				break;

			case 1: accion = eje_aux->Reaccionar();
				if (eje_aux->estado == loco)
				{
					accion = marshall_auxiliar->Detener(eje_aux);
					Cargar_Suceso(marshall_auxiliar, accion, relojito());
					counter++;
					break;
				}
				Cargar_Suceso(personita, eje_aux->Reaccionar(), relojito());
				counter++;
				break;
			case 2:

				azafata_auxiliar = Elegir_Azafata();
				if (azafata_auxiliar != NULL)
				{
					accion = eje_aux->LlamarAzafata(azafata_auxiliar);
					Cargar_Suceso(personita, accion, relojito());
					counter++;
					break;
				}


			}
		}

		tur_aux = dynamic_cast<cTurista*>(personita);
		if (tur_aux != NULL)
		{
			personita = tur_aux;
			switch (rand() % 3)
			{
			case 0: accion = tur_aux->Accionar();
				Cargar_Suceso(personita, accion, relojito());
				counter++;
				break;
			case 1:azafata_auxiliar = Elegir_Azafata();
				if (azafata_auxiliar != NULL)
				{
					accion = tur_aux->LlamarAzafata(azafata_auxiliar);
					Cargar_Suceso(personita, accion, relojito());
					counter++;
					break;
				}
			case 2: accion = tur_aux->Reaccionar();
				if (tur_aux->estado == loco)
				{
					accion = marshall_auxiliar->Detener(tur_aux);
					Cargar_Suceso(marshall_auxiliar, accion, relojito());
					counter++;
					break;
				}

				Cargar_Suceso(personita, accion, relojito());
				counter++;
				break;
			

			}
		}
		counter++;
	    }

	
	piloto_auxiliar = this->lista_tripulacion.BuscarPrimerTemplate<cPiloto>();
	if (piloto_auxiliar != NULL)
	{
		switch (rand() % 2)
		{
		case 0: azafata_auxiliar = Elegir_Azafata();
			if (azafata_auxiliar != NULL)
			{
				accion = piloto_auxiliar->LlamarAzafata(azafata_auxiliar);
				Cargar_Suceso(personita, accion, relojito());
				counter++;
				break;
			}
		case 1:accion = piloto_auxiliar->Pilotear(); //en este caso por ej, pordria hacer movimientos peligrosos
			Cargar_Suceso(personita, accion, relojito());
			break;
		}
	}

	copiloto_auxiliar = this->lista_tripulacion.BuscarPrimerTemplate<cCoPiloto>();
	if (copiloto_auxiliar != NULL)
	{
		copiloto_auxiliar->Comunicar_Torre();
		Cargar_Suceso(personita, accion, relojito());
		counter++;
	}

	cout << "\nSUCESOS";
	lista_sucesos.listarS();
	cout << "\nDATOS DEL VUELO:" << endl;
	cout << "Los pasajeros que nos acompaniaron son:" << endl;
	lista_pasajeros.Listar();
	cout << "\n Los Tripulantes que nos acompaniaron son:" << endl;
	lista_tripulacion.Listar();

	
}
void cAvion::Cargar_Pasajeros()
{
	int array_n[N_A];
	for (int i = 0; i < N_A; i++)
	{
		array_n[i] = i;
	}
	shuffle(array_n,N_A);
	int array_p[PROFESIONES];
	for (int i = 0; i <PROFESIONES; i++)
	{
		array_p[i] = i;
	}
	shuffle(array_p,PROFESIONES);
	srand((unsigned)time(NULL));
	cPasajero* pasajerito;
	cPersona* personita;
	cTurista* tur_aux;
	int j, k;
	j = 0;
	k = 0;
	
	for (int i = 0; i < TU; i++)
	{
		if (k >= PROFESIONES)//recorre todas las profsiones
			k = 0;
		if (j >= N_A) //recorre todos los nombres y apellidos
			j = 0;
		tur_aux = new cTurista(Toolbox::nombresyapellidos[array_n[j]], mi_dni(), Toolbox::profesiones[array_p[k]], normal);
		lista_codigos + tur_aux->GetCodigo();
		lista_pasajeros + tur_aux;
		k++;
		j++;
	}
	
	cEjecutivo* eje_aux;
	k = 0;
	j = 0;
	for (int i = 0; i < BS; i++)
	{
		if (k >= PROFESIONES)
			k = 0;
		if (j >= N_A)
			j = 0;
		eje_aux = new cEjecutivo(Toolbox::nombresyapellidos[array_n[j]], mi_dni(), Toolbox::profesiones[array_p[k]], normal );
		lista_codigos+ eje_aux->GetCodigo();
		lista_pasajeros + eje_aux;
		j++;
		k++;
	}
	
	k = 0; 
	j = 0;
	cPrimeraClase* pc_aux;
	for (int i = 0; i < PC; i++)
	{
		if (k >= PROFESIONES)
			k = 0;
		if (j >= N_A)
			j = 0;
		pc_aux = new cPrimeraClase(Toolbox::nombresyapellidos[array_n[j]], Toolbox::profesiones[array_p[k]], mi_dni(), normal);
		lista_codigos + pc_aux->GetCodigo();
		lista_pasajeros + pc_aux;
		j++;
		k++;
	}
	

}

void cAvion::Cargar_Tripulacion()
{
	cPersona* personita;
	cAzafata* azafata_auxiliar;
	int array_n[N_A];
	for (int i = 0; i < N_A; i++)
	{
		array_n[i] = i;
	}
	shuffle(array_n, N_A);
	int j=0;
	

	for (int i = 0; i < CANT_TRIPULACION; i++)
	{
		if (i < 3)//las primeras 3 son azafatas
		{
			if (j >= N_A)
				j = 0;
			personita = new cPersona(Toolbox::nombresyapellidos[array_n[j]], "azafata", mi_dni());
			azafata_auxiliar = new cAzafata(personita, true, this->lista_pasajeros);
			lista_tripulacion + azafata_auxiliar;
			j++;
		}

	}
	//piloto

	personita = new cPersona(Toolbox::nombresyapellidos[array_n[j]], "piloto", mi_dni());
	cPiloto* piloto_auxiliar = new cPiloto(personita);
	lista_tripulacion + piloto_auxiliar;
	j++;
	//copiloto

	personita = new cPersona(Toolbox::nombresyapellidos[array_n[j]], "copiloto", mi_dni());
	cCoPiloto* copiloto_auxiliar = new cCoPiloto(personita);
	lista_tripulacion + copiloto_auxiliar;
	j++;
	//marshall

	personita = new cPersona(Toolbox::nombresyapellidos[array_n[j]], "marshall", mi_dni());
	cMarshall* marshall_auxiliar = new cMarshall(personita);
	lista_tripulacion + marshall_auxiliar;
	
}

void cAvion::Cargar_Suceso(cPersona* persona, string que_hizo, string tiempo)
{
	cSucesos* s = NULL;
	s = new cSucesos(persona, que_hizo, tiempo);
	lista_sucesos + s;
	cont_sucesos++;
}



void cAvion::Cargar_codigo()// 
{
	int array[CANT_POSIBLES_CODIGOS];
	for (int i = 0; i < CANT_POSIBLES_CODIGOS; i++)
	{
		array[i] = i;
	}
	shuffle(array, CANT_POSIBLES_CODIGOS);
	int i = 0;
	while (i < CANT_CODIGOS_DEFINITIVA)
	{
		if (i > lista_codigos.get_CA())
			i = 0;
		if(lista_codigos[array[i]]!=NULL)
		  lista_codigos.Quitar(lista_codigos.BuscarCodigo(lista_codigos[array[i]]->Getcodigos()));
		i++;
	}
}
	
	
	
	
	


