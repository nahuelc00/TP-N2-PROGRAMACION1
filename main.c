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
    system("cls");

    do
    {
        mostrarMenu();

        if (validarNumero("\ningrese una opcion del menu: ", auxMenu) == 0)
        {
            system("cls");
            printf("\nLO INGRESADO NO ES UN NUMERO!!\n");
        }
        else
        {

            opcion = atoi(auxMenu);

            switch (opcion)
            {
            case 1:
                system("cls");
                agregar(dato);
                break;

            case 2:
                system("cls");
                baja(dato);
                break;

            case 3:
                system("cls");
                mostrar(dato);
                break;

            case 4:
                system("cls");
                ordenarNombre(dato, ASC);
                mostrarNombre(dato);
                break;
            case 5:
                system("cls");
                cargaValor(edades, contadorMenor(dato), contadorMayor(dato), contadorAdulto(dato));
                muestraValor(edades);
                break;
            case 6:
                system("cls");
                limpio(dato);
                printf("\nDatos borrados\n");
                break;
            case 7:
                system("cls");
                break;

            default:
                system("cls");
                printf("\nNO ES OPCION DEL MENU\n");
            }
        }

    } while (opcion != 7);

    return 0;
}
