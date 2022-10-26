// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//datos.c
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#include <iostream>
using namespace std;

#include "../define.h"
#include "dato.h"
#include <string.h>

struct nodo_dato{
     char * info;
     int indice; //Esto es para saber en que posición de la lista esta la primary key del dato (osea la posición de la tupla)
};

char * infoDato(dato d){
     return d->info;
}

int indiceDato(dato d){
     return d->indice;
}

bool datoVacio(dato d){
     return (d == NULL);
}

dato insertIntoD(const char *data, unsigned int index){
     dato d = new(nodo_dato);
     d->info = new(char[MAX_VALOR]);
     strcpy(d->info ,data);
     d->indice = index;
     return d;
}



dato datoEmpty (int i){
	dato d = new (nodo_dato);
	strcpy(d -> info, "EMPTY");
	d -> indice = i;
	return d;
}

void resetearIndice(dato & d, bool sumo){
     if(sumo)
          d->indice++;
     else
          d->indice--;
}

dato deleteFromD(dato d){
	delete d;
	return d;
}
