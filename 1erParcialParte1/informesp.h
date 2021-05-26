#include "notebookp.h"
#include "trabajop.h"
#ifndef INFORMESPRACTICA_H_INCLUDED
#define INFORMESPRACTICA_H_INCLUDED



#endif // INFORMESPRACTICA_H_INCLUDED

/** \brief Muestra las notebooks del tipo seleccionadas por el usuario
 *
 * \param pc[] eNotebook
 * \param tamN int
 * \param marcas[] eMarca
 * \param tamM int
 * \param tipos[] eTipo
 * \param tamT int
 * \param client[] eCliente
 * \param tamC int
 * \return int Devuelve 0 si hubo un error o 1 si pudo hacer el listado
 *
 */
int mostrarNotebooksTipo(eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC);

/** \brief Muestra las notebooks de una marca seleccionada
 *
 * \param pc[] eNotebook
 * \param tamN int
 * \param marcas[] eMarca
 * \param tamM int
 * \param tipos[] eTipo
 * \param tamT int
 * \param client[] eCliente
 * \param tamC int
 * \return int Devuelve 0 si hubo un error o 1 si pudo hacer el listado
 *
 */
int mostrarNotebookUnaMarca(eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC);

/** \brief Informa la o las notebooks mas baratas
 *
 * \param pc[] eNotebook
 * \param tamN int
 * \return int Devuelve 0 si hubo un error o 1 si pudo hacer el listado
 *
 */
int mostrarNotebookMasBarata(eNotebook pc[], int tamN);

/** \brief Muestra un listado de las notebooks separadas por marca
 *
 * \param pc[] eNotebook
 * \param tamN int
 * \param marcas[] eMarca
 * \param tamM int
 * \param tipos[] eTipo
 * \param tamT int
 * \param client[] eCliente
 * \param tamC int
 * \return int Devuelve 0 si hubo un error o 1 si pudo hacer el listado
 *
 */
int mostrarNotebookPorMarca(eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC);

/** \brief Cuenta cuantas notebooks tienen la misma marca y el mismo tipo a la vez
 *
 * \param pc[] eNotebook
 * \param tamN int
 * \param marcas[] eMarca
 * \param tamM int
 * \param tipos[] eTipo
 * \param tamT int
 * \return int Devuelve 0 si hubo un error o 1 si pudo hacer el calculo
 *
 */
int contarNotebooksPorMarcaYTipo(eNotebook pc[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT);

/** \brief Muestra los trabajos que le hicieron a una notebook
 *
 * \param jobs[] eTrabajo
 * \param tamJ int
 * \param service[] eServicio
 * \param tamS int
 * \param pc[] eNotebook
 * \param tamN int
 * \param marcas[] eMarca
 * \param tamM int
 * \param tipos[] eTipo
 * \param tamT int
 * \param client[] eCliente
 * \param tamC int
 * \return int Devuelve 0 si hubo un error o 1 si pudo hacer el listado
 *
 */
int mostrarNotebookConTrabajos(eTrabajo jobs[], int tamJ, eServicio service[], int tamS, eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC);

/** \brief Muestra la suma de los importes de los servicios que se le hicieron a una notebook
 *
 * \param jobs[] eTrabajo
 * \param tamJ int
 * \param service[] eServicio
 * \param tamS int
 * \param pc[] eNotebook
 * \param tamN int
 * \param marcas[] eMarca
 * \param tamM int
 * \param tipos[] eTipo
 * \param tamT int
 * \param client[] eCliente
 * \param tamC int
 * \return int Devuelve 0 si hubo un error o 1 si pudo hacer el calculo
 *
 */
int sumaImportesServiciosNotebook(eTrabajo jobs[], int tamJ, eServicio service[], int tamS, eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC);

/** \brief Muestra una notebook con el servicio y la fecha segun el servicio realizado
 *
 * \param jobs[] eTrabajo
 * \param tamJ int
 * \param service[] eServicio
 * \param tamS int
 * \param pc[] eNotebook
 * \param tamN int
 * \param marcas[] eMarca
 * \param tamM int
 * \param tipos[] eTipo
 * \param tamT int
 * \param client[] eCliente
 * \param tamC int
 * \return int Devuelve 0 si hubo un error o 1 si pudo hacer el listado
 *
 */
int mostrarNotebookServicioFecha(eTrabajo jobs[], int tamJ, eServicio service[], int tamS, eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC);
