#include <stdio.h>
#include <stdlib.h>


typedef struct{

    int edad;
    char nombre[50];

}Persona;

int cargarPersona(Persona* pPersona);
int printPersona(Persona* pPersona);

int main()
{
    Persona persona;

    cargarPersona(&persona);

    printPersona(&persona);




    return 0;
}

int cargarPersona(Persona* pPersona)
{
    //pPersona->edad = 9;
    //pPersona->nombre = {'H','o','l','a',0};

    printf("Ingrese Edad");
    scanf("%d",&pPersona->edad);
    printf("Ingrese Nombre");
    scanf("%s",pPersona->nombre);


    //*************************** 3 formas de hacerlo
    //pPersona->edad = 9;

    //(*pPersona).edad = 9;

    //Persona aux = *pPersona;
    //aux.edad = 88;
    //*pPersona = aux;

    return 1;
}

int printPersona(Persona* pPersona)
{
    printf("%d",pPersona->edad);
    printf("%s",pPersona->nombre);
}


//*(p+i) equivale a  p[i]
