#include <stdio.h>
#include <stdlib.h>
#define NUM_ITERACION 3

int main()
{
    int numeroUsuario;
    int i;
    int contadorNegativos=0;
    int contadorPositivos;
    int acumPositivos;
    int acumNegativos;
    float promPositivos;
    float promNegativos;

    for (i=0;i<NUM_ITERACION;i++)
    {
        printf("Ingrese un numero:\n");
        scanf("%d", &numeroUsuario);

        if (numeroUsuario < 0)
        {
            contadorNegativos++;
            acumNegativos = acumNegativos + numeroUsuario;
        }else
        {
            acumPositivos = acumPositivos + numeroUsuario;
        }
    }
    contadorPositivos = NUM_ITERACION-contadorNegativos;
    if (contadorNegativos!=0)
    {
        promNegativos = acumNegativos / contadorNegativos;
    }
    if (contadorPosivos!=0)
    {
        promPositivos = acumPositivos / contadorPositivos;
    }


    printf("La cantidad de negativos es %d y positivos es %d", contadorNegativos,contadorPositivos);
    printf("El promedio de negativos es %f /n El promedio de positivos es %f",promNegativos,promPositivos);
    return 0;
}
