#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz.h"


void int_menu ()
{
    char seguir = 's';
    int opcion;
    ArrayList* nuevoArrayList = al_newArrayList();

    while(seguir=='s')
    {
        printf("\n1- Alta de socio\n");
        printf("2- Baja de socio\n");
        printf("3- Modificar socio\n");
        printf("4- Listar\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                int_opcionCargaSocio(nuevoArrayList);
                break;
            case 2:
                int_opcionBajaSocio(nuevoArrayList);
                break;
            case 3:
                int_opcionModificarSocio(nuevoArrayList);
                break;
            case 4:
                controller_debugShow(nuevoArrayList);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Ingresar solo opciones 1 a 5");
                break;
        }
    }
}



int int_opcionCargaSocio (ArrayList* listaSocios)
{
    char bNombre[NAME_SIZE];
    char bApellido[LAST_NAME_SIZE];
    char bDni[DNI_SIZE];
    int retorno = -1;


    if ((val_getDni(bDni,"Ingrese DNI\n","DNI invalido, ingrese nuevamente\n",2,DNI_SIZE))== 0)
    {
        if (controller_findDni(listaSocios, bDni) == -1)
        {
            printf("El DNI ingresado corresponde a un Socio existente\n\n");
        }
        else
        {
            if ((val_getNombre(bNombre,"Ingrese nombre\n","Nombre invalido, ingrese nuevamente\n",2,NAME_SIZE))== 0)
            {
                if ((val_getNombre(bApellido,"Ingrese apellido\n","Apellido invalido, ingrese nuevamente\n",2,LAST_NAME_SIZE))== 0)
                {
                    controller_altaSocio(listaSocios,bNombre,bApellido,bDni);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}


int int_opcionModificarSocio (ArrayList* listaSocios)
{
    char bNombre[NAME_SIZE];
    char bApellido[LAST_NAME_SIZE];
    int bId;
    int retorno = -1;

    if ((val_getUnsignedInt(&bId,"Ingrese numero de socio a modificar\n","El numero de socio ingresado no existe, ingrese nuevamente\n",2,0,9999))==0)
    {
        Socio* bSocio = controller_findById(listaSocios,bId);
        if (bSocio != NULL)
        {
            if ((val_getNombre(bNombre,"Ingrese nombre\n","Nombre invalido, ingrese nuevamente\n",2,NAME_SIZE))== 0)
            {
                if ((val_getNombre(bApellido,"Ingrese apellido\n","Apellido invalido, ingrese nuevamente\n",2,LAST_NAME_SIZE))== 0)
                {
                        controller_modificarSocio(bSocio,bNombre,bApellido);
                        retorno = 0;
                }
            }
        }
        else
        {
            printf("El numero de socio ingresado es inexistente\n\n");
        }
    }
    return retorno;
}


int int_opcionBajaSocio (ArrayList* listaSocios)
{
    int bId;
    int retorno = -1;

    if ((val_getUnsignedInt(&bId,"Ingrese numero de socio a dar de baja\n","El numero de socio ingresado no existe, ingrese nuevamente\n",2,0,9999))==0)
    {
        int bSocio = controller_findById2(listaSocios,bId);
        if (bSocio != -1)
        {
            controller_bajaSocio(listaSocios,bSocio);
            retorno = 0;
        }
        else
        {
            printf("El numero de socio ingresado es inexistente\n\n");
        }
    }
    return retorno;
}

