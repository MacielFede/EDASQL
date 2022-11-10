// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// bd.c
// Modulo de Implementación de Base de Datos.

#include <iostream>
using namespace std;
#include <string.h>
#include "bd.h"
#include "tablas/tablas.h"
#include "tablas/tabla.h"

struct nodo_bd{
	tablas ts;
};

bd createBD(){
	bd db = new(nodo_bd);
	db->ts = NULL;
	return db;
}

TipoRet createTable (bd & bd, char *nombreTabla){
	if(encontreTS(bd->ts, nombreTabla)){
		cout << "La tabla indicada ya existe."<< endl;
		return ERROR;
	}else{
		bd->ts = createTableTS(bd->ts, nombreTabla);
		return OK;
	}
}

TipoRet dropTable (bd & bd, char *nombreTabla){
	if(!encontreTS(bd->ts, nombreTabla)){
		cout << "La tabla indicada no existe."<< endl;
		return ERROR;
	}else{
		bd->ts = dropTableTS(bd->ts, nombreTabla);
		return OK;
	}
}

TipoRet addCol (bd & bd, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	if (strlen (nombreTabla) == 0){
		cout << "No se especifico el nombre de Tabla." <<endl;
		return ERROR;
	}else if (strlen (NombreCol)== 0){
		cout << "No se especifico el nombre de la Columna Nueva." <<endl;
		return ERROR;
	}else if (strlen (tipoCol)== 0){
		cout << "No se especifico el Tipo de Datos." <<endl;
		return ERROR;
	}else if (strlen (calificadorCol)== 0){
		cout << "No se especifico el Calificador." <<endl;
		return ERROR;
	}else
		return addColTS (bd->ts, nombreTabla, NombreCol, tipoCol, calificadorCol);
}

TipoRet dropCol (bd & bd, char *nombreTabla, char *NombreCol){
	if (strlen (nombreTabla) == 0){
		cout << "No se especifico el nombre de Tabla." <<endl;
		return ERROR;
	}else if (strlen (NombreCol)== 0){
		cout << "No se especifico el nombre de la Columna." <<endl;
		return ERROR;
	}else
		return dropColTS (bd->ts, nombreTabla, NombreCol);
}

TipoRet alterCol (bd & bd, char * nombreTabla, char * nombreCol, char *tipoColNuevo, char *calificadorColNuevo, char *nombreColNuevo){
	//cout << " - alterCol " << nombreTabla << " "<< nombreCol << " " << tipoColNuevo  << " " << calificadorColNuevo << " " << nombreColNuevo << endl;;
	return NO_IMPLEMENTADA;
}

TipoRet insertInto (bd & bd, char *nombreTabla, char *columnasTupla, char *valoresTupla){
	if(!encontreTS(bd->ts, nombreTabla)){
		cout << "La tabla indicada no existe."<< endl;
		return ERROR;
	}else{
		tabla aux = buscarTabla(bd->ts, nombreTabla);
		return insertIntoTS(aux, columnasTupla, valoresTupla);
	}
}

TipoRet deleteFrom (bd & bd, char *nombreTabla, char *condicionEliminar){
	if(!encontreTS(bd->ts, nombreTabla)){
		cout << "La tabla indicada no existe."<< endl;
		return ERROR;
	}else{
		tabla aux = buscarTabla(bd->ts, nombreTabla);
		char *operador = new(char[2]);
		if(strstr(condicionEliminar, "<") != NULL)
			strcpy(operador, "<");
		else if(strstr(condicionEliminar, ">") != NULL)
			strcpy(operador, ">");
		else if(strstr(condicionEliminar, "=") != NULL)
			strcpy(operador, "=");
		else
			strcpy(operador, "!");
		char *col = strtok(condicionEliminar, "<>=!");
		char *valor = strtok(NULL, "<>=!");
		if(valor == NULL){
			valor = new(char[2]);
			strcpy(valor, " ");
		}
		return deleteFromTS(aux, col, operador, valor);
	}
}

TipoRet update(bd & bd, char * nombreTabla, char * condicionModificar, char * columnaModificar, char * valorModificar){
	//cout << " - update " << nombreTabla << " " << condicionModificar << " " << columnaModificar << " " << valorModificar << endl;
	return NO_IMPLEMENTADA;
}

TipoRet selectWhere (bd & bd,char * nomTabla1, char * condicion, char * nomTabla2){
	if(encontreTS(bd->ts, nomTabla1) && !encontreTS(bd->ts,nomTabla2)){
		char *operador = new(char[2]);
		if(strstr(condicion, "<") != NULL)
			strcpy(operador, "<");
		else if(strstr(condicion, ">") != NULL)
			strcpy(operador, ">");
		else if(strstr(condicion, "=") != NULL)
			strcpy(operador, "=");
		else
			strcpy(operador, "!");
		char *col = strtok(condicion, "<>=!");
		char *valor = strtok(NULL, "<>=!");
		if(valor == NULL){
			valor = new(char[2]);
			strcpy(valor, " ");
		}
		bd->ts = createTableTS(bd->ts, nomTabla2);
		tabla t1 = buscarTabla(bd->ts, nomTabla1);
		tabla t2 = buscarTabla(bd->ts, nomTabla2);
		return selectWereTS(valor, operador, col, t1, t2);
	}else{
		cout<<"La tabla 2 ya existe o la tabla 1 no existe"<<endl;
		return ERROR;
	}
}

TipoRet select (bd & bd, char * nomTabla1, char * nomColumnas, char * nomTabla2){
	//cout << " - select " << nomTabla1 << " " << nomColumnas << " " << nomTabla2 << endl;
	return NO_IMPLEMENTADA;
}

TipoRet join (bd & bd, char * nomTabla1, char * nomTabla2, char * nomTabla3){
	//cout << " - join " << nomTabla1 << " " << nomTabla2 << " " << nomTabla3 << endl;
	return NO_IMPLEMENTADA;
}

TipoRet union_(bd & bd, char * nombreTabla1, char * nombreTabla2, char * nombreTabla3){
	if(encontreTS(bd->ts, nombreTabla1) && encontreTS(bd->ts,nombreTabla2) && !encontreTS(bd->ts, nombreTabla3))
		return unionTS(bd->ts, nombreTabla1, nombreTabla2, nombreTabla3);
	else{
		cout << "Tabla 1 o Tabla 2 no existen, o Tabla 3 ya existe" << endl;
		return ERROR;
	}
}

TipoRet intersec(bd & bd, char * nombreTabla1, char * nombreTabla2, char * nombreTabla3){
	//cout << " - intersec " << nombreTabla1 << " " << nombreTabla2 << " " << nombreTabla3 << endl;
	return NO_IMPLEMENTADA;
}

TipoRet minus_(bd & bd, char * nombreTabla1, char * nombreTabla2, char * nombreTabla3){
	//cout << " - minus_ " << nombreTabla1 << " " << nombreTabla2 << " " << nombreTabla3 << endl;
	return NO_IMPLEMENTADA;
}

TipoRet printdatatable (bd bd, char *NombreTabla){
	if(!encontreTS(bd->ts, NombreTabla)){
		cout << "La tabla indicada no existe."<< endl;
		return ERROR;
	}else{
		printdatatableTS(bd->ts, NombreTabla);
		return OK;
	}
}

TipoRet printTables(bd bd){
	if(bd->ts == NULL)
		cout << "No hay tablas para mostrar"<< endl;
	else{
		printTablesTS(bd->ts);
		cout<< endl;
	}
	return OK;
}

TipoRet printMetadata(bd bd, char *nombreTabla){
	if(!encontreTS(bd->ts, nombreTabla)){
		cout << "La tabla indicada no existe."<< endl;
		return ERROR;
	}else{
		tabla aux = buscarTabla(bd->ts, nombreTabla);
		cout<<"\n";
		printMetadataTS(aux);
		return OK;
	}
}

TipoRet undo(bd & bd){
	//cout << " - undo" << endl;
	return NO_IMPLEMENTADA;
}

TipoRet redo(bd & bd){
	//cout << " - redo" << endl;
	return NO_IMPLEMENTADA;
}

bd destroyBD(bd & bd){
	//
	return NULL;
}

