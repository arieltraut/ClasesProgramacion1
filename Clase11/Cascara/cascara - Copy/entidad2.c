#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidad2.h"
#include "validar.h"

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado un 0.
 *
 * \param Entidad2 array[] Puntero al array de .....
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */
int ent2_init(Entidad2 array[], int len)
{
    int i;
    int retorno = -1;
    if (array != NULL && len >0)
    {
        for(i=0;i<len;i++)
        {
            array[i].flagOcupado = 0;
        }
        retorno = 0;
    }
    return retorno;
}

static int ultimoValorIdAutoincrementable = -1;

/** \brief  Busca en el array el id mas alto entre los usados y los borrados
 * \param Entidad2 array[] Puntero al array de ...........
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (proximo ID) si Ok
 *
 */
int ent2_generarProximoId(Entidad2 array[], int len)
{
    ultimoValorIdAutoincrementable++;
    return ultimoValorIdAutoincrementable;
}


/** \brief  Busca en el array la primer posicion libre
 * \param Entidad2 array[] Puntero al array de abonados
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */
int ent2_buscarPosicionLibre(Entidad2 array[], int len)
{
    int i;
    int retorno = -1;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].flagOcupado == 0)
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
 * \param Entidad2 array[] Puntero al array de ........
 * \param len int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */
int ent2_alta(Entidad1 array1[],Entidad2 array[], int len)
{
    int retorno = -1;
    char bMotivo[51];
    char bOtros[51];
    int idNuevo;
    char b_idEnt1[100];
    int indexVacio = ent2_buscarPosicionLibre(array,len);

    if (array != NULL && indexVacio >=0 && indexVacio < len)
    {
        if(val_getEdad(b_idEnt1,"\nIngrese ID entidad1 \n","\nSolo numeros:\n",2,3)==0)
        {
            int index = ent1_buscarIndicePorId(array1,len,atoi(b_idEnt1));
            if (index != -1)
            {
                if (val_getNombre(bMotivo, "\nIngrese Motivo\n", "\nMotivo invalido\n",3,50)==0) //hacer define en h para 50
                {

                   if (val_getNombre(bOtros, "\nIngrese ..........\n", "\n............ invalido\n",3,50)==0)
                   {
                            idNuevo = ent2_generarProximoId(array,len);

                            strncpy(array[indexVacio].motivo,bMotivo,51);
                            strncpy(array[indexVacio].otros,bOtros,51);
                            array[indexVacio].idEntidad1 = atoi(b_idEnt1);
                            array[indexVacio].id = idNuevo;
                            array[indexVacio].estado = ESTADO_PENDIENTE;
                            retorno = 0;
                   }
                }
            }
            else
            {
                printf("El ID elegido no existe\n");
                system("pause");
            }
        }
    }
    return retorno;
}


