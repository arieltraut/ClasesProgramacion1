#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "Alquiler.h"
#include "Vista.h"
#include "DataManager.h"

static ArrayList* nominaCliente;
static ArrayList* nominaAlquiler;

static int proximoIdCliente=0;
static int getNewIdCliente();
static int setNewIdCliente(int id);

static int proximoIdAlquiler=0;
static int getNewIdAlquiler();
static int setNewIdAlquiler(int id);

void cont_init()
{
    nominaCliente = al_newArrayList();
    nominaAlquiler = al_newArrayList();
    setNewIdCliente(dm_readAll(nominaCliente) + 1);
    setNewIdAlquiler(dm_readAllAlquiler(nominaAlquiler) + 1);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaCliente (char* nombre,char* apellido,char* dni)
{
    Cliente* auxCliente;
    auxCliente = cliente_new(getNewIdCliente(),nombre,apellido,CLIENTE_ESTADO_ACTIVO,dni);
    al_add(nominaCliente,auxCliente);
    dm_saveAll(nominaCliente);
    return 0;
}

int cont_bajaCliente (int id)
{
    Cliente* auxCliente;
    auxCliente=cliente_findById(nominaCliente,id);
    if(auxCliente!=NULL)
    {
        cliente_setEstado(auxCliente,CLIENTE_ESTADO_INACTIVO);
        dm_saveAll(nominaCliente);
    }

    return 0;
}

int cont_modificarCliente (char* nombre,char* apellido,char* dni, int id, int estado)
{
    Cliente* auxCliente;

    auxCliente=cliente_findById(nominaCliente,id);

    if(auxCliente!=NULL)
    {
        cliente_setNombre(auxCliente,nombre);
        cliente_setApellido(auxCliente,apellido);
        cliente_setDni(auxCliente,dni);
        cliente_setEstado(auxCliente,estado);
        dm_saveAll(nominaCliente);
    }

    return 0;
}

int cont_listarCliente ()
{
    vista_mostrarCliente(nominaCliente);
    return 0;
}

int cont_existeCliente (int id)
{
    int retorno = -1;
    Cliente* auxCliente = cliente_findById(nominaCliente,id);

    if (auxCliente != NULL && cliente_getEstado(auxCliente) == CLIENTE_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
    return retorno;
}

static int getNewIdCliente()
{
    return proximoIdCliente++;
}

static int setNewIdCliente(int id)
{
    proximoIdCliente = id;
    return 0;
}


//***************************Alquiler*************

int cont_altaAlquiler (int idCliente,int equipo,int operador,int tiempoEstimado)
{
    Alquiler* auxAlquiler;
    auxAlquiler = alquiler_new(getNewIdAlquiler(),idCliente, equipo,ESTADO_ALQUILADO,operador,tiempoEstimado,0);
    al_add(nominaAlquiler,auxAlquiler);
    dm_saveAllAlquiler(nominaAlquiler);
    return 0;
}

int cont_bajaAlquiler (int id, int tiempoReal)
{
    Alquiler* auxAlquiler;
    auxAlquiler=alquiler_findById(nominaAlquiler,id);
    if(auxAlquiler!=NULL)
    {
        alquiler_setTiempoReal(auxAlquiler,tiempoReal);
        alquiler_setEstado(auxAlquiler,ESTADO_FINALIZADO);
        dm_saveAllAlquiler(nominaAlquiler);
    }

    return 0;
}


int cont_modificarAlquiler (char* descripcion, int id, int estado)
{
    /*Alquiler* auxAlquiler;

    auxAlquiler=alquiler_findById(nominaAlquiler,id);

    if(auxAlquiler!=NULL)
    {
        alquiler_setDescripcion(auxAlquiler,descripcion);
        alquiler_setEstado(auxAlquiler,estado);
        dm_saveAllAlquiler(nominaAlquiler);
    }
*/
    return 0;
}


int cont_listarAlquiler ()
{
    vista_mostrarAlquiler(nominaAlquiler);
    return 0;
}

int cont_existeAlquiler (int id)
{
    int retorno = -1;
    Alquiler* auxAlquiler = alquiler_findById(nominaAlquiler,id);

    if (auxAlquiler != NULL && alquiler_getEstado(auxAlquiler) == ESTADO_ALQUILADO)
    {
        retorno = 0;
    }
    return retorno;
}

static int getNewIdAlquiler()
{
    return proximoIdAlquiler++;
}

static int setNewIdAlquiler(int id)
{
    proximoIdAlquiler = id;
    return 0;
}



