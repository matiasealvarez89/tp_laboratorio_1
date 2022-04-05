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

float descuentoDebito(float *precio);
float recargoTarjetaCredito(float precio);
float bitcoin(float precio);
float precioPorKilometro(float km, float precio);

int main(void) {
	setbuf(stdout, NULL);

	int kilometros;
	float precioAerolineas;
	float precioLatam;

	printf("Ingrese la cantidad de KM: ");
	scanf("%d", &kilometros);

	printf("Ingrese el precio por Aerolineas: $ ");
	scanf("%f", &precioAerolineas);

	printf("Ingrese el precio por Latam: $ ");
	scanf("%f", &precioLatam);

	printf("KMs Ingresados: %d\n\n", kilometros);

	printf("Precio Aerolineas: $%.2f\n", precioAerolineas);
	printf("a) Precio con tarjeta de debito: $%.2f\n", descuentoDebito(&precioAerolineas));
	printf("b) Precio con tarjeta de credito: $%.2f\n", recargoTarjetaCredito(precioAerolineas));
	printf("c) Precio pagando con bitcoin: %.2f BTC\n", bitcoin(precioAerolineas));
	printf("d) Mostrar precio unitario: $%.2f\n\n", precioPorKilometro(kilometros, precioAerolineas));

//	printf("Precio Latam: $%.2f\n", precioAerolineas);
//	printf("a) Precio con tarjeta de debito: $%.2f\n", descuentoDebito(precioLatam));
//	printf("b) Precio con tarjeta de credito: $%.2f\n", recargoTarjetaCredito(precioLatam));
//	printf("c) Precio pagando con bitcoin: %.2f BTC\n", bitcoin(precioLatam));
//	printf("d) Mostrar precio unitario: $%.2f\n", precioPorKilometro(kilometros, precioLatam));



	return EXIT_SUCCESS;
}

float descuentoDebito(float* precio){
	*precio = *precio*0.9;

	return 0;
}

float recargoTarjetaCredito(float precio){
	float resultado;

	resultado = precio*1.25;

	return resultado;
}

float bitcoin(float precio){
	float resultado;

	resultado = precio/4606954.55;

	return resultado;
}

float precioPorKilometro(float km, float precio){
	float resultado;

	resultado = precio/km;

	return resultado;
}
