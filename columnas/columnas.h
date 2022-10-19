#ifndef COLUMNAS_H
#define COLUMNAS_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//columna.h
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#include "columna.h"

typedef struct nodo_columnas * columnas;

bool encontreCS(columnas cs, char *nombre);
//Retorna true si encuentra una columna con el nombre dado

columna buscarColumna(columnas cs, char *nombre);
//Retorna la columna que coincide con ese nombre, NULL si no encuentra coincidencias

columnas revovinarCS(columnas cs);
//Devuelve la primer posicion de la lista de columnas
//Pre: la lista debe tener al menos 1 elemento

TipoRet insertIntoCS(columnas & cs, char *columnasTupla[], char *valoresTupla[]);
//Inserta en las columnas dadas los valores dados
//Pre: el puntero cs debe tener un puntero a la primer columna de la tabla

TipoRet deleteFromCS(columnas & cs, columna c, char *operador, char *valor);
//Busca en la columna pasada los valores que cumplen la condicion
//Pre: la lista cs debe ser un puntero a la primer posicion
//Pre: c debe != NULL



#endif