#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serviciop.h"



int mostrarServicios(eServicio servicios[], int tam){

   int todoOk = 0;

   printf("    Lista de Servicios\n\n");
   printf("    Id         Descripcion   Precio\n");
   if( servicios !=  NULL && tam > 0)
   {
        for(int i=0; i < tam; i++)
        {
            mostrarServicio(servicios[i]);
            todoOk = 1;

        }
   }
   return todoOk;
}


void mostrarServicio(eServicio unServicio){


    printf("  %d    %15s   %d\n", unServicio.id , unServicio.descripcion, unServicio.precio);

}

int validarIdServicio(int id, eServicio service[], int tam){

    int valido = 0;

    if(service != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(service[i].id == id && id >= 20000 && id <= 20003)
            {
                valido = 1;
                break;
            }
        }
    }
    return valido;
}

int cargarDescripcionServicio(int id, eServicio service[], int tam, char desc[]){

    int todoOk = 0;

    if(id >= 20000 && id <= 20003 && service != NULL && tam > 0 && desc != NULL)
    {

        for(int i=0; i < tam; i++)
        {
            if(service[i].id == id && id >= 700)
            {
                strcpy(desc, service[i].descripcion);
                todoOk = 1;
                break;
            }

        }
    }
    return todoOk;
}

int buscarServicio(eServicio service[], int tam, int id)
{

    int indice = -1;
    if(service != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(service[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
