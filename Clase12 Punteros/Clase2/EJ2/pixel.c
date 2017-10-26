#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"

static Pixel arrayPixel[1024];

Pixel* pixel_new(int qty)
{
    Pixel* arrayPixel = NULL;
    arrayPixel = malloc(sizeof(Pixel) * qty);  //malloc reserva memoria  /
    return arrayPixel;
}


void pixel_delete(Pixel* pixel)
{
    if(pPixel != NULL)
        free(pPixel);
}

Pixel* pixel_resize(Pixel* pixel, int newQty)
{
    Pixel* pAuxPixel;
    if(pPixel != NULL)
        prealloc(pPixel,newQty);
}





int pixel_setRgb(Pixel* pixel, int indexPixel, int r, int g, int b)
{
    int retorno = -1;
    if(pixel != NULL && indexPixel >=0)
    {
        retorno = 0;
        (pixel + indexPixel)->r = r;
        (pixel + indexPixel)->g = g;
        (pixel + indexPixel)->b = b;
        //*(pixel + indexPixel).b = b; //es lo mismo
    }

    return retorno;
}



Pixel* pixel_getRgb(Pixel* pixel,int index)
{
    return arrayPixel+index; //devuelve el puntero
}



Pixel pixel_getPixel(Pixel* pixel,int index)
{
    return *(arrayPixel+index); //devuelve el valor
}




