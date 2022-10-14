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
#include "tablas.h"

struct nodo_tablas{
     tabla t;
     tablas izq;
     tablas der;
};