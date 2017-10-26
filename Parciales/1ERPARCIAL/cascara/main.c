#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contrataciones.h"
#include "pantallas.h"
#include "validar.h"
#include "informes.h"

#define LEN_PANTALLA 100
#define LEN_CONTRATACIONES 1000

int main()
{
    sPantalla arrayPantalla[LEN_PANTALLA];
    sContrataciones arrayContratacion[LEN_CONTRATACIONES];

    pantalla_init(arrayPantalla, LEN_PANTALLA);
    contra_init(arrayContratacion, LEN_CONTRATACIONES);

    //prueba(arrayPantalla,arrayContratacion,LEN_PANTALLA,LEN_CONTRATACIONES);

    int opcion,idPantalla;

    do
    {
        val_getUnsignedInt(&opcion,"\n1-Alta de pantalla\n2-Modificar datos de pantalla\n3-Baja de pantalla\n4-Contratar una publicidad\n5-Modificar condiciones de publicacion\n6-Cancelar contratacion\n7-Consulta facturacion\n8-Listar contrataciones\n9-Listar pantallas\n10-Informar\n11-Salir\n","\nSolo opciones permitidas\n",3,1,11);

        switch(opcion)
        {
            case 1:
                pantalla_alta (arrayPantalla, LEN_PANTALLA);
                break;
            case 2:
                pantalla_modificar(arrayPantalla, LEN_PANTALLA);
                break;
            case 3:
                idPantalla = pantalla_baja(arrayPantalla,LEN_PANTALLA);
                if (idPantalla != -1)
                    contra_baja(arrayContratacion,LEN_CONTRATACIONES,idPantalla);
                system("pause");
                break;
            case 4:
                info_printArrayPantalla(arrayPantalla,LEN_PANTALLA);
                contra_alta(arrayPantalla,arrayContratacion, LEN_PANTALLA,LEN_CONTRATACIONES);
                break;
            case 5:
                contra_modificar(arrayContratacion,arrayPantalla,LEN_CONTRATACIONES,LEN_PANTALLA);
                break;
            case 6:
                contra_cancelar(arrayContratacion,arrayPantalla,LEN_CONTRATACIONES,LEN_PANTALLA);
                break;
            case 7:
                info_listarFacturacion(arrayContratacion,arrayPantalla,LEN_CONTRATACIONES,LEN_PANTALLA);
                system("pause");
                break;
            case 8:
                info_listarContrataciones(arrayContratacion,arrayPantalla,LEN_CONTRATACIONES,LEN_PANTALLA);
                system("pause");
                break;
            case 9:
                info_printArrayPantalla(arrayPantalla,LEN_PANTALLA);
                break;
            case 10:
                info_listarClientes(arrayContratacion, arrayPantalla, LEN_CONTRATACIONES, LEN_PANTALLA);

                //contratacion_printArray(arrayContratacion,LEN_CONTRATACIONES);
                //imprimirTodo(arrayPantalla, LEN_PANTALLA, arrayContratacion, LEN_CONTRATACIONES);
                //idEn1_conMasLlamadas(arrayPantalla, LEN_PANTALLA, arrayContratacion, LEN_CONTRATACIONES);
                //OrdenarAlfabeticamentePorCampoChar(arrayPantalla,LEN_PANTALLA);
                break;

            default:
                printf("Opcion invalida");
                system("pause");
                break;
        }

    }while(opcion != 11);

    return 0;
}
