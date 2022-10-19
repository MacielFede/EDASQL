// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//columna.c
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#include <iostream>
using namespace std;

#include "../define.h"
#include <string.h>
#include "columna.h"
#include "../datos/datos.h"

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
     return ((strcasecmp(tipoDatoC(c), "STRING") == 0 && atoi(dato) == 0) || (strcasecmp(tipoDatoC(c), "INTEGER") == 0 && atoi(dato) != 0));
}

datos listaDatos(columna c){
     return c->ds;
}

bool esPrimaryKey(columna c){
     return (strcasecmp(c->calificador , "PRIMARY_KEY") == 0);
}

int insertionIndC(columna pk, char *valor){
     if(pk->ds == NULL)
          return 0;
     else
          return insertionIndDS(pk->ds, valor, pk->tipoDato);
}

void insertIntoC(columna & c, char *valorTupla, unsigned int insertionIndex){
     c->ds = insertIntoDS(c->ds, valorTupla, insertionIndex);
}

int deleteIndex(columna c, char *operador, char *valor){
     return deleteIndexDS(c->ds, operador, valor, c->tipoDato);
}

columna deleteFromC(columna c, int index){
     c->ds = deleteFromDS(c->ds, index);
     return c;
}

columna deleteAllC(columna c){
	c->ds = deleteAllDS(c->ds);
	delete c;
	return c;
}


