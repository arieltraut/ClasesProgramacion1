#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED

typedef struct
{
    int r;
    int g;
    int b;

}Pixel;
#endif // PIXEL_H_INCLUDED

Pixel* pixel_new(int qty);
void pixel_delete(Pixel* pixel);
int pixel_setRgb(Pixel* pixel, int indexPixel, int r, int g, int b);
Pixel* pixel_getRgb(Pixel* pixel,int index);
Pixel pixel_getPixel(Pixel* pixel,int index);





