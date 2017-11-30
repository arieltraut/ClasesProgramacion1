#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "ArrayList.h"


typedef struct
{
    int id;
    char nombre[51];
    float salario;
    int estado;
}Empleado;

#endif // EMPLEADO_H_INCLUDED

#define EMPLEADO_ESTADO_ACTIVO 1
#define EMPLEADO_ESTADO_INACTIVO 0

Empleado* emp_new(int id, char* nombre, float salario, char estado);
int emp_setNombre(Empleado* this,char* nombre);
char* emp_getNombre(Empleado* this);
int emp_setId(Empleado* this,int id);
int emp_getid(Empleado* this);
int emp_setSalario(Empleado* this,float salario);
float emp_getSalario(Empleado* this);
int emp_setEstado(Empleado* this,int estado);
int emp_getEstado(Empleado* this);

int emp_compararEmpleado(void* pEmployeeA,void* pEmployeeB);
int emp_compararEmpleadoPorNombre(void* pEmpleadoA,void* pEmpleadoB);
void emp_printEmpleado(void* empleado);

