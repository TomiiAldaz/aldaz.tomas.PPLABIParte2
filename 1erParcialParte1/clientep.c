#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientep.h"

int mostrarClientes(eCliente client[], int tam){

    int todoOk = 0;
    printf("    Lista de Clientes\n\n");
    printf("    Id     Nombre     Sexo\n\n");
    if( client !=  NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            mostrarCliente(client[i]);
            todoOk = 1;
        }
    }

    return todoOk;
}


void mostrarCliente(eCliente unClient){


    printf("   %d    %-10s   %c\n", unClient.id , unClient.nombre, unClient.sexo );

}

int cargarDescripcionCliente(int id, eCliente client[], int tam, char desc[]){

    int todoOk = 0;

    if(id >= 9000 && id <= 9003 && client != NULL && tam > 0 && desc != NULL)
    {

        for(int i=0; i < tam; i++)
        {
            if(client[i].id == id)
            {
                strcpy(desc, client[i].nombre);
                todoOk = 1;
                break;
            }

        }
    }
    return todoOk;
}

int buscarCliente(eCliente client[], int tam, int id)
{

    int indice = -1;
    if(client != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(client[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
