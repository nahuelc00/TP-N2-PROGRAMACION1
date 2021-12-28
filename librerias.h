#ifndef LIBRERIAS_H_INCLUDED
#define LIBRERIAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

#define LISTA 10 // y tambien es FILA
#define COLUMNA 3

#define ASC 1
#define DESC 2

#define VACIO 0
#define ACTIVO 1

typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int estado;
} Persona;

#endif