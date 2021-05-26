#ifndef MARCAP_H_INCLUDED
#define MARCAP_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eMarca;

#endif // MARCAP_H_INCLUDED

/** \brief Muestra el array de Marcas
 *
 * \param marcas[] eMarca array de Marcas
 * \param tam int Tamanio del array
 * \return int Devuelve 0 si hubo un error o 1 si pudo mostrar el array de Marcas
 *
 */
int mostrarMarcas(eMarca marcas[], int tam);

/** \brief Muestra una Marca
 *
 * \param unaMarca eMarca
 * \return void
 *
 */
void mostrarMarca(eMarca unaMarca);

/** \brief Toma el id de la marca  y carga su descripcion
 *
 * \param id int id de la marca
 * \param marcas[] eMarca array de Marcas
 * \param tam int tamanio del array
 * \param desc[] char guarda la descripcion a cargar
 * \return int Devuelve 0 si hubo un error o 1 si pudo cargar la descripcion de la Marca
 *
 */
int cargarDescripcionMarca(int id, eMarca marcas[], int tam, char desc[]);

/** \brief Busca la posicion de una Marca en el array de marcas
 *
 * \param marcas[] eMarca
 * \param tam int
 * \param id int
 * \return int devuelve la posicion de una marca en el array de marcas o -1 si no pudo buscar la posicion
 *
 */
int buscarMarca(eMarca marcas[], int tam, int id);
