#include "auxiliar.h"

#include <stdio.h>
#include <stdlib.h>

/// @brief Funcion especifica de TP, donde se muestra por pantalla las opciones del menu y se muestran
/// actualizados 3 valores ingresados por el usuario.
///
/// @param distancia Aca se muestran los KM ingresados por el usuario. Si no ha ingresado aun se muestran en 0.
/// @param precio1 Aca se muestran el precio de la primer aerolinea ingresada por el usuario. Si no ha
/// ingresadoaun se muestran en 0.
/// @param precio2 Aca se muestran el precio de la segunda aerolinea ingresada por el usuario. Si no ha
/// ingresado aun se muestran en 0.
void menu(int distancia, float precio1, float precio2){

	printf("1) Ingresar Kilometros: (KM = %d)\n",distancia);
	printf("2) Ingresar precio de vuelos: (Aerolineas = $%.2f, Latam = $%.2f)\n",precio1,precio2);
	printf("3) Calcular todos los costos\n");
	printf("4) Informar Resultados\n");
	printf("5) Carga forzada de datos\n");
	printf("6) Salir\n\n");

}

/// @brief Funcion especifica del TP, donde se muestran las opciones del submenu, para la opcion 2 del
/// menu principal.
///
/// @param precio1 Puntero a la direccion de la primer aerolinea.
/// @param precio2 Puntero a la direccion de la segunda aerolinea.
/// @param bandera1 Puntero a la direccion de la primer bandera.
/// @param bandera2 Puntero a la direccion de la segunda bandera.
void sumbMenu(float* precio1,float* precio2,int* bandera1,int* bandera2){
	int opcionSubMenu;
	int validacionRetornoSubMenu;

	do{
		validacionRetornoSubMenu = getInt(&opcionSubMenu,"1) Ingrese el precio por Aerolineas: \n2) Ingrese el precio por Latam: \n3) Volver al menu principal\n\n"
				"Ingrese la opcion deseada: \n","Ingreso incorrecto\n",1,3,4);
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
					printf("Volviendo al menu...\n\n");
					break;
			}
		}
	}while(opcionSubMenu != 3);

}

/// @brief Funcion especifica TP para calcular el 10% de descuento por debito.
///
/// @param precio Puntero a la variable donde se guarda el precio de una de las aerolineas.
/// @param precioConDescuento Puntero a la direccion donde se guarda el resultado de la funcion.
/// @return En caso de exito (0), en caso de error (-1).
int descuentoDebito(float* precio, float* precioConDescuento){
	int retorno = -1;

	if(precio != NULL){
		retorno = 0;
		*precioConDescuento = *precio*0.90;
	}

	return retorno;
}

/// @brief Funcion especifica TP para calcular el 25% de recargo por credito.
///
/// @param precio Puntero a la variable donde se guarda el precio de una de las aerolineas.
/// @param precioConRecargo Puntero a la direccion donde se guarda el resultado de la funcion.
/// @return En caso de exito (0), en caso de error (-1).
int recargoCredito(float* precio, float* precioConRecargo){
	int retorno = -1;

	if(precio != NULL){
		retorno = 0;
		*precioConRecargo = *precio*1.25;
	}

	return retorno;
}

/// @brief Funcion especifica TP para convertir el precio en pesos a BITCOIN
///
/// @param precio Puntero a la variable donde se guarda el precio de una de las aerolineas.
/// @param precioEnBitcoin Puntero a la direccion donde se guarda el resultado de la funcion.
/// @return En caso de exito (0), en caso de error (-1).
int precioBitcoin(float* precio, float* precioEnBitcoin){
	int retorno = -1;

	if(precio != NULL){
		retorno = 0;
		*precioEnBitcoin = *precio/4791994.87;
	}

	return retorno;
}

/// @brief Funcion especifica TP para calcular el precio por KM
///
/// @param precio Puntero a la variable donde se guarda el precio de una de las aerolineas.
/// @param distancia Puntero a la variable donde se guarda la cantidad de Kilometros.
/// @param precioPorKilometro Puntero a la direccion donde se guarda el resultado de la funcion.
/// @return En caso de exito (0), en caso de error (-1).
int precioUnitario(float* precio,int* distancia,float* precioPorKilometro){
	int retorno = -1;

	if(precio != NULL && distancia != NULL){
		retorno = 0;
		*precioPorKilometro = *precio / *distancia;
	}

	return retorno;
}

/// @brief Funcion especifica TP para calcular la diferencia de precios entre las dos aerolineas.
///
/// @param precio1 Puntero a la variable donde se guarda el precio de una de las aerolineas.
/// @param precio2 Puntero a la variable donde se guarda el precio de una de las aerolineas.
/// @param resultado Puntero a la direccion donde se guarda el resultado de la funcion.
/// @return En caso de exito (0), en caso de error (-1).
int diferencia(float* precio1,float* precio2,float* resultado){
	int retorno = -1;

	if(precio1 != NULL && precio2 != NULL){
		*resultado = *precio1 - *precio2;
		retorno = 0;
		if(*resultado < 0){
			*resultado = *resultado*-1;
		}

	}

	return retorno;
}

/// @brief Funcion especifica del tp, para simplificar codigo. Printea varias lineas, con los resultados
/// de los calculos.
///
/// @param precioConDescuento Variable donde se guarda el precio con descuento.
/// @param precioConRecargo Variable donde se guarda el precio con recargo.
/// @param precioEnBitcoin Variable donde se guarda el precio en BITCOIN.
/// @param precioPorKilometro Variable donde se guarda el precio unitario de los KM.
void mostrarDatos(float precioConDescuento,float precioConRecargo,float precioEnBitcoin,float precioPorKilometro){
	printf("a) Precio con tarjeta de debito: $%.2f\n",precioConDescuento);
	printf("b) Precio con tarjeta de credito: $%.2f\n",precioConRecargo);
	printf("c) Precio pagando con bitcoin: %.2f BTC\n",precioEnBitcoin);
	printf("d) Mostrar precio unitario: $%.2f\n",precioPorKilometro);

}
