

void cont_init();

int cont_altaSocio (char* nombre,char* apellido,char* dni);

int cont_bajaSocio (int);

int cont_modificarSocio (char* nombre,char* apellido,char* dni, int id, int estado);

int cont_existeSocio (int id);

int cont_listarSocios ();

//********************SERVICIOS

int cont_altaServicio (char* descripcion);

int cont_modificarServicios (char* descripcion, int id, int estado);

int cont_bajaServicio (int id);

int cont_existeServicio (int id);

int cont_listarServicios ();


//********************RELACION SOCIO - SERVICIO

int cont_altaRelacionSocioServicio (int idSocio, int idServicio);

int cont_bajaRelacionSocioServicio (int id);

int cont_listarRelacionSocioServicio ();

