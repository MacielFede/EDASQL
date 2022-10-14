#ifndef COLUMNA_H
#define COLUMNA_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//columna.h
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.


typedef struct nodo_columna * columna;

bool columnaVacia(columna col);
//Retorna true si la columna c esta vacia y false en caso contrario

TipoRet insertIntoC(columna & c, char *columnasTupla, char *valoresTupla);
//Chequea que las columnas existan y que una de ellas sea pk, para luego insertar los datos.
//Pre: la tabla t debe existir y debe tener al menos 1 columna

TipoRet deleteFromC(columna & c, char *column, char *operador, char *condicion);
//Elimina de la columna dada las tuplas que cumplan la condicion
//Pre: la columna debe poder existir.

#endif