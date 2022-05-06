#include <stdio.h>
#include <stdlib.h>

#include "Passenger.h"
#include "pedidoDatos.h"

#define LIBRE 1
#define OCUPADO 0

static int idIncremental = 1000;
static int passenger_obtenerID();
static int passenger_obtenerID()
{
	return idIncremental++;
}

int initPassenger(Passenger* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL)
	{
		if(len >= 0)
		{
			for(i = 0; i < len; i++)
			{
				//Inicializo Estructura - LIBRE 0 - OCUPADO 1
				list[i].isEmpty = LIBRE;
			}
		}
		retorno = 0;
	}
	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price,
		int typePassenger, char flyCode[])
{
	int index;
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		index = primerPosicionLibre(list, len);
		if(!getPalabra(list[index].name, "Ingrese el nombre del pasajero\n", "Nombre no valido\n", 2, 49, 3)
			&& !getPalabra(list[index].lastName, "Ingrese el apellido del pasajero\n", "Apellido no valido\n", 2, 49, 3)
			&& !getFloat(&list[index].price, "Ingrese el precio del pasaje\n", "Ingreso no valido\n", 1, 50000, 3)
			)
		{
			list[index].isEmpty = OCUPADO;
			list[index].id = passenger_obtenerID();

			printf("Guardado\n");
		}else
		{
			printf("No se guardo\n");
		}

	}

	return retorno;
}

int findPassenger(Passenger* list, int len, int id)
{
	int retorno = -1;

			if(list != NULL && len > 0 && id > 0)
			{
				for(int i = 0; i < len; i++)
				{
					if(list[i].isEmpty == OCUPADO && list[i].id == id)
					{
						retorno = i;
						break;
					}
				}
			}

		return retorno;
}

int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	int index;

			if(list != NULL && len > 0 && id > 0)
			{
				index = findPassenger(list, len, id);
				if(index != -1)
				{
					// mostrar alumno y pregunta si lo quiere bajar
					printUnPassenger(list[index]);
					list[index].isEmpty = LIBRE;
					retorno = 0;
				}
			}

	return retorno;
}

int sortPassenger(Passenger* list, int len, int order)
{
	return 0;
}

int printPassengers(Passenger* list, int len)
{
	int retorno = -1;

	if(list != NULL && len >0)
	{
		for(int i = 0; i < len; i++)
		{
			printUnPassenger(list[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	return 0;
}

void printUnPassenger(Passenger unPassenger)
{
	if(unPassenger.isEmpty == OCUPADO)
	{
		//Desarrollar como se van a mostrar los passenger
		printf("ID: %d\n", unPassenger.id);
		printf("Nombre: %s\n", unPassenger.name);
		printf("Apellido: %s\n", unPassenger.lastName);
		printf("Precio: $%.2f\n", unPassenger.price);
	}
}

int primerPosicionLibre(Passenger* list, int len)
{
	int retorno = 0;

		if(list != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == LIBRE)
				{
					retorno = 1;
					break;
				}
			}
		}

	return retorno;
}
