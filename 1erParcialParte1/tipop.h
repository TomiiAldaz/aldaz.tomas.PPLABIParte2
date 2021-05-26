#ifndef TIPOP_H_INCLUDED
#define TIPOP_H_INCLUDED

typedef struct {
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPOP_H_INCLUDED

/** \brief Muestra el array de Tipos
 *
 * \param tipos[] eTipo array de Tipos
 * \param tam int tamanio del array
 * \return int Devuelve 0 si hubo un error o 1 si pudo mostrar el array de Tipos
 *
 */
int mostrarTipos(eTipo tipos[], int tam);

/** \brief Muestra un Tipo
 *
 * \param unTipo eTipo
 * \return void
 *
 */
void mostrarTipo(eTipo unTipo);

/** \brief Toma el id del tipo  y carga su descripcion
 *
 * \param id int id del tipo
 * \param tipos[] eTipo array de Tipos
 * \param tam int tamanio del array
 * \param desc[] char guarda la descripcion a cargar
 * \return int Devuelve 0 si hubo un error o 1 si pudo cargar la descripcion del Tipo
 *
 */
int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char desc[]);

/** \brief Busca la posicion de un Tipo en el array de tipos
 *
 * \param tipos[] eTipo
 * \param tam int
 * \param id int
 * \return int devuelve la posicion de un tipo en el array de tipos o -1 si no pudo buscar la posicion
 *
 */
int buscarTipo(eTipo tipos[], int tam, int id);
