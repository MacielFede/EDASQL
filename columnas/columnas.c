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

columnas dropTableCS(columnas cs){
     cs = deleteAll(cs); 
     //Elimino todas las tuplas y luego los nodos columnas
	while(cs!= NULL){
		columnas aux = cs;
		cs = cs->sig;
		delete aux;
	}
	return NULL;
}

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
     while(cs->ant != NULL){       
          cs = cs->ant;
     }
     return cs;
}

int insertionInd(columna pk, char *valor){
     return insertionIndC(pk, valor);
}

bool tienePK(columnas cs){
     columnas aux=cs;
     if(aux == NULL)
          return false;
     else if(esPrimaryKey(aux->c))
          return true;
     else 
          return tienePK(aux->sig);
}

TipoRet addColCS (columnas & cs, char *NombreCol, char *tipoCol, char *calificadorCol){
	if (cs==NULL){		// Si no hay columnas
		cs = new (nodo_columnas);
		cs-> ant = NULL;
		cs-> sig = NULL;
		cs-> c = nuevaCol(0, NombreCol, tipoCol, calificadorCol);
		return OK;
	}else{
		if ((strcmp (calificadorCol, "PRIMARY_KEY"))==0 && tienePK(cs)){
			cout << "La tabla ya tiene una PRIMARY KEY" << endl;
			return ERROR;
		}else{	
			if (( (strcmp (calificadorCol, "ANY"))!=0) && (cantidadTuplas(cs) >0)){
				cout << "El calificador debe ser ANY." << endl;	
				return ERROR;
			}else{
				while((strcmp (nombreC(cs->c), NombreCol) !=0) && cs->sig != NULL){
					cs=cs->sig;
				}
				if (strcmp (nombreC(cs->c), NombreCol) !=0){
                         columnas col=new (nodo_columnas); 
                         col-> ant = cs;
					col-> sig = NULL;
					col-> c = nuevaCol(cantidadTuplas(cs),NombreCol, tipoCol,calificadorCol);
                         cs-> sig = col;
                         cs = revovinarCS(cs);
                         return OK;
				}else{
					cout << "La tabla ya tiene una Columna con ese Nombre." << endl;
                         cs = revovinarCS(cs);
					return ERROR;
				}
			}
		}
	}
}

TipoRet dropColCS (columnas &cs, char* NombreCol){
	columnas aux=cs;
	while ((aux != NULL)&&(strcmp(nombreC(aux->c), NombreCol) != 0)){
		aux = aux->sig;
	}
	if (aux == NULL){
		cout << "La columna indicada no existe" <<endl;
		return ERROR;
	}else{
		if (esPrimaryKey(aux->c) && ( (aux->sig != NULL) || (aux->ant!= NULL) )){ // Si la columna es PK y la tabla tiene mas columnas
			cout << "Intenta eliminar Columna con calificador PRIMARY_KEY y la tabla tiene mas columnas" << endl;
			return ERROR;
		}else{
			aux->c = dropColC (aux -> c);
               if(aux->ant == NULL && aux->sig == NULL){
                    cs = NULL;
               }else if(aux->ant == NULL){ //Estoy al principio de la lista
                    cs = cs->sig;
                    cs->ant = NULL;
               }else if(aux->sig == NULL){ //Estoy al final de la lista
                    aux->ant->sig = NULL;
               }else{ //Estoy en el medio de la lista
                    aux->ant->sig = aux->sig;
				aux->sig->ant = aux->ant;
               }
               delete aux;
               return OK;
		}
	}
}

int cantidadTuplas (columnas cs){
     columnas aux = cs;
	if (aux->sig == NULL)
		return cuentaTuplas(aux->c);
	else{
		int max = cantidadTuplas (aux->sig);
		int actual = cuentaTuplas (aux->c);
		if (actual>max)
			return actual;
		else
			return max;
	}
}

TipoRet insertIntoCS(columnas & cs, char *columnasTupla[], char *valoresTupla[], unsigned int insertionIndex){
     unsigned int iter;
     bool termine = false;
     while(!termine){
          iter = 0;
          while(columnasTupla[iter] != NULL && strcmp(nombreC(cs->c), columnasTupla[iter]) != 0)
               iter++;
          if(columnasTupla[iter] != NULL){ //Encontre la columna
               if(esPrimaryKey(cs->c) &&  mismoTipoDato(cs->c, valoresTupla[iter]) && !seRepiteDato(listaDatos(cs->c), valoresTupla[iter]) ){ 
                    //Chequeamos que no se repita el dato si es primary key, que sea el mismo tipo de dato el que vamos a insertar
                    insertIntoC(cs->c, valoresTupla[iter], insertionIndex);
               }else if(esPrimaryKey(cs->c) && (strcasecmp(valoresTupla[iter], "EMPTY") == 0 || seRepiteDato(listaDatos(cs->c), valoresTupla[iter]))){
                    cout << "El dato de la primary key se repite o intentaste dejarlo vacio" << endl;
                    return ERROR;
               }else if(!mismoTipoDato(cs->c, valoresTupla[iter])){
                    cout << "El tipo de dato de la columna "<< nombreC(cs->c) <<" es distinto al del dato pasado" << endl;
                    return ERROR;
               }else if(strcasecmp(valoresTupla[iter], "EMPTY") == 0 && strcasecmp(calificadorC(cs->c), "NOT_EMPTY") == 0){
                    cout << "La columna " << nombreC(cs->c) << " no acepta valor empty" << endl;
                    return ERROR;
               }else{
                    insertIntoC(cs->c, valoresTupla[iter], insertionIndex);
               }
          }else{
          //Si no encuentro la columna quiere decir que le tengo que poner un valor empty
               if(strcasecmp(calificadorC(cs->c), "NOT_EMPTY") == 0){
                    cout << "La columna " << nombreC(cs->c) << " no acepta valor empty" << endl;
                    return ERROR;
               }else
                    insertIntoC(cs->c, "EMPTY", insertionIndex);
          }
          if(cs->sig == NULL){
               cs = revovinarCS(cs);
               termine = true;
          }else
               cs = cs->sig;
     }
     return OK;
}

TipoRet deleteFromCS(columnas & cs, columna c, char *operador, char *valor){
     if(strcmp(valor, " ") == 0 || (strcasecmp(valor, "EMPTY") == 0 && strcasecmp(calificadorC(c), "NOT_EMPTY") == 0)){
          //Se borran todas las tuplas
          cs = deleteAll(cs);
     }else if(strcasecmp(valor, "EMPTY") == 0 && (strcmp(operador, "<") == 0 || strcmp(operador, ">") == 0)){
          //No hago nada
     }else{
          //Debo verificar en la columna si cada valor cumple o no la condicion
          int index = deleteIndex(c, operador, valor);
          if(index == 0 && (strcmp(operador, "<") == 0 || strcmp(operador, ">") == 0)){ 
               //Si el operador es > o < y quiero empezar a eliminar desde el primer elemento, quiero eliminarlos a todos
               cs = deleteAll(cs);
          }else{
               while(index != -1){
                    columnas aux = cs;
                    while(aux != NULL){
                         aux->c = deleteFromC(aux->c, index);
                         aux = aux->sig;
                    }
                    index = deleteIndex(c, operador, valor);
               }
          }
     }
     return OK;
}

columnas deleteAll(columnas cs){
	columnas aux = cs;
     while(aux != NULL){
          aux->c = deleteAllC(aux->c);
          aux = aux->sig;
     }
	return cs;
}

void printdatatableCS(columnas cs){
     if(cs == NULL)
          cout << "No hay columnas en la tabla" <<endl;
     else{
          printNombresC(cs,cs->c);
          bool termine = false;
          unsigned int iter = 0;
          while(!termine){
               printdatatableC(cs->c, iter, termine);
               if(!termine){
                    if(cs->sig == NULL){ //Si estoy en el final vuelvo al principio para imprimir otros datos
                         cout<<"\n";
                         cs = revovinarCS(cs);
                         iter++;
                    }else{
                         cout << ":";
                         cs = cs->sig;
                    }
               }
          }



         
     }
}

void printNombresC(columnas cs, columna pk){
     //Editar el encabezado una vez haya funcionado sin los chekeos de la primarykey
     while(cs!=NULL){
          if(cs->sig == NULL){
               cout << nombreC(cs->c) << endl;
          }else{
               cout<< nombreC(cs->c) << ":";
          }
          cs = cs->sig;
     }
}

void printMetadataCS(columnas cs){
	if(cs != NULL){
		cout << "Columna: " << nombreC(cs->c) <<" (" << tipoDatoC(cs->c) << "," << calificadorC(cs->c) << ")" << endl;
		printMetadataCS(cs->sig);
	}
}














