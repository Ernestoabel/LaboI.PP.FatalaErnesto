#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "articulos.h"
#include "biblioteca_UTN.h"
#include "menu.h"
int inicializarArticulos(eArticulo* listaArticulos,int cantidad,int estado)
{
	int retorno=-1,i;
	if(listaArticulos != NULL && cantidad > 0 ){
		for(i = 0; i<cantidad; i++){
			(*(listaArticulos+i)).idArticulo = estado;
		}
		retorno = 0;
	}

	return retorno;
}
int validarQueHayaArticulos(eArticulo* listaArticulos,int cantidad,int estado)
{
	int retorno=-1,i;
	if(listaArticulos != NULL && cantidad > 0 ){
		for(i = 0; i<cantidad; i++){
			if((*(listaArticulos+i)).idArticulo!=estado){
				retorno = 0;
			}
		}
	}

		return retorno;
}
int buscarEspacioLibreIdArticulos(eArticulo* espacioLibre,int cantidad, int estado)
{
    int retorno=-1;
    int i;
    if(espacioLibre!=NULL){
    	for(i=0;i<cantidad;i++){
    		if((*(espacioLibre+i)).idArticulo==estado){
    			retorno = i;
    			break;
    		}
        }
    }
    return retorno;
}
eArticulo cargaArticulo(int* id)
{
	eArticulo cargaArticulo;
	int validarEsSoloLetra;
	if(id != NULL){
		do{
		utn_getCadenaCaracteres(30,cargaArticulo.descripcion,"\nINGRESE LA DESCRIPCION DEL ARTICULO\n","--ERROR--");
		validarEsSoloLetra=utn_cadenaSoloLetra(cargaArticulo.descripcion);
		}while(validarEsSoloLetra!=1);
		utn_getCadenaCaracteres(10,cargaArticulo.medida,"\nINGRESE LAS MEDIDAS DEL ARTICULO\n","--ERROR--");
		utn_getFlotante(&cargaArticulo.precio,"\nINGRESE EL PRECIO DEL ARTICULO\n","--ERROR--",1,500000);
		utn_getEntero(&cargaArticulo.rubroId,"\nINGRESE EL ID DEL RUBRO DEL ARTICULO\n","--ERROR--",1001,1004);
		cargaArticulo.idArticulo = *id;
		(*id)++;
	}
	return cargaArticulo;
}
int posicionSector(eArticulo* unArticulo,int* posicion,int indice)
{
	int retorno=-1;
	if((*(unArticulo+indice)).rubroId==1001){
		*posicion=0;
		retorno=0;
	}
	if((*(unArticulo+indice)).rubroId==1002){
		*posicion=1;
		retorno=0;
	}
	if((*(unArticulo+indice)).rubroId==1003){
		*posicion=2;
		retorno=0;
	}
	if((*(unArticulo+indice)).rubroId==1004){
		*posicion=3;
		retorno=0;
	}
	return retorno;
}
int mostrarArticulos(eArticulo* listaArticulos,int cantidad,eRubro* listaRubros)
{
    int retorno=-1,i,indice;
    if(listaArticulos!=NULL){
    	printf("\n+---+------------+------------+----------+------------+\n");
    	printf("|%3s|%12s|%12s|%10s|%12s|\n"," ID"," DESCRIPCION"," MEDIDA"," PRECIO"," RUBRO");
    	printf("+---+------------+------------+----------+------------+\n");
    	for(i=0;i<cantidad;i++){
            if((*(listaArticulos+i)).idArticulo>=100){
            	posicionSector(listaArticulos,&indice,i);
                printf("|%3d|%12s|%12s|%10.2f|%12s|\n",(*(listaArticulos+i)).idArticulo,(*(listaArticulos+i)).descripcion,
                		(*(listaArticulos+i)).medida,(*(listaArticulos+i)).precio,(*(listaRubros+indice)).descripcion);
            }
        }
    	printf("+---+------------+------------+----------+------------+\n");
        retorno=0;
    }
    return retorno;
}
int ingresarIdParaModificar(eArticulo* listaArticulos,int cantidad,int* id)
{
    int i,retorno=-1,entro=0;
    if(listaArticulos!=NULL){
        do{
        	utn_getEntero(id,"\nINGRESE ID\n","\n--ERROR--\n",100,200);
            for(i=0;i<cantidad;i++){
                if((*(listaArticulos+i)).idArticulo>=99){
                    if((*(listaArticulos+i)).idArticulo==(*id)){
                    	(*id)=i;
                        entro=1;
                        break;
                    }
                }
            }
            if(entro==0){
            	printf("\nEL NUMERO DE ID NO CORRESPONDE A UN ARTICULO CARGADO\n");
            }
        }while(entro!=1);
        retorno=0;
    }
    return retorno;
}
int BajaDeArticulo(eArticulo* bajaArticulo,int* id,int estado)
{
    int retorno = -1,baja;
	if(bajaArticulo != NULL){
		baja=continuarCarga("\nCONFIRME BAJA DEL ARTICULO\n");
		if(baja=='S'){
			(*(bajaArticulo+(*id))).idArticulo=0;
		}else if(baja=='N'){
			printf("\nBAJA CANCELADA\n");
		}
		retorno = 0;
	}
	return retorno;
}
int modificarArticulo(eArticulo* modificarArticulo,int* id,int eleccion)
{
	int retorno=-1;
	if(id>=0){
		if(eleccion==1){
			utn_getCadenaCaracteres(10,(modificarArticulo+(*id))->medida,"\nINGRESE LAS MEDIDAS DEL ARTICULO\n","--ERROR--");
		}
		if(eleccion==2){
			utn_getFlotante(&(modificarArticulo+(*id))->precio,"\nINGRESE EL PRECIO DEL ARTICULO\n","--ERROR--",1,500000);
		}
		retorno=0;
	}
	return retorno;
}
int mostrarRubros(int cantidad,eRubro* listaRubros)
{
    int retorno=-1,i;
    if(listaRubros!=NULL){
    	printf("\n+---------+------------+\n");
    	printf("|%3s|%12s|\n"," ID RUBRO"," DESCRIPCION");
    	printf("+---------+------------+\n");
    	for(i=0;i<cantidad;i++){
    		printf("|%9d|%12s|\n",(*(listaRubros+i)).idRubro,(*(listaRubros+i)).descripcion);

        }
    	printf("+---------+------------+\n");
        retorno=0;
    }
    return retorno;
}
int ordenarRubro(eArticulo* primerRubro, eArticulo* segundoRubro)
{
	int retorno=-1;
	if(primerRubro!=NULL&&segundoRubro!=NULL){
		if((*(primerRubro)).rubroId>(*(segundoRubro+1)).rubroId){
			retorno=0;
		}else if((*(primerRubro)).rubroId==(*(segundoRubro+1)).rubroId){
			retorno=1;
		}
	}
	return retorno;
}
int ordenarDescripcion(eArticulo* primerMarca, eArticulo* segundaMarca)
{
	int retorno=-1;
	if(primerMarca!=NULL&&segundaMarca!=NULL){
		if(strcmp((*(primerMarca)).descripcion,(*(segundaMarca+1)).descripcion)>0){
			retorno=0;
		}
	}
	return retorno;
}
int ordenarId(eArticulo* primerId, eArticulo* segundoId)
{
	int retorno=-1;
	if(primerId!=NULL&&segundoId!=NULL){
		if((*(primerId)).idArticulo>(*(primerId+1)).idArticulo){
			retorno=0;
		}
	}
	return retorno;
}
int ordenador(eArticulo* listaArticulos,int cantidad, int(*primerCriterio)(eArticulo*, eArticulo*),int(*segundoCriterio)(eArticulo*, eArticulo*))
{
	int retorno=-1,bandera;
	eArticulo auxiliar;
	if(listaArticulos!=NULL){
		do{
			bandera=1;
			for(int i=0;i<cantidad-1;i++){
				for(int j=i+1;j<cantidad;j++){
					if((listaArticulos+i)->idArticulo>=100){
						if(primerCriterio((listaArticulos+i),(listaArticulos+i))==0){
							bandera=0;
							auxiliar=(*(listaArticulos+i));
							(*(listaArticulos+i))=(*(listaArticulos+j));
							(*(listaArticulos+j))=auxiliar;
						}else if(primerCriterio((listaArticulos+i),(listaArticulos+i))==1){
							if(segundoCriterio((listaArticulos+i),(listaArticulos+i))==0){
								bandera=0;
								auxiliar=(*(listaArticulos+i));
								(*(listaArticulos+i))=(*(listaArticulos+j));
								(*(listaArticulos+j))=auxiliar;
							}
						}
					}
				}
				retorno=0;
			}
		}while(bandera!=1);
	}
	return retorno;
}
int listarOrdenadoPorRubroYDescripcion(eArticulo* listaArticulos,int cantidadArticulos,eRubro* listaRubros)
{
	int retorno=-1,(*primerCriterio)(eArticulo*, eArticulo*),(*segundoCriterio)(eArticulo*, eArticulo*);
	if(listaArticulos!=NULL && listaRubros!=NULL){
		primerCriterio=ordenarRubro;
		segundoCriterio=ordenarDescripcion;
		ordenador(listaArticulos,cantidadArticulos,primerCriterio,segundoCriterio);
		mostrarArticulos(listaArticulos,cantidadArticulos,listaRubros);
		retorno=0;
	}
	return retorno;
}
int ordenarPorId(eArticulo* listaArticulos,int cantidadArticulos)
{
	int retorno=-1,(*primerCriterio)(eArticulo*, eArticulo*),(*segundoCriterio)(eArticulo*, eArticulo*);
		if(listaArticulos!=NULL){
			primerCriterio=ordenarId;
			segundoCriterio=ordenarId;
			ordenador(listaArticulos,cantidadArticulos,primerCriterio,segundoCriterio);
			retorno=0;
		}
	return retorno;
}
int funcionAltaArticulo(eArticulo* listaArticulos,int cantidadArticulos,eRubro* rubros)
{
	int retorno=-1,idArticulo=101,idLibreArticulos,confirmarSalidaAlta;
	if(listaArticulos!=NULL && rubros!=NULL){
		do{
			idLibreArticulos=buscarEspacioLibreIdArticulos(listaArticulos,cantidadArticulos,0);
			*(listaArticulos+idLibreArticulos)=cargaArticulo(&idArticulo);
			ordenarPorId(listaArticulos,cantidadArticulos);
			mostrarArticulos(listaArticulos,cantidadArticulos,rubros);
			confirmarSalidaAlta=continuarCarga("\n¿CARGAR EL SIGUIENTE ARTICULO?");
		}while(confirmarSalidaAlta!='N');
		retorno=0;
	}
	return retorno;
}
int funcionModificarArticulo(eArticulo* listaArticulos,int cantidadArticulos,eRubro* rubros)
{
	int eleccionParaModificarArticulo,confirmarSalidaAlta,id,retorno=-1;
	if(listaArticulos!=NULL && rubros!=NULL){
		do{
			ordenarPorId(listaArticulos,cantidadArticulos);
			mostrarArticulos(listaArticulos,cantidadArticulos,rubros);
			ingresarIdParaModificar(listaArticulos,cantidadArticulos,&id);
			utn_getEntero(&eleccionParaModificarArticulo,"\n+------------------------+\n"
					"|1.PARA MODIFICAR MEDIDAS|\n|2.PARA MODIFICAR PRECIO |"
					"\n+------------------------+\nINGRESE OPCION: ","\n--ERROR--",1,2);
			modificarArticulo(listaArticulos,&id,eleccionParaModificarArticulo);
			confirmarSalidaAlta=continuarCarga("\n¿MODIFICAR OTRO ARTICULO?");
		}while(confirmarSalidaAlta!='N');

		retorno=0;
	}
	return retorno;
}
int funcionBajaArticulo(eArticulo* listaArticulos,int cantidadArticulos,eRubro* rubros)
{
	int retorno=-1,confirmarSalidaAlta,id;
	if(listaArticulos!=NULL && rubros!=NULL){
		do{
			if(validarQueHayaArticulos(listaArticulos,cantidadArticulos,0)==0){
				ordenarPorId(listaArticulos,cantidadArticulos);
				mostrarArticulos(listaArticulos,cantidadArticulos,rubros);
				ingresarIdParaModificar(listaArticulos,cantidadArticulos,&id);
				BajaDeArticulo(listaArticulos,&id,0);
			}else{
				printf("\nNO HAY ARTICULO CARGADOS\n");
			}
			confirmarSalidaAlta=continuarCarga("\n¿DAR DE BAJA OTRO ARTICULO?");
		}while(confirmarSalidaAlta!='N');
		retorno=0;
	}
	return retorno;
}
int funcionListarArticulos(eArticulo* listaArticulos,int cantidadArticulos,eRubro* rubros)
{
	int retorno=-1;
	if(listaArticulos!=NULL){
		listarOrdenadoPorRubroYDescripcion(listaArticulos,cantidadArticulos,rubros);
		utn_pausaPrograma();
		retorno=0;
	}
	return retorno;
}
