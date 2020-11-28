#include "pais.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "validaciones.h"

ePais* pais_new()
{
    ePais* nuevoPais= (ePais*) malloc(sizeof(ePais));

    if(nuevoPais!=NULL)//se encontro espacio en memoria
    {
        nuevoPais->id=0;
        nuevoPais->infectados=0;
        nuevoPais->muertos=0;
        nuevoPais->recuperados=0;
        strcpy(nuevoPais->nombre," ");//limpie los campos
    }

    return nuevoPais;
}

ePais* pais_newParams(int id,char*nombre,int recuperados,int infectados,int muertos)
{
    ePais* newPais=pais_new();

    if(newPais!=NULL)
    {
        if(pais_setId(newPais,id)==-1||
           pais_setInfectados(newPais,infectados)==-1||
           pais_setNombre(newPais,nombre)==-1||
           pais_setMuertos(newPais,muertos)==-1||
           pais_setRecuperados(newPais,recuperados))//si algun setter falla
        {
            pais_delete(newPais);
        }
    }

    return newPais;
}

void pais_delete(ePais* this)
{
    if(this!=NULL)
    {
        free(this);
        this=NULL;
    }
}

int pais_setId(ePais* this,int id)
{
    int retorno=-1;

    if(this!=NULL&&id>=0)
    {
        this->id=id;
        retorno=0;
    }

    return retorno;
}

int pais_getId(ePais* this,int* id)
{
    int retorno=-1;

    if(this!=NULL&&id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }

    return retorno;
}

int pais_setNombre(ePais* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL&&nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }

    return retorno;
}

int pais_getNombre(ePais* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL&&nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }

    return retorno;
}

int pais_setRecuperados(ePais* this,int recuperados)
{
    int retorno=-1;

    if(this!=NULL&&recuperados>=0)
    {
        this->recuperados=recuperados;
        retorno=0;
    }

    return retorno;
}

int pais_getRecuperados(ePais* this,int* recuperados)
{
    int retorno=-1;

    if(this!=NULL&&recuperados!=NULL)
    {
        *recuperados=this->recuperados;
        retorno=0;
    }

    return retorno;
}

int pais_setInfectados(ePais* this,int infectados)
{
    int retorno=-1;

    if(this!=NULL&&infectados>=0)
    {
        this->infectados=infectados;
        retorno=0;
    }

    return retorno;
}

int pais_getInfectados(ePais* this,int* infectados)
{
    int retorno=-1;

    if(this!=NULL&&infectados!=NULL)
    {
        *infectados=this->infectados;
        retorno=0;
    }

    return retorno;
}

int pais_setMuertos(ePais* this,int muertos)
{
    int retorno=-1;

    if(this!=NULL&&muertos>=0)
    {
        this->muertos=muertos;
        retorno=0;
    }

    return retorno;
}

int pais_getMuertos(ePais* this,int* muertos)
{
    int retorno=-1;

    if(this!=NULL&&muertos!=NULL)
    {
        *muertos=this->muertos;
        retorno=0;
    }

    return retorno;
}

void mostrarPais(ePais* this)
{
    int auxId;
    char auxNombre[25];
    int auxRec;
    int auxInf;
    int auxM;

    if(!pais_getId(this,&auxId)&&
       !pais_getInfectados(this,&auxInf)&&
       !pais_getMuertos(this,&auxM)&&
       !pais_getNombre(this,auxNombre)&&
       !pais_getRecuperados(this,&auxRec))//obtengo los valores de todos los campos
    {
        printf(" %02d %20s    %5dk     %6dk    %5dk\n",auxId,auxNombre,auxRec,auxInf,auxM);
    }
}

void* asignarValores(void* pais)
{
    ePais* country= (ePais*) pais;
    int cantInfectados;
    int cantRecuperados;
    int cantMuertos;

    /*un valor de recuperados entre 50k y 1000k personas,
    infectados con valores entre 400k y 2000 y muertos entre 1k y 50k.*/

    if(country!=NULL)
    {
        cantInfectados=rand()%(1601)+400;
        cantRecuperados=rand()%(951)+50;
        cantMuertos=rand()%(50)+1;

        pais_setMuertos(country,cantMuertos);
        pais_setInfectados(country,cantInfectados);
        pais_setRecuperados(country,cantRecuperados);
    }

    return country;
}

int fueExitoso(void* pais)
{
    int retorno=0;
    ePais* country= (ePais*) pais;
    int muertos;

    if(country!=NULL)
    {
        pais_getMuertos(country,&muertos);

        if(muertos<5)//menos de 5000 muertos
        {
            retorno=1;
        }
    }

    return retorno;
}

int estaAlHorno(void* pais)
{
    int retorno=0;
    ePais* country= (ePais*) pais;
    int infectados;
    int recuperados;

    if(country!=NULL)
    {
        pais_getInfectados(country,&infectados);
        pais_getRecuperados(country,&recuperados);

        if(infectados>=(recuperados*3))//el numero de infectados triplica al de recuperados
        {
            retorno=1;
        }
    }

    return retorno;
}

int compararCantInfectados(void* pais1,void* pais2)
{
    int retorno=0;
    ePais* country1= (ePais*) pais1;
    ePais* country2= (ePais*) pais2;
    int cantInf1;
    int cantInf2;

    if(pais1!=NULL&&pais2!=NULL)
    {
        pais_getInfectados(country1,&cantInf1);
        pais_getInfectados(country2,&cantInf2);

        if(cantInf1<cantInf2)
        {
            retorno=-1;
        }else if(cantInf1>cantInf2)
        {
            retorno=1;
        }
    }

    return retorno;
}
