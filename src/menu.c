#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_UTN.h"
char menu(void)
{
	char opcion;
	printf("\n============================\n|  RODO ELECTRODOMESTICOS  |\n----------------------------");
	printf("\n|A.ALTA DE ARTICULOS       |");
	printf("\n|B.MODIFICAR ARTICULOS     |");
	printf("\n|C.BAJA ARTICULOS          |");
	printf("\n|D.LISTAR ARTICULOS        |");
	printf("\n|E.LISTAR RUBROS           |");
	printf("\n|F.ALTA VENTA              |");
	printf("\n|G.LISTAR VENTAS           |");
	printf("\n|H.INFORMES                |");
	printf("\n|I.SALIR                   |\n============================\n");
	fflush(stdin);
	utn_getCaracter(&opcion,"\nINGRESE OPCION: ","\n--Error--\nOPCION NO VALIDA\n",'A','I');
    return opcion;
}
char continuarCarga(char* mensaje)
{
	int validar;
	char opcion;
	do{
		printf("%s",mensaje);
		fflush(stdin);
		validar=utn_getDosCaracter(&opcion,"\nINGRESE OPCION S/N: ","\n--Error--\nOPCION NO VALIDA\n",'S','N');
	}while(validar!=0);
	return opcion;
}
char menuInformes(void)
{
	char opcion;
	printf("=====================================================================================\n"
		   "|1.MOSTRAR ARTICULOS DE UN RUBRO SELECCIONADO                                       |\n");
	printf("|2.MOSTRAR TODAS LAS VENTAS EFECTUADAS DE UNA FECHA SELECCIONADA                    |\n");
	printf("|3.INFORMAR IMPORTE TOTAL DE LAS VENTAS REALIZADAS DE UN ARTICULO SELECCIONADO      |\n");
	printf("|4.INFORMAR IMPORTE TOTAL DE TODAS LAS VENTAS DE UN RUBRO EN UNA FECHA SELECCIONADA |\n"
		   "=====================================================================================");
	fflush(stdin);
	utn_getCaracter(&opcion,"\nINGRESE OPCION: ","\n--Error--\nOpcion no valida\n",'1','4');
	return opcion;
}
