#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TAM 3

typedef struct
{
   int indice;
   char titulo[20];
   char genero[20];
   int duracion;
   char descripcion[200];
   int puntaje;
   char linkImagen[100];

}Epelicula;

/**
 *  Agrega una pelicula al archivo
 *  @param arrayMovie la estructura a ser agregada
 */
void altaPelicula(Epelicula* arrayMovie);

/**
 *  Borra una pelicula del archivo
 *  @param arrayMovie la lista de estructuras que se eliminara
 */
void bajaPelicula(Epelicula* arrayMovie);

/**
 *  Agrega una pelicula al archivo
 *  @param arrayMovie la estructura a ser modificada
 */
void modificarPelicula(Epelicula* arrayMovie);

/**
 *  Busca el primer lugar libre en el array
 *  @param arrayMovie la lista donde se buscara la posicion libre
 *  @return Devuelve el primer indice libre
 */
int buscarEspacio(Epelicula* arrayMovie);

/**
 *  Carga las estructuras en el array de estructuras desde un archivo
 *  @param arrayMovie la lista de estructuras donde se cargaran esas estructuras
 *  @return Devuelve un 1 si se creo el archivo o un 0 si se leyo
 */
int cargarArchivo(Epelicula* arrayMovie);

/**
 *  Agrega una pelicula al archivo
 *  @param arrayMovie el array de estructuras a ser guardada en un archivo
 *  @return Devuelve un 1 si no se puede crear o un 0 si lo creo
 */
int guardarBinario(Epelicula* arrayMovie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo
 *  @param arrayMovie la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPag(Epelicula* arrayMovie, char nombre[]);

#endif // FUNCIONES_H_INCLUDED
