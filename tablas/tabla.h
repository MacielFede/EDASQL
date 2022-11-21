#ifndef TABLA_H
#define TABLA_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
//tabla.h
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

typedef struct nodo_tabla * tabla;

tabla createTableT(tabla t,char *nombreTabla);
//Crea la tabla sin columnas.

tabla dropTableT(tabla t);
//Elimina la tabla y todas sus tuplas

char * nombreT(tabla t);
//Retorna el nombre de t

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

TipoRet selectWereT(char *valor,char *operador,char *col,tabla t1,tabla &t2);
//Copia las columnas y las tuplas de t1 a t2 si cumplen la condición dada
//Pre: Se debe indicar una columna existente en t1 para chequear la condición

bool mismoEsquema(tabla t1, tabla t2);
//Retorna true si el esquema de t1 == t2
//Post: Si ambas tablas son nulas retorna false

tabla unionT(tabla t1, tabla t2, tabla t3);
//Copia todas las tuplas de las tablas t1 y t2 a t3
//Pre: t1 y t2 deben tener el mismo esquema

bool ColPertenece (tabla t1, char *Columnas);
// Retorna TRUE si todas las Columnas indicadas existen en la tabla t1, 
// Retorna FALSE en caso contrario
//Pre: La tabla t1 debe existir

tabla selecT (tabla t1, char* Columnas, tabla t2);
// Copia las Columnas indicadas de la tabla t1 a la tabla t2
//Pre: t1 y t2 deben existir

tabla intersecT (tabla t1,tabla t2, tabla t3);
// Copia a t3 unicamente las tuplas que existan en t1 y en t2
// Pre: t1, t2 y t3 deben existir.
#endif
