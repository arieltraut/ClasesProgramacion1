
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Servicios.h"
#include "RelSocioServicio.h"
#include "DataManager.h"
#include "Validaciones.h"

int dm_saveAll(ArrayList* pArraySocios)
{
    int i;
    int retorno=-1;
    FILE* pArchivoSocios=fopen(ARCHIVO_SOCIOS,"wb");
    void* pSocio=NULL;
    if(pArchivoSocios!=NULL)
    {
        for(i=0;i<al_len(pArraySocios);i++)
        {
            pSocio=al_get(pArraySocios,i);
            fwrite(pSocio,sizeof(Socio),1,pArchivoSocios);
            retorno=0;
        }
    }
    fclose(pArchivoSocios);
    return retorno;
}

int dm_readAll(ArrayList* pArraySocios)
{
    int retorno=-1;
    Socio auxServicio;
    int maxId=0;
    Socio* pSocio=NULL;
    FILE* pArchivoSocios=fopen(ARCHIVO_SOCIOS,"rb");

    if(pArchivoSocios!=NULL)
    {
        do{
            if(fread(&auxServicio,sizeof(Socio),1,pArchivoSocios)==1)
            {
                pSocio=soc_new(auxServicio.nombre,auxServicio.apellido,auxServicio.dni,auxServicio.id,auxServicio.estado);
                al_add(pArraySocios,pSocio);
                if(auxServicio.id>maxId)
                {
                    maxId=auxServicio.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoSocios));
        fclose(pArchivoSocios);
    }
    return retorno;
}

//**********************************************SERVICIOS

int dm_saveAllServicios(ArrayList* pArrayServicios)
{
    int i;
    int retorno=-1;
    FILE* pArchivoServicios=fopen(ARCHIVO_SERVICIOS,"wb");
    void* pServicio=NULL;
    if(pArchivoServicios!=NULL)
    {
        for(i=0;i<al_len(pArrayServicios);i++)
        {
            pServicio=al_get(pArrayServicios,i);
            fwrite(pServicio,sizeof(Servicios),1,pArchivoServicios);
            retorno=0;
        }

    }
    fclose(pArchivoServicios);
    return retorno;
}

int dm_readAllServicios(ArrayList* pArrayServicios)
{
    int retorno=-1;
    Servicios auxServicio;
    int maxId=0;
    Servicios* pServicio=NULL;
    FILE* pArchivoServicios=fopen(ARCHIVO_SERVICIOS,"rb");

    if(pArchivoServicios!=NULL)
    {
        do{
            if(fread(&auxServicio,sizeof(Servicios),1,pArchivoServicios)==1)
            {
                pServicio=serv_new(auxServicio.descripcion,auxServicio.id,auxServicio.estado);
                al_add(pArrayServicios,pServicio);
                if(auxServicio.id>maxId)
                {
                    maxId=auxServicio.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoServicios));
        fclose(pArchivoServicios);
    }
    return retorno;
}


//*******************************************RELACION SOCIO - SERVICIO

int dm_saveAllRelSocioServicio(ArrayList* pArrayRelSocioServicio)
{
    int i;
    int retorno=-1;
    FILE* pArchivoRelSocioServicio=fopen(ARCHIVO_REL_SOCIO_SERVICIO,"wb");
    void* pRelSocioServicio=NULL;
    if(pArchivoRelSocioServicio!=NULL)
    {
        for(i=0;i<al_len(pArrayRelSocioServicio);i++)
        {
            pRelSocioServicio=al_get(pArrayRelSocioServicio,i);
            fwrite(pRelSocioServicio,sizeof(RelSocioServicio),1,pArchivoRelSocioServicio);
            retorno=0;
        }
    }
    fclose(pArchivoRelSocioServicio);
    return retorno;
}

int dm_readAllRelSocioServicio(ArrayList* pArrayRelSocioServicio)
{
    int retorno=-1;
    RelSocioServicio auxRelSocioServicio;
    int maxId=0;
    RelSocioServicio* pRelSocioServicio=NULL;
    FILE* pArchivoRelSocioServicio=fopen(ARCHIVO_REL_SOCIO_SERVICIO,"rb");

    if(pArchivoRelSocioServicio!=NULL)
    {
        do{
            if(fread(&auxRelSocioServicio,sizeof(RelSocioServicio),1,pArchivoRelSocioServicio)==1)
            {
                pRelSocioServicio=relSyS_new(auxRelSocioServicio.id,auxRelSocioServicio.idSocio,auxRelSocioServicio.idServicio,auxRelSocioServicio.estado);
                al_add(pArrayRelSocioServicio,pRelSocioServicio);
                if(auxRelSocioServicio.id>maxId)
                {
                    maxId=auxRelSocioServicio.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoRelSocioServicio));
        fclose(pArchivoRelSocioServicio);
    }
    return retorno;
}



/////////////////////////////////////////////////////LEER DESDE TEXTO EN VEZ DE BINARIO

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
