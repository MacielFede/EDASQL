// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
//tabla.c
// Modulo de Implementación de Base de Datos.

#include <iostream>
using namespace std;

#include <string.h>
#include "define.h"
#include "tabla.h"
#include "columnas.h"

struct nodo_tabla{
     columnas cs;
     char * nombre;
};

tabla crearTabla(){
     return NULL;
}

char * nombreT(tabla t){
     return t->nombre;
}

tabla insertarTabla(tabla t, char *nombreT){
     t = new(nodo_tabla);
     t->nombre = new char[MAX_NOMBRE];
     strcpy(t->nombre, nombreT);
     t->cs = NULL;
     return t;
}

TipoRet insertIntoT(tabla & t, char *columnasTupla[], char *valoresTupla[]){
     unsigned int iter = 0;
     bool primaryK = false;
     while(columnasTupla[iter] != NULL && !primaryK){
          if(esPrimaryKey(buscarColumna(t->cs, columnasTupla[iter]))) 
               primaryK = true;
          else
               iter++;
     }
     if(primaryK)
          return insertIntoCS(t->cs, columnasTupla, valoresTupla);
     else{
          cout << "Intentaste dejar la primary key en EMPTY o no indicaste una columna existente" << endl;
          return ERROR;
     }
}

TipoRet deleteFromT(tabla & t, char *condicionEliminar){
     // if(columnaVacia(t->cs)){ //Si no hay columnas tenemos un error
     //      cout << "La tabla indicada no tiene columnas"<<endl;
     //      return ERROR;
     // }else{
     //      char *col = new char[MAX_NOMBRE];
     //      char *operador = new char;
     //      char *condicion = new char[MAX_VALOR];
     //      col = strtok(condicionEliminar, "<>!=");
     //      operador = strtok(NULL, "abcdefghijklmnñopqrstuvwxyz");;//el primer char de condicion eliminar luego de haberle sacado la columna;
     //      condicion = strtok(NULL, " ");
     return ERROR;
}