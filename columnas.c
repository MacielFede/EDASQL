// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//columna.c
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#include <iostream>
using namespace std;

#include <string.h>
#include "columna.h"
#include "define.h"
#include "columnas.h"

struct nodo_columnas{
     columna c;
     columnas sig;
     columnas ant;
};