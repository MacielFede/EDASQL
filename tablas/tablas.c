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

tablas createTableTS(tablas ts,char *nombreTabla){
     if(ts == NULL){
          ts = new(nodo_tablas);
          ts->t = createTableT(ts->t,nombreTabla);
          ts->der = NULL;
          ts->izq = NULL;
     }else if(strcasecmp(nombreTabla, nombreT(ts->t)) > 0)
          ts->der = createTableTS(ts->der, nombreTabla);
     else
          ts->izq = createTableTS(ts->izq, nombreTabla);
     return ts;
}

int max(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}

int profundidad(tablas ts){
	if (ts == NULL)
		return 0;
	else
		return 1 + max(profundidad(ts->izq), profundidad(ts->der));
}

tablas max_iz(tablas & ts){
	if (ts->der == NULL){
		tablas aux = ts;
		ts = ts->izq;
		return aux;
	}else
		return max_iz(ts->der);
}

tablas min_de(tablas & ts){
	if (ts->izq == NULL){
		tablas aux = ts;
		ts = ts->der;
		return aux;
	}else
		return min_de(ts->izq);
}

tablas dropTableTS(tablas ts,char *nombreTabla){
     if(strcmp(nombreTabla, nombreT(ts->t)) == 0){
          tablas aux;
          if(ts->izq == NULL && ts->der == NULL){
               ts->t = dropTableT(ts->t);
               delete ts;
               return NULL;
          }else if(ts->izq == NULL){
               aux = ts->der;
               ts-> t = dropTableT(ts->t);
               delete ts;
               return aux;
          }else if(ts->der == NULL){
               aux = ts->izq;
               ts-> t = dropTableT(ts->t);
               delete ts;
               return aux;
          }else{
               if (profundidad(ts->izq) > profundidad(ts->der))
				aux = max_iz(ts->izq);
			else
				aux = min_de(ts->der);
			aux->izq = ts->izq;
			aux->der = ts->der;
               ts-> t =dropTableT(ts->t);
			delete ts;
			return aux;
          }
     }
     else if(strcasecmp(nombreTabla, nombreT(ts->t)) > 0){
          ts->der = dropTableTS(ts->der, nombreTabla);
          return ts;
     }
     else{
          ts->izq = dropTableTS(ts->izq, nombreTabla);
          return ts;
     }
          
}

bool encontreTS(tablas ts, char *nombre){
     if(ts == NULL)
          return false;
     else if(strcasecmp(nombre, nombreT(ts->t)) == 0)
          return true;
     else if(strcasecmp(nombre, nombreT(ts->t)) > 0)
          return encontreTS(ts->der, nombre);
     else
          return encontreTS(ts->izq, nombre);
}

tabla buscarTabla(tablas ts, char *nombre){
     if(ts == NULL)
          return NULL;
     else if(strcasecmp(nombre, nombreT(ts->t)) == 0)
          return ts->t;
     else if(strcasecmp(nombre, nombreT(ts->t)) > 0)
          return buscarTabla(ts->der, nombre);
     else
          return buscarTabla(ts->izq, nombre);
}

TipoRet insertIntoTS(tabla & t, char *columnasTupla, char *valoresTupla){
     int iter = 0;
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

TipoRet deleteFromTS(tabla & t, char *col, char *operador, char *valor){
     return deleteFromT(t, col, operador, valor);
}

TipoRet addColTS (tablas & ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	if(ts!=NULL && strcmp(nombreTabla,nombreT(ts->t))==0){
          return addColT (ts->t, NombreCol, tipoCol, calificadorCol);
     }else if(ts!=NULL && strcmp(nombreTabla,nombreT(ts->t))>0){
          return addColTS(ts->der, nombreTabla, NombreCol, tipoCol, calificadorCol);
     }else if(ts!=NULL && strcmp(nombreTabla,nombreT(ts->t))<0){
          return addColTS(ts->izq, nombreTabla, NombreCol, tipoCol, calificadorCol);
     }else{ //No encontre la tabla
          cout << "No se encontro la tabla especificada" <<endl;
          return ERROR; 
     }
}

TipoRet dropColTS (tablas &ts, char* nombreTabla, char* NombreCol){
     if(ts!=NULL && strcmp(nombreTabla,nombreT(ts->t))==0){
          return dropColT (ts->t, NombreCol);
     }else if(ts!=NULL && strcmp(nombreTabla,nombreT(ts->t))>0){
          return dropColTS(ts->der, nombreTabla, NombreCol);
     }else if(ts!=NULL && strcmp(nombreTabla,nombreT(ts->t))<0){
          return dropColTS(ts->izq, nombreTabla, NombreCol);
     }else{ //No encontre la tabla
          cout << "No se encontro la tabla especificada" <<endl;
          return ERROR; 
     }
}

void printdatatableTS(tablas ts, char *nombreTabla){
     tabla aux = buscarTabla(ts, nombreTabla);
     printdatatableT(aux);
}

void printTablesTS(tablas ts){
     if(ts!=NULL){
          printTablesTS(ts->izq);
          printTablesT(ts->t);
          printTablesTS(ts->der);
     }
}

void printMetadataTS(tabla t){
	printMetadataT(t);
}

TipoRet selectWereTS(char *valor,char *operador,char *col,tabla t1, tabla &t2){
     return selectWereT(valor,operador,col,t1,t2);
}

TipoRet unionTS(tablas &ts,char *nombreTabla1,char *nombreTabla2,char *nombreTabla3){
	tabla t1 = buscarTabla(ts, nombreTabla1), t2 = buscarTabla(ts, nombreTabla2);
     if(mismoEsquema(t1, t2)){
          ts = createTableTS(ts, nombreTabla3);
          tabla t3 = buscarTabla(ts, nombreTabla3);
          t3 = unionT(t1,t2,t3);
          return OK;
     }else{
          cout<<"La tabla 1 y la tabla 2 tienen distintos esquemas"<<endl;
          return ERROR;
     }
}
