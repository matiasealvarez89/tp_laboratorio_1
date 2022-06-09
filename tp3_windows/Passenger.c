#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Passenger.h"

//----------------------------------Inicializador----------------------------------------

void Passenger_initArray(Passenger** arrayPassenger, int len)
{

	if (arrayPassenger != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			*(arrayPassenger + i) = NULL;
		}
	}

}


//----------------------------------Constructores----------------------------------------

Passenger* Passenger_new()
{
	Passenger* pNuevoPassenger;

	pNuevoPassenger = NULL;
	pNuevoPassenger = (Passenger*)calloc(sizeof(Passenger), 1);

	/*if(pNuevoPassenger != NULL)
	{
		Passenger_setId(pNuevoPassenger, 0);
		Passenger_setNombre(pNuevoPassenger, " ");
		Passenger_setApellido(pNuevoPassenger," ");
		Passenger_setPrecio(pNuevoPassenger, 0);
		Passenger_setTipoPasajero(pNuevoPassenger, 0);
		Passenger_setCodigoVuelo(pNuevoPassenger, " ");
		Passenger_setFlightStatus(pNuevoPassenger, 0);
	}
	*/
	return pNuevoPassenger;
}

Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr,
		char* codigoVueloStr, char* flightStatusStr)
{
	Passenger* pNuevoPassenger;
	Passenger* pPassengerAux;
	int auxID;
	int auxPrecio;
	int auxTipoPasajero;
	int auxFlightStatus;

	pNuevoPassenger = NULL;
	pPassengerAux = Passenger_new();

	if(pPassengerAux != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL
				&& tipoPasajeroStr != NULL && codigoVueloStr != NULL && flightStatusStr != NULL)
	{
		auxID = atoi(idStr);
		auxPrecio = atoi(precioStr);
		auxTipoPasajero = atoi(tipoPasajeroStr);
		auxFlightStatus = atoi(flightStatusStr);
		/*Passenger_setId(pNuevoPassenger, auxID);
		Passenger_setNombre(pNuevoPassenger, nombreStr);
		Passenger_setApellido(pNuevoPassenger, apellidoStr);
		Passenger_setPrecio(pNuevoPassenger, auxPrecio);
		Passenger_setTipoPasajero(pNuevoPassenger, auxTipoPasajero);
		Passenger_setCodigoVuelo(pNuevoPassenger, codigoVueloStr);
		Passenger_setFlightStatus(pNuevoPassenger, auxFlightStatus);
		*/

		if(!Passenger_setAll(pPassengerAux, auxID, nombreStr, apellidoStr, auxPrecio, auxTipoPasajero, codigoVueloStr, auxFlightStatus))
		{
			pNuevoPassenger = pPassengerAux;
		}else
		{
			Passenger_delete(pNuevoPassenger);
		}

	}

	return pNuevoPassenger;
}

//----------------------------------Destructores----------------------------------------

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/*void Passenger_deleteAll(LinkedList* pArrayListPassenger)
{
	Passenger* this;
	int len;

	if (pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);
		for (int i = 0; i < len; i++)
		{
			this = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_delete(this);
		}
	}
}*/


//----------------------------------Getters y Setters----------------------------------------

//int Passenger_setId(Passenger* this, int id)
//{
//	int retorno;
//	retorno = -1;
//
//	if(this != NULL && id > 0)
//	{
//		this->id = id;
//		retorno = 0;
//	}
//	return retorno;
//}
//
//int Passenger_getId(Passenger* this)
//{
//	return this->id;
//}

int Passenger_setId(Passenger* this, int id)
{
	int retorno;
	retorno = -1;

	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}


	return retorno;
}

int Passenger_getId(Passenger* this, int* id)
{
	int retorno;
	retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}


	return retorno;
}

int Passenger_setNombre(Passenger* this, char* nombre)
{
	int retorno;
	retorno = -1;

	if(this != NULL && nombre != NULL && strlen(nombre) > 0)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}


	return retorno;
}

int Passenger_getNombre(Passenger* this, char* nombre)
{
	int retorno;
	retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}


	return retorno;
}

int Passenger_setApellido(Passenger* this, char* apellido)
{
	int retorno;
	retorno = -1;

	if(this != NULL && apellido != NULL && strlen(apellido) > 0)
	{
		strcpy(this->apellido, apellido);
		retorno = 0;
	}


	return retorno;
}

int Passenger_getApellido(Passenger* this, char* apellido)
{
	int retorno;
	retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 0;
		printf("Apellido en get %s", apellido);

	}


	return retorno;
}


int Passenger_setPrecio(Passenger* this, float precio)
{
	int retorno;
	retorno = -1;

	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		retorno = 0;
	}


	return retorno;
}

int Passenger_getPrecio(Passenger* this, float* precio)
{
	int retorno;
	retorno = -1;

	if(this != NULL && precio >= 0)
	{
		*precio = this->precio;
		retorno = 0;
	}


	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero)
{
	int retorno;
	retorno = -1;

	if(this != NULL && tipoPasajero >= 0)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}


	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero)
{
	int retorno;
	retorno = -1;

	if(this != NULL && tipoPasajero >= 0)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}


	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int retorno;
	retorno = -1;

	if(this != NULL && codigoVuelo != NULL && strlen(codigoVuelo) > 0)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}


	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int retorno;
	retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(codigoVuelo, this->codigoVuelo, 50);
		retorno = 0;
	}


	return retorno;
}

int Passenger_setFlightStatus(Passenger* this, int flightStatus)
{
	int retorno;
		retorno = -1;

		if(this != NULL && flightStatus >= 0)
		{
			this->flightStatus = flightStatus;
			retorno = 0;
		}


		return retorno;
}

int Passenger_getFlightStatus(Passenger* this, int* flightStatus)
{
	int retorno;
	retorno = -1;

	if(this != NULL && flightStatus >= 0)
	{
		*flightStatus = this->flightStatus;
		retorno = 0;
	}


	return retorno;
}

int Passenger_setAll(Passenger* this, int id, char* nombre, char* apellido, float precio, int tipoPasajero,
		char* codigoVuelo, int flightStatus)
{
	int retorno;
	retorno = -1;

	if(this != NULL && !Passenger_setId(this, id) && !Passenger_setNombre(this, nombre) &&
			!Passenger_setApellido(this, apellido) && !Passenger_setPrecio(this, precio) &&
			!Passenger_setTipoPasajero(this, tipoPasajero) && !Passenger_setTipoPasajero(this, tipoPasajero) &&
			!Passenger_setCodigoVuelo(this, codigoVuelo) && !Passenger_setFlightStatus(this, flightStatus))
	{
		retorno = 0;
	}

	return retorno;
}

int Passenger_getAll(Passenger* this, int* id, char* nombre, char* apellido, float* precio,
		int* tipoPasajero, char* codigoVuelo, int* flightStatus)
{
	int retorno;
	retorno = -1;

	if(this != NULL && !Passenger_getId(this, id) && !Passenger_getNombre(this, nombre) &&
			!Passenger_getApellido(this, apellido) && !Passenger_getPrecio(this, precio) &&
			!Passenger_getTipoPasajero(this, tipoPasajero) && !Passenger_getCodigoVuelo(this, codigoVuelo) &&
			!Passenger_getFlightStatus(this, flightStatus))
	{
		printf("Apellido en getall %s", apellido);
		retorno = 0;
	}

	return retorno;
}


//-----------------------------------Printeo-----------------------------------------

void Passenger_printUnPassenger(Passenger* this)
{
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[8];
	int auxFlightStatus;
	char textoTipoPasajero[30];

//	if(!Passenger_getId(this, auxId) && !Passenger_getNombre(this, auxNombre) && !Passenger_getApellido(this, auxApellido)
//			&& !Passenger_getPrecio(this, &auxPrecio) && Passenger_getTipoPasajero(this, auxTipoPasajero) &&
//			!Passenger_getCodigoVuelo(this, auxCodigoVuelo) && !Passenger_getFlightStatus(this, auxFlightStatus))
//	{
//		printf("ID 		Nombre 		Apellido	Precio		TipoPasajero	CodigoVuelo	FlightStatus\n");
//		printf("%-7d 	%-10s 	%-10s \t$%-12.2f \t%d\t\t%s\t\t%d\n", auxId, auxNombre, auxApellido, auxPrecio, auxTipoPasajero, auxCodigoVuelo, auxFlightStatus);
//
//	}


	if(!Passenger_getAll(this, &auxId, auxNombre, auxApellido, &auxPrecio, &auxTipoPasajero, auxCodigoVuelo, &auxFlightStatus))
	{
		switch(auxTipoPasajero)
		{
			case 1:
				strcpy(textoTipoPasajero, "FirstClass");
				break;
			case 2:
				strcpy(textoTipoPasajero,"ExecutiveClass");
				break;
			case 3:
				strcpy(textoTipoPasajero, "EconomyClass");
				break;
		}



		printf("ID 		Nombre 		Apellido	Precio		TipoPasajero	CodigoVuelo	FlightStatus\n");
		printf("%-7d 	%-10s 	%-10s \t$%-12.2f \t%s\t\t%s\t\t%d\n", auxId, auxNombre,  auxApellido, auxPrecio, textoTipoPasajero, auxCodigoVuelo, auxFlightStatus);
	}
}

//------------------------------------ABM---------------------------------------------


