#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Passenger.h"
#include "pedidoDatos.h"
#include "LinkedList.h"


//----------------------------------Constructores----------------------------------------

/// @brief Funcion para guardar espacio en memoria para un pasajero
///
/// @return Retorna el puntero de un nuevo pasajero
Passenger* Passenger_new()
{
	Passenger* pNuevoPassenger;

	pNuevoPassenger = NULL;
	pNuevoPassenger = (Passenger*)calloc(sizeof(Passenger), 1);


	return pNuevoPassenger;
}

/// @brief
///
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param precioStr
/// @param tipoPasajeroStr
/// @param codigoVueloStr
/// @param flightStatusStr
/// @return
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
		auxPrecio = atof(precioStr);

		if(strcmp(tipoPasajeroStr, "FirstClass") == 0)
		{
			auxTipoPasajero = 1;

		}else 	if(strcmp(tipoPasajeroStr, "ExecutiveClass") == 0)
				{
					auxTipoPasajero = 2;
				}else
				{
					auxTipoPasajero = 3;
				}


		if(strcmp(flightStatusStr, "Aterrizado") == 0)
		{
			auxFlightStatus = 1;

		}else	if(strcmp(flightStatusStr, "En Horario") == 0)
				{
					auxFlightStatus = 2;
				}else
				{
					auxFlightStatus = 3;
				}


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

	if(this != NULL && nombre != NULL)
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

	if(this != NULL && apellido != NULL)
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
	char auxCodigoVuelo[50];
	int auxFlightStatus;
	char textoTipoPasajero[50];
	char textoFlightStatus[50];


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

		switch(auxFlightStatus)
		{
			case 1:
				strcpy(textoFlightStatus, "Aterrizado");
				break;
			case 2:
				strcpy(textoFlightStatus, "En Horario");
				break;
			case 3:
				strcpy(textoFlightStatus, "En Vuelo");
				break;
		}

		printf("%-10d %-10s 	%-10s 	$%-10.2f 	%-15s	%-15s	%-15s\n",
				auxId, auxNombre,  auxApellido, auxPrecio, auxCodigoVuelo, textoTipoPasajero, textoFlightStatus);
	}
}

//------------------------------------ABM---------------------------------------------


Passenger* Passenger_addPassenger(int idNuevoPassenger)
{
	Passenger* pPassenger;
	char auxId[50];
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecioFloat;
	char auxPrecio[50];
	char auxFlyCode[50];
	int auxTypePassengerInt;
	char auxTypePassenger[50];
	int auxFlightStatusInt;
	char auxFlightStatus[50];



	pPassenger = NULL;

	if(!getPalabra(auxNombre, "Ingrese el Nombre del Pasajero\n", "Ingreso incorrecto\n", 2, 49, 3)
			&& !getPalabra(auxApellido, "Ingrese el Apellido del Pasajero\n", "Ingreso incorrecto\n", 2, 49, 3)
			&& !getFloat(&auxPrecioFloat, "Ingrese el Precio del Vuelo\n", "Ingreso incorrecto\n", 2000, 1000000, 3)
			&& !getPalabraConNumeros(auxFlyCode, "Ingrese el Codigo de Vuelo\n", "Ingreso incorrecto\n", 3, 9, 3)
			&& !getNumero(&auxTypePassengerInt, "Indique el tipo de Pasajero(1) FirstClass 2) ExecutiveClass 3) EconomyClass)\n", "Ingreso incorrecto\n", 1, 3, 3)
			&& !getNumero(&auxFlightStatusInt, "Indique el estado del vuelo (1) Aterrizado 2) En Horario 3) En Vuelo)\n", "Ingreso incorrecto\n", 1, 3, 4))
			{

			idNuevoPassenger++;

			sprintf(auxId, "%d", idNuevoPassenger);

			sprintf(auxPrecio, "%f", auxPrecioFloat);

			switch(auxTypePassengerInt)
				{
				case 1:
					strcpy(auxTypePassenger, "FirstClass");
					break;
				case 2:
					strcpy(auxTypePassenger,"ExecutiveClass");
					break;
				case 3:
					strcpy(auxTypePassenger, "EconomyClass");
					break;
				}

			switch(auxFlightStatusInt)
				{
					case 1:
						strcpy(auxFlightStatus, "Aterrizado");
						break;
					case 2:
						strcpy(auxFlightStatus, "En Horario");
						break;
					case 3:
						strcpy(auxFlightStatus, "En Vuelo");
						break;
				}

			pPassenger = Passenger_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxTypePassenger, auxFlyCode, auxFlightStatus);
			}

	return pPassenger;
}

int Passenger_edit(Passenger* pPasajeroAEditar)
{
	Passenger* pPasajeroAux;
	int retorno;
	int opcion;
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	char flyCodeAux[50];
	int tipoPasajeroAux;
	int flightStatusAux;
	char respuesta;
	int flagCambio;

	pPasajeroAux = NULL;
	retorno = -1;
	flagCambio = 0;

	if(pPasajeroAEditar != NULL)
	{

		pPasajeroAux = Passenger_new();
		pPasajeroAux = pPasajeroAEditar;

		do{
			printf("ID 	   Nombre 	Apellido	Precio		CodigoVuelo 	TipoPasajero	FlightStatus\n");
			Passenger_printUnPassenger(pPasajeroAux);

			if(!getNumero(&opcion, "Seleccione la opciona modificar\n"
				"1) Nombre\n"
				"2) Apellido\n"
				"3) Precio\n"
				"4) Codigo de vuelo\n"
				"5) Tipo de Pasajero\n"
				"6) Estado de Vuelo\n"
				"7) Volver\n", "No es una ocpion valida\n", 1, 7, 3))
				{
					switch(opcion)
					{
						case 1:
							if(!getPalabra(nombreAux, "Ingrese el Nombre\n", "Ingreso incorrecto\n", 2, 49, 3))
							{
								if(tolower(!getRespuestaDosChar(&respuesta, "Confirma el cambio?(S) SI N) NO)\n", "Ingreso incorrecto\n", 's', 'n', 3)))
								{
									if(respuesta == 's')
									{
										Passenger_setNombre(pPasajeroAux, nombreAux);
										flagCambio = 1;
									}else
									{
										printf("No se modifico\n");
									}
								}
							}
							break;
						case 2:
							if(!getPalabra(apellidoAux, "Ingrese el Apellido\n", "Ingreso incorrecto\n", 2, 49, 3))
							{
								if(tolower(!getRespuestaDosChar(&respuesta, "Confirma el cambio?(S) SI N) NO)\n", "Ingreso incorrecto\n", 's', 'n', 3)))
								{
									if(respuesta == 's')
									{
										Passenger_setApellido(pPasajeroAux, apellidoAux);
										flagCambio = 1;
									}else
									{
										printf("No se modifico\n");
									}
								}
							}
							break;
						case 3:
							if(!getFloat(&precioAux, "Ingrese el precio\n", "Ingreso Incorrecto", 5000, 100000, 3))
							{
								if(tolower(!getRespuestaDosChar(&respuesta, "Confirma el cambio?(S) SI N) NO)\n", "Ingreso incorrecto\n", 's', 'n', 3)))
								{
									if(respuesta == 's')
									{
										Passenger_setPrecio(pPasajeroAux, precioAux);
										flagCambio = 1;
									}else
									{
										printf("No se modifico\n");
									}
								}
							}
							break;
						case 4:
							if(!getPalabraConNumeros(flyCodeAux, "Ingrese el codigo de vuelo\n", "Ingreso incorrecto\n", 3, 9, 3))
							{
								if(tolower(!getRespuestaDosChar(&respuesta, "Confirma el cambio?(S) SI N) NO)\n", "Ingreso incorrecto\n", 's', 'n', 3)))
								{
									if(respuesta == 's')
									{
										Passenger_setCodigoVuelo(pPasajeroAux, flyCodeAux);
										flagCambio = 1;
									}else
									{
										printf("No se modifico\n");
									}
								}
							}
							break;
						case 5:
							if(!getNumero(&tipoPasajeroAux, "Indique el tipo de Pasajero(1) FirstClass 2) ExecutiveClass 3) EconomyClass)\n", "Ingreso incorrecto", 1, 3, 3))
							{
								if(tolower(!getRespuestaDosChar(&respuesta, "Confirma el cambio?(S) SI N) NO)\n", "Ingreso incorrecto\n", 's', 'n', 3)))
								{
									if(respuesta == 's')
									{
										Passenger_setTipoPasajero(pPasajeroAux, tipoPasajeroAux);
										flagCambio = 1;
									}else
									{
										printf("No se modifico\n");
									}
								}
							}
							break;
						case 6:
							if(!getNumero(&flightStatusAux, "Indique el tipo de Pasajero(1) FirstClass 2) ExecutiveClass 3) EconomyClass)\n", "Ingreso incorrecto", 1, 3, 3))
							{
								if(tolower(!getRespuestaDosChar(&respuesta, "Confirma el cambio?(S) SI N) NO)\n", "Ingreso incorrecto\n", 's', 'n', 3)))
								{
									if(respuesta == 's')
									{
										Passenger_setFlightStatus(pPasajeroAux, flightStatusAux);
										flagCambio = 1;
									}else
									{
										printf("No se modifico\n");
									}
								}
							}
							break;
						case 7:
							if(flagCambio == 1)
							{
								printf("ID 	   Nombre 	Apellido	Precio		CodigoVuelo 	TipoPasajero	FlightStatus\n");
								Passenger_printUnPassenger(pPasajeroAux);

								if(tolower(!getRespuestaDosChar(&respuesta, "Confirma los cambios?(S) SI N) NO)\n", "Ingreso incorrecto\n", 's', 'n', 3)))
								{
									if(respuesta == 's')
									{
										pPasajeroAEditar = pPasajeroAux;
									}else
									{
										Passenger_delete(pPasajeroAux);
									}
								}
							}
							printf("Volviendo\n");
							break;
					}
				}
		}while(opcion != 7);

	}

	return retorno;
}



//-----------------------------------Find--------------------------------------------------

int Passenger_findById(LinkedList* pArrayaPasajero, int id)
{
	Passenger* pPasajero;
	int retorno;
	int len;
	int idAux;

	retorno = -1;
	len = ll_len(pArrayaPasajero);

	for(int i = 0; i < len; i++)
	{
		pPasajero = (Passenger*)ll_get(pArrayaPasajero, i);
		if(!Passenger_getId(pPasajero, &idAux) && idAux == id)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}


//-----------------------------------Sort-------------------------------------------------

int Passenger_compareByApellido(Passenger* pasajeroUno, Passenger* pasajeroDos)
{
	int retorno;
	char auxApellidoUno[50];
	char auxApellidoDos[50];

	if(pasajeroUno != NULL && pasajeroDos != NULL)
	{
		Passenger_getApellido(pasajeroUno, auxApellidoUno);
		Passenger_getApellido(pasajeroDos, auxApellidoDos);

		retorno = strcmp(auxApellidoUno, auxApellidoDos);
	}


	return retorno;
}

int Passenger_compareByPrecio(Passenger* pasajeroUno, Passenger* pasajeroDos)
{
	int retorno;
	float auxPrecioUno;
	float auxPrecioDos;
	retorno = 0;

	if(pasajeroUno != NULL && pasajeroDos != NULL)
	{
		Passenger_getPrecio(pasajeroUno, &auxPrecioUno);
		Passenger_getPrecio(pasajeroDos, &auxPrecioDos);

		if(auxPrecioUno > auxPrecioDos)
		{
			retorno = 1;
		}else if(auxPrecioDos > auxPrecioUno)
		{
			retorno = -1;
		}
	}

	return retorno;
}

