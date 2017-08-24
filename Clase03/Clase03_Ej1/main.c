#include <stdio.h>
#include <stdlib.h>
float ingreseNumero ();
float calculaArea (float radio);

int main()
{
    float numero;
    float area;

    numero = ingreseNumero();
    area = calculaArea(numero);

    printf("El area es %f", area);


    return 0;
}

float ingreseNumero ()
{
    float auxiliar;
    printf("Ingrese un numero\n");
    scanf("%f",&auxiliar);

    return auxiliar;
}

float calculaArea (float radio)
{
    float area;
    area = 3.14 * radio * radio;

    return area;
}
