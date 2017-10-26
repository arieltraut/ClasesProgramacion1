#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asociados.h"
#include "validar.h"


int asoc_alta (sAsociado* asociado, int index, int len)
{
    int retorno = -1;
    int id;
    char bNombre[51];
    char bApellido[51];
    char bEdad[3];
    char bDni[8];


    if(asociado != NULL && index >= 0 && index < len)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?\n","\nError:\n",2,51)==0)
        {
            //printf("NOMBRE ok");
            if(val_getNombre(bApellido,"\nAPELLIDO?\n","\nError:\n",2,51)==0)
            {
                //printf("Float ok");
                if(val_getEdad(bEdad,"\nEdad?\n","\nError:\n",2,3)==0)
                {
                    if(val_getDni(bDni,"\nDNI?\n","\nError:\n",2,8)==0)
                    {
                        id = buscarProximoId(asociado,len);
                        if(id != -1)
                        {
                            strncpy(asociado[index].nombre,bNombre,51);
                            strncpy(asociado[index].apellido,bApellido,51);
                            asociado[index].edad = atoi(bEdad);
                            asociado[index].dni = atoi(bDni);
                            asociado[index].flag = ASOCIADO_OCUPADO;
                            asociado[index].id_asoc = id;
                            retorno = 0;
                        }
                    }

                 }
            }

        }
    }
    return retorno;
}

int asoc_modificar(sAsociado asociado[], int len, int id)
{
    /*1. busco la pos donde esta el id
      2. pido datos nuevos
      3. carlo en los campos */
    int retorno = -1;
    //val_getUnsignedInt(bufferAux,"\nIngrese ID a modificar","\n.....\n",3,50)
    int index = asoc_buscarIndicePorId(asociado,len,id);

    if (index != -1)
    {
        //el id esta
        //pido datos a modificar
        char bEdad[3];
        if (val_getEdad(bEdad,"\nEdad?\n","\nError:\n",2,3)==0)
        {
            asociado[index].edad = atoi(bEdad);
            retorno = 0;
        }

    }
    return retorno;
}

int asoc_buscarIndicePorId(sAsociado asociado[],int len,int id)
{
    int i;
    int retorno = -1;
    for(i=0;i<len;i++)
        {
            if(asociado[i].flag == ASOCIADO_OCUPADO)
            {
                if(asociado[i].id_asoc == id)        //(strcmp(asociado[i].a, asociado[i].dni) == 0)  para comparar string
                {
                    retorno = i;
                    break;
                }
            }
        }
    return retorno;
}

int asoc_initAsociado (sAsociado* asociado, int longitud)
{
    int retorno = -1;
    int i;
    if(asociado != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            asociado[i].flag = ASOCIADO_LIBRE;
        }
    }
    return retorno;
}

int asoc_buscarIndiceLibre (sAsociado* asociado, int longitud)
{
    int retorno = -1;
    int i;
    if(asociado != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(asociado[i].flag == ASOCIADO_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}


int buscarProximoId (sAsociado* asociado, int longitud)
{
    int i;
    int idMax = -1;
    if(asociado != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(asociado[i].flag == ASOCIADO_OCUPADO)
            {
                if(idMax < asociado[i].id_asoc)
                    idMax = asociado[i].id_asoc;
            }
        }
    }
    return idMax + 1;
}

void asoc_printAsoc(sAsociado asociado[] , int longitud)
{
    int i;
    for (i=0;i<longitud;i++)
    {
        if(asociado[i].flag==ASOCIADO_OCUPADO)
        {
            printf("ID: %d, Nombre y apellido: %s %s, edad: %d",asociado[i].id_asoc,asociado[i].nombre,asociado[i].apellido,asociado[i].edad);
        }

    }
}

