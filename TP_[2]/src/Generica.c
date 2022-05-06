#include <stdio.h>
#include <stdlib.h>
#include "Generica.h"

static int idIncremental = 1000;
static int eGenerica_obtenerID();
static int eGenerica_obtenerID()
{
	return idIncremental++;
}

void eGenerica_imprimirUno(eGenerica Generica)
{
	printf("ID: %d\t", Generica.idGenerica);

	if(Generica.isEmpty == LIBRE)
	{
		printf("ESTADO: LIBRE\n\n");
	}else
	{
		printf("ESTADO: OCUPADO\n\n");
	}
}

int eGenerica_imprimirTodos(eGenerica array[], int len, int estado)
{
	int retorno = -1;
	int i;

	if(array != NULL)
	{
		if(len >= 0)
		{
			for(i=0; i< len; i++)
			{
				if(array[i].isEmpty == estado)
				{
					eGenerica_imprimirUno(array[i]);
				}
			}
			retorno = 0;
		}
	}

	return retorno;
}

int eGenerica_inicializar(eGenerica array[], int len)
{
	int retorno = -1;
	int i;

	if(array != NULL)
	{
		if(len >= 0)
		{
			for(i = 0; i < len; i++)
			{
				//Inicializo Estructura - LIBRE 0 - OCUPADO 1
				array[i].isEmpty = LIBRE;
			}
		}
		retorno = 0;
	}

	return retorno;
}

int eGenerica_buscarEspacioLibre(eGenerica array[], int len)
{
	int retorno = -1;
	int i;

	if(array != NULL)
	{
		if(len >= 0)
		{
			for(i = 0; i < len; i++)
			{
				//BUSCA EL PRIMER ESPACIO LIBRE DE MI ARRAY
				if(array[i].isEmpty == LIBRE)
				{
					retorno = i;
					break;
				}
			}
		}
	}

	return retorno;
}

eGenerica eGenerica_cargarUno()
{
	eGenerica aux;



	return aux;
}

int eGenerica_alta(eGenerica array[], int len)
{
	int retorno = -1;
	int indiceLibre;
	eGenerica aux;

	if(array != NULL)
	{
		if(len >= 0)
		{
			//BUSCAR ESPACIO LIBRE
			indiceLibre = eGenerica_buscarEspacioLibre(array, len);
			if(indiceLibre >= 0)
			{
				//Cargar datos no genericos
				//aux = eGenerica_cargarUno;
				//Carga datos genericos
				aux.idGenerica = eGenerica_obtenerID();
				aux.isEmpty = OCUPADO;

				//Vuelco AUXILIAR en Array
				array[indiceLibre] = aux;
				retorno = 0;
			}

		}
	}

	return retorno;
}
