#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Socio.h"
#include "DataManager.h"

int dm_saveAll(ArrayList* listaSocios)
{
    FILE* pFile;
    Socio* pSocio;
    int i;
    pFile = fopen(ARCHIVO_SOCIOS,"wb");

    if(pFile != NULL)
    {
        for(i=0; i < al_len(listaSocios); i++)
        {
            pSocio = al_get(listaSocios,i);
            fwrite(pSocio,sizeof(Socio),1,pFile);
        }
        fclose(pFile);

    }
    return 0;
}

int dm_readAll(ArrayList* listaSocios)
{
    FILE* pFile;
    Socio auxSocio;
    Socio* pSocio;
    int maxId = 0;
    pFile = fopen(ARCHIVO_SOCIOS,"rb");

    if(pFile != NULL)
    {
        do //no hacer while porque primero hay q saber si fread pudo leer
        {
            if(fread(&auxSocio,sizeof(Socio),1,pFile) == 1)  //& direccion de memoria de la variable socio creada
            {
                pSocio = soc_new(auxSocio.nombre,auxSocio.apellido,auxSocio.dni,auxSocio.id,auxSocio.estado);
                al_add(listaSocios,pSocio);
                if(maxId<auxSocio.id)
                    maxId = auxSocio.id;
            }

        }while (!feof(pFile));

    return maxId;
    }
    return -1;
}


