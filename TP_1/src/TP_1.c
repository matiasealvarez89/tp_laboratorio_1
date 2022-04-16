/*
 ============================================================================
Matias Ezequiel Alvarez
TP_1
DIV E
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"




int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	int kilometros = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	int flagKilometros = 0;
	int flagAerolineas = 0;
	int flagLatam = 0;
	float aerolineasDebito;
	float aerolineasCredito;
	float aerolineasBitcoin;
	float precioUnitarioAerolineas;
	float diferenciaPrecio;
	float latamDebito;
	float latamCredito;
	float latamBitcoin;
	float precioUnitarioLatam;
	int flagCalculos = 0;

	do{
		menu(kilometros,precioAerolineas,precioLatam);

		if(getInt(&opcionMenu,"Ingrese la opcion deseada: \n","Ingreso incorrecto\n",1,6,5) == 0){
			switch(opcionMenu){
				case 1:
					if(getInt(&kilometros,"Ingrese la cantidad de kilometros: \n","Ingreso incorrecto\n",1,100000,5) == 0){
						flagKilometros = 1;
					}else{
						printf("No se ingresaron correctamente los Kilometros.\n");
					}
					break;
				case 2:
					sumbMenu(&precioAerolineas,&precioLatam,&flagAerolineas,&flagLatam);
					break;
				case 3:
					if(flagKilometros != 0 && flagAerolineas != 0 && flagLatam != 0){
						if(!descuentoDebito(&precioAerolineas, &aerolineasDebito))
						if(!recargoCredito(&precioAerolineas, &aerolineasCredito))
						precioBitcoin(&precioAerolineas, &aerolineasBitcoin);
						precioUnitario(&precioAerolineas, &kilometros, &precioUnitarioAerolineas);
						descuentoDebito(&precioLatam, &latamDebito);
						recargoCredito(&precioLatam, &latamCredito);
						precioBitcoin(&precioLatam, &latamBitcoin);
						precioUnitario(&precioLatam, &kilometros, &precioUnitarioLatam);
						diferencia(&precioAerolineas,&precioLatam,&diferenciaPrecio);
						flagCalculos = 1;
						printf("Se realizaron los calculos correspondientes.\n\n");
					}else{
						printf("Faltan ingresar datos.\n\n");
					}
					break;
				case 4:
					if(flagKilometros != 0 && flagAerolineas != 0 && flagLatam != 0 && flagCalculos != 0){
						printf("\nKms Ingresados: %d km\n", kilometros);
						printf("\nPrecio Aerolineas: $%.2f\n", precioAerolineas);
						mostrarDatos(aerolineasDebito, aerolineasCredito, aerolineasBitcoin, precioUnitarioAerolineas);
						printf("\nPrecio Latam: $%.2f\n", precioLatam);
						mostrarDatos(latamDebito, latamCredito, latamBitcoin, precioUnitarioLatam);
						printf("\nLa diferencia de precio es: $%.2f\n\n", diferenciaPrecio);
					}else{
						if(flagCalculos == 0){
							printf("No se hicieron los calculos aun.\n\n");
						}else{
							printf("Faltan ingresar datos.\n\n");
						}
					}
					break;
				case 5:
					kilometros = 7090;
					precioAerolineas = 162965;
					precioLatam = 159339;
					flagKilometros = 1;
					flagAerolineas = 1;
					flagLatam = 1;

					descuentoDebito(&precioAerolineas, &aerolineasDebito);
					recargoCredito(&precioAerolineas, &aerolineasCredito);
					precioBitcoin(&precioAerolineas, &aerolineasBitcoin);
					precioUnitario(&precioAerolineas, &kilometros, &precioUnitarioAerolineas);
					descuentoDebito(&precioLatam, &latamDebito);
					recargoCredito(&precioLatam, &latamCredito);
					precioBitcoin(&precioLatam, &latamBitcoin);
					precioUnitario(&precioLatam, &kilometros, &precioUnitarioLatam);
					diferencia(&precioAerolineas,&precioLatam,&diferenciaPrecio);

					printf("\nKms Ingresados: %d km\n", kilometros);
					printf("\nPrecio Aerolineas: $%.2f\n", precioAerolineas);
					mostrarDatos(aerolineasDebito, aerolineasCredito, aerolineasBitcoin, precioUnitarioAerolineas);
					printf("\nPrecio Latam: $%.2f\n", precioLatam);
					mostrarDatos(latamDebito, latamCredito, latamBitcoin, precioUnitarioLatam);
					printf("\nLa diferencia de precio es: $%.2f\n\n", diferenciaPrecio);
					break;
				case 6:
					printf("Ha salido con exito.\n");
					break;
			}


		}
	}while(opcionMenu != 6);


	return 0;
}


