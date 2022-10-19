// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//datos.c
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#include <iostream>
using namespace std;

#include "../define.h"
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
     else if(strcasecmp(infoDato(ds->d), dato) == 0)
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

int deleteIndexDS(datos ds, char *operador,char *valor, char *tipoDato){
     if(ds == NULL || datoVacio(ds->d)){
          return -1;
     }else{
          while(ds != NULL){
               if(strcmp(operador, "<") == 0){
                    if(strcasecmp(tipoDato, "STRING") == 0){
                         if(strcmp(valor, infoDato(ds->d) ) > 1)
                              return indiceDato(ds->d);
                    }else{
                         if(atoi(valor) > atoi(infoDato(ds->d)))
                              return indiceDato(ds->d);
                    }
               }else if(strcmp(operador, ">") == 0){
                    if(strcasecmp(tipoDato, "STRING") == 0){
                         if(strcmp(valor, infoDato(ds->d)) < 1)
                              return indiceDato(ds->d);
                    }else{
                         if(atoi(valor) < atoi(infoDato(ds->d)))
                              return indiceDato(ds->d);
                    }
               }else if(strcmp(operador, "=") == 0){
                    if(strcasecmp(tipoDato, "STRING") == 0){
                         if(strcmp(valor, infoDato(ds->d))==0)
                              return indiceDato(ds->d);
                    }else{
                         if(atoi(valor) == atoi(infoDato(ds->d)))
                              return indiceDato(ds->d);
                    }
               }else{
                    //Operador es !
                    if(strcasecmp(tipoDato, "STRING") == 0){
                         if(strcmp(valor, infoDato(ds->d))  != 0)
                              return indiceDato(ds->d);
                    }else{
                         if(atoi(valor) != atoi(infoDato(ds->d)))
                              return indiceDato(ds->d);
                    }
               }
               ds = ds->sig;
          }
          return -1;
     }
}

datos deleteFromDS(datos ds, int index){
     while(indiceDato(ds->d) < index)
          ds = ds->sig;
     datos ant = ds->ant;
     ant->sig = ds->sig;
     ds->sig->ant = ant;
     delete ds;
     do{
          ant = ant->sig;
          resetearIndice(ant->d);
     }while(ant->sig != NULL);
     while(ant->ant != NULL)
          ant = ant->ant;
     return ant;
}