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
		int typePassenger, char flyCode[],int index)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		if(!getPalabra(list[index].name, "Ingrese el nombre del pasajero: \n", "Nombre no valido\n", 2, 49, 3)
			&& !getPalabra(list[index].lastName, "Ingrese el apellido del pasajero: \n", "Apellido no valido\n", 2, 49, 3)
			&& !getFloat(&list[index].price, "Ingrese el precio del pasaje: \n", "Ingreso Incorrecto\n", 1, 500000, 3)
			&& !getPalabra(list[index].flyCode, "Ingrese el codigo de vuelo: \n" , "Ingreso Incorrecto\n", 1, 9, 3)
			&& !getNumero(&list[index].typePassenger, "Ingrese el tipo de pasajero (1- VIP, 2- SUPERIOR, 3- COMUN): \n", "Ingreso Incorrecto\n", 1, 3, 3))
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
			printf("\nId\t\tNombre\t\tApellido\tPrecio\t\tFlycode\t\tTipo de Pasajero\t\t\n");
			printUnPassenger(list[retorno]);


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
					//mostrar alumno y pregunta si lo quiere bajar
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
		printf("\nId\t\tNombre\t\tApellido\tPrecio\t\tFlycode\t\tTipo de Pasajero\t\t\n");
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				printUnPassenger(list[i]);
			}
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
		printf("%d\t\t", unPassenger.id);
		printf("%s\t\t", unPassenger.name);
		printf("%s\t\t", unPassenger.lastName);
		printf("$%.2f\t", unPassenger.price);
		printf("%s\t\t", unPassenger.flyCode);
		printf("%d\t\t\n", unPassenger.typePassenger);

	}
}

int primerEspacioLibre(Passenger* list, int len)
{
	int retorno = -1;

		if(list != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == LIBRE)
				{
					retorno = i;
					break;
				}
			}
		}
	return retorno;
}
