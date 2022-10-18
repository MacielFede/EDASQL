#ifndef DATO_H
#define DATO_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//datos.h
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.


typedef struct nodo_dato * dato;

char * infoDato(dato d);
//Retorna la informacion guardada en d
//Pre: el dato debe != NULL

int indiceDato(dato d);
//Retorna el indice de un dato
//Pre: el dato debe != NULL

dato insertIntoD(char *data, unsigned int index);
//Inserta el dato pasado
//Pre: Si la columna es la primaryKey de la tupla no debemos pasar un dato repetido.
//Pre: Si la columna es de calificador notEmpty no podemos pasarle EMPTY como dato.

bool datoVacio(dato d);
//Retorna true si el dato es vacio, false en caso contrario


#endif