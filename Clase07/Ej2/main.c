#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD_ELEMENTOS 5
#define CANTIDAD_CARACTERES 51
#define LF 10


int validarNumero(char* buffer)
{
    int retorno = 0,i=0;
    while(buffer[i]!= '\0')
    {
        printf("%d",buffer[i]);
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != LF )
        {
            retorno = -1;
            break;
        }
        i++;
    }

    return retorno;

}

int getEdad(int* pEdad, char* msg)
{
    char buffer[4096];
    int retorno = -1;
    printf(msg);
    fgets(buffer,4096,stdin);
    buffer[4094] = LF ;
    buffer[4095] = '\0';

    if(validarNumero(buffer) == 0)
    {
        *pEdad = atoi(buffer);
        retorno = 0;
    }
    return retorno;

}

int main()
{
    //char arrayNombres[CANTIDAD_ELEMENTOS][CANTIDAD_CARACTERES];
    int edad[CANTIDAD_ELEMENTOS];
    int i;

    for(i=0; i < CANTIDAD_ELEMENTOS;i++ )
        if(getEdad(&edad[i],"Edad? ") == -1)
        {
            printf("MALlllllllllllllll");
        }

    for (i=0;i<CANTIDAD_ELEMENTOS;i++)
    {
            printf("%d\n",edad[i]);

    }

    return 0;
}
