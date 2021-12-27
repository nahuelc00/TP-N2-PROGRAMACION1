#ifndef GRAFICO_H_INCLUDED
#define GRAFICO_H_INCLUDED

#define MAX 20

#define LISTA 5 // y tambien es FILA
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

void limpiarMatriz(char edades[LISTA][COLUMNA]);
void cargaValor(char edades[LISTA][COLUMNA], int v1, int v2, int v3);
void muestraValor(char edades[LISTA][COLUMNA]);

int contadorMenor(Persona dato[MAX]);
int contadorMayor(Persona dato[MAX]);
int contadorAdulto(Persona dato[MAX]);

void muestraContador(Persona dato[MAX]);


#endif