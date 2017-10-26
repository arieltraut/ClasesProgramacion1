#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llamada.h"
#include "validar.h"

int llam_alta (sLlamada* llamada, int index, int len)
{
    int retorno = -1;
    int id_llam;
    char b_id_asoc[50];
    char bMotivo[51];


    if(llamada != NULL && index >= 0 && index < len)
    {
        if(val_getNombre(bMotivo,"\nMOTIVO?\n","\nError:\n",2,51)==0)
        {
            if(val_getEdad(b_id_asoc,"\nID Asociado?\n","\nError:\n",2,3)==0)
                {
                    id_llam = buscarProximoIdLlamada(llamada,len);
                    if(id_llam != -1)
                    {
                        strncpy(llamada[index].motivo,bMotivo,51);
                        llamada[index].id_asoc = atoi(b_id_asoc);
                        llamada[index].estado = ESTADO_PENDIENTE;
                        llamada[index].id_llam = id_llam;
                        retorno = 0;
                    }
                 }
        }
    }
    return retorno;
}

int llam_initllamada (sLlamada* llamada, int longitud)
{
    int retorno = -1;
    int i;
    if(llamada != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            llamada[i].flag = LLAMADA_LIBRE;
        }
    }
    return retorno;
}

int llam_buscarIndiceLibre (sLlamada* llamada, int longitud)
{
    int retorno = -1;
    int i;
    if(llamada != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(llamada[i].flag == LLAMADA_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}


int buscarProximoIdLlamada (sLlamada* llamada, int longitud)
{
    int i;
    int idMax = -1;
    if(llamada != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(llamada[i].flag == LLAMADA_LIBRE)
            {
                if(idMax < llamada[i].id_llam)
                    idMax = llamada[i].id_llam;
            }
        }
    }
    return idMax + 1;
}
