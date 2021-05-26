#ifndef CLIENTEP_H_INCLUDED
#define CLIENTEP_H_INCLUDED

typedef struct {
    int id;
    char nombre[20];
    char sexo;
}eCliente;

#endif // CLIENTEP_H_INCLUDED

/** \brief Muestra el array de clientes
 *
 * \param client[] eCliente array de clientes
 * \param tam int tamanio del arrau
 * \return int Devuelve 0 si hubo un error o 1 si se pudo hacer el listado
 *
 */
int mostrarClientes(eCliente client[], int tam);

/** \brief Muestra un Cliente
 *
 * \param unClient eCliente estructura de un cliente
 * \return void
 *
 */
void mostrarCliente(eCliente unClient);

/** \brief Carga el nombre del cliente en la variable desc
 *
 * \param id int id del cliente que le llega a la funcion
 * \param client[] eCliente
 * \param tam int
 * \param desc[] char variable en la que se le carga el nombre del cliente
 * \return int Devuelve 0 si hubo un error o 1 si se pudo cargar el nombre
 *
 */
int cargarDescripcionCliente(int id, eCliente client[], int tam, char desc[]);

/** \brief Busca la posicion de un cliente en el array de clientes
 *
 * \param client[] eCliente
 * \param tam int
 * \param id int id del cliente que le llega a la funcion
 * \return int devuelve la posicion de un cliente en el array de clientes o -1 si no pudo hacer la busqueda
 *
 */
int buscarCliente(eCliente client[], int tam, int id);
