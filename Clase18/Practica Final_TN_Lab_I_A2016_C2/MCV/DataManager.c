#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "Alquiler.h"
#include "DataManager.h"
#include "Validaciones.h"

int dm_saveAll(ArrayList* pArrayClientes)
{
    int i;
    int retorno=-1;
    FILE* pArchivoClientes=fopen(ARCHIVO_SOCIOS,"wb");
    void* pCliente=NULL;
    if(pArchivoClientes!=NULL)
    {
        for(i=0;i<al_len(pArrayClientes);i++)
        {
            pCliente=al_get(pArrayClientes,i);
            fwrite(pCliente,sizeof(Cliente),1,pArchivoClientes);
            retorno=0;
        }
    }
    fclose(pArchivoClientes);
    return retorno;
}

int dm_readAll(ArrayList* pArrayClientes)
{
    int retorno=-1;
    Cliente auxCliente;
    int maxId=0;
    Cliente* pCliente=NULL;
    FILE* pArchivoClientes=fopen(ARCHIVO_SOCIOS,"rb");

    if(pArchivoClientes!=NULL)
    {
        do{
            if(fread(&auxCliente,sizeof(Cliente),1,pArchivoClientes)==1)
            {
                pCliente=cliente_new(auxCliente.id,auxCliente.nombre,auxCliente.apellido,auxCliente.estado,auxCliente.dni);
                al_add(pArrayClientes,pCliente);
                if(auxCliente.id>maxId)
                {
                    maxId=auxCliente.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoClientes));
        fclose(pArchivoClientes);
    }
    return retorno;
}

//**********************************************Alquiler

int dm_saveAllAlquiler(ArrayList* pArrayAlquiler)
{
    int i;
    int retorno=-1;
    FILE* pArchivoAlquiler=fopen(ARCHIVO_ALQUILER,"wb");
    void* pAlquiler=NULL;
    if(pArchivoAlquiler!=NULL)
    {
        for(i=0;i<al_len(pArrayAlquiler);i++)
        {
            pAlquiler=al_get(pArrayAlquiler,i);
            fwrite(pAlquiler,sizeof(Alquiler),1,pArchivoAlquiler);
            retorno=0;
        }

    }
    fclose(pArchivoAlquiler);
    return retorno;
}

int dm_readAllAlquiler(ArrayList* pArrayAlquiler)
{
    int retorno=-1;
    Alquiler auxAlquiler;
    int maxId=0;
    Alquiler* pAlquiler=NULL;
    FILE* pArchivoAlquiler=fopen(ARCHIVO_ALQUILER,"rb");

    if(pArchivoAlquiler!=NULL)
    {
        do{
            if(fread(&auxAlquiler,sizeof(Alquiler),1,pArchivoAlquiler)==1)
            {
                pAlquiler=alquiler_new(auxAlquiler.id,auxAlquiler.idCliente,auxAlquiler.equipo,auxAlquiler.estado,auxAlquiler.operador,auxAlquiler.tiempoEstimado,auxAlquiler.tiempoReal);
                al_add(pArrayAlquiler,pAlquiler);
                if(auxAlquiler.id>maxId)
                {
                    maxId=auxAlquiler.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoAlquiler));
        fclose(pArchivoAlquiler);
    }
    return retorno;
}





/////////////////////////////////////////////////////LEER DESDE TEXTO EN VEZ DE BINARIO
/*
int dm_parserSocio(ArrayList* pArraySocios)
{
    FILE *pFile;
    Socio* pSocio;
    int maxId=0, retorno;

    char id[50],name[50],lastName[50],dni[50],estado[50];

    pFile = fopen(ARCHIVO_SOCIOS,"r");

    char aux[200];
    fgets(aux,200,pFile); //leer primer fila
    //fscanf(pFile,"%[^\n]\n",aux,aux,aux,aux,aux);

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,dni,estado);
        if (val_getUnsignedIntFromFile(id,0,9999)==0)
        {
            if (val_getNombreFromFile(name,50)==0)
            {
                if (val_getNombreFromFile(lastName,50)==0)
                {
                    if(val_getDniFromFile(dni,50)==0)
                    {
                        if(val_getUnsignedIntFromFile(estado,0,1)==0) //ver
                        {
                            pSocio = soc_new(name,lastName,dni,atoi(id),atoi(estado));
                            al_add(pArraySocios,pSocio);
                            if(pSocio->id>maxId)
                            {
                                maxId=pSocio->id;
                            }
                            retorno=maxId;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}
*/
