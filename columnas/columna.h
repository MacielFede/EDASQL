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

int insertionIndC(columna pk, char *valor);
//Chequea que la columna tenga un dato para retornar el indice de insercion de un nuevo dato
//Pre: pk debe ser la primary key de la tabla

void insertIntoC(columna & c, const char *valoresTupla, unsigned int insertionIndex);
//Chequea que las columnas existan y que una de ellas sea pk, para luego insertar los datos.
//Pre: la tabla t debe existir y debe tener al menos 1 columna

int cuentaTuplas(columna col);
//Retorna la cantidad de tuplas de la columna

columna nuevaCol(int tups, char *NombreCol, char *tipoCol, char *calificadorCol);
//Crea una columna nueva

columna dropColC (columna c);
// Elimina la Columna c y libera la memoria asociada.

int deleteIndex(columna c, char *operador, char *valor, int indiceAnterior);
//Dada una columna retorna el indice del primer valor que cumple con la condicion dada
//Retorna -1 en caso de que no haya valores que cumplan la condicion
//Pre: la columna debe != NULL

columna deleteFromC(columna c, int index);
//Elimina de la columna dada el primer valor que cumplan la condicion
//Restaura el indice de cada dato para que no haya saltos entre indices
//Pre: la columna debe != NULL.

columna deleteAllC(columna c);
//Elimina la columna y todos sus datos

void printdatatableC(columna c,unsigned int iter,bool &termine);
//Imprime el dato de la columna en esa posicion, si no hay datos imprime un mensaje

columna copiarTodasTuplasC(columna base, columna copia);
//Copia todos los datos de la columna base a copia
//Pre: base != NULL

columna copiarValorTupla(columna base ,columna copia,unsigned int index);
//Copia el valor en la posicion index de la columna base, a la columna copia

#endif
