#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "datawarehousep.h"
#include "marcap.h"
#include "tipop.h"
#include "serviciop.h"
#include "trabajop.h"
#include "notebookp.h"
#include "informesp.h"

#define TAMM 4
#define TAMT 4
#define TAMN 15
#define TAMC 4
#define TAMS 4
#define TAMJ 10

char menu();
int menuInformes();

int main()
{

    char salir = 'n';
    char salir2 = 'n';
    int flagAltaN = 0;
    int flagAltaT = 0;

    int nextIdNotebook = 300;
    int nextIdTrabajos = 700;
    eMarca marcas[TAMM] = {
        {1000,"Compaq"},
        {1001,"Asus"},
        {1002,"Acer"},
        {1003,"HP"}
    };
    eTipo tipos[TAMT] = {
        {5000,"Gamer"},
        {5001,"Disenio"},
        {5002,"Ultrabook"},
        {5003,"Normalita"}
    };
    eCliente persona[TAMC] = {
        {9000,"Thiago",  'm'},
        {9001,"Marianela", 'f'},
        {9002,"Samanta", 'f'},
        {9003,"Valentin", 'm'}
    };
    eServicio servicios[TAMT] = {
        {20000, "Bateria",250},
        {20001, "Antivirus",300},
        {20002, "Actualizacion",400},
        {20003, "Fuente",600}
    };

    eNotebook notebooks[TAMN];
    eTrabajo trabajos[TAMJ];
    inicializarNotebook(notebooks, TAMN);
    inicializarTrabajos(trabajos, TAMJ);


    hardcodearTrabajos(trabajos, TAMJ, 8, &nextIdTrabajos);
    do
    {
        switch(menu())
        {

        case 'A':
            if( altaNotebook(notebooks, TAMN, marcas, TAMM, tipos, TAMT, persona, TAMC, &nextIdNotebook) )
            {
                printf("\nAlta exitosa.\n");
            }else
            {
                printf("Hubo un problema al realizar el alta.\n\n");
            }
            flagAltaN = 1;
            break;
        case 'B':
           if(flagAltaN)
           {
               if( modificarNootebook(notebooks, TAMN, marcas, TAMM, tipos, TAMT, persona, TAMC))
                {
                    printf("Modificacion exitosa.\n");
                }else
                {
                    printf("Hubo un problema al realizar la modificacion.\n\n");
                }
            }
            else
            {
                printf("\nAntes de modificar una notebook, primero debes dar de alta una notebook\n\n");
            }
            break;
        case 'C':
            if(flagAltaN)
            {
                if(bajaNotebook(notebooks, TAMN, marcas, TAMM, tipos, TAMT, persona, TAMC))
                {
                    printf("\nBaja exitosa.\n");
                }
                else
                {
                    printf("Hubo un problema al realizar la baja.\n\n");
                }
            }
            else
            {
                printf("\nAntes de dar de baja una notebook, primero debes dar de alta una notebook\n\n");
            }
            break;
        case 'D':
            if(flagAltaN)
            {
                system("cls");
                if(mostrarNotebooks(notebooks, TAMN, marcas, TAMM, tipos, TAMT, persona, TAMC))
                {
                    printf("\n\n Listado exitoso\n");
                }else
                {
                    printf("\n\n Hubo un problema al realizar el listado\n\n");
                }
            }
            else
            {
                printf("\nAntes de dar listar una notebook, primero debes dar de alta una notebook\n\n");
            }
            break;
        case 'E':
            system("cls");
            if(mostrarMarcas(marcas, TAMM))
            {
                printf("\n\n Listado exitoso\n");
            }
            else
            {
                printf("\n\n Hubo un problema al realizar el listado\n\n");
            }
            break;
        case 'F':
            system("cls");
            if(mostrarTipos(tipos, TAMT))
            {
                printf("\n\n Listado exitoso\n");
            }
            else
            {
                printf("\n\n Hubo un problema al realizar el listado\n\n");
            }
            break;
        case 'G':
            system("cls");
            if(mostrarServicios(servicios, TAMS))
            {
                printf("\n\n Listado exitoso\n");
            }
            else
            {
                printf("\n\n Hubo un problema al realizar el listado\n\n");
            }
            break;
        case 'H':
            if(flagAltaN)
            {
                if( altaTrabajo(trabajos, TAMJ, servicios, TAMS, notebooks, TAMN, marcas, TAMM, tipos, TAMT, persona, TAMC, &nextIdTrabajos))
                {
                    printf("Alta exitosa.\n");
                }else
                {
                    printf("Hubo un problema al realizar el alta.\n\n");
                }
                flagAltaT = 1;
            }else
            {
                printf("\nAntes de dar de alta un trabajo, primero debes dar de alta una notebook\n\n");
            }
            break;

            break;
        case 'I':
            if(flagAltaT)
            {
                system("cls");
                if(mostrarTrabajos(trabajos, TAMJ, servicios, TAMS, notebooks, TAMN))
                {
                    printf("\n\n Listado exitoso\n");
                }else
                {
                    printf("\n\n Hubo un problema al realizar el listado\n\n");
                }
            }
            else
            {
                printf("\nAntes de dar listar un trabajo, primero debes dar de alta un trabajo\n\n");
            }
            break;
        case 'J':
            do
            {
                switch(menuInformes())
                {
                    case 1:
                        system("cls");
                        if(mostrarNotebooksTipo(notebooks, TAMN, marcas, TAMM, tipos, TAMT, persona, TAMC))
                        {
                            printf("\n\n Listado exitoso\n");
                        }else
                        {
                            printf("\n\n Hubo un problema al realizar el listado\n\n");
                        }
                        break;
                    case 2:
                        system("cls");
                        if(mostrarNotebookUnaMarca(notebooks, TAMN, marcas, TAMM, tipos, TAMT, persona, TAMC))
                        {
                            printf("\n\n Listado exitoso\n");
                        }else
                        {
                            printf("\n\n Hubo un problema al realizar el listado\n\n");
                        }
                        break;
                    case 3:
                        system("cls");
                        if(mostrarNotebookMasBarata(notebooks, TAMN))
                        {
                            printf("\n\n Listado exitoso\n");
                        }else
                        {
                            printf("\n\n Hubo un problema al realizar el listado\n\n");
                        }
                        break;
                    case 4:
                        system("cls");
                        if(mostrarNotebookPorMarca(notebooks, TAMN, marcas, TAMM, tipos, TAMT, persona, TAMC))
                        {
                            printf("\n\n Listado exitoso\n");
                        }else
                        {
                            printf("\n\n Hubo un problema al realizar el listado\n\n");
                        }
                        break;
                    case 5:
                        system("cls");
                        if(contarNotebooksPorMarcaYTipo(notebooks, TAMN, marcas, TAMM, tipos, TAMT))
                        {
                            printf("\n\n Calculo exitoso\n");
                        }else
                        {
                            printf("\n\n Hubo un problema al realizar el calculo\n\n");
                        }
                        break;
                    case 6:
                        printf("   6. Mostrar la o las marcas mas elegidas por los clientes.\n");
                        break;
                    case 7:
                        system("cls");
                        if(mostrarNotebookConTrabajos(trabajos, TAMJ, servicios, TAMS,notebooks, TAMN, marcas, TAMM, tipos, TAMT, persona, TAMC))
                        {
                            printf("\n\n Calculo exitoso\n");
                        }else
                        {
                            printf("\n\n Hubo un problema al realizar el calculo\n\n");
                        }
                        break;
                    case 8:
                        system("cls");
                        if(sumaImportesServiciosNotebook(trabajos, TAMJ, servicios, TAMS,notebooks, TAMN, marcas, TAMM, tipos, TAMT, persona, TAMC))
                        {
                            printf("\n\n Calculo exitoso\n");
                        }else
                        {
                            printf("\n\n Hubo un problema al realizar el calculo\n\n");
                        }
                        break;
                    case 9:
                        system("cls");
                        if(mostrarNotebookServicioFecha(trabajos, TAMJ, servicios, TAMS,notebooks, TAMN, marcas, TAMM, tipos, TAMT, persona, TAMC))
                        {
                            printf("\n\n Calculo exitoso\n");
                        }else
                        {
                            printf("\n\n Hubo un problema al realizar el calculo\n\n");
                        }
                        break;
                    case 10:
                        printf("  10. Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
                        break;
                    case 11:
                        printf("\n   Confirma salida?: ");
                        fflush(stdin);
                        salir2 = getchar();
                        break;
                    default:
                        printf("\n   Opcion Invalida!\n");
                        fflush(stdin);
                        printf("\n");
                }

                printf("\n");
                system("pause");

            }
            while(salir2 == 'n');
            break;
            break;
        case 'K':
            printf("\n   Confirma salida?: ");
            fflush(stdin);
            salir = getchar();
            break;
        default:
            printf("\n   Opcion Invalida!\n");
            fflush(stdin);
            printf("\n");
            //system("pause");

        }
        printf("\n");
        system("pause");

    }
    while(salir == 'n');

    return 0;
}

char menu(){

    char opcion;

    system("cls");
    printf("      Menu de Opciones\n\n");
    printf("   A. Alta Notebook.\n");
    printf("   B. Modificar Notebook.\n");
    printf("   C. Baja Notebook.\n");
    printf("   D. Listar Notebook.\n");
    printf("   E. Listar Marcas.\n");
    printf("   F. Listar Tipos.\n");
    printf("   G. Listar Servicios.\n");
    printf("   H. Alta Trabajo.\n");
    printf("   I. Listar Trabajos.\n");
    printf("   J. Informes.\n");
    printf("   K. Salir.\n\n");
    printf("   Introduzca opcion (A-K): ");
    fflush(stdin);

    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;
}

int menuInformes(){

    int opcion;

    system("cls");
    printf("      Menu de Informes\n\n");
    printf("   1. Mostrar las Notebooks por el tipo seleccionado por el usuario.\n");
    printf("   2. Mostrar las Notebooks de una marca seleccionada.\n");
    printf("   3. Informar las o la notebook mas barata/s.\n");
    printf("   4. Mostrar un listado de las notebooks separadas por marca.\n");
    printf("   5. Elegir un tipo y marca y contar cuantas notebooks hay de ese tipo y marca.\n");
    printf("   6. Mostrar la o las marcas mas elegidas por los clientes.\n");

    printf("   7. Pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma.\n");
    printf("   8. Muestra la suma de los importes de los services hechos a una Notebook.\n");
    printf("   9. Pedir un servicio y mostrar las notebooks a las que se realizo ese servicio y fecha.\n");
    printf("  10. Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
    printf("  11. Salir.\n\n");
    printf("   Introduzca opcion (1-11): ");
    fflush(stdin);

    scanf("%d", &opcion);


    return opcion;
}
