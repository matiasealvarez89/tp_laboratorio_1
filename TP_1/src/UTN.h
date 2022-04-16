

#ifndef UTN_H_
#define UTN_H_

int getInt(int* pNumeroIngresado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int getFloat(float* pNumeroIngresado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
void menu(int distancia, float precio1, float precio2);
void sumbMenu(float* precio1,float* precio2,int* bandera1,int* bandera2);
int descuentoDebito(float* precio, float* precioConDescuento);
int recargoCredito(float* precio, float* precioConRecargo);
int precioBitcoin(float* precio, float* precioEnBitcoin);
int precioUnitario(float* precio,int* distancia,float* precioPorKilometro);
int diferencia(float* precio1,float* precio2,float* resultado);
void mostrarDatos(float precioConDescuento,float precioConRecargo,float precioEnBitcoin,float precioPorKilometro);
//int UTN_multiplicacionFlotante(float num1,float num2,float producto);

#endif /* UTN_H_ */
