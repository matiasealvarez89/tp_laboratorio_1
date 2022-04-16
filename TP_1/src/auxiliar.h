
#ifndef AUXILIAR_H_
#define AUXILIAR_H_

void menu(int distancia, float precio1, float precio2);
void sumbMenu(float* precio1,float* precio2,int* bandera1,int* bandera2);
int descuentoDebito(float* precio, float* precioConDescuento);
int recargoCredito(float* precio, float* precioConRecargo);
int precioBitcoin(float* precio, float* precioEnBitcoin);
int precioUnitario(float* precio,int* distancia,float* precioPorKilometro);
int diferencia(float* precio1,float* precio2,float* resultado);
void mostrarDatos(float precioConDescuento,float precioConRecargo,float precioEnBitcoin,float precioPorKilometro);

#endif /* AUXILIAR_H_ */
