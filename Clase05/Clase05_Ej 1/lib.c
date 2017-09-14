#ifndef LIB_C_INCLUDED
#define LIB_C_INCLUDED
#include "lib.h"

int ingreseDatos (int edad[], float sueldo[])
{
        int i;
        float aux;

        for(i=0;i<CANT_EMPLEADOS;i++)
    {
        printf("Ingrese un edad del legajo %d: \n",i+1);
        scanf("%d",&edad[i]);

        printf("Ingrese el salario del legajo %d \n", i+1);
        scanf("%f",&aux);

        sueldo[i]=aux;

    }


}



#endif // LIB_C_INCLUDED
