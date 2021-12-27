// Hacer un programa que defina un array de 20
// items de esta estructura y con un menu como el
// siguiente

#include "grafico.h"
#include "validaciones.h"
#include "ordenar.h"
#include "abm.h"



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

