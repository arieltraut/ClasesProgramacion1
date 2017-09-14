#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"



int validarPrecio(char bPrecio[])
{
    int i,contadorComas=0;
    while(bPrecio[i] != 10)
    {
        if((bPrecio[i] < '0' || bPrecio[i] > '9') && (bPrecio !=','))
           return -1;
        if (bPrecio[i] == ',')
            contadorComas++;
        i++;
    }
    if (contadorComas <= 1)
        return 0;

    return 0;
}

int cargarDato(char a[],int indice,char msg)
{
    //NOOOOOOO ---> fgets(a[indice].nombre,20,stdin);
    char bNombre[20],bDesc[50],bPrecio[20];
    printf(msg);
    fgets(bPrecio,20,stdin);
    bPrecio[19] = '\0';
    bPrecio[18] = 10; // LF

    if(validarPrecio(bPrecio) == 0)
    {
        a[indice].precio = atof(bPrecio);
        return 0;
    }

    return -1;
}



#endif // FUNCIONES_C_INCLUDED
