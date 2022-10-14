#ifndef TABLA_H
#define TABLA_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
//tabla.h
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

typedef struct nodo_tabla * tabla;

tabla crearTabla();
//Crea la tabla vacía (retorna NULL)

char * nombreT(tabla t);
//Retorna el nombre de t

tabla insertarTabla(tabla t, char *nombreT);
//Crea la tabla t y le asigna un nombre, dejando las columnas en NULL;

TipoRet insertIntoT(tabla & t, char *columnasTupla, char *valoresTupla);
//Inserta la los valores indicados en las columnas indicadas de la tabla indicada (chequea que haya columnas existentes)
//Pre: la tabla t debe existir.

TipoRet deleteFromT(tabla & t, char *condicionEliminar);
//Elimina las tuplas que cumplan la condicion dada, si es que existe la columna y tabla indicadas.
//Pre: la tabla dada debe ser != NULL
//Pre: condicionEliminar debe respetar el formato establecido y usar los operadores <, >, !, =.

#endif