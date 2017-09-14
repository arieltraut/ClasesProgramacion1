#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
typedef struct
{
    char nombre [51];
    char descripcion [256];
    float precio;
    int estaCargado;

}sProducto;

int inicializarArray (sProducto a[], int len)
{
    int i,retorno = -1;
    for (i=0;i<len;i++)
    {

        if(len < 0)
        {
            retorno;
        }
        else
        {
            a[i].estaCargado =0;
            retorno = 0;
        }
    }

   return retorno;
}

int cargarDatos (sProducto a[], int posicion,char *msg)
{

    char bufferPrecio[4096];
    int retorno = -1;

    fgets(bufferPrecio,4096,stdin);
    bufferPrecio[4095] = '\0';

    while(bufferPrecio[posicion]!= '\0')
    {
        if((bufferPrecio[posicion] < '0' || bufferPrecio[posicion] > '9') && buffer[posicion] != LF )
        {
            retorno = -1;
            break;
        }
        i++;


    }



        return retorno;
}
