#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED
#define ESTADO_PENDIENTE 0
#define ESTADO_CUMPLIDO 1
#define LLAMADA_LIBRE 0
#define LLAMADA_OCUPADA 1
#define CANTIDAD_LLAMADAS 100


typedef struct{
    char motivo[51];
    int id_llam;
    int id_asoc;
    int id_ambu;
    int tiempo_insumido;
    int flag;
    int estado;
}sLlamada;

int llam_alta (sLlamada* asociado, int index, int len);
int llam_initLlamada (sLlamada* asociado, int longitud);
int llam_buscarIndiceLibre (sLlamada* asociado, int longitud);
int buscarProximoIdLlamada (sLlamada* asociado, int longitud);




#endif // LLAMADA_H_INCLUDED
