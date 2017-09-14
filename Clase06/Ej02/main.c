#include <stdio.h>
#include <stdlib.h>
#include "ordenar.h"
#define CANTI_ITERACION 5

int main()
{

        int i,a[CANTI_ITERACION] = {6,3,5,4,1};

        ordenar ( a, CANTI_ITERACION);

        for (i=0;i<CANTI_ITERACION;i++)
        {
            printf("%d",a[i]);

        }


    return 0;
}
