#ifndef TABLAS_H
#define TABLAS_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
//tabla.h
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#include "tabla.h"

typedef struct nodo_tablas * tablas;

bool encontreTS(tablas ts, char *nombre);
//Retorna true si se encuentra una tabla con el nombre pasado

tabla buscarTabla(tablas ts, char *nombre);
//Retorna un puntero a la tabla que coincide con el nombre dado, NULL si no hay coincidencias

TipoRet insertIntoTS(tabla & t, char *columnasTupla, char *valoresTupla);
//Inserta en t las tuplas dadas.
//Pre: t debe != NULL

TipoRet deleteFromTS(tabla & t, char *col, char *operador, char *valor);
//Elimina de la tabla especificada las tuplas que cumplan con la condicion
//Pre: la tabla debe != NULL

void printdatatableTS(tablas ts, char *nombreTabla);
//Dada una lista de tablas imprime la informacion de la tabla indicada por su nombre
//Pre: la tabla indicada debe existir

void printMetadataTS(tabla t);
//Imprime la metadata de la tabla t

#endif
