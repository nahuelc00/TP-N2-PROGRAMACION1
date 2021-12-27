// Hacer un programa que defina un array de 20
// items de esta estructura y con un menu como el
// siguiente

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

typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int estado;
} Persona;

//////////////VALIDACIONES///////////////
int validarNumero(char mensaje[], char cant[]);
int esNumerico(char num[]);
int validarLetra(char mensaje[], char cant[]);
int esSoloLetras(char letra[]);
void pideCaracter(char mensaje[], char cant[]);

//////////////ABM///////////////////////
void agregar(Persona dato[MAX]);
void mostrar(Persona dato[MAX]);
void limpio(Persona dato[MAX]);
void alta(Persona dato[MAX]);
void baja(Persona dato[MAX]);
void completarBusqueda(Persona dato[MAX]);
int buscarPersona(Persona dato[MAX]);
void ordenarNombre(Persona dato[MAX], int orden);
void mostrarNombre(Persona dato[MAX]);



void mostrarMenu();

int main()
{

    char edades[LISTA][COLUMNA];
    char auxMenu[MAX];
    Persona dato[MAX];
    limpio(dato);

    int opcion = 0;

    do
    {

        mostrarMenu();

        if (!validarNumero("\ningrese una opcion del menu: ", auxMenu))
        {

            printf("\nLO INGRESADO NO ES UN NUMERO!!\n");
        }

        opcion = atoi(auxMenu);

        switch (opcion)
        {
        case 1:
            agregar(dato);
            break;

        case 2:
            baja(dato);
            break;

        case 3:

            mostrar(dato);
            break;

        case 4:
            ordenarNombre(dato, ASC);
            mostrarNombre(dato);
            break;
        case 5:

            limpiarMatriz(edades);

            cargaValor(edades, contadorMenor(dato), contadorMayor(dato), contadorAdulto(dato));

            muestraValor(edades);

            break;
        case 6:
            break;

        default:
            printf("NO ES OPCION DEL MENU\n");
        }

    } while (opcion != 6);

    return 0;
}

void mostrarMenu()
{

    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- mostrar\n");
    printf("4- Imprimir lista ordenada por nombre\n");
    printf("5- Imprimir grafico de edades\n\n");
    printf("6- Salir\n");
}

/////////////////////////////////////////////////////
void agregar(Persona dato[MAX])
{

    char NOM[MAX];
    char EDAD[MAX];
    char DNI[MAX];
    printf("\nCARGUE ALGUN DATO\n");
    for (int i = 0; i < LISTA; i++)
    {

        if (dato[i].estado == VACIO)
        {

            if (!validarLetra("\nNombre: ", NOM))
            {
                printf("\n Lo ingresado no es letra\n");
                for (int i = 0; i < LISTA; i++)
                {
                    if (dato[i].estado == VACIO)
                    {
                        strcpy(dato[i].nombre, "");
                        dato[i].edad = 0;
                        dato[i].dni = 0;
                        dato[i].estado = VACIO;
                    }
                }
                break;
            }
            else
            {
                strcpy(dato[i].nombre, NOM);
            }

            if (!validarNumero("\nEdad: ", EDAD))
            {
                printf("\n Lo ingresado no es numero\n");
                for (int i = 0; i < LISTA; i++)
                {
                    if (dato[i].estado == VACIO)
                    {
                        strcpy(dato[i].nombre, "");
                        dato[i].edad = 0;
                        dato[i].dni = 0;
                        dato[i].estado = VACIO;
                    }
                }
                break;
            }
            else
            {
                dato[i].edad = atoi(EDAD);

                muestraContador(dato);
            }

            if (!validarNumero("\nDNI: ", DNI))
            {
                printf("\n Lo ingresado no es numero\n");

                for (int i = 0; i < LISTA; i++)
                {
                    if (dato[i].estado == VACIO)
                    {
                        strcpy(dato[i].nombre, "");
                        dato[i].edad = 0;
                        dato[i].dni = 0;
                        dato[i].estado = VACIO;
                    }
                }

                break;
            }
            else
            {
                dato[i].dni = atoi(DNI);
            }

            dato[i].estado = ACTIVO;
            break;
        }
    }
}




/////////////////////////////////////////////////////
void limpio(Persona dato[MAX])
{
    for (int i = 0; i < LISTA; i++)
    {
        strcpy(dato[i].nombre, " ");
        dato[i].edad = 0;
        dato[i].dni = 0;
        dato[i].estado = VACIO;
    }
}
///////////////////////////////////////////////////////
void mostrar(Persona dato[MAX])
{

    for (int i = 0; i < LISTA; i++)
    {

        printf("%i ->>Nombre: %s,Edad: %d,DNI:%d,Estado:%d\n", i + 1,
               dato[i].nombre,
               dato[i].edad,
               dato[i].dni,
               dato[i].estado);
    }
};

void baja(Persona dato[MAX])
{
    printf("\nBORRAR UN DATO \n");
    int posicion = buscarPersona(dato);

    if (posicion != -1)
    {
        strcpy(dato[posicion].nombre, " ");
        dato[posicion].edad = 0;
        dato[posicion].dni = 0;
        dato[posicion].estado = VACIO;
    }
    else
    {
        printf("\nNo se encontro el dato\n");
    }
}

///////////////////----VALIDACIONES---------////////////////////////////////////
void pideCaracter(char mensaje[], char cant[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cant);
    fflush(stdin);
}
/////////////////////////////////////////////////////////////////////////////
int validarNumero(char mensaje[], char cant[])
{
    char aux[256];
    pideCaracter(mensaje, aux);
    if (esNumerico(aux))
    {
        strcpy(cant, aux);
        return 1;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////

int validarLetra(char mensaje[], char cant[])
{
    char aux[256];
    pideCaracter(mensaje, aux);
    if (esSoloLetras(aux))
    {
        strcpy(cant, aux);
        return 1;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////

int esSoloLetras(char letra[])
{
    int i = 0;
    while (letra[i] != '\0')
    {
        if ((letra[i] != ' ') && (letra[i] < 'a' || letra[i] > 'z') && (letra[i] < 'A' || letra[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

/////////////////////////////////////////////////////////////////////////////

int esNumerico(char num[])
{
    int i = 0;
    while (num[i] != '\0')
    {
        if (num[i] < '0' || num[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

///////////////////////////////////////////////////////////////////////////

int buscarPersona(Persona dato[MAX])
{
    int posicion = -1;
    char nombreAux[MAX];

    printf("\nPara buscar una persona escriba su nombre: \n ");
    fflush(stdin);
    scanf("%[^\n]", nombreAux);
    fflush(stdin);

    for (int i = 0; i < LISTA; i++)
    {

        if (dato[i].estado == ACTIVO && strcmp(dato[i].nombre, nombreAux) == 0)
        {
            posicion = i;
        }
    }

    return posicion;
}

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
        if (dato[i].nombre != 0)
        {
            printf("\n%i-->Nombre[%s] Edad[%d] DNI[%d]\n", i + 1, dato[i].nombre, dato[i].edad, dato[i].dni);
        }
    }
}

