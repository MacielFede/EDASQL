#ifndef COLUMNAS_H
#define COLUMNAS_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//columna.h
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#include "columna.h"

typedef struct nodo_columnas * columnas;

columnas dropTableCS(columnas cs);
//Elimina todas la tuplas de una tabla
//Pre: cs != NULL

bool encontreCS(columnas cs, char *nombre);
//Retorna true si encuentra una columna con el nombre dado

columna buscarColumna(columnas cs, char *nombre);
//Retorna la columna que coincide con ese nombre, NULL si no encuentra coincidencias

columnas revovinarCS(columnas cs);
//Devuelve la primer posicion de la lista de columnas
//Pre: la lista debe tener al menos 1 elemento

int insertionInd(columna pk, char *valor);
//Retorna el indice donde se debe insertar el nuevo dato

bool tienePK(columnas cs);
//Retorna true si la tabla tiene primary key, false en caso contrario
//Pre: la tabla debe tener al menos una columna != NULL

TipoRet insertIntoCS(columnas & cs, char *columnasTupla[], char *valoresTupla[],  int insertionIndex);
//Inserta en las columnas dadas los valores dados
//Pre: el puntero cs debe tener un puntero a la primer columna de la tabla

TipoRet deleteFromCS(columnas & cs, columna c, char *operador, char *valor);
//Busca en la columna pasada los valores que cumplen la condicion
//Pre: la lista cs debe ser un puntero a la primer posicion
//Pre: c debe != NULL

columnas deleteAll(columnas cs);
//Elimina todas las tuplas de una columna
//Pre: la lista cs debe ser un puntero a la primer posicion

int cantidadTuplas (columnas cs);
// Retorna la cantidad de tuplas que tiene la tabla.
// Pre: cs apunta a la primer Columna.

TipoRet addColCS (columnas & cs, char *NombreCol, char *tipoCol, char *calificadorCol);
// Agrega a las columnas cs, una nueva columna al final de nombre nombreCol,
// si ésta no existe. Si la tabla tiene tuplas el nuevo campo tendrá el valor EMPTY en cada tupla. Por lo
// tanto, en el caso de que la tabla tenga tuplas, no es válido que se agregue un calificador distinto de ANY.
// Tampoco es válido que calificadorCol sea PRIMARY KEY si existe ya una columna con dicho calificador en la
// tabla nombreTabla.

TipoRet dropColCS (columnas &cs, char* NombreCol);
// Elimina de las columnas cs la columna NombreCol.

void printdatatableCS(columnas cs);
//Imprime la informacion de las columnas de la tabla si es que hay informacion para imprimir

void printNombresC(columnas cs, columna pk);
//Imprime los nombres de las columnas, primero imprimiendo la columna pk
//Pre: pk debe ser != NULL y pertenecer a cs

void printMetadataCS(columnas cs);
//Imprime la metadata de cada columna

columnas copiarColumnas(columnas cs);
//Copia la metadata de la lista de columnas dada a otra lista creada desde 0
//Retorna la copia

columnas copiarDatos(columnas cs1,columna base,columnas cs2, char *valor,char *operador);
//Buscar las tuplas que cumplen la condicion dada en la columna base y copia los datos de cs1 a cs2
//Pre: base debe pertenecer a cs1

columnas copiarTodasTuplas(columnas cs1,columnas cs2);
//Copia todas las tuplas de la lista de columnas cs1 a cs2
//Pre: cs2 ya debe tener todas las columnas(y su metadata) de la cs1

bool mismoEsquemaCS(columnas c1, columnas c2);
//Retorna true si la lista de columnas c1 tiene el mismo esquema que la lista de columnas c2

columnas copiarTuplasConsecutivas(columnas c1, columnas c2, columnas c3);
//Copia las tuplas de la lista de columnas c1 a c3 y luego de c2 a c3

columnas selectCS (columnas c, char *nombre);
// Retorna las columnas que sus solicitadas.
// Pre: Las columnas deben existir

columnas intersecCS (columnas cs1, columnas cs2);
// Copia a cs3 unicamente las tuplas que existan en cs1 y en cs2
// Pre: cs1 y cs2 deben existir.


#endif
