#ifndef ENTIDAD2_H_INCLUDED
#define ENTIDAD2_H_INCLUDED
#define ESTADO_PENDIENTE 0
#define ESTADO_CUMPLIDO 1
#include "entidad1.h"

typedef struct{
    char motivo[51];
    char otros[51];
    int estado;
    int id;
    int idEntidad1;
    int flagOcupado;


}Entidad2;

int ent2_init(Entidad2 array[], int len);
int ent2_generarProximoId(Entidad2 array[], int len); //static
int ent2_buscarPosicionLibre(Entidad2 array[], int len); //static
int ent2_buscarIndicePorId(Entidad2 array[],int len,int id); //static

int ent2_alta(Entidad1 array1[],Entidad2 array[], int len);
int ent2_modificar(Entidad2 array[], int len);
int ent2_baja(Entidad2 array[], int len);

#endif // ENTIDAD2_H_INCLUDED
