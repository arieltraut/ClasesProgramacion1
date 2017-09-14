#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#endif // FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre [51];
    char descripcion [256];
    float precio;
    int estaCargado;

}sProducto;

int inicializarArray (sProducto a[], int len);
int cargarDatos (sProducto a[], int posicion,char *msg);




