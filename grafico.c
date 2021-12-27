#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafico.h"

#define MAX 20

#define LISTA 5 // y tambien es FILA
#define COLUMNA 3

#define ASC 1
#define DESC 2

#define VACIO 0
#define ACTIVO 1

//////////////CONTADOR DE EDAD////////////////////////

int contadorMenor(Persona dato[MAX])
{
    int contador = 0;
    for (int i = 0; i < LISTA; i++)
    {
        if (dato[i].edad <= 18 && dato[i].edad > 0)
        {
            contador++;
        }
    }
    return contador;
}

/////////////////////////////////////////////////////

int contadorMayor(Persona dato[MAX])
{

    int contador = 0;
    for (int i = 0; i < LISTA; i++)
    {
        if (dato[i].edad > 18 && dato[i].edad <= 35)
        {
            contador++;
        }
    }
    return contador;
}
/////////////////////////////////////////////////////

int contadorAdulto(Persona dato[MAX])
{

    int contador = 0;
    for (int i = 0; i < LISTA; i++)
    {
        if (dato[i].edad > 35)
        {
            contador++;
        }
    }
    return contador;
}
/////////////////////////////////////////////////////

void muestraContador(Persona dato[MAX])
{

    int menor = contadorMenor(dato);
    int mayor = contadorMayor(dato);
    int adulto = contadorAdulto(dato);

    printf("\n");
    printf("\nGente con edad menor a 18: %d", menor);
    printf("\nGente con edad de 19 a 35: %d", mayor);
    printf("\nGente con edad mayor a 35: %d", adulto);
}

///////////////////grafico///////////////////////////////

void limpiarMatriz(char edades[LISTA][COLUMNA])
{

    for (int i = 0; i < LISTA + 1; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            edades[i][j] = 'x';
        }
    }
}

///////////////////////////////////////////////////////////////////

void cargaValor(char edades[LISTA][COLUMNA], int v1, int v2, int v3)
{

    if (v1 > 0)
    {
        for (int i = v1; i > 0; i--)
        {
            for (int j = 0; j < COLUMNA; j++)
            {
                edades[i][0] = '*';
            }
        }
    }

    if (v2 > 0)
    {
        for (int i = v2; i > 0; i--)
        {
            for (int j = 0; j < COLUMNA; j++)
            {
                edades[i][1] = '*';
            }
        }
    }

    if (v3 > 0)
    {
        for (int i = v3; i > 0; i--)
        {
            for (int j = 0; j < COLUMNA; j++)
            {
                edades[i][2] = '*';
            }
        }
    }
}

///////////////////////////////////////////////////////////////////

void muestraValor(char edades[LISTA][COLUMNA])
{
    printf(" \n");
    for (int i = LISTA; i > 0; i--)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            printf(" [%c]  ", edades[i][j]);
        }
        printf(" \n");
    }
    printf("<18 |19 a 35| >35\n");
    printf(" \n");
}