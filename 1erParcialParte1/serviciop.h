
#ifndef SERVICIOP_H_INCLUDED
#define SERVICIOP_H_INCLUDED

typedef struct {
    int id;
    char descripcion[25];
    int precio;
}eServicio;

#endif // SERVICIOP_H_INCLUDED

/** \brief Valida el id de un Servicio
 *
 * \param id int Id que recibe en la llamada a la funcion
 * \param service[] eServicio array de servicios
 * \param tam int tamanio del array
 * \return int devuelve 0 si hubo un error o 1 si se pudo hacer la validacion
 *
 */
int validarIdServicio(int id, eServicio service[], int tam);

/** \brief Muestra un Servicio
 *
 * \param unServicio eServicio
 * \return void
 *
 */
void mostrarServicio(eServicio unServicio);

/** \brief Muestra el listado de Servicios
 *
 * \param servicios[] eServicio array de Servicios
 * \param tam int tamanio del array
 * \return int devuelve 0 si hubo un error o 1 si se pudo hacer el listado
 *
 */
int mostrarServicios(eServicio servicios[], int tam);

/** \brief Carga la descripcion de un servicio en la variable desc
 *
 * \param id int Id que recibe en la llamada a la funcion
 * \param service[] eServicio array de Servicios
 * \param tam int tamanio del array
 * \param desc[] char variable en donde se carga la descripcion
 * \return int devuelve 0 si hubo un error o 1 si se pudo cargar la descripcion del Servicio
 *
 */
int cargarDescripcionServicio(int id, eServicio service[], int tam, char desc[]);

/** \brief Busca la posicion de un servicio en el array de servicios
 *
 * \param service[] eServicio
 * \param tam int
 * \param id int
 * \return int devuelve la posicion de un servicio en el array de servicios o -1 si no pudo buscar la posicion
 *
 */
int buscarServicio(eServicio service[], int tam, int id);
