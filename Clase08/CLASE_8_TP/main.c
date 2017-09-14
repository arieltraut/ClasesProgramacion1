#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "funciones.h"


typedef struct
{
    char nombre[20];
    char descripcion[64];
    float precio;
    int estaCargado;
}Producto;

int inicializarArray(Producto a[],int len);



int main()
{
    Producto productos[200];

    inicializarArray(productos,200);

    cargarDato(productos,55,"Ingrese edad");


    return 0;
}






int inicializarArray(Producto a[],int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        a[i].estaCargado = 0;
    }
    return 0;
}
