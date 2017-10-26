#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidad1.h"
#include "entidad2.h"
#include "validar.h"

#define LEN_ENTIDADES1 50
#define LEN_ENTIDADES2 50

int main()
{
    Entidad1 listaEntidades1[LEN_ENTIDADES1];
    Entidad2 listaEntidades2[LEN_ENTIDADES2];

    ent1_init(listaEntidades1, LEN_ENTIDADES1);
    ent2_init(listaEntidades2, LEN_ENTIDADES2);

    char opcion[50];

    do
    {
        val_getUnsignedInt(opcion,"\n1-Alta\n2-Modificar\n3-Baja\n4-Nueva llamada\n5-Asignar Ambulancia\n6-Informar\n8-Salir\n","\nSolo 1 y 2\n",3,50);

        switch(atoi(opcion))
        {
            case 1:
                ent1_alta (listaEntidades1, LEN_ENTIDADES1);
                break;

            case 2:
                ent1_modificar(listaEntidades1, LEN_ENTIDADES1);
                break;
            case 3:
                ent1_baja(listaEntidades1, LEN_ENTIDADES1);
                break;
            case 4:
                ent2_alta (listaEntidades1,listaEntidades2, LEN_ENTIDADES2);

            case 6:
                ent1_printArray(listaEntidades1,LEN_ENTIDADES1);
                break;
        }

    }while( atoi(opcion) != 8);

    return 0;
}
