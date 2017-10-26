#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contrataciones.h"

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado un 0.
 *
 * \param sContrataciones arrayContratacion[] Puntero al array de .....
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int contra_init(sContrataciones arrayContratacion[], int len)
{
    int i;
    int retorno = -1;
    if (arrayContratacion != NULL && len >0)
    {
        for(i=0;i<len;i++)
        {
            arrayContratacion[i].flagOcupado = 0;
        }
        retorno = 0;
    }
    return retorno;
}

static int ultimoValorIdAutoincrementable = -1;

/** \brief  Busca en el array el id mas alto entre los usados y los borrados
 * \param sContrataciones arrayContratacion[] Puntero al array de ...........
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (proximo ID) si Ok
 *
 */
int contra_generarProximoId(sContrataciones arrayContratacion[], int len)
{
    ultimoValorIdAutoincrementable++;
    return ultimoValorIdAutoincrementable;
}


/** \brief  Busca en el array la primer posicion libre
 * \param sContrataciones arrayContratacion[] Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */
int contra_buscarPosicionLibre(sContrataciones arrayContratacion[], int len)
{
    int i;
    int retorno = -1;
    if(arrayContratacion != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(arrayContratacion[i].flagOcupado == 0)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Pide al usuario los datos de un nuevo ...... y luego lo agrega al array
 * \param Entidad1 array[] Puntero al array de ........
 * \param sContrataciones arrayContratacion[] Puntero al array de ........
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int contra_alta(sPantalla arrayPantalla[],sContrataciones arrayContratacion[], int lenPantalla, int lenContratacion)
{
    int retorno = -1;
    char bNombreArchivo[51];
    char bCuit[51];
    int diasPublicacion;
    int idNuevo;
    int bIdPantalla;
    int indexVacio = contra_buscarPosicionLibre(arrayContratacion,lenContratacion);

    if (arrayContratacion != NULL && indexVacio >=0 && indexVacio < lenContratacion)
    {
        if(val_getUnsignedInt(&bIdPantalla,"\nElija pantalla a contratar ingresando su ID\n","\nSolo numeros:\n",2,0,9999999)==0)
        {
            int index = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,bIdPantalla);
            if (index != -1)
            {
                if (val_getUnsignedInt(&diasPublicacion,"\nIngrese dias que dura la publicacion\n","\nValor invalido\n",2,1,365)==0)
                {

                   if (val_getCuit(bCuit,"\nIngrese CUIT\n","\nValor invalido\n",2,51)==0) //ver
                   {

                        if (val_getAlfanumerico(bNombreArchivo,"\nIngrese nombre archivo de video\n", "Nombre invalido",2,51)==0)
                        {
                            idNuevo = contra_generarProximoId(arrayContratacion,lenContratacion);

                            strncpy(arrayContratacion[indexVacio].nombreArchivoVideo,bNombreArchivo,51);
                            arrayContratacion[indexVacio].diasPublicacion = diasPublicacion;
                            strncpy(arrayContratacion[indexVacio].cuit,bCuit,51);
                            //arrayContratacion[indexVacio].cuit = atoi(bCuit);
                            arrayContratacion[indexVacio].idPantalla = bIdPantalla;
                            arrayContratacion[indexVacio].id = idNuevo;
                            arrayContratacion[indexVacio].flagOcupado = 1;
                            retorno = 0;
                        }
                   }
                }
            }
            else
            {
                printf("El ID de pantalla elegido no existe\n");
                system("pause");
            }
        }
    }
    return retorno;
}


int contra_modificar(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla)
{
    int retorno = -1, indexContra, indexPan, idPan, flagCuitEncontrado = 0,bIdPantalla,diasPublicacion;
    char bCuit[51];

    if (val_getCuit(bCuit,"\nIngrese CUIT\n","\nValor invalido\n",2,51)==0)
    {
        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if((strcmp(arrayContratacion[indexContra].cuit,bCuit)==0) && arrayContratacion[indexContra].flagOcupado == 1)
            {
                flagCuitEncontrado = 1;
                idPan = arrayContratacion[indexContra].idPantalla;
                indexPan = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,idPan);
                printf("ID: %d  Tipo: %d  Nombre: %s Direccion: %s  Dias publicacion: %d  Precio  %.2f\n\n\n",arrayContratacion[indexContra].id,arrayPantalla[indexPan].tipoPantalla,arrayPantalla[indexPan].nombre,arrayPantalla[indexPan].direccion,arrayContratacion[indexPan].diasPublicacion,arrayPantalla[indexPan].precio);
            }
        }
        if (flagCuitEncontrado == 0)
        {
            printf("No hay contrataciones asignadas al CUIT ingresado\n");
            system("pause");
        }
        else
        {
            if (val_getUnsignedInt(&bIdPantalla,"\nElija pantalla a modificar ingresando su ID\n","\nSolo numeros:\n",2,0,9999)==0)
            {
                int index = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,bIdPantalla);
                if (index != -1)
                {
                    if (val_getUnsignedInt(&diasPublicacion,"\nIngrese dias que dura la publicacion\n","\nValor invalido\n",2,1,365)==0)
                    {
                        arrayContratacion[index].diasPublicacion = diasPublicacion;
                    }
                }
                else
                {
                    printf("El ID de pantalla elegido no existe\n");
                    system("pause");
                }
            }
        }
    }
    return retorno;
}


int contra_cancelar(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla)
{
    int retorno = -1, indexContra, indexPan, idPan, flagCuitEncontrado = 0,bIdPantalla;
    char bCuit[51], bConfirm[2];

    if (val_getCuit(bCuit,"\nIngrese CUIT\n","\nValor invalido\n",2,51)==0)
    {
        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if((strcmp(arrayContratacion[indexContra].cuit,bCuit))==0 && arrayContratacion[indexContra].flagOcupado == 1)
            {
                flagCuitEncontrado = 1;
                idPan = arrayContratacion[indexContra].idPantalla;
                indexPan = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,idPan);
                printf("ID: %d  Tipo: %d  Nombre: %s Direccion: %s  Precio  %.2f\n\n\n",arrayContratacion[indexContra].id,arrayPantalla[indexPan].tipoPantalla,arrayPantalla[indexPan].nombre,arrayPantalla[indexPan].direccion,arrayPantalla[indexPan].precio);
            }
        }
        if (flagCuitEncontrado == 0)
        {
            printf("No hay contrataciones asignadas al CUIT ingresado\n");
            system("pause");
        }
        else
        {
            if (val_getUnsignedInt(&bIdPantalla,"\nElija contratacion a cancelar ingresando el ID de pantalla\n","\nSolo numeros:\n",2,0,9999)==0)
            {
                int index = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,bIdPantalla);
                if (index != -1)
                {
                    if (val_getNombre(bConfirm,"\nDesea cancelar la contratacion? S/N?\n","\nValor invalido\n",2,3)==0);
                    {

                        if (bConfirm[0] == 'S' || bConfirm[0]=='s')
                        {
                            arrayContratacion[index].flagOcupado = 0;
                            printf("Contratacion cancelada\n\n");
                            system("pause");
                        }
                        else
                        {
                            printf("No se han cancelado contrataciones\n\n");
                            system("pause");
                        }
                    }
                }
                else
                {
                    printf("El ID de pantalla elegido no existe\n");
                    system("pause");
                }
            }
        }
    }
    return retorno;
}

void contra_baja(sContrataciones arrayContratacion[], int lenContratacion, int idPantalla)
{
    int indexContra;

    for (indexContra=0;indexContra<lenContratacion;indexContra++)
    {
        if(arrayContratacion[indexContra].idPantalla == idPantalla)
            arrayContratacion[indexContra].flagOcupado = 0;
    }
}






/** \brief Busca en la lista un ...... que coincida con el Id recibido
 *
 * \param sContrataciones arrayContratacion[] Puntero al array de .....
 * \param len int Longitud del array
 * \param id int ID del .....
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el ......] - (0) si Ok
 *
 */
int contra_buscarIndicePorId(sContrataciones arrayContratacion[],int len,int id)
{
    int i;
    int retorno = -1;
    for(i=0;i<len;i++)
        {
            if(arrayContratacion[i].flagOcupado == 1)
            {
                if(arrayContratacion[i].id == id)        //(strcmp(array[i].a, array[i].dni) == 0)
                {
                    retorno = i;
                    break;
                }
            }
        }
    return retorno;
}

