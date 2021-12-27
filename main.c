// Hacer un programa que defina un array de 20
// items de esta estructura y con un menu como el
// siguiente

#include "grafico.h"
#include "validaciones.h"
#include "ordenar.h"


//////////////ABM///////////////////////
void agregar(Persona dato[MAX]);
void mostrar(Persona dato[MAX]);
void limpio(Persona dato[MAX]);
void alta(Persona dato[MAX]);
void baja(Persona dato[MAX]);
void completarBusqueda(Persona dato[MAX]);
int buscarPersona(Persona dato[MAX]);


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

