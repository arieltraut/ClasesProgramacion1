#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"



int controller_altaSocio(ArrayList* listaSocios, char nombre[], char apellido[], char dni[])
{

    Socio* pSocio = socio_nuevoSocio(nombre,apellido,dni);
    al_add(listaSocios,pSocio);

    printf("Se ha cargado el socio ID:%d\n\n",socio_getId(pSocio));

    return 0;
}

int controller_modificarSocio(Socio* pSocio, char nombre[], char apellido[])
{

    socio_setNombre(pSocio,nombre);
    socio_setApellido(pSocio,apellido);

    printf("Se ha modificado el socio ID:%d\n\n",socio_getId(pSocio));

    return 0;
}

int controller_bajaSocio(ArrayList* listaSocios, int id)
{

    //socio_setEstado(pSocio,ESTADO_LIBRE);

    printf("Se ha dado de baja el socio ID:%d\n\n",socio_getId(al_pop(listaSocios,id)));

    return 0;
}




void controller_debugShow(ArrayList* listaSocios)
{
    int i;
    Socio* bSocio;
    if(listaSocios != NULL)
    {
        for(i=0; i < listaSocios->len(listaSocios); i++)
        {
            bSocio = listaSocios->get(listaSocios,i);
            printf("\nID: %d, Nombre: %s, Apellido:  %s, DNI %s\n",bSocio->id,bSocio->nombre,bSocio->apellido,bSocio->dni);
        }
    }
    else if(listaSocios == NULL || listaSocios->isEmpty(listaSocios))
    {
        printf("El array no posee registros. \n\n");
    }
}






//pasar estas a socio.c

int controller_findDni(ArrayList* listaSocios, char dni[])
{
    int i = 0;
    Socio* bSocio;
    for(i=0; i < listaSocios->len(listaSocios); i++)
    {
        bSocio = listaSocios->get(listaSocios,i);
        if((strcmp(bSocio->dni,dni))==0)  //usar getDni
            return -1;
            break;
    }
    return 0;
}

Socio* controller_findById (ArrayList* listaSocios, int id)
{
    int i = 0;
    Socio* bSocio;
    for(i=0; i < listaSocios->len(listaSocios); i++)
    {
        bSocio = listaSocios->get(listaSocios,i);
        if(bSocio->id == id)  //usar getId
            return bSocio;
    }
    return NULL;
}

int controller_findById2 (ArrayList* listaSocios, int id)
{
    int i = 0;
    Socio* bSocio;
    for(i=0; i < listaSocios->len(listaSocios); i++)
    {
        bSocio = listaSocios->get(listaSocios,i);
        if(bSocio->id == id)  //usar getId
            return i;
    }
    return -1;
}
