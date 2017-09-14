#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char auxiliar[51];
    strcpy(auxiliar,"-Hello world!\n");
    strncpy(auxiliar,"-Hello world!\n",51); //para que no se pase y escriba mas que el tamaño del array (51)
    auxiliar[50] = '\0';

    printf("----> %s  - Largo: %d",auxiliar, strlen(auxiliar)); //strlen cuenta cantidad caracteres

    printf ("%d",strcmp("A","B")); //compara cada caracter de un string con otro
    printf ("%d",strcmp("B","A"));

    char buffer2[40] = "HOLA";
    char buffer[4];

    fgets(buffer,4,stdin); //reemplaza a scanf
    printf("\n %s",buffer);
    printf("\n %s",buffer);





    return 0;
}
