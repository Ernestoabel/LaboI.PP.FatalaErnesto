/**
 * @brief -Funcion que sirve, mediante condicionales, para validar una fecha que ha sido ingresada anteriormente
 *
 * @param dia -Recive por parametro una direccion de memoria que contiene el valor del dia ingresado
 * @param mes -Recive por parametro una direccion de memoria que contiene el valor del mes ingresado
 * @param anio -Recive por parametro una direccion de memoria que contiene el valor del anio ingresado
 * @param validarFecha -Recive por parametro una direccion de memoria que contiene los valores de campo en la estructura eVenta
 * @param cantidadVentas -Cantidad de elementos en el array de eVentas
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int validarFechaIngresada(int* dia,int* mes,int* anio,eVenta* validarFecha,int cantidadVentas);
/**
 * @brief -Funcion que pide un entero en los campos dia,mes y anio
 *
 * @param fecha -Llamada a la estructura eVenta para validar la funcion
 * @param dia -Devuelve por referencia la direccion de memoria de un valor dia
 * @param mes -Devuelve por referencia la direccion de memoria de un valor mes
 * @param anio -Devuelve por referencia la direccion de memoria de un valor anio
 * @param cantidadVentas -Cantidad de elementos en el array de eVentas
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int ingresoFechaParaInformes(eVenta* fecha,int* diaFactura,int* mesFactura,int* anioFactura,int cantidadVentas);
/**
 * @brief -Funcion que sirve,mediante la validacion con la llamada de otra funcion, listar una por una las facturas emitidas,
 *  el dia eligido por el usuario
 *
 * @param listaVentas -llamada a la estructura eVenta
 * @param cantidadVentas -Cantidad de elementos en el array de eVentas
 * @param articuloId -llamada por puntero al campo articuloId para la impresion de los datos de su array
 * @param listaArticulos -llamada a la estructura eArticulo
 * @param cantidadArticulos -Cantidad de elementos en el array de eVenta
 * @param dia -Recive por parametro una direccion de memoria que contiene el valor del dia ingresado
 * @param mes -Recive por parametro una direccion de memoria que contiene el valor del mes ingresado
 * @param anio -Recive por parametro una direccion de memoria que contiene el valor del anio ingresado
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int listarFacturaPorFecha(eVenta* listaVentas,int cantidadVentas,int* articuloId,eArticulo* listaArticulos,int cantidadArticulos,int* dia,int* mes,int* anio);
/**
 * @brief -Funcion que sirve, mediante condicionales, para mostrar los articulos vendidos por rubro
 *
 * @param -listaArticulos -llamada a la estructura eArticulo
 * @param -cantidad -Cantidad de elementos en el array de eArticulo
 * @param -rubros -llamada a la estructura eRubro
 * @param -idRubro -LLamada a un campo, mediante su dioreccion de memoria, para validar un condicional
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int mostrarArticulosPorRubro(eArticulo* listaArticulos,int cantidad,eRubro* rubros,int* idRubro);
/**
 * @brief -Funcion que sirve,mediante condicionales, acumular las ventas por articulo
 *
 * @param listaVentas -llamada a la estructura eVenta
 * @param cantidadVentas -Cantidad de elementos en el array de eVenta
 * @param idArticulo -llamada por puntero al campo articuloId para la comparacion por el puntero pasado por referencia
 * @param ventaTotal -Calculo de la acumulacion del campo precioTotal para ser duvuelta por valor en el parametro
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int aumuladorDeVentasPorArticulo(eVenta* listaVentas,int cantidadVentas,int* idArticulo,float* ventaTotal);
/**
 * @brief -Funcion que sirve,mediante condicionales, acumular las ventas totales por rubro y fecha
 *
 * @param listaVentas -llamada a la estructura eVenta
 * @param cantidadVentas -Cantidad de elementos en el array de eVenta
 * @param ventaTotal -Calculo de la acumulacion del campo precioTotal para ser duvuelta por valor en el parametro
 * @param rubros -Campo rubroId recivido por direccion de memoria, para ser comparado con los ingresados
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int aumuladorDeVentasPorRubroYFecha(eVenta* listaVentas,int cantidadVentas,float* ventaTotal,eArticulo* listaArticulos,int cantidadArticulos);
/**
 * @brief -Funcion que se encarga de llamar, a otras funciones, para las cuatro opciones de informes
 *
 * @param listaArticulos -llamada a la estructura eArticulo
 * @param cantidadArticulos -Cantidad de elementos en el array de eArticulo
 * @param listaRubros -llamada a la estructura eRubro
 * @param cantidadRubro -Cantidad de elementos en el array de eRubro
 * @param listaVentas -llamada a la estructura eVenta
 * @param cantidadVentas -Cantidad de elementos en el array de eVenta
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int funcionInformes(eArticulo* listaArticulos,int cantidadArticulos,eRubro* listaRubros,int cantidadRubro,eVenta* listaVentas,int cantidadVentas);

