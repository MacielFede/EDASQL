// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//datos.c
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#include <iostream>
using namespace std;

#include "define.h"
#include "dato.h"
#include <string.h>
#include "datos.h"

struct nodo_datos{
     dato d;
     datos sig;
     datos ant;
};

bool seRepiteDato(datos ds, char *dato){
     if(ds == NULL)
          return false;
     else if(strcmp(infoDato(ds->d), dato) == 0)
          return true;
     else
          return seRepiteDato(ds->sig, dato);
}

void insertIntoDS(datos & ds, char *valorTupla){
     if(ds == NULL){
          ds = new(nodo_datos);
          ds->sig = NULL;
          ds->ant = NULL;
          ds->d = insertIntoD(valorTupla, 0);
     }else{
          datos ant;
          unsigned int index = 0;
          while(ds != NULL){
               ant = ds;
               ds = ds->sig;
               index++;
          }
          ds = new(nodo_datos);
          ds->sig = NULL;
          ds->ant = ant;
          ant->sig = ds;
          ds->d = insertIntoD(valorTupla, index);
     }
}