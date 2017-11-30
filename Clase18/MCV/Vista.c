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
    int buffer;
    int option=0;

    while(option != 12)
    {
        val_getUnsignedInt(&buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,1,11);
        option = buffer;

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

    if(val_getString(auxNombre, "Nombre?\n", "Error\n",2,50)==0)
    {
        if(val_getString(auxApellido, "Apellido?\n ", "Error\n",2,50)==0)
        {
            if(val_getDni(auxDni, "DNI?\n ", "Error\n",2,50)==0)
            {
                cont_altaSocio(auxNombre,auxApellido,auxDni);
            }
        }
    }
}

static void opcionBaja()
{
    int auxId;

    if((val_getUnsignedInt(&auxId,"Id a dar de baja\n" , "Error\n",2,0,99999)==0))
    {
        if(cont_existeSocio(auxId)!=0)
        {
            printf("El ID no existe\n");
        }
        else
        {
            cont_bajaSocio(auxId);
        }
    }

}

static void opcionModificacion()
{
    int auxId;
    int auxEstado;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];

    if((val_getUnsignedInt(&auxId,"Id a modificar\n" , "Error\n",2,0,99999)==0))
    {
        if(cont_existeSocio(auxId)!=0)
        {
            printf("El ID no existe");
        }
        else
        {
            if(val_getString(auxNombre, "Nombre\n? ", "Error\n",2,50)==0)
            {
                if(val_getString(auxApellido, "Apellido?\n", "Error\n",2,50)==0)
                {
                    if(val_getDni(auxDni, "DNI?\n", "Error\n",2,50)==0)
                    {
                        if(val_getUnsignedInt(&auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,0,1)==0)
                        {
                            if(auxEstado == 0 || auxEstado == 1)
                            {
                                cont_modificarSocio(auxNombre,auxApellido,auxDni,auxId,auxEstado);
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
    int auxId;

    if((val_getUnsignedInt(&auxId,"Id a dar de baja" , "Error",2,0,99999)==0))
    {
        if(cont_existeServicio(auxId)!=0)
        {
            printf("El ID de servicio no existe");
        }
        else
        {
            cont_bajaServicio(auxId);
        }
    }
}

static void opcionModificacionServicios()

{
    int auxId;
    int auxEstado;
    char auxDescripcion[50];

    if((val_getUnsignedInt(&auxId,"Id a modificar", "Error",2,0,99999)==0))
    {
        if(cont_existeServicio(auxId)!=0)
        {
            printf("El ID de servicio no existe");
        }
        else
        {
            if(val_getString(auxDescripcion, "Descripcion? ", "Error",2,50)==0)
            {
                if(val_getUnsignedInt(&auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,0,1)==0)
                {
                    if(auxEstado == 0 || auxEstado == 1)
                    {
                        cont_modificarServicios(auxDescripcion,auxId,auxEstado);
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
    int auxIdSocio;
    int auxIdServicio;

    val_getUnsignedInt(&auxIdSocio,"ID Socio?\n", "Error\n",2,0,99999);
    if(cont_existeSocio(auxIdSocio)!=-1)
    {
        val_getUnsignedInt(&auxIdServicio, "Servicio? ", "Error",2,0,99999);
        if(cont_existeServicio(auxIdServicio)!=-1)
        {
            if(cont_existeRelSocioServicioRepetida(auxIdSocio,auxIdServicio)!=0)
            {
                cont_altaRelSocioServicio(auxIdSocio,auxIdServicio);
            }
            else
            {
                printf("\nEl socio ya se encuentra asociado a este servicio.\n");
            }
        }
        else
        {
            printf("\nEl servicio no existe o ha sido dado de baja.\n");
        }
    }
    else
    {
        printf("\nEl socio no existe o ha sido dado de baja.\n");
    }
}

static void opcionBajaRelSocioServicio()

{
    int auxId;

    if((val_getUnsignedInt(&auxId,"Id a dar de baja", "Error",2,0,99999)==0))
    {
        if(cont_existeRelSocioServicio(auxId) != -1)
        {
            cont_bajaRelSocioServicio(auxId);
            printf("\nBaja exitosa\n");
        }
        else
        {
            printf("\nLa relacion no existe o ha sido dado de baja\n");
        }
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
    cont_listarRelSocioServicio();
}


