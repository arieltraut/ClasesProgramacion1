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
static ArrayList* listaServicios;
static ArrayList* listaRelSyS;
static int proximoIdSocio=0;
static int proximoIdServicios=0;
static int proximoIdRelSyS=0;
static int getNewIdSocio();
static int getNewIdServicios();
static int getNewIdRelSyS();
static int setNewIdSocio(int id);
static int setNewIdServicios(int id);
static int setNewIdRelSyS(int id);

void cont_init()
{
    nominaSocios = al_newArrayList();
    listaServicios = al_newArrayList();
    listaRelSyS = al_newArrayList();
    setNewIdSocio(dm_readAll(nominaSocios) + 1);
    setNewIdServicios(dm_readAllServicios(listaServicios) + 1);
    setNewIdRelSyS(dm_readAllRelSocioServicio(listaRelSyS) + 1);
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
    al_add(listaServicios,auxServicios);
    dm_saveAllServicios(listaServicios);
    return 0;
}

int cont_bajaServicio (int id)
{
    Servicios* auxServicios;
    auxServicios=serv_findById(listaServicios,id);
    if(auxServicios!=NULL)
    {
        serv_setEstado(auxServicios,SERVICIOS_ESTADO_INACTIVO);
        dm_saveAllServicios(listaServicios);
    }

    return 0;
}


int cont_modificarServicios (char* descripcion, int id, int estado)
{
    Servicios* auxServicios;

    auxServicios=serv_findById(listaServicios,id);

    if(auxServicios!=NULL)
    {
        serv_setDescripcion(auxServicios,descripcion);
        serv_setEstado(auxServicios,estado);
        dm_saveAllServicios(listaServicios);
    }

    return 0;
}


int cont_listarServicios ()
{
    vista_mostrarServicios(listaServicios);
    return 0;
}

int cont_existeServicio (int id)
{
    int retorno = -1;
    Servicios* auxServicio = serv_findById(listaServicios,id);

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

int cont_altaRelacionSocioServicio (int idSocio, int idServicio)
{

        int retorno = -1;
        RelSocioServicio* auxRelSocioServicio;// = relSyS_findByIdSocioAndIdServicio(listaRelSyS,idSocio,idServicio);

        if(auxRelSocioServicio == NULL && cont_existeSocio(idSocio) == 0 && cont_existeServicio(idServicio) == 0)
        {

            auxRelSocioServicio = relSyS_new(getNewIdRelSyS(),idSocio,idServicio,REL_SOCIO_SERVICIO_ESTADO_ACTIVO);
            al_add(listaRelSyS,auxRelSocioServicio);
            dm_saveAllRelSocioServicio(listaRelSyS);
            retorno = 0;
        }
        return retorno;


    /*
    RelSocioServicio* auxRelSocioServicio;
    auxRelSocioServicio = relSyS_new(getNewIdRelSyS(),idSocio,idServicio,REL_SOCIO_SERVICIO_ESTADO_ACTIVO);
    al_add(listaRelSyS,auxRelSocioServicio);
    dm_saveAllRelSocioServicio(listaRelSyS);*/
}

int cont_bajaRelacionSocioServicio (int id)
{
    RelSocioServicio* auxRelSocioServicio;
    auxRelSocioServicio = relSyS_findById(listaRelSyS,id);
    if(auxRelSocioServicio!=NULL)
    {
        relSyS_setEstado(auxRelSocioServicio,REL_SOCIO_SERVICIO_ESTADO_INACTIVO);
        dm_saveAllRelSocioServicio(listaRelSyS);
    }

    return 0;
}

int cont_listarRelacionSocioServicio ()
{
    vista_mostrarRelacionSocioServicio(listaRelSyS);
    return 0;
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



