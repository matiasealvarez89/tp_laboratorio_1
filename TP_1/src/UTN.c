
#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"

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


int sumbenuPrecio(float* precio1,float* precio2,int* bandera1,int* bandera2){
	int opcionSubMenu;
	int validacionRetornoSubMenu;

	do{
		printf("1) Ingrese el precio por Aerolineas: \n");
		printf("2) Ingrese el precio por Latam: \n");
		printf("3) Salir\n");
		validacionRetornoSubMenu = getInt(&opcionSubMenu,"Ingrese la opcion deseada: \n","Ingreso incorrecto\n"
				"1) Ingrese el precio por Aerolineas: \n2) Ingrese el precio por Latam: \n3) Salir\n",1,3,4);
		if(validacionRetornoSubMenu == 0){
			switch(opcionSubMenu){
				case 1:
					validacionRetornoSubMenu = getFloat(precio1,"Ingrese el precio por Aerolineas: \n","Ingreso incorrecto\n",1,10000000,5);
					*bandera1 = 1;
					break;
				case 2:
					validacionRetornoSubMenu = getFloat(precio2,"Ingrese el precio por Latam: \n","Ingreso incorrecto\n",1,10000000,5);
					*bandera2 = 1;
					break;
				case 3:
					printf("Volviendo al menu...\n");
					break;
			}
		}

	}while(opcionSubMenu != 3);


	return 0;
}

int descuentoDebito(float* precio, float* precioConDescuento){
	int retorno = -1;

	if(precio > 0){
		retorno = 0;
		*precioConDescuento = *precio*0.90;
	}

	return retorno;
}

int recargoCredito(float* precio, float* precioConRecargo){
	int retorno = -1;

	if(precio > 0){
		retorno = 0;
		*precioConRecargo = *precio*1.25;
	}

	return retorno;
}

int precioBitcoin(float* precio, float* precioEnBitcoin){
	int retorno = -1;

	if(precio > 0){
		retorno = 0;
		*precioEnBitcoin = *precio/4791994.87;
	}

	return retorno;
}

int precioUnitario(float* precio,int* distancia,float* precioPorKilometro){
	int retorno = -1;

	if(precio > 0 && distancia > 0){
		retorno = 0;
		*precioPorKilometro = *precio / *distancia;
	}

	return retorno;
}

int diferencia(float* precio1,float* precio2,float* resultado){
	int retorno = -1;

	if(precio1 > 0 && precio2 > 0){
		if(precio1 > precio2){
			*resultado = *precio1 - *precio2;
		}else{
			if(precio2 > precio1){
				*resultado = *precio2 - *precio1;
			}else{
				printf("No hay diferencia de precios.\n");
			}
		}
	}

	return retorno;
}

int mostrarDatos(float* precioConDescuento,float* precioConRecargo,float* precioEnBitcoin,float* precioPorKilometro){
	printf("a) Precio con tarjeta de debito: $%.2f\n",precioConDescuento);
	printf("b) Precio con tarjeta de credito: $%.2f\n",precioConRecargo);
	printf("c) Precio pagando con bitcoin: $%.2f\n",precioEnBitcoin);
	printf("d) Precio pagando con bitcoin: $%.2f\n",precioPorKilometro);

	return 0;
}
