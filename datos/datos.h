#ifndef DATOS_H
#define DATOS_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//datos.h
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.


typedef struct nodo_datos * datos;

bool seRepiteDato(datos ds, char *dato);
//Retorna true si se repite el dato pasado en la columna c, false en caso contrario

int insertionIndDS(datos ds,char *valor, char *tipoD);
//Retorna el indice donde se va a insertar la nueva tupla
//Pre: ds debe ser un puntero a la primer posicion de la lista.

datos insertIntoDS(datos ds, char *valorTupla, unsigned int insertionIndex);
//Inserta el dato pasado en la lista de datos
//Pre: ds debe ser un puntero al primer elemento de la lista de datos

int deleteIndexDS(datos ds, char *operador,char *valor, char *tipoDato);
//Retorna el index del primer dato que cumple la condicion

datos deleteFromDS(datos ds, int index);
//Elimina de la lista de datos aquel con el index establecido
//Pre: ds debe != NULL y su cantidad de datos >= index

datos deleteAllDS(datos ds);
//Elimina todos los datos de la columna

#endif
