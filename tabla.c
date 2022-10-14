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
     columnas c;
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
     t->c = NULL;
     return t;
}

TipoRet insertIntoT(tabla & t, char *columnasTupla, char *valoresTupla){
     if(columnaVacia(t->c)){ //Si no hay columnas tenemos un error
          cout << "La tabla indicada no tiene columnas"<<endl;
          return ERROR;
     }else
          return insertIntoC(t->c, columnasTupla, valoresTupla);
}

TipoRet deleteFromT(tabla & t, char *condicionEliminar){
     if(columnaVacia(t->c)){ //Si no hay columnas tenemos un error
          cout << "La tabla indicada no tiene columnas"<<endl;
          return ERROR;
     }else{
          char *col = new char[MAX_NOMBRE];
          char *operador = new char;
          char *condicion = new char[MAX_VALOR];
          col = strtok(condicionEliminar, "<>!=");
          operador = strtok(NULL, "abcdefghijklmnñopqrstuvwxyz");;//el primer char de condicion eliminar luego de haberle sacado la columna;
          condicion = strtok(NULL, " ");
          return deleteFromC(t->c, col, operador, condicion);
     }
}