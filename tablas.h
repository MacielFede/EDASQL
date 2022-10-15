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

#endif