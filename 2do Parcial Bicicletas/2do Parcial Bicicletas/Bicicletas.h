#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id_bici;
    char nombre[128];
    char tipo[128];
    int tiempo;

}eBici;

#endif // PAIS_H_INCLUDED


/** \brief Guarda espacio en memoria para la nueva bicicleta
 *
 * \return Puntero al espacio guardado
 *
 */
eBici* bici_New();

/** \brief Carga los nuevos parametros de las bicicletas
 *
 * \param id_Bici char*
 * \param nombre char*
 * \param tipo char*
 * \param tiempo char*
 * \return retorna nueva bicicleta
 *
 */
eBici* bici_NewParametros(char* id_bici, char* nombre, char* tipo, char* tiempo);

/** \brief Elimina una bicicleta de la lista
 *
 * \param this Employee*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */

void bicis_borrar(eBici* this);



//FUNCIONES SETTER
/** \brief Carga el id
 *
 * \param this eBici*
 * \param id int
 * \return int retorno 0 si hubo error, 1 si no hubo error
 *
 */
int bici_SetId(eBici* this, int id);

/** \brief Carga el nombre
 *
 * \param this eBici*
 * \param nombre char*
 * \return int exito 0 si hubo error, 1 si no hubo error
 *
 */
int bici_SetNombre(eBici* this, char* nombre);

/** \brief Carga el Tipo
 *
 * \param this eBici*
 * \param tipo char*
 * \return int exito 0 si hubo error, 1 si no hubo error
 *
 */
int bici_SetTipo(eBici* this, char* tipo);

/** \brief Carga el tiempo
 *
 * \param this eBici*
 * \param tiempo float
 * \return int exito 0 si hubo error, 1 si no hubo error
 *
 */
int bici_SetTiempo(eBici* this, int tiempo);
//FUNCIONES GETTER

/** \brief Obtiene el id de una bicicleta
 *
 * \param this eBici*
 * \param id int*
 * \return int exito 0 si hubo error, 1 si no hubo error
 *
 */
int bici_GetId(eBici* this, int* id);

/** \brief Obtiene el nombre de una bicicleta
 *
 * \param this eBici*
 * \param id int*
 * \return int exito 0 si hubo error, 1 si no hubo error
 *
 */
int bici_GetNombre(eBici* this, char* nombre);

/** \brief obtiene el tipo de una bicicleta
 *
 * \param this eBici*
 * \param id int*
 * \return int exito 0 si hubo error, 1 si no hubo error
 *
 */
int bici_GetTipo(eBici* this, char* tipo);

/** \brief obtiene el tiempo de una bicicleta
 *
 * \param this eBici*
 * \param id int*
 * \return int exito 0 si hubo error, 1 si no hubo error
 *
 */
int bici_GetTiempo(eBici* this, int* tiempo);


/** \brief Muestra el listado de las bicicletas si la lista no esta vacia
 *
 * \param listaBicis LinkedList*
 * \return int exito 0 si hubo error, 1 si no hubo error
 *
 */
int listarBicis(LinkedList* listaBicis);



/** \brief ordena y compara las bicicletas en cuanto al tipo y tiempo
 *
 * \param tipo1 void*
 * \param tipo2 void*
 * \return retorna 1 o -1
 *
 */
int ordenarPorTipoXTiempo(void* tipo1, void* tipo2);


/** \brief genera numeros aleatorios, en este caso flotantes al azar a tiempo
 *
 * \param a void*
 * \return int retorno 0 si lo agrego a la lista o no
 *
 */
int datosRandom(void* a);

/** \brief hace un filtrado pidiendole al usuario por que tipo se quiere que se lo muestre en la lista
 *
 * \param pFilter void*
 * \param temp char*
 * \return int retorno 0 si hubo error, 1 si no hubo error
 *
 */
int filterTipo(void* pFilter, char* temp);


