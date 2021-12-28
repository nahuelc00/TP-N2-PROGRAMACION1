#include "abm.h"

int contadorDeEstado = 0;

void mostrarMenu()
{
    printf("\n");
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- mostrar\n");
    printf("4- Imprimir lista ordenada por nombre\n");
    printf("5- Imprimir grafico de edades\n");
    printf("6- Borrar todo\n\n");
    printf("7- Salir\n");

}

/////////////////////////////////////////////////////
void agregar(Persona dato[MAX])
{
    char NOM[MAX];
    char EDAD[MAX];
    char DNI[MAX];

    if (contadorDeEstado == LISTA)
    {
        printf("\nNO HAY MAS ESPACIOS PARA LLENAR\n");
    }

    for (int i = 0; i < LISTA; i++)
    {

        if (dato[i].estado == VACIO)
        {

            if (!validarLetra("\nIngrese Nombre: ", NOM))
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

            if (!validarNumero("\nIngrese Edad: ", EDAD))
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
            }

            if (!validarNumero("\nIngrese DNI: ", DNI))
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
            contadorDeEstado++;
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

        printf("\n%i ->>Nombre: %s  Edad: %d  DNI:%d  Estado:%d\n", i + 1,
               dato[i].nombre,
               dato[i].edad,
               dato[i].dni,
               dato[i].estado);
    }
}

///////////////////////////////////////////////////////

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
        contadorDeEstado--;
        printf("\nDATO BORRADO\n");
    }
    else
    {
        printf("\nNO SE ESCUENTRA EL DATO\n");
    }
}

///////////////////////////////////////////////////////

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
