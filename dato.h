#ifndef DATO_H
#define DATO_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//datos.h
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.


typedef struct nodo_dato * dato;

bool seRepite(dato d, char *data);
//Retorna true si el dato pasado se repite en la lista, false en caso contrario
//Pre: el i pasado debe empezar en 0.
//Pos: el i resultante se usa para saber la posición de la tupla de esa primary key

void insertIntoD(dato & d, char *data);
//Inserta el dato pasado, en la columna indicada 
//Pre: Si la columna es la primaryKey de la tupla no debemos pasar un dato repetido.
//Pre: Si la columna es de calificador notEmpty no podemos pasarle EMPTY como dato.



#endif