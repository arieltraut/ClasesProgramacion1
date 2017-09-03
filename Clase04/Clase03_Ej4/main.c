#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"
#include "Consola.h"



int main()
{
    float numUno, numDos, resOperacion;

    if (ingreseNumero ("Ingrese un numero \n", &numUno, 100,-100) == -1)
    {
        printf("Numero erroneo \n");
    }

    if (ingreseNumero ("Ingrese otro numero \n", &numDos, 100,-100) == -1)
    {
        printf("Numero erroneo");
    }


    calculadora (&resOperacion, numUno, numDos, SUMA);
    printf("La suma es: %.2f \n",resOperacion);

    calculadora (&resOperacion, numUno, numDos, RESTA);
    printf("La resta es: %.2f \n",resOperacion);

    calculadora (&resOperacion, numUno, numDos, MULTIPLICACION);
    printf("La multiplicacion es: %.2f \n",resOperacion);

    calculadora (&resOperacion, numUno, numDos, DIVISION);
    printf("La division es: %.2f \n",resOperacion);

    return 0;
}



