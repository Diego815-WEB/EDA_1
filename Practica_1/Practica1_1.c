#include <stdio.h>
#define MAX 10
int main()
{
    int n, array[MAX];

    printf("Numero de elementos del arreglo:");
    scanf("%d",&n);
    if(n<=MAX && n>0 )
    {
        for (int  i = 0; i < n; i++)
        {
            printf("Elemento[%d]:",i);
            scanf("%d",&array[i]);
        }

        printf("Valores del arreglo\n");
        for (int i = 0; i < n; i++)
        {
            printf("Elemento[%d]:%d\n",i,array[i]);
        }
        
    }
    else
    {
        printf("Valores menores de 10 y mayores a 0\n");
    }
}