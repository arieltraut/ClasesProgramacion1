#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socios.h"

static int ultimoValorIdAutoincrementable = -1;

Socio* socio_nuevoSocio(char nombre[],char apellido[],char dni[])
{
    Socio* returnAux = NULL;
    Socio* pSocio = malloc(sizeof(Socio));

    if(pSocio != NULL)
    {
        socio_setNombre(pSocio,nombre);
        socio_setApellido(pSocio,apellido);
        socio_setDni(pSocio,dni);
        socio_setId(pSocio);
        socio_setEstado(pSocio,ESTADO_OCUPADO);

        returnAux = pSocio;
    }
    return returnAux;
}

/*
void socio_delete(Socio* pSocio)
{
    if(pSocio != NULL)
        free(pSocio);
}*/

int socio_setId(Socio* pSocio)
{

    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = 0;
        pSocio->id = socio_generarProximoId();
    }
    return retorno;
}


/** \brief  Busca en el array el id mas alto entre los usados y los borrados
 * \param
 * \return int retorna el id generado
 *
 */
int socio_generarProximoId(void)
{
    ultimoValorIdAutoincrementable++;
    return ultimoValorIdAutoincrementable;
}


int socio_getId(Socio* pSocio)
{
    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = pSocio->id;
    }
    return retorno;
}

int socio_setNombre(Socio* pSocio, char nombre[])
{
    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = 0;
        strncpy(pSocio->nombre,nombre,NAME_SIZE);
    }
    return retorno;
}

char* socio_getNombre(Socio* pSocio)
{
    char* retorno = NULL;
    if(pSocio != NULL)
    {
        retorno = pSocio->nombre;
    }
    return retorno;
}

int socio_setApellido(Socio* pSocio, char apellido[])
{
    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = 0;
        strncpy(pSocio->apellido,apellido,LAST_NAME_SIZE);
    }
    return retorno;
}


char* socio_getApellido(Socio* pSocio)
{
    char* retorno = NULL;
    if(pSocio != NULL)
    {
        retorno = pSocio->apellido;
    }
    return retorno;
}


int socio_setDni(Socio* pSocio, char dni[])
{

    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = 0;
        strcpy(pSocio->dni,dni);
    }
    return retorno;
}

char* socio_getDni(Socio* pSocio)
{
    char* retorno = NULL;
    if(pSocio != NULL)
    {
        retorno = pSocio->dni;
    }
    return retorno;
}

int socio_setEstado(Socio* pSocio, int estado)
{

    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = 0;
        pSocio->flagOcupado = estado;
    }
    return retorno;
}

int socio_getEstado(Socio* pSocio)
{
    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = 0;
        retorno = pSocio->flagOcupado;
    }
    return retorno;
}

