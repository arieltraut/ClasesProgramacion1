#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

int main()
{
    Epelicula peliculas [TAM];
    char seguir = 's';
    int opcion = 0, i;


    for(i=0; i<TAM; i++) //Inicializo el array de estructuras
    {
        peliculas[i].indice=0;
    }

    if(cargarArchivo(peliculas))
    {
        printf("No se puede abrir el fichero");
    }
    else
    {
        printf("Se cargaron las estructuras\n");
    }

    system("pause");
    system("cls");

    while(seguir == 's')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            altaPelicula(peliculas);
            break;
        case 2:
            system("cls");
            bajaPelicula(peliculas);
            break;
        case 3:
            system("cls");
            modificarPelicula(peliculas);
            break;
        case 4:
            system("cls");
            generarPag(peliculas, "index.html");
            break;
        case 5:
            if(guardarBinario(peliculas))
            {
                printf("\nNo se pudo abrir el fichero\n");
            }
            else
            {
                printf("\nSe guardo la informacion \n");
            }
            seguir = 'n';
            break;
        }
    }

    return 0;
}

