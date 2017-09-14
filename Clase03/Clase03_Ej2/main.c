#include <stdio.h>
#include <stdlib.h>
int dividir (float* resultado, float a, float b);

int main()
{
    float x,y,z;

    printf("Ingrese primer numero\n");
    scanf("%f",&x);
    printf("Ingrese segundo numero\n");
    scanf("%f",&y);

    if (dividir(&z,x,y) == -1)
    {
        printf("eRROR");
    }else
    {
        printf("El resultado de la division es %.2f", z);
    }


    return 0;
}
/** \brief divide dos numero flotantes
 *
 * \param
 * \param
 * \return (0) ok - (-1) error
 *
 */

int dividir (float* resultado, float a, float b)
{
    int retorno = -1;
    if (b != 0)
    {
        *resultado = a / b;
        retorno = 0;
    }
    return retorno;
}
