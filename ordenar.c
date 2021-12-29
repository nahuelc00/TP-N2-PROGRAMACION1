#include "ordenar.h"

/////////////////////////////////--ordenar---/////////////////

void ordenarNombre(Persona dato[MAX], int orden)
{

    for (int i = 0; i < LISTA; i++)
    {
        int ordenado = 0;

        for (int j = 0; j < LISTA - 1 - i; j++)
        {
            if ((strcmp(dato[j].nombre, dato[j + 1].nombre) > 0 && orden == 1) ||
                strcmp(dato[j].nombre, dato[j + 1].nombre) < 0 && orden == 2)
            {

                Persona aux;
                memcpy(&aux, &dato[j], sizeof(Persona));
                memcpy(&dato[j], &dato[j + 1], sizeof(Persona));
                memcpy(&dato[j + 1], &aux, sizeof(Persona));
                ordenado = 1;
            }
        }
        if (ordenado == 0)
        {
            break;
        }
    }
}

///////////////////////////////////////////////////////////////////

void mostrarNombre(Persona dato[MAX])
{

    for (int i = 0; i < LISTA; i++)
    {
        if (dato[i].estado != 0)
        {
            printf("\nNombre: %s  Edad: %d  DNI:%d  Estado:%d\n",
                   dato[i].nombre,
                   dato[i].edad,
                   dato[i].dni,
                   dato[i].estado);
        }
    }
}
