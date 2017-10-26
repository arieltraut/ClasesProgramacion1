#ifndef ASOCIADOS_H_INCLUDED
#define ASOCIADOS_H_INCLUDED
#define ASOCIADO_LIBRE 0
#define ASOCIADO_OCUPADO 1
#define CANTIDAD_ASOCIADOS 3

typedef struct{
    char nombre[51];
    char apellido[51];
    int edad;
    int dni;
    int id_asoc;
    int flag;
}sAsociado;

int asoc_alta (sAsociado* asociado, int index, int len);
int asoc_initAsociado (sAsociado* asociado, int longitud);
int asoc_buscarIndiceLibre (sAsociado* asociado, int longitud);
int buscarProximoId (sAsociado* asociado, int longitud);
int asoc_buscarIndicePorId(sAsociado asociado[],int len,int id);
int asoc_modificar(sAsociado asociado[], int len, int id);

void asoc_printAsoc(sAsociado asociado[] , int longitud);



#endif // ASOCIADOS_H_INCLUDED
