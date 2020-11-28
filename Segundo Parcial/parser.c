#include "parser.h"
#include "pais.h"
#include <stdlib.h>

int parser_countriesFromTxt(LinkedList*pArray,FILE*pFile)
{
    int retorno=-1;
    int cant;
    char buffer[5][128];
    ePais* newPais;

    if(pArray!=NULL&&pFile!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);//leo el encabezado

        while(!feof(pFile))
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

            if(cant==5)//5 es la cant de campos de ePais
            {
                newPais=pais_newParams(atoi(buffer[0]),buffer[1],atoi(buffer[2]),atoi(buffer[3]),atoi(buffer[4]));
                if(newPais!=NULL)
                {
                    ll_add(pArray,newPais);//agrego el pais a la linkdlist
                    retorno=0;
                }
            }else
            {
                break;
            }
        }
    }

    return retorno;
}
