#define ARCHIVO_SOCIOS "socios.bin"
#define ARCHIVO_ALQUILER "alquiler.bin"

int dm_saveAll(ArrayList* pArraySocios);
int dm_readAll(ArrayList* pArraySocios);

int dm_saveAllAlquiler(ArrayList* pArrayAlquiler);
int dm_readAllAlquiler(ArrayList* pArrayAlquiler);



int dm_parserSocio(ArrayList* pArraySocios);
