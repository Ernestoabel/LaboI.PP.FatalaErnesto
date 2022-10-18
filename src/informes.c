#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "venta.h"
#include "articulos.h"
#include "biblioteca_UTN.h"
#include "menu.h"
int validarFechaIngresada(int* dia,int* mes,int* anio,eVenta* validarFecha,int cantidadVentas)
{
	int i,retorno=-1,entro=0;

	if(validarFecha!=NULL){
		for(i=0;i<cantidadVentas;i++){
				if((*(validarFecha+i)).fecha.dia==*dia && (*(validarFecha+i)).fecha.mes==*mes
					&& (*(validarFecha+i)).fecha.anio==*anio){
					entro=1;
					retorno=0;
					//break;
				}
		}
		if(entro==0){
			printf("\nLA FECHA INGRESADA NO CORRESPONDE A UNA FACTURA CARGADA\n");
		}
	}
	return retorno;
}
int ingresoFechaParaInformes(eVenta* fecha,int* diaFactura,int* mesFactura,int* anioFactura,int cantidadVentas)
{
	int retorno=-1;
	if(fecha!=NULL){
		do{
			utn_getEntero(*&diaFactura,"\nINGRESE EL DIA EN QUE SE EMITIO LA FACTURA\n","--ERROR--",1,31);
			utn_getEntero(*&mesFactura,"\nINGRESE EL MES EN QUE SE EMITIO LA FACTURA\n","--ERROR--",1,12);
			utn_getEntero(*&anioFactura,"\nINGRESE EL ANIO EN QUE SE EMITIO LA FACTURA\n","--ERROR--",2000,2050);
		}while(validarFechaIngresada(*&diaFactura,*&mesFactura,*&anioFactura,fecha,cantidadVentas)!=0);
		retorno=0;
	}
	return retorno;
}
int listarFacturaPorFecha(eVenta* listaVentas,int cantidadVentas,int* articuloId,eArticulo* listaArticulos,
							int cantidadArticulos,int* dia,int* mes,int* anio)
{
	int retorno=-1,i,posicionArticulo;
	if(listaVentas!=NULL && listaArticulos!=NULL){
		ingresoFechaParaInformes(listaVentas,*&dia,*&mes,*&anio,cantidadVentas);
		for(i=0;i<cantidadVentas;i++){
			if((*(listaVentas+i)).fecha.dia==*dia && (*(listaVentas+i)).fecha.mes==*mes &&
				(*(listaVentas+i)).fecha.anio==*anio){
				validarIdExistente(listaArticulos,cantidadArticulos,(&(*(listaVentas+i)).articuloId),&posicionArticulo,"");
				printf("%s%s%s%6d|\n%s%2d/%2d/%4d|\n%s",
									"==========================           =====           =============\n",
									"|RODO ELECTRODOMESTICOS  |           | B |           |FACTURA    |\n",
									"|BOEDO 1050-(C1239) CABA |           =====           |   Nª",(*(listaVentas+i)).idVenta,
									"|VENTAS@RODOELECTRO.COM  |                           | ",(*(listaVentas+i)).fecha.dia,
									(*(listaVentas+i)).fecha.mes,(*(listaVentas+i)).fecha.anio,
									"==========================                           =============\n" );
							printf("%s%s%s%s",
									"==========================\n",
									"|CLIENTE                 |\n",
									"|CONSUMIDOR FINAL        |\n",
									"==================================================================\n");
							printf("%s|%6d|%8d|%-19s|%15.2f|%12.2f|\n%s\n%s\n%s\n",
									"|CODIGO|CANTIDAD|ARTICULO           |PRECIO UNITARIO|PRECIO FINAL|\n",
									(*(listaArticulos+posicionArticulo)).idArticulo,(*(listaVentas+i)).cantidad,(*(listaArticulos+posicionArticulo)).descripcion,
									(*(listaArticulos+posicionArticulo)).precio,(*(listaVentas+i)).precioTotal,
									"|      |        |                   |               |            |",
									"|      |        |                   |               |            |",
									"------------------------------------------------------------------");
							printf("%s|%12.2f|\n%s\n","|PRECIO TOTAL                                       ",(*(listaVentas+i)).precioTotal,
									"==================================================================");
							printf("(PRESIONE DOBLE ENTER)");
							utn_pausaPrograma();
			}
		}
		retorno=0;
	}
	return retorno=0;
}
int mostrarArticulosPorRubro(eArticulo* listaArticulos,int cantidad,eRubro* rubros,int* idRubro)
{
	int retorno=-1,i,indice;
	    if(listaArticulos!=NULL){
	    	printf("\n+---+--------------------+------------+----------+------------+\n");
	    	printf("|%3s|%20s|%12s|%10s|%12s|\n"," ID"," DESCRIPCION"," MEDIDA"," PRECIO"," RUBRO");
	    	printf("+---+--------------------+------------+----------+------------+\n");
	    	for(i=0;i<cantidad;i++){
	            if((*(listaArticulos+i)).idArticulo>=100){
	            	if((*(listaArticulos+i)).rubroId==*idRubro){
	            		posicionSector(listaArticulos,&indice,i);
						printf("|%3d|%20s|%12s|%10.2f|%12s|\n",(*(listaArticulos+i)).idArticulo,(*(listaArticulos+i)).descripcion,
						(*(listaArticulos+i)).medida,(*(listaArticulos+i)).precio,(*(rubros+indice)).descripcion);
	            	}
	            }
	        }
	    	printf("+---+--------------------+------------+----------+------------+\n");
	        retorno=0;
	    }
	return retorno;
}
int aumuladorDeVentasPorArticulo(eVenta* listaVentas,int cantidadVentas,int* idArticulo,float* ventaTotal)
{
	int retorno=-1,i;
	float acumumladorVenta=0;
	if(listaVentas!=NULL){
		for(i=0;i<cantidadVentas;i++){
			if((*(listaVentas+i)).articuloId==*idArticulo){
				acumumladorVenta+=(*(listaVentas+i)).precioTotal;
			}
		}
		*ventaTotal=acumumladorVenta;
		retorno=0;
	}
	return retorno;
}
int aumuladorDeVentasPorRubroYFecha(eVenta* listaVentas,int cantidadVentas,float* ventaTotal,eArticulo* listaArticulos,int cantidadArticulos)
{
	int retorno=-1,i,datoIdRubro,diaFactura,mesFactura,anioFactura,bandera=0;
	float acumumladorVenta=0;
	if(listaVentas!=NULL){
		utn_getEntero(&datoIdRubro,"\nINGRESE EL ID DEL RUBRO DEL ARTICULO\n","--ERROR--",1001,1004);
		if((*(listaVentas)).idVenta>=2000){
			for(i=0;i<cantidadVentas;i++){
				if((*(listaVentas+i)).articuloRubro==*&datoIdRubro){
						printf("\n%s%2d/%2d/%4d\n","FACTURAS EMITIDAS DEL RUBRO: ",(*(listaVentas+i)).fecha.dia,(*(listaVentas+i)).fecha.mes,(*(listaVentas+i)).fecha.anio);
						bandera=1;
				}
			}
			if(bandera==1){
				ingresoFechaParaInformes(listaVentas,&diaFactura,&mesFactura,&anioFactura,cantidadVentas);
				for(i=0;i<cantidadVentas;i++){
					if((*(listaVentas+i)).fecha.mes==*&diaFactura && (*(listaVentas+i)).fecha.mes==*&mesFactura &&
							(*(listaVentas+i)).fecha.anio==*&anioFactura && (*(listaVentas+i)).articuloRubro==*&datoIdRubro){
						acumumladorVenta+=(*(listaVentas+i)).precioTotal;
					}
				}
			}
			*ventaTotal=acumumladorVenta;
		}
		retorno=0;
	}
	return retorno;
}
int funcionInformes(eArticulo* listaArticulos,int cantidadArticulos,eRubro* listaRubros,int cantidadRubro,
					eVenta* listaVentas,int cantidadVentas)
{
	int retorno=-1,i=0,menu,datoIdRubro,confirmarSalidaAlta,dia,mes,anio,validarId,idArticulo,posicionArticulo;
	float ventaTotal=0;
	if(listaArticulos!=NULL && listaRubros!=NULL){
		ordenarPorId(listaArticulos,cantidadArticulos);
		do{
			menu=menuInformes();
			switch(menu){
				case '1':
					do{
						mostrarRubros(cantidadRubro,listaRubros);
						utn_getEntero(&datoIdRubro,"\nINGRESE EL ID DEL RUBRO DEL ARTICULO\n","--ERROR--",1001,1004);
						mostrarArticulosPorRubro(listaArticulos,cantidadArticulos,listaRubros,&datoIdRubro);
						confirmarSalidaAlta=continuarCarga("\n¿DESEA LISTAR OTRO RUBRO?");
					}while(confirmarSalidaAlta!='N');
					break;
				case '2':
					if((*(listaVentas)).idVenta>=20000){
						do{
							mostrarVentas(listaVentas,cantidadVentas,listaArticulos,cantidadArticulos);
							listarFacturaPorFecha(listaVentas,cantidadVentas,(&(*(listaVentas+i)).articuloId),listaArticulos,cantidadArticulos,&dia,&mes,&anio);
							confirmarSalidaAlta=continuarCarga("\n¿DESEA LISTAR OTRAS FACTURAS?");
						}while(confirmarSalidaAlta!='N');
					}else{
						printf("\nNO SE REALIZARON VENTAS\n");
					}
					break;
				case '3':
					if((*(listaVentas)).idVenta>=20000){
						do{
							do{
								mostrarArticulos(listaArticulos,cantidadArticulos,listaRubros);
								utn_getEntero(&idArticulo,"\nINGRESE EL ID DEL ARTICULO\n","--ERROR--",100,200);
								validarId=validarIdExistente(listaArticulos,cantidadArticulos,&idArticulo,&posicionArticulo,"\nEL NUMERO DE ID NO CORRESPONDE A UN ARTICULO CARGADO\n");
							}while(validarId!=0);
							aumuladorDeVentasPorArticulo(listaVentas,cantidadVentas,&idArticulo,&ventaTotal);
							if(*&ventaTotal>0){
								printf("\nEl ARTICULO %s SE VENDIO EN UN TOTAL DE %.2f \n",(*(listaArticulos+posicionArticulo)).descripcion,*&ventaTotal);
							}else{
								printf("\nNO SE HA VENDIDO NINGUNA UNIDAD DE ESTE ARTICULO\n");
							}
							confirmarSalidaAlta=continuarCarga("\n¿DESEA INGRESAR OTRO ARTICULO?");
						}while(confirmarSalidaAlta!='N');
					}else{
						printf("\nNO SE REALIZARON VENTAS\n");
					}
					break;
				case '4':
					if((*(listaVentas)).idVenta>=20000){
						do{
							mostrarRubros(cantidadRubro,listaRubros);
							aumuladorDeVentasPorRubroYFecha(listaVentas,cantidadVentas,&ventaTotal,listaArticulos,cantidadArticulos);
							if(*&ventaTotal>0){
								printf("\nLA VENTA TOTAL EN EL RUBRO SELECCIONADO ES DE %.2f\n",*&ventaTotal);
							}else{
								printf("\nNO SE HAN VENDIDO ARTICULOS DE EL RUBRO SELECCIONADO EN ESTA FECHA\n");
							}
							confirmarSalidaAlta=continuarCarga("\n¿DESEA INGRESAR OTRO RUBRO?");
						}while(confirmarSalidaAlta!='N');
					}else{
						printf("\nNO SE REALIZARON VENTAS\n");
					}
					break;
			}
			confirmarSalidaAlta=continuarCarga("\n¿SALIR DEL MENU INFORMES?");
		}while(confirmarSalidaAlta!='S');
		retorno=0;
	}
	return retorno;
}
