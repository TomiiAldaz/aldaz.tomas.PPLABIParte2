#include "fechap.h"
#include "notebookp.h"
#include "serviciop.h"


#ifndef TRABAJOP_H_INCLUDED
#define TRABAJOP_H_INCLUDED

typedef struct{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fechaIngreso;
    int isEmpty;
}eTrabajo;


#endif // TRABAJOP_H_INCLUDED

/** \brief Coloca todos los isEmpty en 1
 *
 * \param jobs[] eTrabajo array de Trabajos
 * \param tam int tamanio del array
 * \return void
 *
 */
void inicializarTrabajos(eTrabajo jobs[], int tam);

/** \brief Busca la primer posicion libre en el array de Trabajos
 *
 * \param jobs[] eTrabajo eTrabajo array de Trabajos
 * \param tam int tamanio del array
 * \return int Devuelve -1 si el estado es invalido o el estado de una Notebook (isEmpty)
 *
 */
int buscarLibreTrabajo(eTrabajo jobs[], int tam);

/** \brief Muestra un Trabajo
 *
 * \param unJob eTrabajo una estructura de Trabajo
 * \param service[] eServicio Array de Servicios
 * \param tamS int tamanio del array
 * \param pc[] eNotebook Array de Notebooks
 * \param tamN int tamanio del array
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo unJob, eServicio service[], int tamS, eNotebook pc[], int tamN);

/** \brief Muestra el Array de Trabajos
 *
 * \param jobs[] eTrabajo eServicio Array de Trabajos
 * \param tamJ int tamanio del array
 * \param service[] eServicio eServicio Array de Servicios
 * \param tamS int tamanio del array
 * \param pc[] eNotebook eServicio Array de Notebooks
 * \param tamN int tamanio del array
 * \return int Devuelve 0 si hubo un error o 1 si se pudo mostrar el array de Trabajos
 *
 */
int mostrarTrabajos(eTrabajo jobs[], int tamJ, eServicio service[], int tamS, eNotebook pc[], int tamN);

/** \brief Genera el alta de un Trabajo
 *
 * \param jobs[] eTrabajo Array de Trabajos
 * \param tamJ int tamanio del array
 * \param service[] eServicio Array de Servicios
 * \param tamS int tamanio del array
 * \param pc[] eNotebook Array de Notebooks
 * \param tamN int tamanio del array
 * \param marcas[] eMarca Array de Marcas
 * \param tamM int tamanio del array
 * \param tipos[] eTipo Array de Tipos
 * \param tamT int tamanio del array
 * \param pNextid int* puntero del id de trabajos
 * \return int Devuelve 0 si hubo algun error o 1 si se dio la alta de un trabajo
 *
 */
int altaTrabajo(eTrabajo jobs[], int tamJ, eServicio service[], int tamS, eNotebook pc[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC,  int* pNextid);
