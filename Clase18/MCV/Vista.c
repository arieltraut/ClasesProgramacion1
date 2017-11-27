#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Socio.h"
#include "Servicios.h"
#include "RelSocioServicio.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

static int idiomaVista = VISTA_IDIOMA_ES;

static void opcionAlta();
static void opcionBaja();
static void opcionModificacion();
static void opcionListado();

static void opcionAltaServicios();
static void opcionBajaServicios();
static void opcionModificacionServicios();
static void opcionListadoServicios();

static void opcionAltaRelSocioServicio();
static void opcionBajaRelSocioServicio();
static void opcionListadoRelSocioServicio();

int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 12)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
        case 1:
            opcionListado();
            break;
        case 2:
            opcionAlta();
            break;
        case 3:
            opcionBaja();
            break;
        case 4:
            opcionModificacion();
            break;
        case 5:
            opcionListadoServicios();
            break;
        case 6:
            opcionAltaServicios();
            break;
        case 7:
            opcionBajaServicios();
            break;
        case 8:
            opcionModificacionServicios();
            break;
        case 9:
            opcionListadoRelSocioServicio();
            break;
        case 10:
            opcionAltaRelSocioServicio();
            break;
        case 11:
            opcionBajaRelSocioServicio();
            break;
        }
    }

    return 0;
}

void vista_mostrarSocios(ArrayList* pListaSocios)
{
    int i;
    Socio* auxSocio;
    for(i=0;i<al_len(pListaSocios);i++)
        {
            auxSocio=al_get(pListaSocios,i);
            if(auxSocio->estado==SOCIO_ESTADO_ACTIVO)
            {
                printf("NOMBRE: %s - APELLIDO: %s- ID: %d - DNI: %s\n",soc_getNombre(auxSocio),
                            soc_getApellido(auxSocio),soc_getId(auxSocio),soc_getDni(auxSocio));
            }
        }

}

void mostrarError(char *);



static void opcionAlta()
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];

    if(val_getString(auxNombre, "Nombre? ", "Error",2,50)==0)
    {
        if(val_getString(auxApellido, "Apellido? ", "Error",2,50)==0)
        {
            if(val_getInt(auxDni, "DNI? ", "Error",2,50)==0)
            {
                cont_altaSocio(auxNombre,auxApellido,auxDni);
            }
        }
    }
}

static void opcionBaja()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(cont_existeSocio(id)!=0)
        {
            printf("El ID no existe");
        }
        else
        {
            cont_bajaSocio(id);
        }
    }

}

static void opcionModificacion()
{
    char auxId[10];
    int id;
    int estado;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    char auxEstado[5];

    if((val_getUnsignedInt(auxId,"Id a modificar" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(cont_existeSocio(id)!=0)
        {
            printf("El ID no existe");
        }
        else
        {
            if(val_getString(auxNombre, "Nombre? ", "Error",2,50)==0)
            {
                if(val_getString(auxApellido, "Apellido? ", "Error",2,50)==0)
                {
                    if(val_getInt(auxDni, "DNI? ", "Error",2,50)==0)
                    {
                        if(val_getUnsignedInt(auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,5)==0)
                        {
                            estado=atoi(auxEstado);
                            if(estado == 0 || estado == 1)
                            {
                                cont_modificarSocio(auxNombre,auxApellido,auxDni,id,estado);
                            }
                        }
                    }
                }
            }
        }
    }
}

static void opcionListado()
{
    cont_listarSocios();
}



//**************************************SERVICIOS


static void opcionAltaServicios()
{
    char auxDescripcion[50];
    if (val_getString(auxDescripcion, "Descripcion? ", "Error",2,50)==0)
    {
        cont_altaServicio(auxDescripcion);
    }
}

static void opcionBajaServicios()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(cont_existeServicio(id)!=0)
        {
            printf("El ID de servicio no existe");
        }
        else
        {
            cont_bajaServicio(id);
        }
    }
}

static void opcionModificacionServicios()

{
    char auxId[10];
    int id;
    int estado;
    char auxDescripcion[50];
    char auxEstado[5];

    if((val_getUnsignedInt(auxId,"Id a modificar", "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(cont_existeServicio(id)!=0)
        {
            printf("El ID de servicio no existe");
        }
        else
        {
            if(val_getString(auxDescripcion, "Descripcion? ", "Error",2,50)==0)
            {
                if(val_getInt(auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,5)==0)
                {
                    estado=atoi(auxEstado);
                    if(estado == 0 || estado == 1)
                    {
                        cont_modificarServicios(auxDescripcion,id,estado);
                    }
                }
            }
        }
    }
}


void vista_mostrarServicios(ArrayList* pListaServicios)
{
    int i;
    Servicios* auxServicio;
    for(i=0;i<al_len(pListaServicios);i++)
        {
            auxServicio=al_get(pListaServicios,i);
            if(auxServicio->estado==SERVICIOS_ESTADO_ACTIVO)
            {
                auxServicio = al_get(pListaServicios,i);
                printf("DESCRIPCION: %s - ID: %d\n",serv_getDescripcion(auxServicio),serv_getId(auxServicio));
            }
        }
}

static void opcionListadoServicios()
{
    cont_listarServicios();
}



//**************************************RELACION SOCIO - SERVICIO

static void opcionAltaRelSocioServicio()
{
    char auxIdSocio[10];
    char auxIdServicio[10];

    if(val_getInt(auxIdSocio, "Socio? ", "Error",2,50)==0)
    {
        if(val_getInt(auxIdServicio, "Servicio? ", "Error",2,50)==0)
        {
            cont_altaRelacionSocioServicio(atoi(auxIdSocio),atoi(auxIdServicio));
        }
    }
}

static void opcionBajaRelSocioServicio()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaServicio(id);
    }
}

void vista_mostrarRelacionSocioServicio(ArrayList* pListaRelSyS)
{
    int i;
    RelSocioServicio* auxRelSocioServicio;
    for(i=0;i<al_len(pListaRelSyS);i++)
        {
            auxRelSocioServicio=al_get(pListaRelSyS,i);
            if(auxRelSocioServicio->estado==REL_SOCIO_SERVICIO_ESTADO_ACTIVO)
            {
                auxRelSocioServicio = al_get(pListaRelSyS,i);
                printf("ID: %d - ID SOCIO: %d - ID SERVICIO: %d\n",relSyS_getId(auxRelSocioServicio),relSyS_getIdSocio(auxRelSocioServicio),relSyS_getIdServicio(auxRelSocioServicio));
            }
        }
}

static void opcionListadoRelSocioServicio()
{
    cont_listarRelacionSocioServicio();
}


