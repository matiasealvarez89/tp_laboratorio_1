
#include "pedidoDatos.h"

#include <stdio.h>
#include <stdlib.h>

/// @brief  Funcion que solicita al usuario un entero por consola. Lo valida, verifica y devuelve resultado.
///
/// @param pNumeroIngresado Puntero al resultado donde se guarda el numero ingresado.
/// @param mensaje Es el mensaje, donde se solicita el entero.
/// @param mensajeError Es el mensaje de error, que se muestra si el numero ingresado no esta dentro de los rangos.
/// @param minimo Valor minimo aceptado.
/// @param maximo Valor maximo aceptado.
/// @param reintentos Cantidad de reintentos en caso de error.
/// @return En caso de exito (0), en caso de error (-1)
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

/// @brief  Funcion que solicita al usuario un flotante por consola. Lo valida, verifica y devuelve resultado.
///
/// @param pNumeroIngresado Puntero al resultado donde se guarda el numero ingresado.
/// @param mensaje Es el mensaje, donde se solicita el flotante.
/// @param mensajeError Es el mensaje de error, que se muestra si el numero ingresado no esta dentro de los rangos.
/// @param minimo Valor minimo aceptado.
/// @param maximo Valor maximo aceptado.
/// @param reintentos Cantidad de reintentos en caso de error.
/// @return En caso de exito (0), en caso de error (-1)
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



