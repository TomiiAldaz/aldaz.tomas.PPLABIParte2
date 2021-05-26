#include "marcap.h"
#include "tipop.h"
#include "clientep.h"

#ifndef NOTEBOOKP_H_INCLUDED
#define NOTEBOOKP_H_INCLUDED
typedef struct{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int precio;
    int idCliente;
    int isEmpty;
}eNotebook;


#endif // NOTEBOOKP_H_INCLUDED

/** \brief Coloca todos los isEmpty en 1
 *
 * \param pc[] eNotebook array de Notebooks
 * \param tam int tamanio del array
 * \return void
 *
 */
void inicializarNotebook(eNotebook pc[], int tam);

/** \brief Genera el alta de una Notebook
 *
 * \param pc[] eNotebook array de Notebooks
 * \param tamN int tamanio del array
 * \param marcas[] eMarca array de Marcas
 * \param tamM int tamanio del array
 * \param tipos[] eTipo array de Tipos
 * \param tamT int tamanio del array
 * \param pId int* puntero del id de notebooks
 * \return int Devuelve 0 si hubo algun error o 1 si se dio la alta de la notebook
 *
 */
int altaNotebook(eNotebook pc[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC, int* pId);

/** \brief Muestra el array de Notebooks
 *
 * \param pc[] eNotebook
 * \param tamn int
 * \param marcas[] eMarca
 * \param tamm int
 * \param tipos[] eTipo
 * \param tamt int
 * \return int Devuelve 0 si hubo un error o 1 si se pudo mostrar el array de Notebooks
 *
 */
int mostrarNotebooks(eNotebook pc[], int tamn, eMarca marcas[],int tamm, eTipo tipos[],int tamt, eCliente client[], int tamC);

/** \brief Muestra una Notebook
 *
 * \param unaNotebook eNotebook
 * \param marcas[] eMarca
 * \param tamm int
 * \param tipos[] eTipo
 * \param tamt int
 * \return void
 *
 */
void mostrarNotebook(eNotebook unaNotebook, eMarca marcas[], int tamm, eTipo tipos[], int tamt, eCliente client[], int tamC);

/** \brief Busca la posicion de una Notebook en el array de Notebooks en base a su id (Tambien se usa para validar idNotebook)
 *
 * \param pc[] eNotebook
 * \param tam int
 * \param id int id de la notebook a buscar
 * \return int Devuelve la posicion de una Notebook dentro del array de Notebooks o -1 si la posicion es invalida
 *
 */
int buscarNotebook(eNotebook pc[], int tam, int id);

/** \brief Genera la baja de una Notebook previamente dada de alta
 *
 * \param pc[] eNotebook
 * \param tamN int
 * \param marcas[] eMarca
 * \param tamM int
 * \param tipos[] eTipo
 * \param tamT int
 * \return int Devuelve 0 si hubo algun error o 1 si se dio la baja de la notebook
 *
 */
int bajaNotebook(eNotebook pc[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC);

/** \brief Busca la primer posicion libre en el array de Notebooks
 *
 * \param pc[] eNotebook
 * \param tam int
 * \return int Devuelve -1 si el estado es invalido o el estado de una Notebook (isEmpty)
 *
 */
int buscarLibre(eNotebook pc[], int tam);


/** \brief Al ingresar al menu de modificaciones, permite modificar el precio o el tipo de una notebook
 *
 * \param pc[] eNotebook array de Notebooks
 * \param tamN int tamanio del array
 * \param marcas[] eMarca array de Marcas
 * \param tamM int tamanio del array
 * \param tipos[] eTipo array de Tipos
 * \param tamT int tamanio del array
 * \return int Devuelve 0 si hubo algun error o 1 si se pudo modificar la notebook
 *
 */
int modificarNootebook(eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC);

/** \brief Carga en la variable desc el Modelo de una Notebook
 *
 * \param id int Id que recibe en la llamada de la funcion
 * \param pc[] eNotebook Array de Notebooks
 * \param tam int tamanio del array
 * \param desc[] char variable en la que se guarda el modelo de la Notebook
 * \return int devuelve 0 si hubo un error o 1 si se pudo cargar el modelo de la Notebook
 *
 */
int cargarModeloNotebook(int id, eNotebook pc[], int tam, char desc[]);
