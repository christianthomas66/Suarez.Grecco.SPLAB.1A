#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "Bicicletas.h"
#include "parser.h"

int main()
{

    int opcion = 0;
    char salir[3];
    char aux;

    int opcionBici;

    LinkedList* listaOriginal = ll_newLinkedList();
    LinkedList* listaOrdenada= NULL;
    LinkedList* listaRandomMapeada = NULL;
    LinkedList* listaFiltradaTipo = NULL;
    do
    {   strcpy(salir,"no");

        getInt("------ MENU BICICLETAS ------\n\n1) Cargar archivo bicicletas.csv (modo texto)\n2) Imprimir lista\n3) Asignar tiempos\n4) Filtrar por tipo (clonar la lista a un 2do archivo con un solo tipo)\n5) Mostrar posiciones (ornedar tipo y tiempo)\n6) Guardar posiciones (Guardar en un archivo del punto anterior)\n7) Salir\n\n Elija la opcion deseada: ","Error\n", 1, 3, 0, &opcion);
        printf("\n\n");
        switch(opcion)
        {
        case 1:
                if(cargarTexto("bicicletas.csv", listaOriginal) == 1)
                    {
                        printf("Archivo cargado con exito\n");
                    }


            system("pause");
            break;
        case 2:
                if(listarBicis(listaOriginal))
                    {
                        printf("Lista cargada con exito\n");
                    }
                else
                    {
                        printf("Hay problemas. No se pudo cargar la lista");
                    }

            system("pause");
            break;
        case 3:

            listaRandomMapeada = ll_map(listaOriginal, datosRandom);
            listarBicis(listaRandomMapeada);
            system("pause");

            break;
        case 4:

            getInt("------ SUB MENU FILTRAR ------ \n1. BMX\n2. PLAYERA\n3. MTB\n4. PASEo\nElija el tipo que quiera a filtrar en el archivo: ","Error, escriba un numero del 1 al 4", 1,4,4, &opcionBici);

            char temp[20];

            switch(opcionBici)
            {
                case 1:
                    strcpy(temp,"PLAYERA");
                break;
                case 2:
                    strcpy(temp,"BMX");
                break;
                case 3:
                    strcpy(temp, "PASEO");
                break;
                case 4:
                    strcpy(temp, "MTB");
                break;
            }

            listaFiltradaTipo = ll_filter_parametro(listaOriginal, filterTipo, temp);

            listarBicis(listaFiltradaTipo);
            guardarComoTexto("bicicletasTipo.csv", listaFiltradaTipo);

            system("pause");
            break;
        case 5:

            listaOrdenada = ll_clone(listaOriginal);

            if(listaOrdenada != NULL)
            {
                ll_sort(listaOrdenada, ordenarPorTipoXTiempo, 1);
            }
            listarBicis(listaOrdenada);
            system("pause");
            break;
        case 6:

            guardarComoTexto("bicicletasOrdenadas.csv", listaOrdenada);

            system("pause");
            break;
        case 7:
            printf("Seguro que desea salir? ");
            fflush(stdin);
            scanf("%c", &aux);
            while(aux != 's' && aux != 'n')
            {
                printf("Opcion incorrecta. Reingrese 's'(si) o 'n'(no)");
                printf(" s/n : \n");
                fflush(stdin);
                scanf("%c", &aux);
            }

            if(aux == 's')
            {
                printf("Gracias. Vuelva pronto!!!\n");
                return 0;
            }


            system("pause");
            break;;
        default:
            printf("Opcion incorrecta. Reingrese\n");
            system("pause");
        }

        system("cls");
    }
    while(strcmp(salir,"si")!= 0);

    ll_deleteLinkedList(listaRandomMapeada);
    ll_deleteLinkedList(listaOrdenada);
    ll_deleteLinkedList(listaOriginal);
    ll_deleteLinkedList(listaFiltradaTipo);
    return 0;
}

