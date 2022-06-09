#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

#define LEN 5

int main()
{
	setbuf(stdout, NULL);

	LinkedList* listaPasajeros = ll_newLinkedList();


    Passenger* pPassenger[LEN];
    char* auxApellido[50];

    Passenger_initArray(pPassenger, LEN);


    pPassenger[0] = Passenger_newParametros("1", "Lucas", "Gomez", "5250.25", "1", "AB1275C", "1");

    Passenger_printUnPassenger(pPassenger[0]);

    pPassenger[1] = Passenger_newParametros("7", "Jorge", "Gonzalez", "5250", "1", "AB1275C", "1");

    Passenger_printUnPassenger(pPassenger[1]);

    Passenger_getApellido(pPassenger[0], &auxApellido);
    printf("%s\n", &auxApellido);
    printf("%f\n", pPassenger[0]->precio);

    return 0;
}

