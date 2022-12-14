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

tablas createTableTS(tablas ts, char *nombreTabla);
//Crea la tabla con el nombre indicado.

tablas dropTableTS(tablas ts,char *nombreTabla);
//Elimina de la base de datos la tabla con todos sus datos
//Pre:La tabla debe existir en la base de datos

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

void printTablesTS(tablas ts);
//Imprime los nombres de las tablas existentes en la base de datos

void printMetadataTS(tabla t);
//Imprime la metadata de la tabla t

TipoRet addColTS (tablas & ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
// Agrega a la tabla de nombre nombreTabla, si ésta existe, una nueva columna al final de nombre nombreCol,
// si ésta no existe. Si la tabla tiene tuplas el nuevo campo tendrá el valor EMPTY en cada tupla. Por lo
// tanto, en el caso de que la tabla tenga tuplas, no es válido que se agregue un calificador distinto de ANY.
// Tampoco es válido que calificadorCol sea PRIMARY KEY si existe ya una columna con dicho calificador en la
// tabla nombreTabla.

TipoRet dropColTS (tablas & ts, char* nombreTabla, char* NombreCol);
// Elimina de la tabla nombreTabla, si ésta existe, la columna NombreCol

TipoRet selectWereTS(char *valor,char *operador,char *col,tabla t1, tabla &t2);
//Dada 2 tablas, copia las tuplas de t1 a t2 dada una condición. Al ya estar ordenada t1, t2 queda ordenada
//Pre: t1 y t2 != NULL

TipoRet unionTS(tablas &ts, char *nombreTabla1, char *nombreTabla2, char *nombreTabla3);
//Dadas 2 tablas, copia las tuplas de la tabla 1 y la tabla 2 en la nueva tabla 3
//Pre: las tablas 1 y 2 deben existir, pero la 3 no.

TipoRet selecTS(tablas &ts, char *Tabla1, char *Columnas, char *Tabla2);
//Copia las columnas indicadas en Columnas de la Tabla 1 y a la nueva Tabla 2
//Pre: las tabla 1 debe existir, pero la 2 no.

TipoRet intersecTS(tablas &ts, char * Tabla1, char * Tabla2, char * Tabla3);
//Crea Tabla 3 y le copia las tuplas que existan en Tabla 1 y tambien existan en la Tabla 2

#endif
