
#include "pedidoDatos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int esNumerica(char* array);
static int getInt(int* pResultado);
static int myGets(char* array, int len);


static int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];


	if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
	{
		retorno = 0;
		*pResultado = atoi(buffer);
	}

	return retorno;
}

static int myGets(char* array, int len)
{
	int retorno = -1;

	if(array != NULL && len > 0)
	{
		fflush(stdin);
		fgets(array, len, stdin);
		array[strlen(array) - 1] = '\0';
		retorno = 0;
	}


	return retorno;
}

static int esNumerica(char* array)
{
	int retorno = -1;
	int i;

	if(array[0] == '-')
	{
		i = 1;
	}else
	{
		i = 0;
	}

	for( ; array[i] != '\0'; i++)
	{
		if(array[i]< '0' || array[i] > '9')
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}

/// @brief  Funcion que solicita al usuario un entero por consola. Lo valida, verifica y devuelve resultado.
///
/// @param pNumeroIngresado Puntero al al espacio de memoria donde se guarda el numero ingresado.
/// @param mensaje Es el mensaje, donde se solicita el entero.
/// @param mensajeError Es el mensaje de error, que se muestra si el numero ingresado no esta dentro de los rangos.
/// @param minimo Valor minimo aceptado.
/// @param maximo Valor maximo aceptado.
/// @param reintentos Cantidad de reintentos en caso de error.
/// @return En caso de exito (0), en caso de error (-1)
int getNumero(int* pNumeroIngresado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int buffer;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && reintentos>= 0)
	{
		do
		{
			printf("%s", mensaje);


			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
			{
						*pNumeroIngresado = buffer;
						retorno = 0;
						break;
			}else
			{
				printf("%s", mensajeError);
			}
			reintentos--;

		}while(reintentos >= 0);
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

/// @brief Pide un char de dos opciones posibles, lo valida y lo guarda en una variable
///
/// @param pRespuesta Puntero a donde se guarda el caracter ingresado
/// @param mensaje Mensaje donde se pide el caracter, indicando las dos opciones
/// @param mensajeError Mensaje para indicar que no se ingreso un caracter valido
/// @param a Primer caracter posible
/// @param b Segundo caracter posible
/// @param reintentos Cantidad de reintentos en caso de error
/// @return Encaso de exito (0), en caso de error (-1)
int getRespuestaDosChar(char* pRespuesta,char* mensaje,char* mensajeError,char a,char b,int reintentos){
	int retorno = -1;
	char buffer;

	if(pRespuesta != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c",&buffer);

			if(buffer == a || buffer == b)
			{
				*pRespuesta = buffer;
				retorno = 0;
				break;
			}else
			{
				printf("%s",mensajeError);
				reintentos--;
			}

		}while(reintentos >= 0);
	}

	return retorno;
}
