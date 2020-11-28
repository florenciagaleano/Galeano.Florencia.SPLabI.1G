#include "LinkedList.h"

#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[25];
    int recuperados;
    int infectados;
    int muertos;
}ePais;

#endif // PAIS_H_INCLUDED


/** \brief Crea un nuevo pais en la memoria dinamica
 *
 * \return Puntero al nuevo pais
 *
 */
ePais* pais_new();

/** \brief Crea un nuevo pais en la memoria dinamica asignando a sus campos los valores pasados
 *
 * \param id int Id que se le asignara
 * \param char*nombre Nombre que se le asignara
 * \param recuperados int Cant que se asignara
 * \param infectados int Cant que se le asignara
 * \param muertos int Cant que se le asignara
 * \return ePais* Puntero al nuevo pais
 *
 */
ePais* pais_newParams(int id,char*nombre,int recuperados,int infectados,int muertos);

/** \brief Borra al pais y hace que apunte a NULL
 *
 * \param Pais a borrar
 * \return void
 *
 */
void pais_delete(ePais* this);

/** \brief Settea id al pais pasado por parametro
 *
 * \param this Pais al que se le cargara el id pasado
 * \param id int Id a cargarle al pais
 * \return int 0 si se pudo settear y sino -1
 *
 */
int pais_setId(ePais* this,int id);

/** \brief Carga en el puntero a id pasado el id del pais pasado
 *
 * \param this ePais* Pais del que se obtendra el id
 * \param id int* Puntero en el que se cargara el id
 * \return int 0 se se pudo obtener el id y sino -1
 *
 */
int pais_getId(ePais* this,int* id);

/** \brief Settea nombre al pais pasado por parametro
 *
 * \param this Pais al que se le cargara el nombre pasado
 * \param nombre char* Nombre a cargarle al pais
 * \return int 0 si se pudo settear y sino -1
 *
 */
int pais_setNombre(ePais* this,char* nombre);

/** \brief Carga en el puntero a nombre pasado el nombre del pais pasado
 *
 * \param this ePais* Pais del que se obtendra el nombre
 * \param id int* Puntero en el que se cargara el nombre
 * \return int 0 se se pudo obtener el nombre y sino -1
 *
 */
int pais_getNombre(ePais* this,char* nombre);

/** \brief Settea la cantidad de recuperados al pais pasado
 *
 * \param this ePais* Pais al que se le asignara la cant de recuperados
 * \param recuperados int Cant de recuperados que se asignara al pais
 * \return int 0 si se pudo asignar y sino -1
 *
 */
int pais_setRecuperados(ePais* this,int recuperados);

/** \brief Carga en el puntero a recuperados pasado la cant de recuperados del pais pasado
 *
 * \param this ePais* Pais del que se obtendra la cant de recuperados
 * \param recuperados int* Puntero en el que se cargara la cant de recuperados
 * \return int 0 se se pudo obtener la cant de recuperados y sino -1
 *
 */
int pais_getRecuperados(ePais* this,int* recuperados);

/** \brief Settea la cantidad de infectados al pais pasado
 *
 * \param this ePais* Pais al que se le asignara la cant de infectados
 * \param infectados int Cant de infectados que se asignara al pais
 * \return int 0 si se pudo asignar y sino -1
 *
 */
int pais_setInfectados(ePais* this,int infectados);

/** \brief Carga en el puntero a infectados pasado la cant de infectados del pais pasado
 *
 * \param this ePais* Pais del que se obtendra la cant de infectados
 * \param infectados int* Puntero en el que se cargara la cant de infectados
 * \return int 0 se se pudo obtener la cant de infectados y sino -1
 *
 */
int pais_getInfectados(ePais* this,int* infectados);

/** \brief Settea la cantidad de muertos al pais pasado
 *
 * \param this ePais* Pais al que se le asignara la cant de muertos
 * \param muertos int Cant de muertos que se asignara al pais
 * \return int 0 si se pudo asignar y sino -1
 *
 */
int pais_setMuertos(ePais* this,int muertos);

/** \brief Carga en el puntero a muertos pasado la cant de muertos del pais pasado
 *
 * \param this ePais* Pais del que se obtendra la cant de muertos
 * \param muertos int* Puntero en el que se cargara la cant de muertos
 * \return int 0 se se pudo obtener la cant de muertos y sino -1
 *
 */
int pais_getMuertos(ePais* this,int* muertos);

/** \brief muestra un solo pais
 *
 * \param this ePais* Puntero al pais a mostrar
 * \return void
 *
 */
void mostrarPais(ePais* this);

/** \brief Asigna valores a los campos recuperados, muertos e infectados de un pais
 *
 * \param pais void* Puntero que contiene el pais a mostrar
 * \return void*
 *
 */
void* asignarValores(void* pais);

/** \brief Determina si un pais fue o no exitoso (menos de 5k muertos)
 *
 * \param pais void* Puntero al pais
 * \return int 1 si fue exitoso y sino 0
 *
 */
int fueExitoso(void* pais);

/** \brief Determina si un pais esta o no al horno (cant infectados triplica a la de recuperados)
 *
 * \param pais void* Puntero que contiene al pais
 * \return int 1 si fue exitoso y sino 0
 *
 */
int estaAlHorno(void* pais);

/** \brief Compara la cantidad de infectados entre 2 paises
 *
 * \param pais1 void* Pais a comparar
 * \param pais2 void* Pais a comparar
 * \return int 0 si la cant de infectados es igual, -1 si pais1 tiene menos que pais 2 y sino 1
 *
 */
int compararCantInfectados(void* pais1,void* pais2);
