#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Passenger.h"
#include "pedidoDatos.h"

#define LIBRE 1
#define OCUPADO 0
#define ELEMENTS 2000

int main(void)
{
	setbuf(stdout, NULL);

	Passenger arrayPasengers[ELEMENTS];
	int primerPosicionLibre;
	int respuesta;
	int flagCarga = 0;
	int ordenSort;

	if(!initPassenger(arrayPasengers, ELEMENTS))
	{
		printf("Se inicializo el programa\n");
	}else
	{
		printf("No hay arrayPasengers reservada");
	}

	do{
		printf("*****************************MENU PRINCIPAL*****************************\n");
		printf("1. ALTAS \n");
		printf("2. MODIFICAR: \n");
		printf("3. BAJA: \n");
		printf("4. INFORMAR: \n");
		printf("5. HARDCODEO: \n");
		printf("6. SALIR: \n");
		if(!getNumero(&respuesta, "Eliga la opcion deseada: \n", "Ingreso incorrecto \n", 1, 6, 3)){
			switch(respuesta){
				case 1:
					primerPosicionLibre = primerEspacioLibre(arrayPasengers, ELEMENTS);
					if(primerPosicionLibre != -1)
					{

						addPassenger(arrayPasengers, ELEMENTS, arrayPasengers[primerPosicionLibre].id, arrayPasengers[primerPosicionLibre].name,
								arrayPasengers[primerPosicionLibre].lastName, arrayPasengers[primerPosicionLibre].price,
								arrayPasengers[primerPosicionLibre].typePassenger, arrayPasengers[primerPosicionLibre].flyCode, primerPosicionLibre);
						flagCarga = 1;
					}else
					{

						printf("No se encontro espacio para almacenar un nuevo ingreso \n\n");
					}
					printPassengers(arrayPasengers, ELEMENTS);
					break;
				case 2:
					if(flagCarga == 1)
					{
						if(!printPassengers(arrayPasengers, ELEMENTS) &&
							!getNumero(&respuesta, "Ingrese el ID del pasajero a modificar: \n", "Numero no valido\n" , 1000, 2000, 3))
						{
							if(findPassenger(arrayPasengers, ELEMENTS, respuesta) == -1)
							{
								printf("No se encontro un pasajero con esa ID\n\n");
							}
							else
							{
								changePassenger(arrayPasengers, ELEMENTS, respuesta);
							}
							respuesta = 0;
						}
					}else
					{
						printf("Aun no se realizo ninguna carga\n");
					}
					break;
				case 3:
					if(flagCarga == 1)
					{
						if(!printPassengers(arrayPasengers, ELEMENTS) &&
							!getNumero(&respuesta, "Ingrese el ID del pasajero a dar de baja: \n", "Numero no valido\n" , 1000, 2000, 3))
								{
									if(findPassenger(arrayPasengers, ELEMENTS, respuesta) == -1)
									{
										printf("No se encontro un pasajero con esa ID\n\n");
									}
									else
									{
										removePassenger(arrayPasengers, ELEMENTS, respuesta);
									}
								}
					}else
					{
						printf("Aun no se realizo ninguna carga\n");
					}
						break;
				case 4:
					if(flagCarga == 1)
					{
						printPassengers(arrayPasengers, ELEMENTS);
						do{
							if(!getNumero(&respuesta, "1) arrayPasengersr Alfabeticamente\n2) Promedio de precios\n3) arrayPasengersr por codigo de vuelo\n4) Volver al menu principal\n"
														"Seleccione el tipo de informe: \n", "Numero no valido\n" , 1, 4, 3))
								switch(respuesta)
								{
									case 1:
										getNumero(&ordenSort, "Ingrese el critero para ordenar (1- Descendente 2- Ascendente)\n", "Ingreso incorrecto\n", 1, 2, 3);
										sortPassenger(arrayPasengers, ELEMENTS, ordenSort);
										printPassengers(arrayPasengers, ELEMENTS);
										break;
									case 2:
										promedioPasajes(arrayPasengers, ELEMENTS);
										break;
									case 3:
										getNumero(&ordenSort, "Ingrese el critero para ordenar (1- Descendente 2- Ascendente)\n", "Ingreso incorrecto\n", 1, 2, 3);
										sortPassengersByCode(arrayPasengers, ELEMENTS, ordenSort);
										printPassengersStatus(arrayPasengers, ELEMENTS);
										break;
									case 4:
										printf("Volviendo al menu principal\n");
										break;
								}
							}while(respuesta != 4);
					}else
					{
						printf("Aun no se realizo ninguna carga\n");
					}
					break;
				case 5:
					flagCarga = 1;
					forcedPassenger(arrayPasengers, ELEMENTS);
					break;
				case 6:
					printf("Ha salido con exito...");
					break;
			}
		}

	}while(respuesta != 6);

	return EXIT_SUCCESS;

}
