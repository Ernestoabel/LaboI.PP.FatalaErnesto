/**
 * @brief -Funcion que permite la impresion de opciones de un menu, con un retorno char que valida la opcion de un switch
 *
 * @param mensajeUno -Primer mensaje impreso
 * @param mensajeDos -Segundo mensaje impreso
 * @param mensajeTres -Tercer mensaje impreso
 * @param mensajeCuatro -Cuarto mensaje impreso
 * @param mensajeCinco -Quinto mensaje impreso
 * @param mensajeSeis -Sexto mensaje impreso
 * @param mensajeSiete -Septimo mensaje impreso
 * @param mensajeOcho -Octavo mensaje impreso
 * @param mensajeNueve -Noveno mensaje impreso
 * @param mensajeDiez -Decimo mensaje impreso
 * @param mensajeOnce -Onceavo mensaje impreso
 * @param mensajeDose -Doseavo mensaje impreso
 * @param mensajeTrece -Treceavo mensaje impreso
 * @return -Char validado para la utilizacion en el switch
 */
char menu(char* mensajeUno,char* mensajeDos,char* mensajeTres,char* mensajeCuatro,char* mensajeCinco,
		  char* mensajeSeis,char* mensajeSiete,char* mensajeOcho,char* mensajeNueve,char* mensajeDiez,
		  char* mensajeOnce,char* mensajeDose,char* mensajeTrece);
/**
 * @brief -Funcion que se encarga de preguntar y validar la interrupcion de un bucle
 *
 * @param mensaje -Mensaje impreso con las especificacion para continuar o no con el bucle
 * @return -Char para validar la interrupcion del bucle donde se llamo a la funcion
 */
char continuarCarga(char* mensaje);
