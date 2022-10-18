#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "venta.h"
#include "biblioteca_UTN.h"
#include "menu.h"
int inicializarVentas(eVenta* listaVentas,int cantidad,int estado)
{
	int retorno=-1,i;
	if(listaVentas != NULL && cantidad > 0 ){
		for(i = 0; i<cantidad; i++){
			(*(listaVentas+i)).idVenta = estado;
		}
		retorno = 0;
	}

	return retorno;
}
int buscarEspacioLibreIdVentas(eVenta* espacioLibre,int cantidad, int estado)
{
    int retorno=-1;
    int i;
    if(espacioLibre!=NULL){
    	for(i=0;i<cantidad;i++){
    		if((*(espacioLibre+i)).idVenta==estado){
    			retorno = i;
    			break;
    		}
        }
    }
    return retorno;
}
int validarIdExistente(eArticulo* listaArticulos,int cantidadArticulos,int* articuloId,int* posicionArticulo,char* mensajeError)
{
	int i,retorno=-1,entro=0;
	if(listaArticulos!=NULL){
		for(i=0;i<cantidadArticulos;i++){
			if((*(listaArticulos+i)).idArticulo>=100){
				if((*(listaArticulos+i)).idArticulo==*articuloId){
					entro=1;
					*posicionArticulo=i;
					retorno=0;
					break;
				}
			}
		}
		if(entro==0){
			printf("%s",mensajeError);
		}
	}
	return retorno;
}
int calcularPrecioTotal(int* cantidadDeVentas,eArticulo* precio,int cantidadArticulos,float* precioTotal,int* posicionArticulo)
{
	int retorno=-1,i;
	if(precio!=NULL){
		for(i=0;i<cantidadArticulos;i++){
			*precioTotal=(float)((*(precio+*posicionArticulo)).precio)*(*cantidadDeVentas);
			break;
		}
		retorno=0;
	}
	return retorno;
}
eVenta realizarFactura(int* id,eArticulo* listaArticulos,int cantidadArticulos,int* posicionArticulo,eRubro* listaRubros)
{
	eVenta cargaFactura;
	int validarId=-1,i;
	if(id != NULL){
		do{
			mostrarArticulos(listaArticulos,cantidadArticulos,listaRubros);
			utn_getEntero(&cargaFactura.articuloId,"\nINGRESE EL ID DEL ARTICULO A VENDER\n","--ERROR--",100,200);
			validarId=validarIdExistente(listaArticulos,cantidadArticulos,&cargaFactura.articuloId,*&posicionArticulo,"\nEL NUMERO DE ID NO CORRESPONDE A UN ARTICULO CARGADO\n");
		}while(validarId!=0);
		utn_getEntero(&cargaFactura.cantidad,"\nINGRESE LA CANTIDAD DEL ARTICULO A VENDER\n(MAXIMO 100 UNIDADES POR FACTURA)\n","--ERROR--",1,100);
		calcularPrecioTotal(&cargaFactura.cantidad,listaArticulos,cantidadArticulos,&cargaFactura.precioTotal,*&posicionArticulo);
		for(i=0;i<cantidadArticulos;i++){
			cargaFactura.articuloRubro=(*(listaArticulos+*posicionArticulo)).rubroId;
			break;
		}
		do{
			utn_getEntero(&cargaFactura.fecha.dia,"\nINGRESE EL DIA EN QUE SE EMITIO LA FACTURA\n","--ERROR--",1,31);
			utn_getEntero(&cargaFactura.fecha.mes,"\nINGRESE EL MES EN QUE SE EMITIO LA FACTURA\n","--ERROR--",1,12);
			utn_getEntero(&cargaFactura.fecha.anio,"\nINGRESE EL ANIO EN QUE SE EMITIO LA FACTURA\n","--ERROR--",2000,2050);
		}while(utn_validarFechaIngresada(&cargaFactura.fecha.dia,&cargaFactura.fecha.mes,&cargaFactura.fecha.anio)!=0);
		cargaFactura.idVenta = *id;
		(*id)++;
	}
	return cargaFactura;
}
int mostrarVentas(eVenta* listaVentas,int cantidadVentas,eArticulo* listaArticulos,int cantidadArticulos)
{
    int retorno=-1,i,posicionArticulo;
    if(listaVentas!=NULL){
    	printf("+---------+--------------------+---------+----------------+----------+\n");
    	printf("|%9s|%20s|%9s|%16s|%10s|\n"," ID VENTA"," PRODUCTO"," CANTIDAD"," PRECIO FINAL"," FECHA");
    	printf("+---------+--------------------+---------+----------------+----------+\n");
    	for(i=0;i<cantidadVentas;i++){
            if((*(listaVentas+i)).idVenta>=20000){
            	validarIdExistente(listaArticulos,cantidadArticulos,(&(*(listaVentas+i)).articuloId),&posicionArticulo,"");
                printf("|%9d|%20s|%9d|%16.2f|%2d/%2d/%4d|\n",(*(listaVentas+i)).idVenta,(*(listaArticulos+posicionArticulo)).descripcion,
                		(*(listaVentas+i)).cantidad,(*(listaVentas+i)).precioTotal,(*(listaVentas+i)).fecha.dia,
						(*(listaVentas+i)).fecha.mes,(*(listaVentas+i)).fecha.anio);
            }
        }
    	printf("+---------+--------------------+---------+----------------+----------+\n");
        retorno=0;
    }
    return retorno;
}
int funcionCargarVentas(eVenta* listaVentas,int cantidadVentas,eArticulo* listaArticulos,int cantidadArticulos,eRubro* listaRubros,int* idVenta)
{
	int retorno=-1,idLibreVentas,posicionArticulo,confirmarSalidaAlta;
	if(listaVentas!=NULL && listaArticulos!=NULL){
		do{
			idLibreVentas=buscarEspacioLibreIdVentas(listaVentas,cantidadVentas,0);
			(*(listaVentas+idLibreVentas))=realizarFactura(*&idVenta,listaArticulos,cantidadArticulos,&posicionArticulo,listaRubros);
			mostrarVentas(listaVentas,cantidadVentas,listaArticulos,cantidadArticulos);
			confirmarSalidaAlta=continuarCarga("\n¿DESEA REALIZAR OTRA FACTURA?");
		}while(confirmarSalidaAlta!='N');
		retorno=0;
	}
	return retorno;
}
int funcionListarVentas(eVenta* listaVentas,int cantidadVentas,eArticulo* listaArticulos,int cantidadArticulos)
{
	int retorno=-1;
	if(listaVentas!=NULL && listaArticulos!=NULL){
		if((*(listaVentas)).idVenta>=20000){
		mostrarVentas(listaVentas,cantidadVentas,listaArticulos,cantidadArticulos);
		utn_pausaPrograma();
		}else{
			printf("\nNO SE REALIZARON VENTAS\n");
			utn_pausaPrograma();
		}
		retorno=0;
	}
	return retorno;
}
