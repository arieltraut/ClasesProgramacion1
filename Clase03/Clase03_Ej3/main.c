#include <stdio.h>
#include <stdlib.h>

int operaciones (float* resSum, float* resResta, float* resMulti, float* resDiv, float a, float b);

int main()
{
    float u,v,w,x,y,z;

    printf("Ingrese primer numero\n");
    scanf("%f",&y);
    printf("Ingrese segundo numero\n");
    scanf("%f",&z);


    if (operaciones(&u,&v,&w,&x,y,z) == -1)
    {
        printf("eRROR \n");
    }
    else
    {
        printf("El resultado de la division es %.2f \n", x);
    }
    printf("El resultado de la suma es %.2f \n", u);
    printf("El resultado de la resta es %.2f \n", v);
    printf("El resultado de la multiplicacion es %.2f \n", w);


    return 0;
}
/** \brief
 *
 * \param
 * \param
 * \return (0) ok - (-1) error
 *
 */

int operaciones (float* resSum, float* resResta, float* resMulti, float* resDiv, float a, float b)
{
    *resSum = a + b;
    *resResta = a - b;
    *resMulti = a * b;

    int retorno = -1;
    if (b != 0)
    {
        *resDiv = a / b;
        retorno = 0;
    }
    return retorno;
}
