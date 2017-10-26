#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"

int main()
{
    Pixel* pPixel;
    Pixel* pAuxiliarPixel;
    Pixel AuxiliarPixel;

    pPixel = pixel_new(100);

    if (pixel_setRgb(pPixel,10,255,255,255) == -1)
    {
        printf("ERROR");
    }


    pAuxiliarPixel = pixel_getRgb(pPixel, 10);
    if (pAuxiliarPixel == NULL)
    {
        printf("ERROR");
    }
    printf("\nRED: %d, GREEN: %d, BLUE: %d",pAuxiliarPixel->r,pAuxiliarPixel->g,pAuxiliarPixel->b);


    AuxiliarPixel = pixel_getPixel(pPixel, 10);
    printf("\nRED: %d, GREEN: %d, BLUE: %d",AuxiliarPixel.r,AuxiliarPixel.g,AuxiliarPixel.b);

    return 0;
}
