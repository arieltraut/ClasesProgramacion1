#include <stdio.h>
#include <stdlib.h>
#define SUMA 0
#define RESTA 1
#define MULTIPLICACION 2
#define DIVISION 3


int calculadora (float*, float, float, char);

int main()
{
    float numUno, numDos, resOperacion;

    printf("Ingrese un numero\n");
    scanf("%f", &numUno);
    printf("Ingrese otro numero\n");
    scanf("%f", &numDos);

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



//** return (0) OK  -- (-1) error division -- (-2) operacion no soportada

int calculadora (float* resultado, float num1, float num2, char operacion)
{
    int retorno = -1;

    switch(operacion)
    {
        case SUMA:
            *resultado = num1 + num2;
            retorno = 0;
        break;
        case RESTA:
            *resultado = num1 - num2;
            retorno = 0;
        break;
        case MULTIPLICACION:
            *resultado = num1 * num2;
            retorno = 0;
        break;
        case DIVISION:
            if(num2 != 0)
            {
                *resultado = num1 / num2;
                retorno = 0;
            }
        break;
        default:
            retorno = -2;
        break;
    }

    return retorno;
}
