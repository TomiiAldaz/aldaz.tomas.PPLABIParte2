#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajop.h"



int altaTrabajo(eTrabajo jobs[], int tamJ, eServicio service[], int tamS, eNotebook pc[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC,  int* pNextid){

    int todoOk = 0;
    int indice;
    int idNotebook;
    int idServicio;
    int fecha_correcta;

    eTrabajo nuevoTrabajo;

    if(jobs != NULL && service != NULL && pc != NULL && marcas != NULL && tipos != NULL && pNextid != NULL && tamJ > 0 && tamS > 0 && tamN > 0 && tamM > 0 && tamT > 0 && client != NULL && tamC > 0)
    {
        system("cls");
        printf("\n\n   Alta Trabajos \n\n");
        indice = buscarLibreTrabajo(jobs, tamJ);
        if(indice == -1)
        {
            printf("   No hay lugar para mas Trabajos\n\n");
        }
        else
        {
            mostrarNotebooks(pc, tamN, marcas, tamM, tipos, tamT, client, tamC);
            printf("Ingrese el ID de la Notebook: ");
            scanf("%d", &idNotebook);

            while(buscarNotebook(pc, tamN, idNotebook) == -1)
            {
                printf("\nNo existe una Notebook con ese ID. Reingrese ID de la Notebook: ");
                scanf("%d", &idNotebook);
            }

            nuevoTrabajo.idNotebook = idNotebook;

            printf("\n\n");
            mostrarServicios(service, tamS);
            printf("\nIngrese el ID del Servicio: ");
            scanf("%d", &idServicio);

            while(!validarIdServicio(idServicio, service, tamS))
            {
                printf("\nNo existe un Servicio con ese ID. Reingrese el ID del Servicio: ");
                scanf("%d", &idServicio);
            }

            nuevoTrabajo.idServicio = idServicio;

            do
            {
                printf("Ingrese fecha dd/mm/aaaa: ");
                scanf("%d/%d/%d", &nuevoTrabajo.fechaIngreso.dia, &nuevoTrabajo.fechaIngreso.mes, &nuevoTrabajo.fechaIngreso.anio);

                fecha_correcta = 0;

                if( nuevoTrabajo.fechaIngreso.anio <= 2021 )
                {
                    if ( nuevoTrabajo.fechaIngreso.mes >= 1 && nuevoTrabajo.fechaIngreso.mes <= 12 )
                    {
                        switch ( nuevoTrabajo.fechaIngreso.mes )
                        {
                        case  1 :
                            if ( nuevoTrabajo.fechaIngreso.dia >= 1 && nuevoTrabajo.fechaIngreso.dia <= 31 )
                            {
                                fecha_correcta = 1;
                            }
                            else
                            {
                                printf("\nDia incorrecto. Si el mes es Enero, ingrese un dia entre 1 y 31\n");
                                fecha_correcta = 0;
                            }
                            break;
                        case  3 :
                            if ( nuevoTrabajo.fechaIngreso.dia >= 1 && nuevoTrabajo.fechaIngreso.dia <= 31 )
                            {
                                fecha_correcta = 1;
                            }
                            else
                            {
                                printf("\nDia incorrecto. Si el mes es Marzo, ingrese un dia entre 1 y 31");
                                fecha_correcta = 0;
                            }
                            break;
                        case  5 :
                            if ( nuevoTrabajo.fechaIngreso.dia >= 1 && nuevoTrabajo.fechaIngreso.dia <= 31 )
                            {
                                fecha_correcta = 1;
                            }
                            else
                            {
                                printf("\nDia incorrecto. Si el mes es Mayo, ingrese un dia entre 1 y 31");
                                fecha_correcta = 0;
                            }
                            break;
                        case  7 :
                            if ( nuevoTrabajo.fechaIngreso.dia >= 1 && nuevoTrabajo.fechaIngreso.dia <= 31 )
                            {
                                fecha_correcta = 1;
                            }
                            else
                            {
                                printf("\nDia incorrecto. Si el mes es Julio, ingrese un dia entre 1 y 31");
                                fecha_correcta = 0;
                            }
                            break;
                        case  8 :
                            if ( nuevoTrabajo.fechaIngreso.dia >= 1 && nuevoTrabajo.fechaIngreso.dia <= 31 )
                            {
                                fecha_correcta = 1;
                            }
                            else
                            {
                                printf("\nDia incorrecto. Si el mes es Agosto, ingrese un dia entre 1 y 31");
                                fecha_correcta = 0;
                            }
                            break;
                        case 10 :
                            if ( nuevoTrabajo.fechaIngreso.dia >= 1 && nuevoTrabajo.fechaIngreso.dia <= 31 )
                            {
                                fecha_correcta = 1;
                            }
                            else
                            {
                                printf("\nDia incorrecto. Si el mes es Octubre, ingrese un dia entre 1 y 31");
                                fecha_correcta = 0;
                            }
                            break;
                        case 12 :
                            if ( nuevoTrabajo.fechaIngreso.dia >= 1 && nuevoTrabajo.fechaIngreso.dia <= 31 )
                            {
                                fecha_correcta = 1;
                            }
                            else
                            {
                                printf("\nDia incorrecto. Si el mes es Diciembre, ingrese un dia entre 1 y 31");
                                fecha_correcta = 0;
                            }
                            break;

                        case  4 :
                            if ( nuevoTrabajo.fechaIngreso.dia >= 1 && nuevoTrabajo.fechaIngreso.dia <= 30 )
                            {
                                fecha_correcta = 1;
                            }
                            else
                            {
                                printf("\nDia incorrecto. Si el mes es Abril, ingrese un dia entre 1 y 30");
                                fecha_correcta = 0;
                            }
                            break;
                        case  6 :
                            if ( nuevoTrabajo.fechaIngreso.dia >= 1 && nuevoTrabajo.fechaIngreso.dia <= 30 )
                            {
                                fecha_correcta = 1;
                            }
                            else
                            {
                                printf("\nDia incorrecto. Si el mes es Junio, ingrese un dia entre 1 y 30");
                                fecha_correcta = 0;
                            }
                            break;
                        case  9 :
                            if ( nuevoTrabajo.fechaIngreso.dia >= 1 && nuevoTrabajo.fechaIngreso.dia <= 30 )
                            {
                                fecha_correcta = 1;
                            }
                            else
                            {
                                printf("\nDia incorrecto. Si el mes es Septiembre, ingrese un dia entre 1 y 30");
                                fecha_correcta = 0;
                            }
                            break;
                        case 11 :
                            if ( nuevoTrabajo.fechaIngreso.dia >= 1 && nuevoTrabajo.fechaIngreso.dia <= 30 )
                            {
                                fecha_correcta = 1;
                            }
                            else
                            {
                                printf("\nDia incorrecto. Si el mes es Noviembre, ingrese un dia entre 1 y 30");
                                fecha_correcta = 0;
                            }
                            break;

                        case  2 :
                            if ((nuevoTrabajo.fechaIngreso.anio % 4 == 0 && nuevoTrabajo.fechaIngreso.anio % 100 != 0 ) && nuevoTrabajo.fechaIngreso.anio % 400 == 0)
                            {
                                if ( nuevoTrabajo.fechaIngreso.dia >= 1 && nuevoTrabajo.fechaIngreso.dia <= 29 )
                                {
                                    fecha_correcta = 1;
                                }
                                else
                                {
                                    printf("\nDia incorrecto. Si el mes es Febrero, ingrese un dia entre 1 y 29");
                                    fecha_correcta = 0;
                                }
                            }
                            else
                            {
                                if ( nuevoTrabajo.fechaIngreso.dia >= 1 && nuevoTrabajo.fechaIngreso.dia <= 28 )
                                {
                                    fecha_correcta = 1;
                                }
                                else
                                {
                                    printf("\nDia incorrecto. Si el mes es Febrero, ingrese un dia entre 1 y 28");
                                    fecha_correcta = 0;
                                }
                            }
                            break;

                        }
                    }
                    else
                    {
                        printf("\nMes incorrecto. Ingrese un mes entre 1 y 12");
                        fecha_correcta = 0;
                    }
                }else
                {
                    printf("\nAnio incorrecto. Ingrese un anio menor o igual a 2021");
                    fecha_correcta = 0;
                }
                printf("\n\n");
                system("pause");
            }while(!fecha_correcta);


            nuevoTrabajo.id = *pNextid;
            (*pNextid)++;
            nuevoTrabajo.isEmpty = 0;
            jobs[indice] = nuevoTrabajo;

            todoOk = 1;
        }

    }

    return todoOk;
}

int mostrarTrabajos(eTrabajo jobs[], int tamJ, eServicio service[], int tamS, eNotebook pc[], int tamN){
    int estado = 1;
    int todoOk = 0;
    printf("\t         Listado de Trabajos\n\n");
    printf("   Id    Notebook     Servicio    Fecha\n\n");

    for(int i=0; i < tamJ; i++)
    {
        if( !jobs[i].isEmpty )
        {
            mostrarTrabajo(jobs[i], service, tamS, pc, tamN);
            estado = 0;
            todoOk = 1;
        }
    }
    if(estado)
    {
        printf("    No hay Trabajos que mostrar.");
    }

    printf("\n\n");

    return todoOk;
}
void mostrarTrabajo(eTrabajo unJob, eServicio service[], int tamS, eNotebook pc[], int tamN){

    char modeloNotebook[20];
    char descServicio[20];

    if(cargarModeloNotebook(unJob.idNotebook, pc, tamN, modeloNotebook) &&
       cargarDescripcionServicio(unJob.idServicio, service, tamS, descServicio))
    {

            printf("  %d  %10s %10s      %02d/%02d/%d\n", unJob.id,
                   modeloNotebook,
                   descServicio,
                   unJob.fechaIngreso.dia,
                   unJob.fechaIngreso.mes,
                   unJob.fechaIngreso.anio);

    }
}

int buscarLibreTrabajo(eTrabajo jobs[], int tam){
    int estado = -1;

    for(int i=0; i < tam; i++)
    {
        if(jobs[i].isEmpty)
        {

            estado = i;
            break;
        }
    }
    return estado;
}
void inicializarTrabajos(eTrabajo jobs[], int tam){
    for(int i=0; i < tam; i++)
    {
        jobs[i].isEmpty = 1;
    }
}
