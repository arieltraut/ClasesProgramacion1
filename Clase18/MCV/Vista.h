#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n1. Listar socios\n2. Agregar socio\n3. Baja socio\n4. Editar socio\n5. Listar Servicios\n6. Alta Servicio\n7. Baja Servicio\n8. Edita Servicio\n9. Listar relaciones\n10. Alta relacion\n11. Baja relacion\n12. Salir\n"
#define MENU_PPAL_EN "\n1. List Employees\n2. Add an item\n3. Edit an item\n4. Delete an item \n5. Exit \n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"
#define MENU_PPAL_ERROR_EN "\nINVALID OPTION\n"



int vista_init (int idioma);

int vista_mostrarMenu();

void vista_mostrarSocios(ArrayList* pListaSocios);
void vista_mostrarServicios(ArrayList* pListaServicios);
void vista_mostrarRelacionSocioServicio(ArrayList* pListaRelSyS);


void vista_mostrarError(char *);





