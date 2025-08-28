#include <stdio.h>
#define MAX 5
int main()
{
    int array[MAX];

    for (int  i = 0; i < MAX; i++)
    {
        
        printf("Elemento[%d]:",i);
        scanf("%d",&array[i]);
    }

    printf("Valores del arreglo\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("Elemento[%d]:%d\n",i,array[i]);
    }

    printf("Arreglo inverso\n");
    for (int i = MAX-1; i>=0; i--)
    {
        printf("Elementos[%d]:%d\n",i,array[i]);
    }
    
    
    
}