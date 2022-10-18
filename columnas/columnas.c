// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//columna.c
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#include <iostream>
using namespace std;

#include <string.h>
#include "../define.h"
#include "columna.h"
#include "columnas.h"

struct nodo_columnas{
     columna c;
     columnas sig;
     columnas ant;
};

bool encontreCS(columnas cs, char *nombre){
     if(cs == NULL)
          return false;
     else if(strcmp(nombre, nombreC(cs->c)) == 0)
          return true;
     else
          return encontreCS(cs->sig, nombre);
}

columna buscarColumna(columnas cs, char *nombre){
     if(cs == NULL)
          return NULL;
     else if(strcmp(nombre, nombreC(cs->c)) == 0)
          return cs->c;
     else 
          return buscarColumna(cs->sig, nombre);
}

columnas revovinarCS(columnas cs){
     while(cs->ant != NULL)
          cs = cs->ant;
     return cs;
}

TipoRet insertIntoCS(columnas & cs, char *columnasTupla[], char *valoresTupla[]){
     unsigned int iter;
     while(cs != NULL){
          iter = 0;
          while(columnasTupla[iter] != NULL && strcmp(nombreC(cs->c), columnasTupla[iter]) != 0)
               iter++;
          if(columnasTupla[iter] != NULL){ //Encontre la columna
               if(esPrimaryKey(cs->c) &&  mismoTipoDato(cs->c, valoresTupla[iter]) && !seRepiteDato(listaDatos(cs->c), valoresTupla[iter]) ){ 
                    //Chequeamos que no se repita el dato si es primary key, que sea el mismo tipo de dato el que vamos a insertar
                    insertIntoC(cs->c, valoresTupla[iter]);
               }else if(esPrimaryKey(cs->c) && (strcasecmp(valoresTupla[iter], "EMPTY") == 0 || seRepiteDato(listaDatos(cs->c), valoresTupla[iter]))){
                    cout << "El dato de la primary key se repite o intentaste dejarlo vacio" << endl;
                    return ERROR;
               }else if(!mismoTipoDato(cs->c, valoresTupla[iter])){
                    cout << "El tipo de dato de la columna "<< nombreC(cs->c) <<" es distinto al del dato pasado" << endl;
                    return ERROR;
               }else if(strcasecmp(valoresTupla[iter], "EMPTY") == 0 && strcasecmp(calificadorC(cs->c), "NOT_EMPTY") == 0){
                    cout << "La columna " << nombreC(cs->c) << " no acepta valor empty" << endl;
                    return ERROR;
               }else
                    insertIntoC(cs->c, valoresTupla[iter]);
          }else{
          //Si no encuentro la columna quiere decir que le tengo que poner un valor empty
               if(strcasecmp(calificadorC(cs->c), "NOT_EMPTY") == 0){
                    cout << "La columna " << nombreC(cs->c) << " no acepta valor empty" << endl;
                    return ERROR;
               }else
                    insertIntoC(cs->c, "EMPTY");
          }
          cs = cs->sig;
     }
     cs = revovinarCS(cs);
     return OK;
}

TipoRet deleteFromCS(columnas cs, columna c, char *operador, char *valor){
     if(strcmp(valor, "") == 0 || (strcasecmp(valor, "EMPTY") == 0 && strcasecmp(calificadorC(c), "NOT_EMPTY") == 0)){
          //Se borran todas las tuplas
          //cs = deleteAll();
     }else if(strcasecmp(valor, "EMPTY") == 0 && (strcmp(operador, "<") == 0 || strcmp(operador, ">") == 0)){
          //No hago nada
     }else{
          //Debo verificar en la columna si cada valor cumple o no la condicion
          int index = deleteIndex(c, operador, valor);
          while(index != -1){
               while(cs != NULL){
                    //cs->c = deleteFromC();
                    cs = cs->sig;
               }
               cs = revovinarCS(cs);
               index = deleteIndex(c, operador, valor);
          }
     }
          return OK;
}