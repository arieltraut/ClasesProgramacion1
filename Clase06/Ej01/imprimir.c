#ifndef IMPRIMIR_C_INCLUDED
#define IMPRIMIR_C_INCLUDED


void imprimirCadena (char cadena[])
{
    int i=0;
    int flagEncontreFinal=0;
    while (flagEncontreFinal==0)
    {
        char c = cadena[i];
        if (c!=0)
        {
            printf("%c", c); //imprimo cada caracter
        }
        else
        {
            flagEncontreFinal=1;
        }

        i++;
    }

return 0;
}


#endif // IMPRIMIR_C_INCLUDED
