#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

int cargarArchivo(Epelicula* arrayMovie)
{
    int bandera = 0;
    FILE *Archv;

    Archv = fopen("bin.dat", "rb");
    if(Archv == NULL)
    {
        Archv = fopen("bin.dat", "wb");
        if(Archv == NULL)
        {
            return 1;
        }
        bandera = 1;
    }
    if(bandera = 0)
    {
     fread(arrayMovie, sizeof(Epelicula), TAM, Archv);
    }
     fclose(Archv);
     return 0;
}

int buscarEspacio(Epelicula* arrayMovie){
    int indiceDos, i;
    for(i = 0; i < TAM; i++){

        arrayMovie[i].indice==0;
        indiceDos = i;
        break;
    }
    return indiceDos;

}

void altaPelicula(Epelicula* arrayMovie){
     int indiceDos, i;
     int encontro = 0;
     int auxIndice, auxDuracion, auxPuntaje;
     indiceDos = buscarEspacio(arrayMovie);
     if(indiceDos !=-1){

        printf("Ingrese indice");
        scanf("%d", &auxIndice);

     for(i = 0; i < TAM ; i++){
        auxIndice = arrayMovie[i].indice;
        encontro =1;
     }

             if(!encontro)//entra si encontro==0
        {
            arrayMovie[indiceDos].indice=auxIndice;
            printf("Ingrese titulo: ");
            fflush(stdin);
            gets(arrayMovie[indiceDos].titulo);

            printf("Ingrese genero: ");
            fflush(stdin);
            gets(arrayMovie[indiceDos].genero);

            printf("Ingrese duracion: ");
            scanf("%d", &auxDuracion);
            arrayMovie[indiceDos].duracion = auxDuracion;

            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets(arrayMovie[indiceDos].descripcion);

            printf("Ingrese puntaje: ");
            scanf("%d", &auxPuntaje);
            arrayMovie[indiceDos].puntaje = auxPuntaje;
            printf("Ingrese link a imagen: ");

            fflush(stdin);
            gets(arrayMovie[indiceDos].linkImagen);
            system("cls");
        }
        else
        {
            printf("El indice ya existe");
        }
}
    else
    {
        printf("No queda espacio");
    }


}

void bajaPelicula(Epelicula* arrayMovie)
{
    int auxIndice, bandera=0, i;
    printf("Ingrese indice ");
    scanf("%d", &auxIndice);
    for(i=0; i<TAM; i++)
    {
        if(auxIndice == arrayMovie[i].indice)
        {
            arrayMovie[i].indice=0;
            printf("Registro eliminado\n");
            system("cls");
            bandera=1;
            break;
        }
    }
    if(bandera==0)
    {
        printf("Indice inexistente");
    }
}

void modificarPelicula(Epelicula* arrayMovie)
{
    int bandera=0,i;
    int auxIndice, auxDuracion, auxPuntaje;
    char opcion;
    system("cls");
    printf("Ingrese indice para modificar: ");
    scanf("%d",&auxIndice);
    for( i=0; i<TAM; i++)
    {
        if(auxIndice==arrayMovie[i].indice)
        {
            printf("Indice encontrado\n");
            printf("Ingrese titulo: ");
            fflush(stdin);
            gets(arrayMovie[i].titulo);
            printf("Ingrese genero: ");
            fflush(stdin);
            gets(arrayMovie[i].genero);
            printf("Ingrese duracion: ");
            scanf("%d", &auxDuracion);
            arrayMovie[i].duracion = auxDuracion;
            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets(arrayMovie[i].descripcion);
            printf("Ingrese puntaje: ");
            scanf("%d", &auxPuntaje);
            arrayMovie[i].puntaje = auxPuntaje;
            printf("Ingrese link a imagen: ");
            fflush(stdin);
            gets(arrayMovie[i].linkImagen);
            system("pause");
            system("cls");

            printf("\nPelicula modificada \n");
            system("cls");

            bandera=1;
            break;
        }
    }
    if(bandera==0)
    {
        printf("indice de pelicula inexistente");
    }
}

void generarPag(Epelicula* arrayMovie, char nombre[])
{
    int i;
    FILE *Archv;
    Archv=fopen(nombre, "w");
    if(Archv == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(Archv,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");
        for(i=0; i<TAM; i++)
        {
            if(arrayMovie[i].indice != 0)
            {
                fprintf(Archv,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul><p>%s</p></article>", arrayMovie[i].linkImagen, arrayMovie[i].titulo, arrayMovie[i].genero, arrayMovie[i].puntaje, arrayMovie[i].duracion, arrayMovie[i].descripcion);
            }
        }
        fprintf(Archv,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
    }
    fclose(Archv);
    printf("Pagina creada \n");
    system("pause");
}

int guardarBinario(Epelicula* arrayMovie)
{

    FILE *Archv;

    Archv=fopen("bin.dat","wb");
    if(Archv == NULL)
    {
        return 1;
    }

    fwrite(arrayMovie,sizeof(Epelicula),TAM,Archv);

    fclose(Archv);

    return 0;
}

