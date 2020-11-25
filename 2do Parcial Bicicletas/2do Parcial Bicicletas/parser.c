#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Bicicletas.h"
#include "parser.h"

int parser_BiciFromText(FILE* miFile, LinkedList* pMiLista)
{
	eBici* pBici;
    int retorno = 0;
	char id[200];
	char nombre[200];
	char tipo[200];
	char tiempo[200];

	if(miFile != NULL && pMiLista != NULL)
	{
	    fscanf(miFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, tipo, tiempo);
		do
		{
			if(fscanf(miFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, tipo, tiempo) == 4)
			{
				pBici = bici_NewParametros(id, nombre, tipo, tiempo);

				if(pBici != NULL)
				{
					ll_add(pMiLista, pBici);
					retorno = 1;
				}
			}
			else
			{
				break;
			}

		}while(feof(miFile) == 0);
	}
return retorno;
}


int cargarTexto(char* path , LinkedList* pLista)
{
	FILE* pFile;
	int retorno = 1;

	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		if(parser_BiciFromText(pFile, pLista) == 1)
		{
		    retorno = 0;
			printf("\nLos datos de las bicicletas en modo texto fueron cargados corretamente!!!\n\n");
		}
	}

	fclose(pFile);

    return retorno;

}


int guardarComoTexto(char* path, LinkedList* pLista)
{
	FILE* pFile;
	eBici* pBici;

	int auxId;
	char auxNombre[25];
	char auxTipo[25];
	int auxTiempo;
	int retorno = 0;

	if(pLista!=NULL && path!=NULL)
	{
		pFile= fopen(path, "w");
		if(pFile!=NULL)
		{
			retorno = 1;
			for(int i = 0; i < ll_len(pLista); i++)
			{
				pBici = (eBici*)ll_get(pLista, i);
                bici_GetId(pBici, &auxId);
                bici_GetNombre(pBici, auxNombre);
                bici_GetTipo(pBici, auxTipo);
                bici_GetTiempo(pBici, &auxTiempo);

                fprintf(pFile, "%d,%s,%s,%d\n", auxId, auxNombre, auxTipo, auxTiempo);
			}

			fclose(pFile);

			printf("Archivo guardado correctamente\n");
		}
		else if(retorno == 0)
        {
            printf("Error\n");
        }
	}

    return retorno;
}
