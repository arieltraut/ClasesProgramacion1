#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    FILE* pArchivo;

    pArchivo = fopen("archivo.txt","w");

    if (pArchivo == NULL)
    {
        printf("\nError de Apertura");
        exit(1);
    }
    else
    {
        for(i=1;i<=100;i++)
        {
            fprintf(pArchivo,"%d\n",i);
        }
    }
    fclose(pArchivo);


    char textoLinea[50];

    pArchivo = fopen("archivo.txt","r");

    if (pArchivo == NULL)
    {
        printf("\nError de Apertura");
        exit(1);
    }
    else
    {
        while(!feof(pArchivo))
        {
            //fread(textoLinea,sizeof(char),50,pArchivo);
            fgets(textoLinea,50,pArchivo);
            printf(">>>>>>%s\n",textoLinea);
        }
    }
    fclose(pArchivo);


    return 0;
}
