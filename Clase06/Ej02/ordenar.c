#ifndef ORDENAR_C_INCLUDED
#define ORDENAR_C_INCLUDED
#include "ordenar.h"

void ordenar (int a[], int len)
{
    int aux, i,flagCambio;
    do
    {
    flagCambio=0;
    for(i=0; i<(len-1);i++)
    {
        if (a[i]>a[i+1])
            {
                flagCambio=1;
                aux = a[i];
                a[i]= a[i+1];
                a[i+1] = aux;

            }
    }

    }while (flagCambio==1);


}





#endif // ORDENAR_C_INCLUDED
