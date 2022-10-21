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

int insertionIndDS(datos ds,char *valor, char *tipoD){
     unsigned int iter = 0;
     if(strcasecmp(tipoD, "STRING") == 0){
          while(!datoVacio(ds->d) && strcmp(valor, infoDato(ds->d))  > 0){
               iter++;
               ds = ds->sig;
          }
     }else{
          while(!datoVacio(ds->d) && atoi(valor) > atoi(infoDato(ds->d))){
               iter++;
               ds = ds->sig;
          }
     }
          return iter;
}

datos insertIntoDS(datos ds,const char *valorTupla, unsigned int insertionIndex){
     if(ds == NULL){
          ds = new(nodo_datos);
          ds->sig = NULL;
          ds->ant = NULL;
          ds->d = insertIntoD(valorTupla, 0);
          return ds;
     }else{
          datos aux = new(nodo_datos), ant;
          aux->d = insertIntoD(valorTupla, insertionIndex);
          for (unsigned int index = 0; index < insertionIndex; index++){
               ant = ds;
               ds = ds->sig;
          }
          if(insertionIndex == 0){
               aux->ant = NULL;
               aux->sig = ds;
               ds->ant = aux;
               return aux;
          }else if(ds == NULL){
               ant->sig = aux;
               aux->sig = NULL;
               aux->ant = ant;
          }else{
               ant->sig = aux;
               ds->ant = aux;
               aux->ant = ant;
               aux->sig = ds;
          }
          if(ds != NULL){
               do{
                    resetearIndice(ds->d, true);
                    if(ds->sig != NULL)
                         ds = ds->sig;
               }while(ds->sig != NULL);
          }
          while(ant->ant != NULL)
               ant = ant->ant;
          return ant;
     }
}

int deleteIndexDS(datos ds, char *operador,char *valor, char *tipoDato){
     if(ds == NULL || datoVacio(ds->d)){
          return -1;
     }else{
          while(ds != NULL){
               if(strcmp(operador, "<") == 0){
                    if(strcasecmp(tipoDato, "STRING") == 0){
                         if(strcmp(valor, infoDato(ds->d) ) > 0)
                              return indiceDato(ds->d);
                    }else{
                         if(atoi(valor) > atoi(infoDato(ds->d)))
                              return indiceDato(ds->d);
                    }
               }else if(strcmp(operador, ">") == 0){
                    if(strcasecmp(tipoDato, "STRING") == 0){
                         if(strcmp(valor, infoDato(ds->d)) < 0)
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
     datos aux;
     if(index == 0){
          aux = ds->sig;
          aux->ant = NULL;
     }else if(ds->sig == NULL){
          aux = ds->ant;
          aux->sig = NULL;
     }else{
          aux = ds->sig;
          aux->ant = ds->ant;
          ds->ant->sig = aux;
     }
     if(ds->sig !=NULL){
          do{
               resetearIndice(aux->d, false);
               if(aux->sig != NULL)
                    aux = aux->sig;
          }while(aux->sig != NULL);
     }
     while(aux->ant != NULL)
          aux = aux->ant;
     ds->d = deleteFromD(ds->d);
     delete ds;
     return aux;
}


datos deleteAllDS(datos ds){
	if( ds != NULL){
		while(ds!= NULL){
			datos aux = ds;
			ds = ds->sig;
			aux->d = deleteFromD(aux->d);
			delete aux;
		}
	}
	return ds;
}

void printdatatableDS(datos ds, unsigned int iter,bool &termine){
     unsigned int aux = 0;
     while (ds != NULL && aux<iter){
          ds = ds->sig;
          aux++;
     }
     if(ds == NULL)
          termine = true;
     else
          cout<< infoDato(ds->d);
}
