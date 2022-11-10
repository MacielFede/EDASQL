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

datos revovinarDS(datos ds){
     while(ds->ant != NULL)
          ds = ds->ant;
     return ds;
}

bool seRepiteDato(datos ds, char *dato){
     if(ds == NULL)
          return false;
     else if(strcasecmp(infoDato(ds->d), dato) == 0)
          return true;
     else
          return seRepiteDato(ds->sig, dato);
}

int insertionIndDS(datos ds,char *valor, char *tipoD){
     int iter = 0;
     if(strcasecmp(tipoD, "STRING") == 0){
          while(ds!=NULL && strcmp(valor, infoDato(ds->d))  > 0){
               iter++;
               ds = ds->sig;
          }
     }else{
          while(ds!=NULL && atoi(valor) > atoi(infoDato(ds->d))){
               iter++;
               ds = ds->sig;
          }
     }
     return iter;
}

datos insertIntoDS(datos ds,const char *valorTupla,  int insertionIndex){
     if(ds == NULL){
          ds = new(nodo_datos);
          ds->sig = NULL;
          ds->ant = NULL;
          ds->d = insertIntoD(valorTupla, 0);
          return ds;
     }else{
          datos aux = new(nodo_datos), ant;
          aux->d = insertIntoD(valorTupla, insertionIndex);
          for ( int index = 0; index < insertionIndex; index++){
               ant = ds;
               ds = ds->sig;
          }
          if(insertionIndex == 0){
               aux->ant = NULL;
               aux->sig = ds;
               ds->ant = aux;
               ant = aux;
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
          while(ds != NULL){
               resetearIndice(ds->d, true);
               ds = ds->sig;
          }
          ant = revovinarDS(ant);
          return ant;
     }
}

int cuentaTuplasDs(datos ds){
	if (ds!=NULL && ds->d!=NULL){
          int max = indiceDato (ds-> d);
          int actual;
          datos iter=ds;
          while (iter != NULL){
               actual=indiceDato (iter->d);
               if (max < actual)
                    max = actual;
               iter=iter->sig;
          }
          return max;
     }
     else
          return 0;
}

datos llenaEmpty(int tups){
	datos iter = NULL;
	datos ds = NULL;
	for (int i=0; i<=tups; i++){
		datos aux = new (nodo_datos); 
		aux -> d = datoEmpty (i);
		aux -> ant = iter; 
		aux -> sig = NULL;
		if (i==0)
			ds = aux;
		else 
			aux->ant->sig=aux;
		iter = aux;
	}
	return ds;
}

datos suprDatos (datos ds){
	if (ds != NULL){
		while (ds != NULL){
			datos aux = ds;
			ds = ds -> sig;
			aux -> d = deleteFromD (ds -> d);
			delete aux;
		}
	}
	return ds;
}

int deleteIndexDS(datos ds, char *operador,char *valor, char *tipoDato,int indiceAnterior){
     if(ds != NULL){
          while(ds != NULL && !datoVacio(ds->d)){
               if(strcasecmp(valor, "EMPTY")){
                    if((strcmp(operador, "=") == 0 && strcmp(valor, infoDato(ds->d) ) == 0) || (strcmp(operador, "!") == 0 && strcmp(valor, infoDato(ds->d) ) != 0)){
                         //Si el el valor es igual a empty y el operador es =, O si el valor es distinto de empty y el operador es ! se cumple la condición
                         return indiceDato(ds->d);
                    }
               }
               if (strcmp(operador, "<") == 0){
                    if(strcasecmp(tipoDato, "STRING") == 0){
                         if(strcmp(valor, infoDato(ds->d) ) > 0)
                              return indiceDato(ds->d);
                    }else{
                         if(atoi(valor) > atoi(infoDato(ds->d))){
                              return indiceDato(ds->d);
                         }
                    }
               }else if(strcmp(operador, ">") == 0){
                    if(strcasecmp(tipoDato, "STRING") == 0){
                         if(strcmp(valor, infoDato(ds->d)) < 0)
                              return indiceDato(ds->d);
                    }else{
                         if(atoi(valor) < atoi(infoDato(ds->d))){
                              return indiceDato(ds->d);
                         }
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
     }
     return -1;
}

datos deleteFromDS(datos ds, int index){
     while(indiceDato(ds->d) < index)
          ds = ds->sig;
     datos aux;
     bool quieroRes = true;
     if(index == 0){
          if(ds->sig == NULL){
               ds->d = deleteFromD(ds->d);
               delete ds;
               return NULL;
          }else{
               aux = ds->sig;
               aux->ant = NULL;
          }
     }else if(ds->sig == NULL){
          aux = ds->ant;
          aux->sig = NULL;
          quieroRes = false;
     }else{
          aux = ds->sig;
          aux->ant = ds->ant;
          ds->ant->sig = aux;
     }
     if(quieroRes){
          while(aux->sig != NULL){
               resetearIndice(aux->d, false);
               aux = aux->sig;
          }
          resetearIndice(aux->d, false);
     }
     ds->d = deleteFromD(ds->d);
     delete ds;
     aux = revovinarDS(aux);
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
	return NULL;
}

void printdatatableDS(datos ds, int iter,bool &termine){
     while (ds != NULL && indiceDato(ds->d)<iter)
          ds = ds->sig;
     if(ds == NULL)
          termine = true;
     else
          cout<< infoDato(ds->d);
}

datos copiarTodasTuplasDS(datos base, datos copia){
     bool termine = false;
     while(base != NULL && !termine){
          if(base->ant == NULL && base->sig != NULL){
               //Estoy en el primer dato y hay mas de 1 dato
               copia = new(nodo_datos);
               copia->ant = NULL;
               copia->sig = new(nodo_datos);
               copia->sig->ant = copia;
          }else if(base->ant == NULL && base->sig == NULL){
               //Estoy en el primer dato y hay 1 dato
               copia = new(nodo_datos);
               copia->ant = NULL;
               copia->sig = NULL;
               termine = true;
          }else if(base->sig == NULL){
               //Estoy en el ultimo dato y ya copie todo los otros datos
               copia->sig = NULL;
               termine = true;
          }else{
               //Estoy en el medio
               copia->sig = new(nodo_datos);
               copia->sig->ant = copia;
          }
          copia->d = insertIntoD(infoDato(base->d), indiceDato(base->d));
          if(!termine){
               copia = copia->sig;
               base = base->sig;
          }
     }
     copia = revovinarDS(copia);
     return copia;
}

datos copiarValorTuplaDS(datos base,datos copia, int index){
     while(base != NULL && indiceDato(base->d) < index) //Voy hasta el valor que tengo que copiar
          base = base->sig;
     int i = 0;
     if(copia == NULL){
          copia = new(nodo_datos);
          copia->ant = NULL;
          copia->sig = NULL;
     }else{
          while(copia->sig != NULL){
           //Voy hasta el ultimo lugar para insertar en orden de llegada
               copia = copia->sig;
               i++;
          }
          copia->sig = new(nodo_datos);
          copia->sig->ant = copia; //Anclo el dato siguiente con el actual
          copia = copia->sig;
          copia->sig = NULL;
     }
     copia->d = insertIntoD(infoDato(base->d), index);
     while(i < indiceDato(copia->d))
          resetearIndice(copia->d, false);
     copia = revovinarDS(copia);
     return copia;
}

datos copiarTuplasConsecutivasDS(datos d1, datos d2){
     if(d2 == NULL || datoVacio(d2->d))
          d2 = copiarTodasTuplasDS(d1, d2);
     else{
          while(d2->sig != NULL)
               d2 = d2->sig;
          //Voy hasta el final de la lista y agrego todas las tuplas ahi
          d2->sig = copiarTodasTuplasDS(d1, d2->sig);
          d2->sig->ant = d2;
          datos aux = d2;
          int iter = indiceDato(d2->d);
          //Reseteo los indices de las tuplas nuevas para que no se pierdan datos
          while(aux!=NULL){
               while(iter>indiceDato(aux->d))
                    resetearIndice(aux->d, true);
               while(iter<indiceDato(aux->d))
                    resetearIndice(aux->d, false);
               iter++;
               aux = aux->sig;
          }
          d2 = revovinarDS(d2);
     }
     return d2;
}