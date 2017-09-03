#include "Lib.h"
#include <stdio.h>
#include <stdlib.h>

int obtenerDatos (int edad[], float salario[], int cantMaxima)
{

int i;
float aux;


for(i = 0; i < cantMaxima ; i++)
    {
        printf("\nIngrese edad persona %d: ", i+1);
        scanf("%d", &edad[i]);

        printf("\nIngrese salario persona %d: ", i+1);
        scanf("%f", &aux);

        salario[i] = aux;

    }

return 0;

}

int mostrarDatos(int edad[], float salario[], int cantMaxima){
    int i;

        printf("\nEDAD\t\tSALARIO");
        for(i = 0; i < cantMaxima; i++)
        {
            printf("\n%d\t\t%.2f\n", edad[i], salario[i]);
        }
    return 0;
    }


int mostrarMaximo(int edad[], float salario[], int cantMaxima){

        int i;
        float maxSalario;

        for(i = 0; i < cantMaxima; i++)
        {
             if (salario[i]>maxSalario || i==0)
            {
                maxSalario = salario[i];
            }

        }
        printf("El sueldo maximo es %.2f", maxSalario);
    return 0;
    }
