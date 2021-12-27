
#include "validaciones.h"

///////////////////----VALIDACIONES---------////////////////////////////////////
void pideCaracter(char mensaje[], char cant[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cant);
    fflush(stdin);
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
