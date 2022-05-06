#include <stdio.h>
#include <stdlib.h>

#include "Passenger.h"
#include "pedidoDatos.h"

#define LIBRE 0
#define OCUPADO 1
#define ELEMENTS 4

int main(void) {
	setbuf(stdout, NULL);

	Passenger lista[ELEMENTS];
	char prueba[50];
	int pruebas;

	if(!initPassenger(lista, ELEMENTS))
	{
		printf("Se inicializo el programa\n");
	}else
	{
		printf("No hay lista reservada"); // preguntar sobre estos mensajes
	}

	pruebas = primerPosicionLibre(lista, ELEMENTS);
	addPassenger(lista, ELEMENTS, lista[pruebas].id, lista[pruebas].name, lista[pruebas].lastName, lista[pruebas].price, lista[pruebas].typePassenger, lista[pruebas].flyCode);
	printPassengers(lista, ELEMENTS);


	return EXIT_SUCCESS;
}
