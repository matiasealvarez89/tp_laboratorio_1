#include <stdio.h>
#include <stdlib.h>

#include "Passenger.h"
#include "pedidoDatos.h"

#define LIBRE 1
#define OCUPADO 0
#define ELEMENTS 4

int main(void) {
	setbuf(stdout, NULL);

	/*Passenger lista[ELEMENTS] = {{1000, "Juan", "Gomez", 59850.25, "Hr45", 1, 0},
								 {1001, "Camila", "Gutierrez", 25200.65, "Hr45", 2, 0},
								 {1002, "Roberto", "Alvarez", 62500.25, "Jw35", 1, 0},
								 {1003, "Candela", "Gimenez", 45213.78, "Kr76", 3, 0}};
								 */
	char prueba[50];
	int primerPosicionLibre;
	int respuesta;

	/*if(!initPassenger(lista, ELEMENTS))
	{
		printf("Se inicializo el programa\n");
	}else
	{
		printf("No hay lista reservada"); // preguntar sobre estos mensajes
	}
	*/

	Passenger lista[ELEMENTS] = {{1000, "Juan", "Gomez", 59850.25, "Hr45", 1, 0},
									 {1001, "Camila", "Martin", 25200.65, "Hr45", 2, 0},
									 {1002, "Roberto", "Alvarez", 62500.25, "Jw35", 1, 1},
									 {1003, "Candela", "Gimenez", 45213.78, "Kr76", 3, 0}};

	do{
		printf("*****************************MENU PRINCIPAL*****************************\n");
		printf("1. ALTAS \n");
		printf("2. MODIFICAR: \n");
		printf("3. BAJA: \n");
		printf("4. INFORMAR: \n");
		printf("5. SALIR: \n");
		if(!getNumero(&respuesta, "Eliga la opcion deseada: \n", "Ingreso incorrecto \n", 1, 5, 3)){
			switch(respuesta){
				case 1:
					primerPosicionLibre = primerEspacioLibre(lista, ELEMENTS);
					if(primerPosicionLibre != -1)
					{
						printf("Posicion %d\n",primerPosicionLibre);
						addPassenger(lista, ELEMENTS, lista[primerPosicionLibre].id, lista[primerPosicionLibre].name,
								lista[primerPosicionLibre].lastName, lista[primerPosicionLibre].price,
								lista[primerPosicionLibre].typePassenger, lista[primerPosicionLibre].flyCode, primerPosicionLibre);
					}else
					{

						printf("No se encontro espacio para almacenar un nuevo ingreso \n");
					}
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					printf("Ha salido con exito...");
					break;

			}
		}

	}while(respuesta != 5);



	return EXIT_SUCCESS;
}
