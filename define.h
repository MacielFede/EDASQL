#ifndef DEFINE_H
#define DEFINE_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// define.h
// Modulo de Definiciones Generales.

#define MAX_COMANDO 128
#define MAX_NOMBRE 20 //Este valor es usado para los nombres de tablas y columnas
#define MAX_VALOR 30 //Este valor es usado para los datos de tipo string
#define MAX_TIPO_DATO 10 //Este valor se usa para los tipoDato en las columnas
#define MAX_CANT_COL 5 //Este valor es usado para saber la cantidad maxima de columnas de las tablas

enum _retorno{OK, ERROR, NO_IMPLEMENTADA};
typedef enum _retorno TipoRet;


#endif
