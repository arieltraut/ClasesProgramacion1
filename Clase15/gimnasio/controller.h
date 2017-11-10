#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED
#include "socios.h"
#include "ArrayList.h"

int controller_altaSocio(ArrayList* listaSocios, char nombre[], char apellido[], char dni[]);
int controller_modificarSocio(Socio* socio, char nombre[], char apellido[]);
int controller_bajaSocio(ArrayList* listaSocios, int id);


void controller_debugShow(ArrayList* listaSocios);
int controller_findDni(ArrayList* listaSocios, char dni[]);
Socio* controller_findById (ArrayList* listaSocios, int id);
int controller_findById2 (ArrayList* listaSocios, int id);

