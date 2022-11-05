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

void insertIntoC(columna & c, const char *valorTupla,  int insertionIndex){
     c->ds = insertIntoDS(c->ds, valorTupla, insertionIndex);
}

int cuentaTuplas(columna col){
	return cuentaTuplasDs(col->ds);
}

columna nuevaCol(int tups,char *NombreCol, char *tipoCol, char *calificadorCol){
	columna col = new (nodo_columna);
     col->calificador = new(char[MAX_NOMBRE]);
     col->tipoDato = new(char[MAX_NOMBRE]);
     col->nombre = new(char[MAX_NOMBRE]);
	strcpy(col -> tipoDato, tipoCol);
	strcpy(col -> calificador, calificadorCol);
	strcpy(col -> nombre, NombreCol);
	if (tups>0)
		col -> ds = llenaEmpty(tups);
     else
          col -> ds = NULL;
	return col;
}

columna dropColC (columna c){
	if (cuentaTuplasDs(c->ds)>0)
		c -> ds = suprDatos (c->ds);
     delete c->calificador;
     delete c->tipoDato;
     delete c->nombre;
	delete c;
	return NULL;
}

int deleteIndex(columna c, char *operador, char *valor, int indiceAnterior){
     return deleteIndexDS(c->ds, operador, valor, c->tipoDato, indiceAnterior);
}

columna deleteFromC(columna c, int index){
     c->ds = deleteFromDS(c->ds, index);
     return c;
}

columna deleteAllC(columna c){
	c->ds = deleteAllDS(c->ds);
	return c;
}

void printdatatableC(columna c, int iter,bool &termine){
     if(c->ds == NULL){
          cout << "La tabla no tiene tuplas"<<endl;
          termine = true;
     }
     else
          printdatatableDS(c->ds, iter, termine);
}

columna copiarTodasTuplasC(columna base, columna copia){
     copia->ds = copiarTodasTuplasDS(base->ds, copia->ds);
     return copia;
}

columna copiarValorTupla(columna base ,columna copia, int index){
     copia->ds = copiarValorTuplaDS(base->ds, copia->ds, index);
     return copia;
}