#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehousep.h"
#include "fechap.h"



int idNotebooks2[] = {303,306,309,302,305,301,304,308,307,306,302,308,301,303};

int idServicios[] = {20000,20004,20002,20009,20007,20005,20008,20002,20006,20004,20009,20007,20005,20008};

eFecha fechas2[] =
{
    {1,1,2021},
    {12,2,2021},
    {9,3,2021},
    {25,3,2021},
    {13,4,2021},
    {22,4,2021},
    {14,5,2021},
    {26,6,2021},
    {10,7,2021},
    {22,8,2021},
    {11,9,2021},
    {19,10,2021},
    {25,10,2021},
    {5,11,2021},
    {16,11,2021},
    {3,12,2021},
    {29,12,2021},

};



int hardcodearTrabajos(eTrabajo jobs[], int tam, int cant, int* pId){

    int cantidad = 0;

    if( jobs != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        for(int i=0; i < cant; i++)
        {
            jobs[i].id = *pId;
            (*pId)++;
            jobs[i].idNotebook = idNotebooks2[i];
            jobs[i].idServicio = idServicios[i];
            jobs[i].fechaIngreso = fechas2[i];
            jobs[i].isEmpty = 0;
            cantidad++;
        }
    }
    return cantidad;
}

