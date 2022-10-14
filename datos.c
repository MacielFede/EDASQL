// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//datos.c
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#include <iostream>
using namespace std;

#include "define.h"
#include "dato.h"
#include <string.h>
#include "datos.h"

struct nodo_datos{
     dato d;
     datos sig;
     datos ant;
};