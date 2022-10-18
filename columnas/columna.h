#ifndef COLUMNA_H
#define COLUMNA_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//columna.h
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#include "../datos/datos.h"

typedef struct nodo_columna * columna;

bool columnaVacia(columna col);
//Retorna true si la columna c esta vacia y false en caso contrario

char * nombreC(columna c);
//Retorna el nombre de la tabla indicada
//Pre: la columna debe existir

char * calificadorC(columna c);
//Retorna el calificador de una columna
//Pre: la columna debe != NULL

char * tipoDatoC(columna c);
//Retorna el tipo de dato de la columna dada
//Pre:la columna debe != NULL

bool mismoTipoDato(columna c, char *dato);
//Retorna true si el tipo de dato de la columna es igual al dato pasado, false en caso contrario
//Pre: la columna debe != NULL

datos listaDatos(columna c);
//Retorna el primer elemento de la lista de datos de la columna
//Pre: la columna debe != NULL

bool esPrimaryKey(columna c);
//Retorna true si la columna es primary key, false en caso contrario
//Pre: c debe ser != NULL

void insertIntoC(columna & c, char *valoresTupla);
//Chequea que las columnas existan y que una de ellas sea pk, para luego insertar los datos.
//Pre: la tabla t debe existir y debe tener al menos 1 columna

int deleteIndex(columna c, char *operador, char *valor);
//Dada una columna retorna el indice del primer valor que cumple con la condicion dada
//Retorna -1 en caso de que no haya valores que cumplan la condicion
//Pre: la columna debe != NULL

TipoRet deleteFromC(columna & c, char *operador, char *valor);
//Elimina de la columna dada el primer valor que cumplan la condicion
//Restaura el indice de cada dato para que no haya saltos entre indices
//Pre: la columna debe != NULL.

#endif