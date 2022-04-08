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
					sumbenuPrecio(&precioAerolineas,&precioLatam,&flagAerolineas,&flagLatam);
					break;
				case 3:
					if(flagKilometros != 0 && flagAerolineas != 0 && flagLatam != 0){
						descuentoDebito(&precioAerolineas, &aerolineasDebito);
						recargoCredito(&precioAerolineas, &aerolineasCredito);
						precioBitcoin(&precioAerolineas, &aerolineasBitcoin);
						precioUnitario(&precioAerolineas, &kilometros, &precioUnitarioAerolineas);
						descuentoDebito(&precioLatam, &latamDebito);
						recargoCredito(&precioLatam, &latamCredito);
						precioBitcoin(&precioLatam, &latamBitcoin);
						precioUnitario(&precioLatam, &kilometros, &precioUnitarioLatam);
						diferencia(&precioAerolineas,&precioLatam,&diferenciaPrecio);

						printf("%.2f\n",aerolineasDebito);
						printf("%.2f\n",aerolineasCredito);
						printf("%.2f\n",aerolineasBitcoin);
						printf("%.2f\n",precioUnitarioAerolineas);
						printf("%.2f\n",latamDebito);
						printf("%.2f\n",latamCredito);
						printf("%.2f\n",latamBitcoin);
						printf("%.2f\n",precioUnitarioLatam);
						printf("%.2f\n",diferenciaPrecio);
					}else{
						printf("Faltan ingresar datos.\n");
					}
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					printf("Ha salido con exito.");
					break;
			}


		}
	}while(opcionMenu != 6);


	return 0;
}


