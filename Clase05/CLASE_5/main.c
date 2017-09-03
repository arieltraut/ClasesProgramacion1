#include <stdio.h>
#include <stdlib.h>
#include "Lib.h"
#define CANT_EMPLEADOS 3


int main()
{
    int edad[CANT_EMPLEADOS];
    float salario[CANT_EMPLEADOS];

   obtenerDatos ( edad, salario, CANT_EMPLEADOS);
   mostrarDatos (edad, salario, CANT_EMPLEADOS);
   mostrarMaximo(edad, salario, CANT_EMPLEADOS);

    return 0;
}
