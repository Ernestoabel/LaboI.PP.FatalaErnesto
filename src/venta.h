#ifndef VENTA_H_INCLUDE
#define VENTA_H_INCLUDE
#include "articulos.h"
typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;
typedef struct{
	int idVenta;
	int articuloId;
	int cantidad;
	int articuloRubro;
	float precioTotal;
	eFecha fecha;
}eVenta;
/**
 * @brief -Funcion que recorre el array de un campo para inicializar todos los elementos
 *
 * @param listaVentas -Estructura eVenta a ser inicializada
 * @param cantidad -Numero de elementos arrays de la estructura eVenta
 * @param estado -Variable que define el valor de los elementos del array
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int inicializarVentas(eVenta* listaVentas,int cantidad,int estado);
/**
 * @brief -Funcion que recorre un campo en busqueda de un estado para ocupar su posicion en el array
 *
 * @param espacioLibre -Estructura eVenta a ser analizada por la funcion
 * @param cantidad -Numero de elementos arrays de la estructura eVenta
 * @param estado -Variable que compara su valor con los elementos del array
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int buscarEspacioLibreIdVentas(eVenta* espacioLibre,int cantidad, int estado);
/**
 * @brief -Funcion que recorre un array en busca de validar un id, que recibe por parametro, con un
 * idArticulo existente en otra extructura, y que ademas guarda su posicion en un puntero entero
 *
 * @param listaArticulos -Estructura eArticulo a ser analizada por la funcion
 * @param cantidadArticulos -Numero de elementos arrays de la estructura eVenta
 * @param articuloId -Puntero entero que recive la direccion de memoria de un valor
 * @param posicionArticulo -Puntero que guarda la direccion de memoria de la posicion del indice del id
 * @param mensajeError -Mensaje impreso para advertir al usurio de un error en la validacion
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int validarIdExistente(eArticulo* listaArticulos,int cantidadArticulos,int* articuloId,int* posicionArticulo,char* mensajeError);
/**
 * @brief -Funcion que recive la direccion de memoria del valor cantidad de ventas, de la estructura eVentas, para luego
 * multiplicarla, por el valor de la direccion de memoria del campo precio, en la posicion del indice recivida por puntero.
 * Guarda ese valor un puntero flotante, para luego ser posicionado como parametro en la funcion.
 *
 * @param cantidadDeVentas -Direccion de memoria del campo cantidad de eVentas
 * @param precio -Llamada al array de la estructura eArticulo
 * @param cantidadArticulos -Numero de elementos arrays de la estructura eArticulo
 * @param precioTotal -Puntero flotante donde se almacena el valor de la multiplicacion
 * @param posicionArticulo -Direccion de memoria de la posicion donde se encuentra el idArticulo y su precio
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int calcularPrecioTotal(int* cantidadDeVentas,eArticulo* precio,int cantidadArticulos,float* precioTotal,int* posicionArticulo);
/**
 * @brief Funcion que pide: El ingreso del campo articuloId y lo valida si existe cargado en la estructura eArticulo
 * El ingreso de un entero para el campo cantidad
 * El calculo del precio total por la multiplicacion de la cantidad de eVenta por el precio eArticulo
 * El ingreso del dia,mes y año, validado para que sea real segun el calendario gregoriano!!!.
 * El incremento del numero idFactura segun se van cargando en el array de la estructura eVenta
 *
 * @param id -La direccion de memoria del entero id que se incremeta en uno
 * @param listaArticulos -Llamada a la funcion eArticulo para las validaciones
 * @param cantidadArticulos -Numero de elementos arrays de la estructura eArticulo
 * @param posicionArticulo -Direccion de memoria de la posicion en el arrays de eArticulo para la validacion de carga de datos
 * @param listaRubros -Llamada a estructura eRubro para ser impresa por consola
 * @return -Una estructura eVenta con sus campos llenos de datos ingresados por el usuario
 */
eVenta realizarFactura(int* id,eArticulo* listaArticulos,int cantidadArticulos,int* posicionArticulo,eRubro* listaRubros);
/**
 * @brief -Funcion que imprime por consola los datos de cada array de campos en la estructura eVentas, junto
 * a la validacion del articuloId conectar con el campo descripcion de la estructura eArticulo
 *
 * @param listaVentas -Llamada a la funcion eVenta para la carga de sus campos
 * @param cantidadVentas -Numero de elementos arrays de la estructura eVenta
 * @param listaArticulos -Llamada a la funcion eArticulo para la impresion de su campo descripcion
 * @param cantidadArticulos -Numero de elementos arrays de la estructura eArticulo
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int mostrarVentas(eVenta* listaVentas,int cantidadVentas,eArticulo* listaArticulos,int cantidadArticulos);
/**
 * @brief -Funcion que llama a:Buscar el siguiente espacio libre en el campo idVenta
 * Llama a la funcion que carga un array de todos los campos de la estructura eVenta en un espacio del idVenta
 * Muestra el listado segun se vallan cargando las facturas
 * Una funcion para confirmar la salida del bucle de carga de facturas
 *
 * @param listaVentas -Llamada a la funcion eVenta para su carga en array
 * @param cantidadVentas -Numero de elementos arrays de la estructura eVenta
 * @param listaArticulos -Llamada a la funcion eArticulo para la impresion de su campo descripcion
 * @param cantidadArticulos -Numero de elementos arrays de la estructura eArticulo
 * @param listaRubros -Llamada a estructura eRubro para ser impresa por consola
 * @param idArticulo -Parametro que recive por direccion de memoria el valor idVenta
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int funcionCargarVentas(eVenta* listaVentas,int cantidadVentas,eArticulo* listaArticulos,int cantidadArticulos,eRubro* listaRubros,int* idVenta);
/**
 * @brief -Funcion que se encarga de llamar a la funcion listar las ventas realizadas
 *
 * @param listaVentas -Llamada a la funcion eVenta para la impresion
 * @param cantidadVentas -Numero de elementos arrays de la estructura eVenta
 * @param listaArticulos -Llamada a la funcion eArticulo para la impresion de su campo descripcion
 * @param cantidadArticulos -Numero de elementos arrays de la estructura eArticulo
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int funcionListarVentas(eVenta* listaVentas,int cantidadVentas,eArticulo* listaArticulos,int cantidadArticulos);
#endif
