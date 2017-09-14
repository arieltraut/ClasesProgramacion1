#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sPersona          // o typedef struct
{
    char nombre[21];
    char apellido [21];
    int edad;
};                      // } sPersona;


int main()
{
    struct sPersona aux; //creacion variable aux del tipo struct persona

    strncpy(aux.nombre,"Juan",20);
    aux.nombre[20] = '\0';
    strncpy(aux.apellido,"Perez",20);
    aux.edad = 30;

    printf("El nombre es %s %s y la edad es %d",aux.nombre,aux.apellido,aux.edad);

return 0;
}
