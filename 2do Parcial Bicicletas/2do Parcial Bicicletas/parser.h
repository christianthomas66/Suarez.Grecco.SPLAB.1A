#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#endif // PARSER_H_INCLUDED


/** \brief Analiza y parsea los datos de las bicicletas desde el archivo jugador.csv (modo texto).
 *
 * \param  miFile* FILE
 * \param  pMiLista* LinkedList
 * \return retorno 0 si hubo error, 1 si no hubo error
 *
 */
int parser_BiciFromText(FILE* miFile, LinkedList* pMiLista);


/** \brief Carga los datos de las bicicletas desde el archivo bicicletas.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int retorno 1 si hubo error, 0 si no hubo error
 *
 */
int cargarTexto(char* path , LinkedList* pLista);

/** \brief Guarda los datos de las bicicletas en el archivo bicicletas.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int retorno 0 si hubo error, 1 si no hubo error
 *
 */
int guardarComoTexto(char* path, LinkedList* pLista);
