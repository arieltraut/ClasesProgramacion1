#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Empleado.h"
#include "Validaciones.h"

static void cargarData(ArrayList* nuevoArrayList);
static void guardarData(ArrayList*);


int main()
{
    ArrayList* nuevoArrayList = al_newArrayList();


    cargarData(nuevoArrayList);
    al_map(nuevoArrayList,emp_printEmpleado);


    printf("\n\n\n");

    al_sort(nuevoArrayList,emp_compararEmpleadoPorNombre,1);
    al_map(nuevoArrayList,emp_printEmpleado);

    guardarData(nuevoArrayList);

    return 0;
}




static void cargarData(ArrayList* nuevoArrayList)

{
    FILE *pFile;
    Empleado* empleado;

    char id[50],nombre[50],salario[50];

    pFile = fopen("data.csv","r");

    char aux[30];
    fgets(aux,30,pFile);
    while(!feof(pFile))
    {
        fscanf(pFile,"%[^;];%[^;];%[^\n]\n",id,nombre,salario);
        if (val_getUnsignedIntFromFile(id,0,9999)==0)
        {
            if (val_getNombreFromFile(nombre,50)==0)
            {
                if(val_getFloatFromFile(salario,0,999999)==0)
                {
                    empleado = emp_new(atoi(id),nombre,atof(salario),1);
                    al_add(nuevoArrayList,empleado);
                    //printf("%s,%s,%s\n",id,nombre,salario);
                }
            }
        }
    }
}



static void guardarData(ArrayList* nuevoArrayList)
{
    int i;
    FILE *pArchivo;
    pArchivo=fopen("data2.csv", "w");
    if(pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(pArchivo,"id;nombre;salario\n");
        Empleado* auxEmpleado;
        for(i=0; i<al_len(nuevoArrayList); i++)
        {
            auxEmpleado = al_get(nuevoArrayList,i);
            //if(auxEmpleado->estado == EMPLEADO_ESTADO_ACTIVO)
            //{
                fprintf(pArchivo,"%d,%s,%.2f\n", emp_getid(auxEmpleado), emp_getNombre(auxEmpleado),emp_getSalario(auxEmpleado));
            //}
        }
    }
    fclose(pArchivo);
    printf("\nArchivo guardado con exito\n");
}












    /*
    int i;
    for(i=0;i<al_len(nuevoArrayList);i++)
    {
        empleado = al_get(nuevoArrayList,i);
        printf("%d,%s;%.2f\n",emp_getid(empleado),emp_getNombre(empleado),emp_getSalario(empleado));
    }
    */
