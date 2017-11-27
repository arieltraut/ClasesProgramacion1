#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED
typedef struct
{
    char descripcion[51];
    int id;
    int estado;
}Servicios;
#endif // SERVICIOS_H_INCLUDED

#define SERVICIOS_ESTADO_ACTIVO 0
#define SERVICIOS_ESTADO_INACTIVO 1

Servicios* serv_new(char* descripcion, int id, int estado);
int serv_delete(Servicios* this);
int serv_setDescripcion(Servicios* this,char* descripcion);
char* serv_getDescripcion(Servicios* this);
int serv_setId(Servicios* this,int id);
int serv_getId(Servicios* this);
int serv_setEstado(Servicios* this,int estado);
int serv_getEstado(Servicios* this);
Servicios* serv_findById(ArrayList* pArrayServicios, int id);

