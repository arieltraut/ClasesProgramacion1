#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 3

int main()
{
    float numero;
    int i;
    float acum;
    float maxNumero;


    for(i=0;i<CANTIDAD;i++)
    {
        printf("Ingrese numero\n");
        scanf("%f",&numero);

        while(numero<0)
        {
            printf("Numero erroneo, ingrese nuevamente\n");
            scanf("%f",&numero);
        }

        acum = acum+numero;

        if(numero>maxNumero || i==0)
        {
            maxNumero=numero;
        }


    }
    printf("La suma es %.2f\n",acum);
    printf("El numero maximo es %.2f\n",maxNumero);
    printf("El promedio es %.2f",acum/CANTIDAD);
    return 0;
}
