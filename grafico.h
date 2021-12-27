#ifndef GRAFICO_H_INCLUDED
#define GRAFICO_H_INCLUDED

#include "librerias.h"

void limpiarMatriz(char edades[LISTA][COLUMNA]);
void cargaValor(char edades[LISTA][COLUMNA], int v1, int v2, int v3);
void muestraValor(char edades[LISTA][COLUMNA]);

int contadorMenor(Persona dato[MAX]);
int contadorMayor(Persona dato[MAX]);
int contadorAdulto(Persona dato[MAX]);

void muestraContador(Persona dato[MAX]);


#endif