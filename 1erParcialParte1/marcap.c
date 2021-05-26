#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marcap.h"



int mostrarMarcas(eMarca marcas[], int tam){

   int todoOk = 0;

   printf("    Lista de Marcas\n\n");
   printf("    Id    Descripcion\n\n");
   if( marcas !=  NULL && tam > 0)
   {
        for(int i=0; i < tam; i++)
        {
            mostrarMarca(marcas[i]);
            todoOk = 1;

        }
   }

   return todoOk;
}


void mostrarMarca(eMarca unaMarca){


    printf("   %d    %10s\n", unaMarca.id , unaMarca.descripcion);

}

int cargarDescripcionMarca(int id, eMarca marcas[], int tam, char desc[]){

    int todoOk = 0;

    if(id>= 1000 && id<= 1003 && marcas != NULL && tam > 0 && desc != NULL)
    {

        for(int i=0; i < tam; i++)
        {
            if(marcas[i].id == id)
            {
                strcpy(desc, marcas[i].descripcion);
                todoOk = 1;
                break;
            }

        }
    }
    return todoOk;
}

int buscarMarca(eMarca marcas[], int tam, int id)
{

    int indice = -1;
    if(marcas != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(marcas[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
