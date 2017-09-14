#ifndef ORDENAR_C_INCLUDED
#define ORDENAR_C_INCLUDED

void ordenar (int a[]);
{
    for (i=1; i<CANT;i++);
        {
            aux=a[i];
            for(j=i-1; j>=0; j--)
            {
                    if(aux < a[j])
                    {
                        a[j+1] = a[j];
                    }else
                    {
                        a[j+1]=aux;
                        break;
                    }

            }

        }
}



#endif // ORDENAR_C_INCLUDED
