#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"



int info_listarFacturacion(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla)
{
    int retorno = -1, indexContra, indexPan, idPan, flagCuitEncontrado = 0;
    char bCuit[51];

    if (val_getCuit(bCuit,"\nIngrese CUIT\n","\nCUIT invalido, ingrese nuevamente\n",2,51)==0)
    {
        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if((strcmp(arrayContratacion[indexContra].cuit,bCuit) == 0) && arrayContratacion[indexContra].flagOcupado == 1)
            {
                flagCuitEncontrado = 1;
                idPan = arrayContratacion[indexContra].idPantalla;
                indexPan = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,idPan);
                float importeContra = arrayPantalla[indexPan].precio * arrayContratacion[indexContra].diasPublicacion;
                printf("ID Contratacion: %d  Precio contratacion: %.2f\n\n",arrayContratacion[indexContra].id, importeContra);
            }
        }
        if (flagCuitEncontrado == 0)
        {
            printf("No hay contrataciones asignadas al CUIT ingresado\n");
        }
    }
    return retorno;
}


int info_listarContrataciones(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla)
{
    int retorno = -1, indexContra, indexPan, idPan, flagCuitEncontrado = 0;

        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if(arrayContratacion[indexContra].flagOcupado == 1)
            {
                flagCuitEncontrado = 1;
                idPan = arrayContratacion[indexContra].idPantalla;
                indexPan = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,idPan);
                printf("Nombre pantalla: %s,  Nombre video: %s, Cantidad dias: %d, CUIT Cliente: %s\n\n",arrayPantalla[indexPan].nombre, arrayContratacion[indexContra].nombreArchivoVideo,arrayContratacion[indexContra].diasPublicacion,arrayContratacion[indexContra].cuit);
            }
        }
        if (flagCuitEncontrado == 0)
        {
            printf("No se han cargado contrataciones\n");
        }

    return retorno;
}


void info_printArrayPantalla(sPantalla arrayPantalla[] , int len)
{
    int i, flagOcupadoEncontrado = 0;
    for (i=0;i<len;i++)
    {
        if(arrayPantalla[i].flagOcupado == 1)
        {
            printf("ID: %d, Tipo: %d, Nombre: %s, Direccion: %s, precio: %.2f\n\n\n",arrayPantalla[i].id,arrayPantalla[i].tipoPantalla,arrayPantalla[i].nombre,arrayPantalla[i].direccion,arrayPantalla[i].precio);
            flagOcupadoEncontrado = 1;
        }
    }
    if (flagOcupadoEncontrado == 0)
    {
            printf("No hay ninguna pantalla cargada en el sistema\n");
            system("pause");
    }
}


int info_listarClientes(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla, sInformes arrayInfo[])
{
    int retorno = -1, indexContra; //flagCuitEncontrado = 0; //indexContra2;//indexPan,idPan
    int iArrayClientes=0, indiceCuit=0; //arrayClientes[lenContrataciones];
    char bCuit[51]; //arrayClientes[51][lenContrataciones];

    for(iArrayClientes=0; iArrayClientes<lenContrataciones; iArrayClientes++)
    {
        strcpy(arrayInfo[iArrayClientes].cuit,"0");
        arrayInfo[iArrayClientes].cantiContra = 0;
    }

    if (arrayContratacion[0].flagOcupado==1)
    {
        strcpy(arrayInfo[0].cuit,arrayContratacion[0].cuit);
        iArrayClientes++;
    }

    int j;
    for(indexContra=1; indexContra<lenContrataciones; indexContra++)
    {
        if(arrayContratacion[indexContra].flagOcupado == 0)
            continue;

        strncpy(bCuit, arrayContratacion[indexContra].cuit,50);
        j=indexContra-1;
        while((strcmp(bCuit,arrayContratacion[j].cuit)!=0) && j>=0 && arrayContratacion[j].flagOcupado == 1)
        {
            j--;
        }
        if(j==-1)
        {
            strcpy(arrayInfo[iArrayClientes].cuit,bCuit);
            iArrayClientes++;
        }
    }

    for (indiceCuit=0;indiceCuit<lenContrataciones;indiceCuit++)
    {
        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if((strcmp(arrayContratacion[indexContra].cuit,arrayInfo[indiceCuit].cuit))==0)
                arrayInfo[indiceCuit].cantiContra++;
        }
    }

    for (indiceCuit=0;indiceCuit<lenContrataciones;indiceCuit++)
    {
        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if((strcmp(arrayContratacion[indexContra].cuit,arrayInfo[indiceCuit].cuit))==0 && arrayContratacion[indexContra].flagOcupado == 1)
            {
                //flagCuitEncontrado = 1;
                idPan = arrayContratacion[indexContra].idPantalla;
                indexPan = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,idPan);
                printf("Nombre pantalla: %s,  Nombre video: %s, Cantidad dias: %d, CUIT Cliente: %s\n\n",arrayPantalla[indexPan].nombre, arrayContratacion[indexContra].nombreArchivoVideo,arrayContratacion[indexContra].diasPublicacion,arrayContratacion[indexContra].cuit);
            }

            }
        }
        printf("Cantidad de contrataciones: %d",arrayInfo[indiceCuit].cantiContra;
    }



        if (flagCuitEncontrado == 0)
        {
            printf("No hay contrataciones asignadas al CUIT ingresado\n");
        }






        //for(i=0;i<lenContrataciones;i++)
        //{
           printf("%s\n",arrayClientes[0]);
           printf("%s\n",arrayClientes[1]);
           printf("%s\n",arrayClientes[2]);
           printf("%s\n",arrayClientes[3]);

        //}


        /*
                flagCuitEncontrado = 1;
                idPan = arrayContratacion[indexContra].idPantalla;
                indexPan = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,idPan);
                printf("Nombre pantalla: %s,  Nombre video: %s, Cantidad dias: %d, CUIT Cliente: %.d\n\n",arrayPantalla[indexPan].nombre, arrayContratacion[indexContra].nombreArchivoVideo,arrayContratacion[indexContra].diasPublicacion,arrayContratacion[indexContra].cuit);
                system("pause");
            }
        }
        if (flagCuitEncontrado == 0)
        {
            printf("No hay contrataciones asignadas al CUIT ingresado\n");
            system("pause");
        }*/
    return retorno;
}































/*
void imprimirTodo(Entidad1 arrayEntidad1[], int lenEntidad1, Entidad2 arrayEntidad2[], int lenEntidad2)
{
    int indexE2;
    for(indexE2=0; indexE2<lenEntidad2; indexE2++)
    {
        if (arrayEntidad2[indexE2].flagOcupado ==1)
        {
            int idE1 = arrayEntidad2[indexE2].idEntidad1;

            int indexE1 = ent1_buscarIndicePorId(arrayEntidad1,lenEntidad1,idE1);

            printf("ID: %d\t Nombre: %s | ID: %d\t Motivo%d\n\n",arrayEntidad1[indexE1].id,
                   arrayEntidad1[indexE1].nombre,
                   arrayEntidad2[indexE2].id,
                   arrayEntidad2[indexE2].motivo);
        }
    }
}




void idEn1_conMasLlamadas(Entidad1 arrayEntidad1[], int lenEntidad1, Entidad2 arrayEntidad2[], int lenEntidad2)

{
    if(arrayEntidad1 != NULL && lenEntidad1 > 0 && arrayEntidad2 != NULL && lenEntidad2 > 0)
    {

        int llamadasPorUsuario[lenEntidad1];
        int i;
        //incializa el array contador en 0
        for(i=0; i<lenEntidad1; i++)
        {
            llamadasPorUsuario[i] = 0;
        }

        //carga el array, //el indice del array va a coincidir con el id de usuario
        for(i=0; i<lenEntidad2; i++)
        {
            if(arrayEntidad2[i].flagOcupado == 1)
            {
                int indexLlamadasPorUsuario = arrayEntidad2[i].idEntidad1;
                llamadasPorUsuario[indexLlamadasPorUsuario] ++;
            }
        }

        // busca el numro mas alto
        int mayorLlamados = llamadasPorUsuario[0];
        for(i=1; i<lenEntidad1; i++)
        {
            if (llamadasPorUsuario[i] > mayorLlamados)
            {
                mayorLlamados = llamadasPorUsuario[i];
            }
        }
        int idUsuario;
        //imprime todos los campos de el/losiusuarios con mas llamadas
        for(idUsuario=0; idUsuario<lenEntidad1; idUsuario++)
        {
            if (llamadasPorUsuario[idUsuario] == mayorLlamados)
            {
                int indexFinal = ent1_buscarIndicePorId(arrayEntidad1,lenEntidad1,idUsuario);
                printf("%d\t%s",arrayEntidad1[indexFinal].id,arrayEntidad1[indexFinal].nombre);
            }
        }
    }
}



int OrdenarAlfabeticamentePorCampoChar(Entidad1 arrayEntidad1[], int lenEntidad1)
{
   int retorno = -1;
   int i, j;
   Entidad1 temporal;
   int temporalNumerico;

   if(arrayEntidad1 != NULL && lenEntidad1 > 0)
   {
       for (i = 1; i < lenEntidad1; i++)
       {
           temporal = arrayEntidad1[i];
           temporalNumerico = arrayEntidad1[i].edad;
           j = i-1;

           // orden menor a mayor, cambiar el < por > para mayor a menor
           while (j >= 0 && strcmp(temporal.nombre,arrayEntidad1[j].nombre)<0)
           {
               arrayEntidad1[j+1]=arrayEntidad1[j];  // es igual porque es la estructura completa, si fuese solo un campo seria strcpy
               --j;
           }
           while(j>=0 && strcmp(temporal.nombre,arrayEntidad1[j].nombre)==0)      // aca ordena por otro criterio, no se si esta bien, sino borrar
           {
               if (temporalNumerico < arrayEntidad1[j].edad)
               {
                  arrayEntidad1[j+1]=arrayEntidad1[j];
                   --j;
               }
           } //borrar hasta aca
           arrayEntidad1[j+1] = temporal;
       }
   retorno = 0;
   }
   return retorno;
}





















































void prueba(Entidad1 arrayEntidad1[], Entidad2 arrayEntidad2[], int lenEntidad1, int lenEntidad2)
{

        int indexVacio = ent1_buscarPosicionLibre(arrayEntidad1,lenEntidad1);
        int indexVacio2;
        int idNuevo;
        int idNuevo2;

        if (arrayEntidad1 != NULL && indexVacio >=0 && indexVacio < lenEntidad1)
        {
            int idNuevo = ent1_generarProximoId(arrayEntidad1,lenEntidad1);

            strncpy(arrayEntidad1[indexVacio].nombre,"Juan",51);
            strncpy(arrayEntidad1[indexVacio].apellido,"Perez",51);
            arrayEntidad1[indexVacio].edad = 30;
            arrayEntidad1[indexVacio].dni = 30666777;
            arrayEntidad1[indexVacio].flagOcupado = 1;
            arrayEntidad1[indexVacio].id = idNuevo;
        }

        indexVacio = ent1_buscarPosicionLibre(arrayEntidad1,lenEntidad1);

        if (arrayEntidad1 != NULL && indexVacio >=0 && indexVacio < lenEntidad1)
        {
            idNuevo = ent1_generarProximoId(arrayEntidad1,lenEntidad1);

            strncpy(arrayEntidad1[indexVacio].nombre,"Ariel",51);
            strncpy(arrayEntidad1[indexVacio].apellido,"Traut",51);
            arrayEntidad1[indexVacio].edad = 33;
            arrayEntidad1[indexVacio].dni = 30859667;
            arrayEntidad1[indexVacio].flagOcupado = 1;
            arrayEntidad1[indexVacio].id = idNuevo;
        }


        indexVacio2 = ent2_buscarPosicionLibre(arrayEntidad2,lenEntidad2);

        if (arrayEntidad2 != NULL && indexVacio2 >=0 && indexVacio2 < lenEntidad2)
        {
            idNuevo2 = ent2_generarProximoId(arrayEntidad2,lenEntidad2);

            arrayEntidad2[indexVacio2].motivo=0;
            strncpy(arrayEntidad2[indexVacio2].otros,"Cualquier otro",51);
            arrayEntidad2[indexVacio2].idEntidad1 = 0;
            arrayEntidad2[indexVacio2].id = idNuevo2;
            arrayEntidad2[indexVacio2].estado = ESTADO_PENDIENTE;
            arrayEntidad2[indexVacio2].flagOcupado = 1;
        }

        indexVacio2 = ent2_buscarPosicionLibre(arrayEntidad2,lenEntidad2);

        if (arrayEntidad2 != NULL && indexVacio2 >=0 && indexVacio2 < lenEntidad2)
        {
            idNuevo2 = ent2_generarProximoId(arrayEntidad2,lenEntidad2);

            arrayEntidad2[indexVacio2].motivo=1;
            strncpy(arrayEntidad2[indexVacio2].otros,"Cualquier otro 2",51);
            arrayEntidad2[indexVacio2].idEntidad1 = 1;
            arrayEntidad2[indexVacio2].id = idNuevo2;
            arrayEntidad2[indexVacio2].estado = ESTADO_PENDIENTE;
            arrayEntidad2[indexVacio2].flagOcupado = 1;
        }

}
*/
