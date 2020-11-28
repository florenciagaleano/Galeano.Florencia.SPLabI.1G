#include "LinkedList.h"
#include <stdio.h>

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#endif // PARSER_H_INCLUDED

/** \brief Parsea los datos de un archivo .csv(modo texto)
 *
 * \param LinkedList*pArray Lista en la que se agregaaran los datos parseados
 * \param FILE*pFile Archivo desde el cual se parsean los datos
 * \return int 0 si salio todo bien y sino -1
 *
 */
int parser_countriesFromTxt(LinkedList*pArray,FILE*pFile);
