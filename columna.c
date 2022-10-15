// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//columna.c
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#include <iostream>
using namespace std;

#include "define.h"
#include <string.h>
#include "columna.h"
#include "datos.h"

struct nodo_columna{
     char * tipoDato;
     char * calificador;
     char * nombre;
     datos ds;
};

bool columnaVacia(columna col){
     return (col == NULL);
}

char * nombreC(columna c){
     return c->nombre;
}

char * calificadorC(columna c){
     return c->calificador;
}

char * tipoDatoC(columna c){
     return c->tipoDato;
}

bool mismoTipoDato(columna c, char *dato){
     return ((strcmp(tipoDatoC(c), "STRING") == 0 && atoi(dato) == 0) || (strcmp(tipoDatoC(c), "INTEGER") == 0 && atoi(dato) != 0));
}

datos listaDatos(columna c){
     return c->ds;
}

bool esPrimaryKey(columna c){
     return (strcmp(c->calificador , "PRIMARY_KEY") == 0);
}

void insertIntoC(columna & c, char *valorTupla){
     return insertIntoDS(c->ds, valorTupla);
}


TipoRet deleteFromC(columna & c, char *column, char *operador, char *condicion){
     return ERROR;
}

