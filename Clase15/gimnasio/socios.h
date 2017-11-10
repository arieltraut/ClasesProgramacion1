#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED
#define NAME_SIZE 51
#define LAST_NAME_SIZE 51
#define DNI_SIZE 13
#define ESTADO_LIBRE 0
#define ESTADO_OCUPADO 1

typedef struct
{
    int id; //numeroSocio
    char nombre[NAME_SIZE];
    char apellido[LAST_NAME_SIZE];
    char dni[DNI_SIZE];
    int flagOcupado;

}Socio;
#endif // SOCIOS_H_INCLUDED

Socio* socio_nuevoSocio(char nombre[],char apellido[],char dni[]);
//void Socio_delete(Socio* pSocio);
int socio_setNombre(Socio* pSocio, char nombre[]);
char* socio_getNombre(Socio* pSocio);
int socio_setApellido(Socio* pSocio, char apellido[]);
char* socio_getApellido(Socio* pSocio);
int socio_setId(Socio* pSocio);
int socio_getId(Socio* pSocio);
int socio_generarProximoId(void);
int socio_setDni(Socio* pSocio, char dni[]);
char* socio_getDni(Socio* pSocio);
int socio_setEstado(Socio* pSocio, int estado);
int socio_getEstado(Socio* pSocio);
