#include "Calculadora.h"


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
