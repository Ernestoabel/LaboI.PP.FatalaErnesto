#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_UTN.h"
char menu(char* mensajeUno,char* mensajeDos,char* mensajeTres,char* mensajeCuatro,char* mensajeCinco,
		  char* mensajeSeis,char* mensajeSiete,char* mensajeOcho,char* mensajeNueve,char* mensajeDiez,
		  char* mensajeOnce,char* mensajeDose,char* mensajeTrece)
{
	char opcion;
	printf("%s",mensajeUno);
	printf("%s",mensajeDos);
	printf("%s",mensajeTres);
	printf("%s",mensajeCuatro);
	printf("%s",mensajeCinco);
	printf("%s",mensajeSeis);
	printf("%s",mensajeSiete);
	printf("%s",mensajeOcho);
	printf("%s",mensajeNueve);
	printf("%s",mensajeDiez);
	printf("%s",mensajeOnce);
	printf("%s",mensajeDose);
	printf("%s",mensajeTrece);
	fflush(stdin);
	utn_getCaracter(&opcion,"\nINGRESE OPCION: ","\n--Error--\nOpcion no valida\n",'A','I');
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
