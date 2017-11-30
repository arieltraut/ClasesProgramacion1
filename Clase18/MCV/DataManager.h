#define ARCHIVO_SOCIOS "socios.bin"
#define ARCHIVO_SERVICIOS "servicios.bin"
#define ARCHIVO_REL_SOCIO_SERVICIO "rel_socio_servicio.bin"

int dm_saveAll(ArrayList* pArraySocios);
int dm_readAll(ArrayList* pArraySocios);

int dm_saveAllServicios(ArrayList* pArrayServicios);
int dm_readAllServicios(ArrayList* pArrayServicios);

int dm_saveAllRelSocioServicio(ArrayList* pArrayRelSocioServicio);
int dm_readAllRelSocioServicio(ArrayList* pArrayRelSocioServicio);



int dm_parserSocio(ArrayList* pArraySocios);
