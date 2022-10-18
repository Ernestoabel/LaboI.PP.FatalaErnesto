#ifndef ARTICULOS_H_INCLUDE
#define ARTICULOS_H_INCLUDE
typedef struct{
	int idRubro;
	char descripcion[30];
}eRubro;
typedef struct{
	int idArticulo;
	char descripcion[30];
	char medida[10];
	float precio;
	int rubroId;
}eArticulo;
/**
 * @brief -Funcion que recorre el array de un campo para inicializar todos los elementos
 *
 * @param listaArticulos -Estructura eArticulo a ser inicializada
 * @param cantidad -Numero de elementos arrays de la estructura eArticulos
 * @param estado -Variable que define el valor de los elementos del array
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int inicializarArticulos(eArticulo* listaArticulos,int cantidad,int estado);
/**
 * @brief -Funcion que recorre un campo para validar que haya al menos un articulo cargado en el array
 *
 * @param listaArticulos -Estructura eArticulo a ser analizada por la funcion
 * @param cantidad -Numero de elementos arrays de la estructura eArticulos
 * @param estado -Variable que se encarga de negar el estado de los elementos del array
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int validarQueHayaArticulos(eArticulo* listaArticulos,int cantidad,int estado);
/**
 * @brief -Funcion que recorre un campo en busqueda de un estado para ocupar su posicion en el array
 *
 * @param espacioLibre -Estructura eArticulo a ser analizada por la funcion
 * @param cantidad -Numero de elementos arrays de la estructura eArticulos
 * @param estado -Variable que compara su valor con los elementos del array
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int buscarEspacioLibreIdArticulos(eArticulo* espacioLibre,int cantidad, int estado);
/**
 * @brief -Funcion que se encarga de pedirle al usuario los valores para los campos de la estructura
 *
 * @param id -Entero autoincremental del principal campo de la estructura
 * @param candidadRubro -Numero de elementos arrays de la estructura eRubro
 * @param listaRubros -Llamada a la estructura eRubro para ser impresa por consola
 * @return -Retorna una estructura con datos cargados por el usuario
 */
eArticulo cargaArticulo(int* id,int candidadRubro,eRubro* listaRubros);
/**
 * @brief -Funcion que se encarga de condicionar, el ingreso del valor de rubroId, a la posicion de la descripcion
 * en el la estructura eRubro, para que queden relacionada con la estructura eArticulo, esta funcion se utiliza
 * principalmente para la impresion del listado.
 *
 * @param unArticulo -LLamada a la estructura eArticulos para ser conndicionada
 * @param posicion -Posicion del indice que se guarda en un puntero
 * @param indice -Entero que se utiliza en la llamada de la funcion para indicar la posicion en el array rubroId
 * de la estructura eArticulo
 * @return -Una estructura eArticulo con sus campos llenos de datos ingresados por el usuario
 */
int posicionSector(eArticulo* unArticulo,int* posicion,int indice);
/**
 * @brief -Funcion que se encarga de imprimir los datos que se han cargado en las estructuras relacionadas
 *
 * @param listaArticulos -LLamada a la estructura eArticulos para ser mostrada
 * @param cantidad -Numero de elementos arrays de la estructura eArticulos
 * @param listaRubros -LLamada a la estructura eRubros
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int mostrarArticulos(eArticulo* listaArticulos,int cantidad,eRubro* listaRubros);
/**
 * @brief -Funcion para pedir un id cargado en el array del campo idArticulo,que carga la posicion de ese id en el array
 *
 * @param listaArticulos -LLamada a la estructura eArticulos para ser analizada
 * @param cantidad -Numero de elementos arrays de la estructura eArticulos
 * @param id -Puntero donde sera guardado el indice del array correspondiente al numero de id ingrezado
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int ingresarIdParaModificar(eArticulo* listaArticulos,int cantidad,int* id);
/**
 * @brief -Funcion que cambia el valor del campo idArticulo seleccionado para darlo de baja del sistema
 *
 * @param bajaArticulo -LLamada a la estructura eArticulos para ser analizada
 * @param id -Puntero que recive el indice del idArticulo en el array
 * @param estado -Valor utilizado para dar de baja el articulo del sistema
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int BajaDeArticulo(eArticulo* bajaArticulo,int* id,int estado);
/**
 * @brief -Funcion que se encarga de cambiar el valor de uno de dos campos de la estructura
 *
 * @param modificarArticulo -LLamada a la estructura eArticulos para ser analizada
 * @param id -Puntero que recive el indice de los campos a cambiar en el array
 * @param eleccion -Enero que se encarga de seleccion uno de los dos campos a modificar
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int modificarArticulo(eArticulo* modificarArticulo,int* id,int eleccion);
/**
 * @brief -Funcion que imprime todos los datos guardados en la estructura eRubro
 *
 * @param cantidad -Numero de elementos de la estructura eArticulos
 * @param listaRubros -Llamada a la estructura eRubro
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int mostrarRubros(int cantidad,eRubro* listaRubros);
/**
 *
 * @brief -Funcion que indica la condicion de ordenamiento para el campo rubroId de la estructura eRubro
 *
 * @param primerRubro -Llamada utilizada para la primera posicion del array en el campo rubroId
 * @param segundoRubro -Llamada utilizada para la segunda posicion del array en el campo rubroId
 * @return -Un entero que se encarga de validar la condicion del ordenamiento
 */
int ordenarRubro(eArticulo* primerRubro, eArticulo* segundoRubro);
/**
 * @brief -Funcion que indica la condicion de ordenamiento para el campo descripcion de la estructura eArticulo
 *
 * @param primerMarca -Llamada utilizada para la primera posicion del array en el campo descripcion
 * @param segundaMarca -Llamada utilizada para la segunda posicion del array en el campo descripcion
 * @return -Un entero que se encarga de validar la condicion del ordenamiento
 */
int ordenarDescripcion(eArticulo* primerMarca, eArticulo* segundaMarca);
/**
 * @brief -Funcion que se encarga del burbujeo bajo las candiciones recibidas por punteros a funcion
 *
 * @param listaArticulos -LLamada a la estructura eArticulos para ser ordenada
 * @param cantidad -Numero de elementos arrays de la estructura eArticulos
 * @param primerCriterio -Puntero a funcion encargado de la condicion del primero ordenamiento
 * @param segundoCriterio -Puntero a funcion encargado de la condicion del segundo ordenamiento
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int ordenador(eArticulo* listaArticulos,int cantidad, int(*primerCriterio)(eArticulo*, eArticulo*),int(*segundoCriterio)(eArticulo*, eArticulo*));
/**
 * @brief -Funcion que se encarga de la asignacion de los puntero a funcion en la funcion ordenador y luego imprime el listado
 *
 * @param listaArticulos -LLamada a la estructura eArticulos para ser ordenada
 * @param cantidadArticulos -Numero de elementos arrays de la estructura eArticulos
 * @param listaRubros -LLamada a la estructura eRubros para imprimir su campo descripcion
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int listarOrdenadoPorRubroYDescripcion(eArticulo* listaArticulos,int cantidadArticulos,eRubro* listaRubros);
/**
 * @brief -Funcion que indica la condicion de ordenamiento para el campo idArticulo de la estructura eArticulo
 *
 * @param listaArticulos -LLamada a la estructura eArticulos para ser analizada
 * @param cantidadArticulos -Numero de elementos arrays de la estructura eArticulos
 * @return -Un entero que se encarga de validar la condicion del ordenamiento
 */
int ordenarPorId(eArticulo* listaArticulos,int cantidadArticulos);
/**
 * @brief -Funcion que se encarga de la llamada a funciones, para buscar el indice libre donde se carga una estructura,
 * con datos pedidos por el usuario, en un array de la estructura, para luego ser ordenada de menor a mayor por el numero
 * de id, y luego se imprime en pantalla. Al final, el pedido de un char para confimar la salida del bucle de carga.
 *
 * @param listaArticulos -LLamada a la estructura eArticulos para ser cargada
 * @param cantidadArticulos -Numero de elementos arrays de la estructura eArticulos
 * @param rubros -LLamada a la estructura eRubros para imprimir su campo descripcion
 * @param cantidadRubro -Numero de elementos arrays de la estructura eRubro
 * @param idArticulo -Parametro que recive por direccion de memoria el valor idArticulo
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int funcionAltaArticulo(eArticulo* listaArticulos,int cantidadArticulos,eRubro* rubros,int cantidadRubro,int* idArticulo);
/**
 * @brief -Funcion que se encarga de la llamada a funciones, para ser ordenada de menor a mayor por el numero
 * de id, y luego se imprime en pantalla como indice, para que el usuario ingrese el id, que luego eligira entre
 * modificar un campo o el otro, para despues remplazar el valor del campo seleccionado. Al final, el pedido
 * de un char para confimar la salida del bucle de carga.
 *
 * @param listaArticulos -LLamada a la estructura eArticulos para ser modificada
 * @param cantidadArticulos -Numero de elementos arrays de la estructura eArticulos
 * @param rubros -LLamada a la estructura eRubros para imprimir su campo descripcion
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int funcionModificarArticulo(eArticulo* listaArticulos,int cantidadArticulos,eRubro* rubros);
/**
 * @brief -Funcion que se encarga de la llamada a funciones, para ser ordenada de menor a mayor por el numero
 * de id, y luego se imprime en pantalla como indice, para que el usuario ingrese el id, que luego eligira entre
 * confirmar la baja del articulo o no, y cambiar su id a 0 si se confirma la baja.  Al final, el pedido
 * de un char para confimar la salida del bucle de carga.
 *
 *
 * @param listaArticulos -LLamada a la estructura eArticulos para ser dada de baja
 * @param cantidadArticulos -Numero de elementos arrays de la estructura eArticulos
 * @param rubros -LLamada a la estructura eRubros para imprimir su campo descripcion
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int funcionBajaArticulo(eArticulo* listaArticulos,int cantidadArticulos,eRubro* rubros);
/**
 * @brief -Funcion que se encarga de la llamada de una funcion que se encarga de ordenar y listar las estructuras
 * eArticulo y eRubro.
 *
 * @param listaArticulos -LLamada a la estructura eArticulos para ser ordenada y listada
 * @param cantidadArchivos -Numero de elementos arrays de la estructura eArticulos
 * @param rubros -LLamada a la estructura eRubros para imprimir su campo descripcion
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int funcionListarArticulos(eArticulo* listaArticulos,int cantidadArchivos,eRubro* rubros);
#endif
