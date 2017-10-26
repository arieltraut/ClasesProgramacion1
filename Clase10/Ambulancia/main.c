#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asociados.h"
#include "llamada.h"
#include "validar.h"

int main()
{
    sAsociado arrayAsociado[CANTIDAD_ASOCIADOS];
    sLlamada arrayLlamada[CANTIDAD_LLAMADAS];

    char bufferInt[40];

    asoc_initAsociado (arrayAsociado, CANTIDAD_ASOCIADOS);

    do
    {
        val_getUnsignedInt(bufferInt,"\n1-Alta\n2-Modificar\n3-Baja\n4-Nueva llamada\n5-Asignar Ambulancia\n6-Informar\n8-Salir\n","\nSolo 1 y 2\n",2,40);

        switch(atoi(bufferInt))
        {
            case 1:

                asoc_alta (arrayAsociado, asoc_buscarIndiceLibre (arrayAsociado, CANTIDAD_ASOCIADOS),CANTIDAD_ASOCIADOS);
                break;

            case 2:
                val_getUnsignedInt(bufferInt,"Ingrese ID a modificar","\nIngrese solo numeros\n",2,40);
                asoc_modificar(arrayAsociado, CANTIDAD_ASOCIADOS, atoi(bufferInt));
                break;
            case 4:
                llam_alta (arrayLlamada, llam_buscarIndiceLibre (arrayLlamada, CANTIDAD_LLAMADAS), CANTIDAD_LLAMADAS);

            case 6:
                asoc_printAsoc(arrayAsociado,CANTIDAD_ASOCIADOS);
                break;
        }

    }while( atoi(bufferInt) != 8);







    return 0;
}
