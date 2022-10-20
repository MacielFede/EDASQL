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
	return NO_IMPLEMENTADA;
}

TipoRet dropTable (bd & bd, char *nombreTabla){
	//cout << " - dropTable " << nombreTabla << endl;;
	return NO_IMPLEMENTADA;
}

TipoRet addCol (bd & bd, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	//cout << " - addCol " << nombreTabla << " " << NombreCol << " " << tipoCol << " " << calificadorCol << endl;;
	return NO_IMPLEMENTADA;
}

TipoRet dropCol (bd & bd, char *nombreTabla, char *NombreCol){
	//cout << " - dropCol " << nombreTabla << " " << NombreCol << endl;;
	return NO_IMPLEMENTADA;
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
		char *operador = new(char);
		if(strstr(condicionEliminar, "<") != NULL)
			operador = strstr(condicionEliminar, "<");
		else if(strstr(condicionEliminar, ">") != NULL)
			operador = strstr(condicionEliminar, ">");
		else if(strstr(condicionEliminar, "=") != NULL)
			operador = strstr(condicionEliminar, "=");
		else
			operador = strstr(condicionEliminar, "!");
		char *col = strtok(condicionEliminar, "<>=!");
		char *valor = strtok(NULL, "<>=!");
		return deleteFromTS(aux, col, operador, valor);
	}
}

TipoRet update(bd & bd, char * nombreTabla, char * condicionModificar, char * columnaModificar, char * valorModificar){
	//cout << " - update " << nombreTabla << " " << condicionModificar << " " << columnaModificar << " " << valorModificar << endl;
	return NO_IMPLEMENTADA;
}

TipoRet selectWhere (bd & bd,char * nomTabla1, char * condicion, char * nomTabla2){
	//cout << " - selectWhere " << nomTabla1 << " " << condicion << " " << nomTabla2 << endl;
	return NO_IMPLEMENTADA;
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
	//cout << " - union_ " << nombreTabla1 << " " << nombreTabla2 << " " << nombreTabla3 << endl;
	return NO_IMPLEMENTADA;
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
	//cout << " - printTables " << endl;
	return NO_IMPLEMENTADA;
}

TipoRet printMetadata(bd bd, char *nombreTabla){
	if(!encontreTS(bd->ts, nombreTabla)){
		cout << "La tabla indicada no existe."<< endl;
		return ERROR;
	}else{
		tabla aux = buscarTabla(bd->ts, nombreTabla);
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

