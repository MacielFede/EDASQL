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

TipoRet insertIntoT(tabla & t, char *columnasTupla[], char *valoresTupla[]);
//Inserta la los valores indicados en las columnas indicadas de la tabla indicada (chequea que haya columnas existentes)
//Pre: la tabla t debe existir.

TipoRet deleteFromT(tabla & t, char *col, char *operador, char *valor);
//Elimina las tuplas que cumplan la condicion dada
//Pre: la tabla dada debe ser != NULL

TipoRet addColT (tabla &t, char *NombreCol, char *tipoCol, char *calificadorCol);
// Agrega a la tabla t una columna de Nombre NombreCol, tipo tipoCol y calificador calificadorCol
// Pre: La tabla t existe

TipoRet dropColT (tabla &t, char* NombreCol);
// Elimina de la tabla t la columna NombreCol.
// Pre: La tabla t existe


void printdatatableT(tabla t);
//Dada una tabla imprime toda la informacion contenida
//Pre: la tabla debe != NULL

void printTablesT(tabla t);
//Imprime el nombre de la tabla dada
//Pre:la tabla t debe ser != NULL

void printMetadataT(tabla t);
//Imprime la metadata de la tabla indicada

#endif
