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

int insertionInd(columna pk, char *valor){
     return insertionIndC(pk, valor);
}

bool tienePK(columnas cs){
     if(cs == NULL)
          return false;
     else if(esPrimaryKey(cs->c))
          return true;
     else 
          return tienePK(cs->sig);
}

TipoRet addColCS (columnas & cs, char *NombreCol, char *tipoCol, char *calificadorCol){
	columnas aux = cs;
	if (aux==NULL){					// Si no hay columnas
		columnas col=new (nodo_columnas);
		col-> ant = NULL;
		col-> sig = NULL;
		col-> c = nuevaCol(0, NombreCol, tipoCol, calificadorCol);
		return OK;
	}else{							// 
		if ((strcmp (calificadorCol, "PRIMARY_KEY"))==0 && tienePK(aux)){
			cout << "La tabla ya tiene una PRIMARY KEY" << endl;
			return ERROR;
		}else{
			if ((strcmp (calificadorCol, "ANY"))!=0 && (cantidadTuplas(aux) >0)){
				cout << "El calificador debe ser ANY." << endl;	
				return ERROR;
			}else{
				while((strcmp (nombreC(aux->c), NombreCol) !=0) && aux->sig != NULL){
						aux=aux->sig;
				}
				if (aux -> sig == NULL){
					columnas col=new (nodo_columnas);
					aux-> sig = col; 
					col-> ant = aux;
					col-> sig = NULL;
					col-> c = nuevaCol(cantidadTuplas(cs),NombreCol, tipoCol,calificadorCol);
				return OK;
				}else{
					cout << "La tabla ya tiene una Columna con ese Nombre." << endl;
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
	}
	else{
		if (esPrimaryKey(aux->c) && ( (aux->sig != NULL) || (aux->ant!= NULL) )){ // Si la columna es PK y la tabla tiene mas columnas
			cout << "Intenta eliminar Columna con calificador PRIMARY_KEY y la tabla tiene mas columnas" << endl;
			return ERROR;
		}else{
			aux->c = dropColC (aux -> c);
			if (aux->ant!=NULL || aux->sig!=NULL){ // Si la tabla a borrar no es la unica
				aux->ant->sig = aux->sig;
				aux->sig->ant = aux->ant;
			}
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
               }else
                    insertIntoC(cs->c, valoresTupla[iter], insertionIndex);
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
     if(strcmp(valor, "") == 0 || (strcasecmp(valor, "EMPTY") == 0 && strcasecmp(calificadorC(c), "NOT_EMPTY") == 0)){
          //Se borran todas las tuplas
          cs = deleteAll(cs);
     }else if(strcasecmp(valor, "EMPTY") == 0 && (strcmp(operador, "<") == 0 || strcmp(operador, ">") == 0)){
          //No hago nada
     }else{
          //Debo verificar en la columna si cada valor cumple o no la condicion
          int index = deleteIndex(c, operador, valor);
          while(index != -1){
               columnas aux = cs;
               while(aux != NULL){
                    aux->c = deleteFromC(aux->c, index);
                    aux = aux->sig;
               }
               index = deleteIndex(c, operador, valor);
          }
     }
          return OK;
}

columnas deleteAll(columnas cs){
	if( cs != NULL){
		while(cs != NULL){
			columnas aux = cs;
			cs = cs->sig;
			aux->c = deleteAllC(aux->c);
			delete aux;
		}
	}
	return cs;
}

void printdatatableCS(columnas cs){
     if(cs == NULL || columnaVacia(cs->c))
          cout << "No hay datos en la tabla" <<endl;
     else{
          while(!esPrimaryKey(cs->c) && cs->sig!=NULL){
               cs = cs->sig;
          }
          //Si tengo primary key en la tabla va a terminar justo en ella
          //Si no tengo primary key no me interesa cual imprimo primero
          columna aux = cs->c;
          cs = revovinarCS(cs);
          printNombresC(cs, aux);
          // imprimo los nombres de las columnas
          bool termine = false;
          unsigned int iter = 0;
          while(!termine){
               if(cs->c != aux && cs->ant!=NULL)
               //Si no estoy en la primary key y no estoy en el primer lugar imprimo
                    printdatatableC(cs->c, iter, termine);
               if(cs->sig == NULL){
                    //Si estoy en el ultimo lugar itero para imprimir el resto de datos
                    cs = revovinarCS(cs);
                    iter++;
               }else if(cs->ant == NULL){
                    //Si estoy en el primer lugar imprimo la pk y la primera columna
                    printdatatableC(aux, iter, termine);
                    cout << ":";
                    if(cs->c != aux){
                    //Si justo la primer columna es la primary key no la imprimo 2 veces
                         printdatatableC(cs->c, iter, termine);
                         cout<< ":";
                    }
                    cs = cs->sig;
               }else{
                    //Si estoy en el medio itero
                    if((cs->sig->c != aux || (cs->sig->c == aux && cs->sig->sig != NULL)) && cs->c != aux)
                    //Cheque que la columna no sea pk, que la sig sea pk y que esta no sea la ultima columna y que la siguiente no sea pk
                         cout<<":";
                    cs = cs->sig;
               }
          }
     }
}

void printNombresC(columnas cs, columna pk){
     cout<< nombreC(pk) << ":";
     while(cs!=NULL){
          if(cs->c != pk){
               if(cs->sig != NULL)
                    cout<< nombreC(cs->c) << ":";
               else
                    cout << nombreC(cs->c) << endl;
          }
     }
}

void printMetadataCS(columnas cs){
	if(cs != NULL){
		cout << "Columna: " << nombreC(cs->c) <<" (" << tipoDatoC(cs->c) << "," << calificadorC(cs->c) << ")" << endl;
		printMetadataCS(cs->sig);
	}
}














