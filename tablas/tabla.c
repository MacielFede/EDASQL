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
#include "../columnas/columnas.h"

struct nodo_tabla{
     columnas cs;
     char * nombre;
};

tabla createTableT(tabla t,char *nombreTabla){
     t = new(nodo_tabla);
     t->nombre = new(char[MAX_NOMBRE]);
     strcpy(t->nombre, nombreTabla);
     t->cs = NULL;
     return t;
}

tabla dropTableT(tabla t){
     delete t->nombre;
     if(t->cs != NULL)
          t->cs = dropTableCS(t->cs);
     delete t;
     return t;
}

char * nombreT(tabla t){
     return t->nombre;
}

TipoRet insertIntoT(tabla & t, char *columnasTupla[], char *valoresTupla[]){
     int iter = 0;
     bool mePasanPk = false;
     if(tienePK(t->cs)){
          int pkIndex;
          while(columnasTupla[iter] != NULL && !mePasanPk){
               if(esPrimaryKey(buscarColumna(t->cs, columnasTupla[iter]))){
                    mePasanPk = true;
                    columna pk = buscarColumna(t->cs, columnasTupla[iter]);
                    pkIndex = insertionInd(pk, valoresTupla[iter]);
               }else
                    iter++;
          }
          if(mePasanPk)
               return insertIntoCS(t->cs, columnasTupla, valoresTupla, pkIndex);
          else{
               cout << "Intentaste dejar la primary key en EMPTY" << endl;
               return ERROR;
          }
     }else{
          //Si no tengo primary key inserto en el primer lugar
          //mePasanPk lo uso para saber si me pasan una columna valida
          while(columnasTupla[iter] != NULL && !mePasanPk){
               if(buscarColumna(t->cs, columnasTupla[iter]) != NULL){
                    mePasanPk = true;
               }else
                    iter++;
          }
          if(mePasanPk)
               return insertIntoCS(t->cs, columnasTupla, valoresTupla, 0);
          else{
               cout << "No ingresaste ninguna columna existente en la tabla" << endl;
               return ERROR;
          }
     }
}

TipoRet deleteFromT(tabla & t, char *col, char *operador, char *valor){
     if(!encontreCS(t->cs, col)){
          cout << "La columna indicada no existe" << endl;
          return ERROR;
     }else{
          columna aux = buscarColumna(t->cs, col);
          return deleteFromCS(t->cs , aux, operador, valor);
     }
}

TipoRet addColT (tabla &t, char *NombreCol, char *tipoCol, char *calificadorCol){
	return addColCS (t->cs, NombreCol, tipoCol, calificadorCol);
}

TipoRet dropColT (tabla &t, char* NombreCol){
	return dropColCS (t->cs,NombreCol);
}

void printdatatableT(tabla t){
     cout<< t->nombre <<endl;
     printdatatableCS(t->cs);
}

void printTablesT(tabla t){
     cout<< t->nombre << "; ";
}

void printMetadataT(tabla t){
	cout << "Tabla: " << t->nombre << endl;
	printMetadataCS(t->cs);
}

TipoRet selectWereT(char *valor,char *operador,char *col,tabla t1,tabla &t2){
     if(!encontreCS(t1->cs, col)){
          cout<<"La columna indicada no existe en la tabla indicada"<<endl;
          return ERROR;
     }else{
          //La columna indicada si existe en la tabla
          t2->cs = copiarColumnas(t1->cs);
          columna aux = buscarColumna(t1->cs, col);
          t2->cs = copiarDatos(t1->cs, aux, t2->cs, valor, operador);
          return OK;
     }
}

bool mismoEsquema(tabla t1, tabla t2){
     if(t1 == NULL || t2 == NULL)
          return false;
     else
          return mismoEsquemaCS(t1->cs, t2->cs);
}

tabla unionT(tabla t1, tabla t2, tabla t3){
     t3->cs = copiarColumnas(t1->cs);
     t3->cs = copiarTuplasConsecutivas(t1->cs, t2->cs, t3->cs);
     return t3;
}

bool ColPertenece (tabla t1, char *Columnas){
	char * col = strtok(Columnas, ":");
	if (encontreCS(t1->cs, col)){
		do{
               col = strtok (NULL, ":");
		}while (col != NULL && encontreCS(t1->cs, col));
		if (col == NULL) // Sale del while xq todas las columnas indicadas pertenecen
			return true;
		else
			return false;
	}
	else 
		return false;
}

tabla selecT (tabla t1, char *Columnas, tabla t2){
	t2->cs = selectCS (t1->cs, Columnas);
	return t2;
}

tabla intersecT (tabla t1,tabla t2, tabla t3){
	t3->cs= intersecCS (t1->cs, t2->cs);
	return t3;
}
