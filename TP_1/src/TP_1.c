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
int getFloat(float* pNumeroIngresado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int menu(int distancia, float precio1, float precio2);
int sumbenuPrecio(float* precio1,float* precio2);

int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	int kilometros = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	int validacionRetorno;

	do{
		menu(kilometros,precioAerolineas,precioLatam);

		validacionRetorno = getInt(&opcionMenu,"Ingrese la opcion deseada: \n","Ingreso incorrecto\n",1,6,5);

		if(validacionRetorno == 0){
			switch(opcionMenu){
				case 1:
					validacionRetorno = getInt(&kilometros,"Ingrese la cantidad de kilometros: \n","Ingreso incorrecto\n",1,100000,5);
					break;
				case 2:
//					validacionRetorno = getFloat(&precioAerolineas,"Ingrese el precio por Aerolineas: \n","Ingreso incorrecto\n",1,10000000,5);
//					validacionRetorno = getFloat(&precioLatam,"Ingrese el precio por Latam: \n","Ingreso incorrecto\n",1,10000000,5);
					sumbenuPrecio(&precioAerolineas,&precioLatam);
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
			}


		}
	}while(opcionMenu != 6);


	return 0;
}

int getInt(int* pNumeroIngresado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int buffer;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && reintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%d", &buffer);
			reintentos--;

			if(buffer >= minimo && buffer <= maximo){
						*pNumeroIngresado = buffer;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(reintentos > 0);
	}

	return retorno;
}

int getFloat(float* pNumeroIngresado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	float buffer;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && reintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%f", &buffer);
			reintentos--;

			if(buffer >= minimo && buffer <= maximo){
						*pNumeroIngresado = buffer;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(reintentos > 0);
	}

	return retorno;
}

int menu(int distancia, float precio1, float precio2){

	printf("1) Ingresar Kilometros: (KM = %d)\n",distancia);
	printf("2) Ingresar precio de vuelos: (Aerolineas = $%.2f, Latam = $%.2f)\n",precio1,precio2);
	printf("3) Calcular todos los costos\n");
	printf("4) Informar Resultados\n");
	printf("5) Carga forzada de datos\n");
	printf("6) Salir\n");

	return 0;
}

int subMenuKilometros(int distancia){
	printf("Ingrese la cantidad de km: \n");
	scanf("%d", &distancia);

	return 0;
}

int sumbenuPrecio(float* precio1,float* precio2){
	int opcionSubMenu;
	int validacionRetornoSubMenu;

	do{
		printf("1) Ingrese el precio por Aerolineas: \n");
		printf("2) Ingrese el precio por Latam: \n");
		printf("3) Salir");
		validacionRetornoSubMenu = getInt(&opcionSubMenu,"Ingrese la opcion deseada: \n","Ingreso incorrecto\n",1,3,4);
		if(validacionRetornoSubMenu == 0){
			switch(opcionSubMenu){
				case 1:
					validacionRetornoSubMenu = getFloat(precio1,"Ingrese el precio por Aerolineas: \n","Ingreso incorrecto\n",1,10000000,5);
					break;
				case 2:
					validacionRetornoSubMenu = getFloat(precio2,"Ingrese el precio por Latam: \n","Ingreso incorrecto\n",1,10000000,5);
					break;
				case 3:
					break;
			}
		}

	}while(opcionSubMenu != 3);


	return 0;
}
