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

void insertIntoDS(datos & ds, char *valorTupla);
//Inserta el dato pasado en la lista de datos
//Pre: ds debe ser un puntero al primer elemento de la lista de datos

int deleteIndexDS(datos ds, char *operador,char *valor, char *tipoDato);
//Retorna el index del primer dato que cumple la condicion

#endif