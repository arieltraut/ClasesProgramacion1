#include <stdio.h>
#include <stdlib.h>
#include "datos.h"

int validarInt (char* buffer)
{
    int retorno = -1;
    while ()

}




int getEdad (int* pEdad, char* msg)
{
    char buffer[4096];
    int retorno = -1;
    printf(msg);
    fgets(buffer,4096,stdin);
    buffer[4096] = '\0';
    if (validarInt(buffer) == 0)
    {
            *pEdad
    }

    return retorno;

}





