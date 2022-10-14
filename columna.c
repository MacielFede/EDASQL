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
     datos d;
};

bool columnaVacia(columna col){
     return (col == NULL);
}

TipoRet insertIntoC(columna & c, char *columnasTupla, char *valoresTupla){
     //Ya se verifico que existan tablas
     unsigned int iter=0, x;
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
     columna aux = c;
     bool primaryKey = false; //Este bool indica si en las columnas a cambiar esta la pk
     x = iter; //me guardo iter para reiniciarlo en la iteracion.
     while(aux != NULL && !primaryKey){
          while( iter > 0 && col[iter-1] != NULL && !primaryKey){ //iter va a quedar en una posicion donde col va a ser null, por eso usamos iter-1
               if(strcmp(aux->nombre, col[iter-1])==0)
                    if(strcmp(aux->calificador,"PRIMARY_KEY") == 0){
                         if(seRepite(aux->d, valores[iter-1])){
                              cout<<"Ya existe ese dato en la columna PRIMARY KEY"<< endl;
                              return ERROR;
                         }
                         primaryKey = true;
                    }
               iter--;
          }
          iter=x;
          aux = aux->sig;
     }
     if(aux == NULL){ //Si no se indica ningún nombre de columnas existentes hay error y si no se indica la columna de la pk también hay error
          cout << "No existe ninguna de las columnas indicadas o intentaste dejar la primary key en EMPTY"<<endl;
          return ERROR;
     }else{
          aux = c;
          char empty[] = "EMPTY";
          while(aux != NULL){
               x = 0;
               while(col[x] != NULL && strcmp(aux->nombre, col[x]) != 0)
                    x++;
               if(col[x] != NULL){ //Significa que encontré la columna
                    insertIntoD(aux->d, valores[x]);
               }else{//Significa que a la columna tengo que agregarle el valor empty
                    if(strcmp(aux->calificador, "NOT_EMPTY") != 0)
                         insertIntoD(aux->d, empty);
                    else{
                         cout<<"Intentaste dejar una columna en EMPTY cuando es de tipo notEmpty"<<endl;
                         return ERROR;
                    }
               }
               aux = aux->sig;
          }
          return OK;
     }
}


TipoRet deleteFromC(columna & c, char *column, char *operador, char *condicion){
     return ERROR;
}

