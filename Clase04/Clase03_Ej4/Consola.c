#include <stdio.h>
#include <stdlib.h>

int ingreseNumero (char msg [], float* resultado, float max, float min)
{
    int retorno =0;
    float auxiliar;

    printf ("%s", msg); //el string no lleva & (ampersand) antes
    scanf("%f",&auxiliar);

    if (auxiliar>max || auxiliar<min)
    {
        retorno = -1;
    }else
    {
        *resultado = auxiliar;
    }

    return retorno;
}
