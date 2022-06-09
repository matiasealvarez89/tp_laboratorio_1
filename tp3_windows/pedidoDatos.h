

#ifndef PEDIDODATOS_H_
#define PEDIDODATOS_H_

int getNumero(int* pNumeroIngresado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int getFloat(float* pNumeroIngresado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int getRespuestaDosChar(char* pRespuesta,char* mensaje,char* mensajeError,char a,char b,int reintentos);


#endif /* PEDIDODATOS_H_ */
