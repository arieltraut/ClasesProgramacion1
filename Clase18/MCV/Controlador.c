#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Servicios.h"
#include "RelSocioServicio.h"
#include "Vista.h"
#include "DataManager.h"

static ArrayList* nominaSocios;
static ArrayList* nominaServicios;
static ArrayList* nominaRelSyS;

static int proximoIdSocio=0;
static int getNewIdSocio();
static int setNewIdSocio(int id);

static int proximoIdServicios=0;
static int getNewIdServicios();
static int setNewIdServicios(int id);

static int proximoIdRelSyS=0;
static int getNewIdRelSyS();
static int setNewIdRelSyS(int id);


void cont_init()
{
    nominaSocios = al_newArrayList();
    nominaServicios = al_newArrayList();
    nominaRelSyS = al_newArrayList();
    setNewIdSocio(dm_readAll(nominaSocios) + 1);
    setNewIdServicios(dm_readAllServicios(nominaServicios) + 1);
    setNewIdRelSyS(dm_readAllRelSocioServicio(nominaRelSyS) + 1);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaSocio (char* nombre,char* apellido,char* dni)
{
    Socio* auxSocio;
    auxSocio = soc_new(nombre,apellido,dni,getNewIdSocio(),SOCIO_ESTADO_ACTIVO);
    al_add(nominaSocios,auxSocio);
    dm_saveAll(nominaSocios);
    return 0;
}

int cont_bajaSocio (int id)
{
    Socio* auxSocio;
    auxSocio=soc_findById(nominaSocios,id);
    if(auxSocio!=NULL)
    {
        soc_setEstado(auxSocio,SOCIO_ESTADO_INACTIVO);
        dm_saveAll(nominaSocios);
    }

    return 0;
}

int cont_modificarSocio (char* nombre,char* apellido,char* dni, int id, int estado)
{
    Socio* auxSocio;

    auxSocio=soc_findById(nominaSocios,id);

    if(auxSocio!=NULL)
    {
        soc_setNombre(auxSocio,nombre);
        soc_setApellido(auxSocio,apellido);
        soc_setDni(auxSocio,dni);
        soc_setEstado(auxSocio,estado);
        dm_saveAll(nominaSocios);
    }

    return 0;
}

int cont_listarSocios ()
{
    vista_mostrarSocios(nominaSocios);
    return 0;
}

int cont_existeSocio (int id)
{
    int retorno = -1;
    Socio* auxSocio = soc_findById(nominaSocios,id);

    if (auxSocio != NULL && soc_getEstado(auxSocio) == SOCIO_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
    return retorno;
}

static int getNewIdSocio()
{
    return proximoIdSocio++;
}

static int setNewIdSocio(int id)
{
    proximoIdSocio = id;
    return 0;
}


//***************************SERVICIOS*************

int cont_altaServicio (char* descripcion)
{
    Servicios* auxServicios;
    auxServicios = serv_new(descripcion,getNewIdServicios(),SERVICIOS_ESTADO_ACTIVO);
    al_add(nominaServicios,auxServicios);
    dm_saveAllServicios(nominaServicios);
    return 0;
}

int cont_bajaServicio (int id)
{
    Servicios* auxServicios;
    auxServicios=serv_findById(nominaServicios,id);
    if(auxServicios!=NULL)
    {
        serv_setEstado(auxServicios,SERVICIOS_ESTADO_INACTIVO);
        dm_saveAllServicios(nominaServicios);
    }

    return 0;
}


int cont_modificarServicios (char* descripcion, int id, int estado)
{
    Servicios* auxServicios;

    auxServicios=serv_findById(nominaServicios,id);

    if(auxServicios!=NULL)
    {
        serv_setDescripcion(auxServicios,descripcion);
        serv_setEstado(auxServicios,estado);
        dm_saveAllServicios(nominaServicios);
    }

    return 0;
}


int cont_listarServicios ()
{
    vista_mostrarServicios(nominaServicios);
    return 0;
}

int cont_existeServicio (int id)
{
    int retorno = -1;
    Servicios* auxServicio = serv_findById(nominaServicios,id);

    if (auxServicio != NULL && serv_getEstado(auxServicio) == SERVICIOS_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
    return retorno;
}

static int getNewIdServicios()
{
    return proximoIdServicios++;
}

static int setNewIdServicios(int id)
{
    proximoIdServicios = id;
    return 0;
}

//***************************RELACION SOCIO SERVICIO*************

int cont_altaRelSocioServicio (int idSocio, int idServicio)
{
    int retorno = -1;
    RelSocioServicio* auxRelSocioServicio;

    if(auxRelSocioServicio != NULL)
    {
        auxRelSocioServicio = relSyS_new(getNewIdRelSyS(),idSocio,idServicio,REL_SOCIO_SERVICIO_ESTADO_ACTIVO);
        al_add(nominaRelSyS,auxRelSocioServicio);
        dm_saveAllRelSocioServicio(nominaRelSyS);
        retorno = 0;
    }
    return retorno;
}

int cont_bajaRelSocioServicio (int id)
{
    RelSocioServicio* auxRelSocioServicio;
    auxRelSocioServicio = relSyS_findById(nominaRelSyS,id);
    if(auxRelSocioServicio!=NULL)
    {
        relSyS_setEstado(auxRelSocioServicio,REL_SOCIO_SERVICIO_ESTADO_INACTIVO);
        dm_saveAllRelSocioServicio(nominaRelSyS);
    }

    return 0;
}

int cont_listarRelSocioServicio ()
{
    vista_mostrarRelacionSocioServicio(nominaRelSyS);
    return 0;
}

int cont_existeRelSocioServicio (int id)
{
    int retorno = -1;
    RelSocioServicio* auxRelSocioServicio = relSyS_findById(nominaRelSyS,id);

    if (auxRelSocioServicio != NULL && relSyS_getEstado(auxRelSocioServicio) == REL_SOCIO_SERVICIO_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
    return retorno;
}

int cont_existeRelSocioServicioRepetida (int idSocio,int idServicio)
{
    int retorno = -1;
    int i;
    RelSocioServicio* auxRelSocioServicio;
    for(i=0; i<al_len(nominaRelSyS); i++)
    {
        auxRelSocioServicio=al_get(nominaRelSyS,i);
        if(auxRelSocioServicio->estado==REL_SOCIO_SERVICIO_ESTADO_ACTIVO && auxRelSocioServicio->idServicio == idServicio && auxRelSocioServicio->idSocio == idSocio)
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

static int getNewIdRelSyS()
{
    return proximoIdRelSyS++;
}

static int setNewIdRelSyS(int id)
{
    proximoIdRelSyS = id;
    return 0;
}



