#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED

void myFgets(char* buffer, int limite ,FILE* archivo);

int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarUnsignedInt(char* buffer);

int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarNombre(char* buffer);

int val_getEdad(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_soloNumeros(char* buffer);

int val_getDni(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);



#endif // VALIDAR_H_INCLUDED
