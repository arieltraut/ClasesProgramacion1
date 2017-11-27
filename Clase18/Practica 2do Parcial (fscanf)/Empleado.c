#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Empleado.h"


Empleado* emp_new(int id, char* nombre, float salario, char estado)
{
    Empleado* nuevoEmpleado = malloc(sizeof(Empleado));
    emp_setNombre(nuevoEmpleado,nombre);
    emp_setId(nuevoEmpleado,id);
    emp_setSalario(nuevoEmpleado,salario);
    emp_setEstado(nuevoEmpleado,estado);

    return nuevoEmpleado;
}


int emp_delete(Empleado* this)
{
    free(this);
    return 0;
}


int emp_setNombre(Empleado* this,char* nombre)
{
    strcpy(this->nombre,nombre);
    return 0;
}


char* emp_getNombre(Empleado* this)
{
    return this->nombre;
}

int emp_setId(Empleado* this,int id)
{
    this->id=id;
    return 0;
}


int emp_getid(Empleado* this)
{
    return this->id;
}

int emp_setSalario(Empleado* this,float salario)
{
    this->salario=salario;
    return 0;
}


float emp_getSalario(Empleado* this)
{
    return this->salario;
}

int emp_setEstado(Empleado* this,int estado)
{

    this->estado = estado;
    return 0;
}

int emp_getEstado(Empleado* this)
{
    return this->estado;
}


int emp_compararEmpleado(void* pEmpleadoA,void* pEmpleadoB)
{

    if(((Empleado*)pEmpleadoA)->salario > ((Empleado*)pEmpleadoB)->salario)
    {
        return 1;
    }
    if(((Empleado*)pEmpleadoA)->salario < ((Empleado*)pEmpleadoB)->salario)
    {
        return -1;
    }
    return 0;
}

int emp_compararEmpleadoPorNombre(void* pEmpleadoA,void* pEmpleadoB)
{

    if((strcmp(((Empleado*)pEmpleadoA)->nombre,((Empleado*)pEmpleadoB)->nombre)==1))
    {
        return 1;
    }
    if((strcmp(((Empleado*)pEmpleadoA)->nombre,((Empleado*)pEmpleadoB)->nombre)==-1))
    {
        return -1;
    }
    return 0;
}

void emp_printEmpleado(void* empleado)
{
    if(empleado != NULL)
    {
        Empleado* auxEmpleado = (Empleado*)empleado;
    printf("%d,%s;%.2f\n",emp_getid(auxEmpleado),emp_getNombre(auxEmpleado),emp_getSalario(auxEmpleado));
    }
}
