/*
 ============================================================================
 Name        : Parcial de laboratorio
 Author      : Ernesto Fatala
 Version     :
 Copyright   : Your copyright notice
 Description : Division J
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "biblioteca_UTN.h"
#include "articulos.h"
#include "venta.h"

#define TAMARTICULOS 100 //PONER EN 100 SI POR CARGA/PONER EN 10 SI POR DATOS HARDCODEADOS
#define TAMVENTAS 500 //PONER 10 500 SI ES POR CARGA/PONER EN 10 SI POR DATOS HARDCODEADOS
#define TAMRUBROS 4
#define VACIO 0
#define OCUPADO 1

int main(void) {
	setbuf(stdout, NULL);
	// COMENTAR DESDE LA LINEA 28 HASTA LA 42 SI SE TRABAJA CON DATOS DE CARGA POR USUARIO/AL REVES SI POR DATOS HARDCODEADOS
	/*eArticulo listaArticulos[10]={
			{100,"Televisor","40x30x10",76000,1002},{101,"Heladera","90x120x50",120000,1001},
			{102,"Televisor","40x30x10",85000,1004},{103,"Tostadora","15x10x5",63000,1003},
			{104,"Tablet","10x5x2",70000,1003},{105,"Filmadora","40x30x10",76000,1003},
			{106,"Microondas","15x10x10",80000,1001},{107,"Ipod","6x3x1",76000,1002},
			{108,"Parlante","40x30x10",76000,1002},{109,"Heladera","90x120x50",50000,1001}
	};

	eVenta listaVentas[10]={
			{20000,102,5,76000,{1,1,2023}},{20001,100,2,120000,{2,2,2023}},
			{20002,103,7,85000,{3,3,2023}},{20003,101,1,63000,{4,6,2023}},
			{20004,109,5,76000,{5,6,2023}},{20005,108,2,120000,{6,6,2023}},
			{20006,104,5,76000,{7,6,2023}},{20007,107,2,120000,{8,6,2023}},
			{20008,105,5,76000,{9,6,2023}},{20009,106,2,120000,{10,6,2023}},
	};*/
	eRubro rubros[TAMRUBROS]={
				{1001,"ELECTRONICA"},{1002,"BLANCO"},
				{1003,"AUDIO"},{1004,"VIDEO"},
	};
	//COMENTAR DE LA LINEA 47 A LA 51 EN CASO DE TRABAJAR CON DATOS HARDCODEADOS/ AL REVES SI POR CARGA
	eArticulo listaArticulos[TAMARTICULOS];
	eVenta listaVentas[TAMVENTAS];
	inicializarArticulos(listaArticulos,TAMARTICULOS,VACIO);
	inicializarVentas(listaVentas,TAMVENTAS,VACIO);
	int bandera=VACIO;//PONER OCUPADO SI SE UTILIZAN DATOS HARDCODEADOS/PONER VACIO SI SE INGRESAN DATOS
	char menuPrincipal,confirmarSalida;
	do{
		menuPrincipal=menu("\n+----------------------+","\n|RODO ELECTRODOMESTICOS|","\n+----------------------+",
				"\n|A.ALTA DE ARTICULOS   |","\n|B.MODIFICAR ARTICULOS |","\n|C.BAJA ARTICULOS      |",
				"\n|D.LISTAR ARTICULOS    |","\n|E.LISTAR RUBROS       |","\n|F.ALTA VENTA          |",
				"\n|G.LISTAR VENTAS       |","\n|H.INFORMES            |","\n|I.SALIR               |",
				"\n+----------------------+");
		switch(menuPrincipal){
			case 'A':
				funcionAltaArticulo(listaArticulos,TAMARTICULOS,rubros);
				bandera=OCUPADO;
			break;
			case 'B':
				if(bandera==OCUPADO){
					funcionModificarArticulo(listaArticulos,TAMARTICULOS,rubros);
				}else{
					printf("\nNO HAY ARTICULOS CARGADO EN SISTEMA\n");
					utn_pausaPrograma();
				}
			break;
			case 'C':
				if(bandera==OCUPADO){
					funcionBajaArticulo(listaArticulos,TAMARTICULOS,rubros);
				}else{
					printf("\nNO HAY ARTICULOS CARGADO EN SISTEMA\n");
					utn_pausaPrograma();
				}
				if(validarQueHayaArticulos(listaArticulos,TAMARTICULOS,VACIO)==0){
					bandera=OCUPADO;
				}else{
					bandera=VACIO;
				}
			break;
			case 'D':
				if(bandera==OCUPADO){
					funcionListarArticulos(listaArticulos,TAMARTICULOS,rubros);
				}else{
					printf("\nNO HAY ARTICULOS CARGADO EN SISTEMA\n");
					utn_pausaPrograma();
				}
			break;
			case 'E':
				mostrarRubros(TAMRUBROS,rubros);
				utn_pausaPrograma();
			break;
			case 'F':
				if(bandera==OCUPADO){
					funcionCargarVentas(listaVentas,TAMVENTAS,listaArticulos,TAMARTICULOS);
				}else{
					printf("\nNO HAY ARTICULOS CARGADO EN SISTEMA\n");
					utn_pausaPrograma();
				}
			break;
			case 'G':
				if(bandera==OCUPADO){
					funcionListarVentas(listaVentas,TAMVENTAS,listaArticulos,TAMARTICULOS);
				}else{
					printf("\nNO HAY ARTICULOS CARGADO EN SISTEMA\n");
					utn_pausaPrograma();
				}
			break;
			case 'H':
				if(bandera==OCUPADO){

				}else{
					printf("\nNO HAY ARTICULOS CARGADO EN SISTEMA\n");
					utn_pausaPrograma();
				}
			break;
			case 'I':
				confirmarSalida=continuarCarga("\n¿SALIR DEL PROGRAMA?");
			break;
		}
	}while(confirmarSalida!='S');
	printf("\n--GRACIAS POR ELEGIRNOS--\n-----VUELVA PRONTO------");
	return EXIT_SUCCESS;
}
