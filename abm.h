#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

#include "librerias.h"

//////////////ABM///////////////////////
void agregar(Persona dato[MAX]);
void mostrar(Persona dato[MAX]);
void limpio(Persona dato[MAX]);
void alta(Persona dato[MAX]);
void baja(Persona dato[MAX]);
void completarBusqueda(Persona dato[MAX]);
int buscarPersona(Persona dato[MAX]);

void mostrarMenu();


#endif