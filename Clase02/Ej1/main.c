#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numeroIngresado;
    float maxNum;
    float minNum;
    float acum=0;
    float prom;
    int cantidadNumeros=0;
    char respuesta;

    do
    {
        printf("Ingrese un numero \n");
        scanf("%f",&numeroIngresado);
        acum = acum + numeroIngresado;

        if(cantidadNumeros==0)
        {
            maxNum = numeroIngresado;
            minNum = numeroIngresado;
        }

        if(numeroIngresado>maxNum)
        {
            maxNum = numeroIngresado;
        }
        if(numeroIngresado<minNum)
        {
            minNum = numeroIngresado;
        }

        cantidadNumeros++;

        printf("Desea continuar? s/n \n");
        fflush(stdin); //siempre debe ir para borrar el enter, borra el buffer que genero tocar enter para ingresar s o n.
        scanf("%c",&respuesta);

    }while(respuesta=='s');

    prom = acum / cantidadNumeros;
    printf("El numero maximo es: %.2f \n",maxNum);
    printf("El numero minimo es: %.2f \n",minNum);
    printf("El promedio es %.2f \n",prom);

}
