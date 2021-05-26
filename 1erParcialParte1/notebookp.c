#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "notebookp.h"
#include "datawarehousep.h"

char menuModificaciones();

void inicializarNotebook(eNotebook pc[], int tam)
{

    if( pc != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            pc[i].isEmpty = 1;
        }
    }
}

int buscarLibre(eNotebook pc[], int tam)
{

    int estado = -1;

    if( pc != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(pc[i].isEmpty)
            {

                estado = i;
                break;
            }
        }
    }
    return estado;
}

int altaNotebook(eNotebook pc[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC, int* pId){

    int todoOk = 0;
    int i;
    int idMarca;
    int idTipo;
    int precio;
    int idCliente;

    eNotebook auxNotebook;

    system("cls");
    printf("    Alta Notebook\n\n");
    printf("ID: %d\n", *pId);

    if( pc != NULL && tamN > 0 && pId != NULL && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && client != NULL && tamC > 0)
    {
        i = buscarLibre(pc, tamN);

        if(i == -1)
        {

            printf("No hay lugar en el sistema\n");
        }

        else
        {
            printf("\nIngrese Modelo: ");
            fflush(stdin);
            gets(auxNotebook.modelo);

            printf("\n");
            mostrarMarcas(marcas, tamM);
            printf("\nIngrese el id de la marca: ");
            scanf("%d", &idMarca);

            while(!(idMarca >= 1000 && idMarca <= 1003))
            {
                printf("\nErorr. Reingrese el id de la marca: ");
                scanf("%d", &idMarca);

            }

            auxNotebook.idMarca = idMarca;

            printf("\n");
            mostrarTipos(tipos, tamT);
            printf("\nIngrese el id del tipo: ");
            scanf("%d", &idTipo);

            while((!(idTipo >= 5000 && idTipo <= 5003)))
            {
                printf("\nErorr. Reingrese el id del tipo: ");
                scanf("%d", &idTipo);
            }
            auxNotebook.idTipo = idTipo;

            printf("\nIngrese Precio: ");
            scanf("%d", &precio);
            while(!(precio >0))
            {
                printf("\nErorr. Ingrese un precio mayor a 0: ");
                scanf("%d", &precio);
            }

            auxNotebook.precio = precio;

            printf("\n");
            mostrarClientes(client, tamC);
            printf("\nIngrese el ID del Cliente: ");
            scanf("%d", &idCliente);

            while((!(idCliente >= 9000 && idCliente <= 9003)))
            {
                printf("\nErorr. Reingrese el ID del cliente: ");
                scanf("%d", &idCliente);
            }
            auxNotebook.idCliente = idCliente;

            auxNotebook.isEmpty = 0;

            auxNotebook.id = *pId;
            (*pId)++;
            pc[i] = auxNotebook;
            todoOk = 1;
        }
    }
    return todoOk;
}

int mostrarNotebooks(eNotebook pc[], int tamn, eMarca marcas[],int tamm, eTipo tipos[],int tamt, eCliente client[], int tamC){

    int estado = 1;
    int todoOk = 0;
    if(pc != NULL && marcas != NULL && tipos != NULL && tamn > 0 && tamm > 0 && tamt > 0 && client != NULL && tamC > 0)
    {
        printf("\t          Listado de Notebooks \n\n");
        printf("ID     Modelo          Marca         Tipo            Precio    Cliente\n\n");
        for(int i=0; i < tamn; i++)
        {
            if( !pc[i].isEmpty )
            {
                mostrarNotebook(pc[i], marcas, tamm, tipos, tamt, client, tamC);
                estado = 0;
                todoOk = 1;
            }
        }
        if(estado)
        {
            printf("    No hay Notebooks que mostrar.\n");
        }

        printf("\n\n");
    }
    return todoOk;
}

void mostrarNotebook(eNotebook unaNotebook, eMarca marcas[], int tamm, eTipo tipos[], int tamt, eCliente client[], int tamC){

    char descripcionM[20];
    char descripcionT[20];
    char nombreCliente[20];

    if(marcas != NULL && tipos != NULL && tamm > 0 && tamt > 0 && client != NULL && tamC > 0)
    {


    if(cargarDescripcionMarca(unaNotebook.idMarca, marcas, tamm, descripcionM)
       && cargarDescripcionTipo(unaNotebook.idTipo, tipos, tamt, descripcionT)
       && cargarDescripcionCliente(unaNotebook.idCliente, client, tamC, nombreCliente))
    {



        printf("%d    %-11s     %-10s    %-10s      %d       %-10s\n"
               , unaNotebook.id
               , unaNotebook.modelo
               , descripcionM
               , descripcionT
               , unaNotebook.precio
               , nombreCliente
              );
    }
    }
}


int buscarNotebook(eNotebook pc[], int tam, int id)
{

    int indice = -1;
    if(pc != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(pc[i].id == id && pc[i].isEmpty == 0)
            {

                indice = i;
                break;
            }
        }
    }
    return indice;
}

int bajaNotebook(eNotebook pc[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC)
{

    int todoOk = 0;
    int id;
    int indice;
    char confirma;

    if(pc != NULL && marcas != NULL && tipos != NULL && tamN > 0 && tamM> 0 && tamT > 0 && client != NULL && tamC > 0)
    {
        system("cls");
        printf("    Baja de Notebook\n\n");
        mostrarNotebooks(pc, tamN, marcas, tamM, tipos, tamT, client, tamC);
        printf("Ingrese ID de la Notebook que desea dar de baja: ");
        scanf("%d", &id);
        printf("\n");

        indice = buscarNotebook(pc, tamN, id);

        if( indice == -1)
        {
            printf("No hay ninguna notebook registrada con ese id %d\n", id);
        }
        else
        {
            mostrarNotebook(pc[indice], marcas, tamM, tipos, tamT, client, tamC);
            printf("\nConfirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                pc[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }

        }
    }
    return todoOk;
}

int modificarNootebook(eNotebook pc[], int tamN , eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente client[], int tamC){

    int todoOk = 0;
    int id;
    int indice;
    int idTipo;
    char confirma;
    char salir = 'n';

    if(pc != NULL && marcas != NULL && tipos != NULL && tamN > 0 && tamM> 0 && tamT > 0 && client != NULL && tamC > 0)
    {


        system("cls");
        printf("    Menu de Modificaciones\n\n");
        mostrarNotebooks(pc, tamN, marcas, tamM, tipos, tamT, client, tamC);
        printf("Ingrese ID: ");
        scanf("%d", &id);
        printf("\n");

        indice = buscarNotebook(pc, tamN, id);

        if( indice == -1)
        {
            printf("No hay ninguna Notebook registrada con el ID: %d\n", id);
        }
        else
        {
            mostrarNotebook(pc[indice], marcas, tamM, tipos, tamT, client, tamC);
            printf("\nDesea modificar esta Notebook?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                do
                {
                    switch(menuModificaciones())
                    {

                    case 'A':
                        printf("\nIngrese un nuevo Precio: ");
                        scanf("%d", &pc[indice].precio);
                        break;
                    case 'B':
                        printf("\n");
                        mostrarTipos(tipos, tamT);
                        printf("\nIngrese el id del Tipo: ");
                        scanf("%d", &idTipo);
                        pc[indice].idTipo = idTipo;
                        break;
                    case 'C':
                        printf("\n   Confirma salida?: ");
                        fflush(stdin);
                        salir = getchar();
                        break;
                    default:
                        printf("\n   Opcion Invalida!\n");
                        fflush(stdin);
                        printf("\n");
                        system("pause");

                    }
                    printf("\n");
                    system("pause");


                }
                while(salir == 'n');
                todoOk = 1;
                printf("\n");
            }
            else
            {
                printf("\nModificacion cancelada por el usuario\n");
            }

        }
    }
    return todoOk;
}

char menuModificaciones(){

    char opcion;
    system("cls");
    printf("      Menu de Modificaciones\n\n");
    printf("   A. Modificar Precio.\n");
    printf("   B. Modificar Tipo.\n");
    printf("   C. Salir.\n\n");
    printf("   Introduzca opcion (A-C): ");
    fflush(stdin);

    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;
}

int cargarModeloNotebook(int id, eNotebook pc[], int tam, char desc[]){

    int todoOk = 0;
    int indice;

    if( pc != NULL && tam > 0 && desc != NULL )
    {
        indice = buscarNotebook(pc, tam, id);
        if(indice != -1)
        {
            strcpy(desc, pc[indice].modelo);
            todoOk = 1;
        }
    }
    return todoOk;
}
