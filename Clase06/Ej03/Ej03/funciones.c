#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED
#include "funciones.h"

void ordenar (int a[])
{
    int i,j, aux;

    for (i=1; i<5;i++);
        {
            aux=a[i];
            for(j=i-1; j>=0; j--)
            {
                    if(aux < a[j])
                    {
                        a[j+1] = a[j];
                    }else
                    {
                        a[j+1]=aux;
                        break;
                    }
                a[j+1]=aux;
            }

        }
}

void ordenar2 (int a[])
{
    int i,j;
    int temp;
    for(i=1;i<5;i++)
    {
        temp = a[i];
        j=i-1;
        while(temp<a[j] && j>=0) // temp<data[j] o temp>data[j]
        {
             a[j+1] = a[j];
             j--;
        }
        a[j+1]=temp; // inserción
    }
}






#endif // FUNCIONES_C_INCLUDED
