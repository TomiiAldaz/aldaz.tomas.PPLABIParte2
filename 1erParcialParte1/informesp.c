#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informesp.h"

int mostrarNotebooksTipo(eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC){

    int idTipo;
    int indice;
    int flag = 0;
    int todoOk = 0;

    if(pc != NULL && tamN > 0 && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && client != NULL && tamC > 0)
    {
        system("cls");
        printf("    Informe de Notebooks por Tipo\n\n");
        mostrarTipos(tipos, tamT);
        printf("\nIngrese el id del Tipo: ");
        scanf("%d", &idTipo);
        indice = buscarTipo(tipos, tamT, idTipo);

        while(indice == -1)
        {
            printf("\nError. Ingrese un id de Tipo valido: ");
            scanf("%d", &idTipo);
            indice = buscarTipo(tipos, tamT, idTipo);
        }

        printf("\n\t     Listado de Notebooks de Tipo: %s\n\n", tipos[indice].descripcion);
        printf("ID     Modelo              Marca          Tipo       Precio  \n\n");
        for(int i=0; i < tamN; i++)
        {
            if(pc[i].isEmpty == 0 && pc[i].idTipo == idTipo)
            {
                mostrarNotebook(pc[i], marcas, tamM, tipos, tamT, client, tamC);
                flag = 1;
                todoOk = 1;
            }
        }
        if(flag == 0)
        {
            printf("  No hay Notebooks de Tipo %s\n\n", tipos[indice].descripcion);
        }
    }

    return todoOk;
}

int mostrarNotebookUnaMarca(eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC){

    int idMarca;
    int indice;
    int flag = 0;
    int todoOk = 0;

    if(pc != NULL && tamN > 0 && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && client != NULL && tamC > 0)
    {

        printf("    Informe de Notebooks de una Marca\n\n");
        mostrarMarcas(marcas, tamM);
        printf("\nIngrese el id de la Marca: ");
        scanf("%d", &idMarca);
        indice = buscarMarca(marcas, tamM, idMarca);

        while(indice == -1)
        {
            printf("\nError. Ingrese el id de la Marca: ");
        scanf("%d", &idMarca);
        indice = buscarMarca(marcas, tamM, idMarca);
        }

        printf("\n\t     Listado de Notebooks de  la Marca: %s\n\n", marcas[indice].descripcion);
        printf("ID     Modelo              Marca          Tipo       Precio  \n\n");
        for(int m = 0; m < tamM; m++)
        {
            if(marcas[m].id == idMarca)
            {
                for(int i=0; i < tamN; i++)
                {
                    if(pc[i].isEmpty == 0 && pc[i].idMarca == idMarca)
                    {

                        mostrarNotebook(pc[i], marcas, tamM, tipos, tamT, client, tamC);
                        flag = 1;
                        todoOk = 1;
                    }
                }

            }
        }
        if(flag == 0)
        {
            printf("  No hay Notebooks de la Marca %s\n\n", marcas[indice].descripcion);
        }
    }

    return todoOk;
}

int mostrarNotebookMasBarata(eNotebook pc[], int tamN){

    int todoOk = 0;
    int mayor = 0;
    int menor = 9999999;
    int posMenor = 0;

    if(pc != NULL && tamN > 0 )
    {

        printf("     Notebook mas barata\n\n");
        for(int i = 0; i < tamN; i++)
        {
                if(pc[i].precio > mayor && pc[i].isEmpty == 0)
                {
                    mayor = pc[i].precio;
                }
                if(pc[i].precio < menor && pc[i].isEmpty == 0)
                {
                    menor = pc[i].precio;
                    posMenor = i;
                }
                todoOk = 1;

        }

        printf("Las o la Notebook mas barata: %s con un valor de %d", pc[posMenor].modelo, pc[posMenor].precio);
    }

    return todoOk;
}

int mostrarNotebookPorMarca(eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC){

    int flag;
    int todoOk = 0;

    if(pc != NULL && tamN > 0 &&  marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && client != NULL && tamC > 0)
    {
        system("cls");
        printf("  Lista de Notebooks por Marca\n\n");
        for(int m=0; m < tamM; m++)
        {
            flag = 1;
            printf("\n Marca:  %s\n\n", marcas[m].descripcion);
            for(int n =0; n < tamN; n++)
            {
                if(marcas[m].id == pc[n].idMarca && pc[n].isEmpty == 0)
                {
                    mostrarNotebook(pc[n], marcas, tamM, tipos, tamT, client, tamC);
                    flag = 0;
                    todoOk =1;

                }
            }

            if(flag == 1)
            {
                printf("  No hay Notebooks de la Marca: %s\n\n", marcas[m].descripcion);
            }
            printf("\n-----------------------------------------------------------\n");

        }
    }

    return todoOk;
}

int contarNotebooksPorMarcaYTipo(eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT){

    int todoOk = 0;
    int flag = 0;
    int idMarca;
    int idTipo;
    int indiceM;
    int indiceT;
    int contadorMyT = 0;

    if(pc != NULL && tamN > 0 && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 )
    {
        printf("Cantidad de Notebooks con la misma marca y el mismo tipo.\n\n");

        mostrarMarcas(marcas, tamM);
        printf("\nIngrese el id de la Marca: ");
        scanf("%d", &idMarca);
        indiceM = buscarMarca(marcas, tamM, idMarca);

        while(indiceM == -1)
        {
            printf("\nError. Ingrese el id de la Marca: ");
        scanf("%d", &idMarca);
        indiceM = buscarMarca(marcas, tamM, idMarca);
        }

        printf("\n\n");
        mostrarTipos(tipos, tamT);
        printf("\nIngrese el id del Tipo: ");
        scanf("%d", &idTipo);
        indiceT = buscarTipo(tipos, tamT, idTipo);

        while(indiceT == -1)
        {
            printf("\nError. Ingrese un id de Tipo valido: ");
            scanf("%d", &idTipo);
            indiceT = buscarTipo(tipos, tamT, idTipo);
        }

        for(int i=0; i < tamN; i++)
        {
            if(pc[i].isEmpty == 0 && pc[i].idTipo == idTipo && pc[i].idMarca == idMarca)
            {
                contadorMyT++;
                flag = 1;
                todoOk = 1;
            }
        }

        if(flag == 0)
        {
            printf("  No hay Notebooks %s y de la Marca %s\n\n", tipos[indiceT].descripcion, marcas[indiceM].descripcion);

        }else
        {
            printf("\n\n La cantidad de Notebooks %s y de la Marca %s es de: %d\n\n", tipos[indiceT].descripcion, marcas[indiceM].descripcion, contadorMyT);

        }
    }

    return todoOk;
}

int mostrarNotebookConTrabajos(eTrabajo jobs[], int tamJ, eServicio service[], int tamS, eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC){

    int todoOk = 0;
    int idNotebook;
    int flag = 1;
    int indice;

    if(jobs != NULL && tamJ > 0 && service != NULL && tamS > 0 && pc != NULL && tamN > 0 &&  marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && client != NULL && tamC > 0)
    {

        printf("  Notebooks con Trabajos \n\n");
        mostrarNotebooks(pc, tamN, marcas, tamM, tipos, tamT, client, tamC);
        printf("Ingrese el ID de la Notebook deseada: ");
        scanf("%d", &idNotebook);
        indice = buscarNotebook(pc, tamN, idNotebook);

        while( indice == -1)
        {
            printf("\nNo existe una Notebook con ese ID. Reingrese ID de la Notebook: ");
            scanf("%d", &idNotebook);
        }

        for(int t=0; t < tamJ; t++)
        {
            if(jobs[t].isEmpty == 0 && jobs[t].idNotebook == idNotebook)
            {
                mostrarTrabajo(jobs[t], service, tamS, pc, tamN);
                flag = 0;
                todoOk = 1;
            }
        }

        if(flag)
        {
            printf("\n\n  No hay Trabajos en la Notebook: %s\n\n", pc[indice].modelo);
        }
    }

    return todoOk;
}

int sumaImportesServiciosNotebook(eTrabajo jobs[], int tamJ, eServicio service[], int tamS, eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC)
{
    int todoOk = 0;
    int idNotebook;
    int flag = 1;
    int indice;
    int total;


    if(jobs != NULL && tamJ > 0 && service != NULL && tamS > 0 && pc != NULL && tamN > 0 &&  marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && client != NULL && tamC > 0)
    {

        printf("   Informe de Importes por los Servicios de una Notebook\n\n");

        mostrarNotebooks(pc, tamN, marcas, tamM, tipos, tamT, client, tamC);
        printf("Ingrese el ID de la Notebook deseada: ");
        scanf("%d", &idNotebook);
        indice = buscarNotebook(pc, tamN, idNotebook);

        while( indice == -1)
        {
            printf("\nNo existe una Notebook con ese ID. Reingrese ID de la Notebook: ");
            scanf("%d", &idNotebook);
        }

        for(int i=0; i < tamJ; i++)
        {
            if(jobs[i].isEmpty == 0 && jobs[i].idNotebook == idNotebook)
            {
                for(int j=0; j < tamS; j++)
                {
                    if(service[j].id == jobs[i].idServicio)
                    {
                        total += service[j].precio;
                        flag = 0;
                        todoOk = 1;
                    }
                }
            }
        }

        if(flag)
        {
            printf("La Notebook %s no registra Trabajos\n", pc[indice].modelo);
        }else
        {
            printf("Total a pagar de la Notebook %s es de: $ %d", pc[indice].modelo, total);

        }
        printf("\n\n");
    }

    return todoOk;
}

int mostrarNotebookServicioFecha(eTrabajo jobs[], int tamJ, eServicio service[], int tamS, eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC){

    int todoOk = 0;
    int flag = 1;
    int indice;
    int idServicio;

    if(jobs != NULL && tamJ > 0 && service != NULL && tamS > 0 && pc != NULL && tamN > 0 &&  marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && client != NULL && tamC > 0)
    {
        mostrarServicios(service, tamS);
        printf("\nIngrese el ID del Servicio: ");
        scanf("%d", &idServicio);
        indice = buscarServicio(service, tamS, idServicio);

        while(indice == -1)
        {
            printf("\nError. Ingrese el ID del Servicio: ");
            scanf("%d", &idServicio);
            indice = buscarServicio(service, tamS, idServicio);
        }

        for(int i=0; i < tamJ; i++)
        {
            if(jobs[i].isEmpty == 0 && jobs[i].idServicio == idServicio)
            {
                mostrarTrabajo(jobs[i], service, tamS, pc, tamN);
                flag = 0;
                todoOk = 1;
            }
        }

        if(flag)
        {
            printf("La Notebook no registra Servicios\n");
        }
        printf("\n\n");
    }

    return todoOk;
}


