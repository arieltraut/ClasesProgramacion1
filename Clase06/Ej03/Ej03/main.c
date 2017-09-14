#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int i,a[5]={2,5,4,3,1};


    ordenar(a);
    //ordenar2(a);

    for (i=0;i<5;i++)
    {
        printf("%d",a[i]);
    }


    return 0;
}
