/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getInt(int* pNumeroIngresado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);


int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	int kilometros = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	int validacionRetorno;

	printf("1) Ingresar Kilometros: (KM = %d)\n",kilometros);
	printf("2) Ingresar precio de vuelos: (Aerolineas = %.2f, Latam = %.2f)\n",precioAerolineas,precioLatam);





	return 0;
}

int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,int minimo, int maximo, int reintentos){
	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && reintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);
			reintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(reintentos > 0);
	}

	return retorno;
}
