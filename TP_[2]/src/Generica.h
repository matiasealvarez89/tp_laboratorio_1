#ifndef Generica_H_
#define Generica_H_
#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM_CHAR 50
#define LIBRE 0
#define OCUPADO 1

typedef struct{
	int idGenerica;
	int isEmpty;
}eGenerica;

//PROTOTIPOS
void eGenerica_imprimirUno(eGenerica Generica);
int eGenerica_imprimirTodos(eGenerica array[], int len, int estado);
int eGenerica_inicializar(eGenerica array[], int len);
int eGenerica_alta(eGenerica array[], int len);
int eGenerica_buscarEspacioLibre(eGenerica array[], int len);

#endif /* Generica_H_ */
