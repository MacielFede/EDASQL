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

struct nodo_dato{
     char * info;
     int indice; //Esto es para saber en que posición de la lista esta la primary key del dato (osea la posición de la tupla)
};

bool seRepite(dato d, char *data){
     if(d==NULL)
          return false;
     else if(strcmp(d->info, data) != 0)
          return seRepite(d->sig, data);
     else
          return true;
}

void insertIntoD(dato & d, char *data){
     dato ant;
     int iter = 0;
     while(d != NULL){
          ant = d;
          d = d->sig;
          iter++;
     }
     d = new(nodo_dato);
     d->info = data;
     d->sig = NULL;
     d->indice = iter;
     if(iter == 0){
          d->ant = NULL;
          delete ant;
     }else{
          d->ant = ant;
          ant->sig = d;
          while(d->ant != NULL)
               d = d->ant;
     }
}