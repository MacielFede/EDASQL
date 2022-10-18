// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
//tabla.c
// Modulo de Implementación de Base de Datos.

#include <iostream>
using namespace std;

#include <string.h>
#include "../define.h"
#include "tabla.h"
#include "tablas.h"

struct nodo_tablas{
     tabla t;
     tablas izq;
     tablas der;
};

bool encontreTS(tablas ts, char *nombre){
     if(ts == NULL)
          return false;
     else if(strcmp(nombre, nombreT(ts->t)) == 0)
          return true;
     else if(strcmp(nombre, nombreT(ts->t)) > 0)
          return encontreTS(ts->der, nombre);
     else
          return encontreTS(ts->izq, nombre);
}

tabla buscarTabla(tablas ts, char *nombre){
     if(ts == NULL)
          return NULL;
     else if(strcmp(nombre, nombreT(ts->t)) == 0)
          return ts->t;
     else if(strcmp(nombre, nombreT(ts->t)) > 0)
          return buscarTabla(ts->der, nombre);
     else
          return buscarTabla(ts->izq, nombre);
}

TipoRet insertIntoTS(tabla & t, char *columnasTupla, char *valoresTupla){
     unsigned int iter = 0;
     char *col[MAX_CANT_COL], *valores[MAX_CANT_COL];
     col[iter] = strtok(columnasTupla, ":");
     while(iter<MAX_CANT_COL && col[iter]!=NULL){
          iter++;
          col[iter] = strtok(NULL, ":");
     }
     iter = 0;
     valores[iter] = strtok(valoresTupla, ":");
     while(iter<MAX_CANT_COL && valores[iter]!=NULL){
          iter++;
          valores[iter] = strtok(NULL, ":");
     }
     return insertIntoT(t, col, valores);
}

TipoRet deleteFromTs(tabla & t, char *col, char *operador, char *valor){
     return deleteFromT(t, col, operador, valor);
}