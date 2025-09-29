#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;

    //malloc
    printf("Cuantos enteros quiere :\n");
    scanf("%d",&n);

    int *arr1=(int*)malloc(n*sizeof(int));
    if (arr1==NULL)
    {
        printf("Error in memory\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Elemento[%d]:%d\n",i,arr1[i]);
    }

    printf("\n");
    //calloc
    int*arr2=(int*)calloc(n,sizeof(int));
    if (arr2==NULL)
    {
        printf("Error in memory");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Elemento[%d]:%d\n",i,arr2[i]);
    }
    
    printf("\n");

    //paso 3
    printf("Ingrese cantidad de enteros:\n");
    scanf("%d",&n);

    for (int i = 0; i <n; i++)
    {
        printf("Elemento[%d]:",i);
        scanf("%d",&arr2[i]);
    }
    
    printf("Nuevo tamanio del arreglo:");
    scanf("%d",&m);
    arr2=(int*)realloc(arr2,m*sizeof(int));
    if(arr2==NULL)
    {
        printf("Error in memory\n");
        return 1;
    }

    if(m>n)
    {
        for (int i = n; i < m; i++)
        {
            printf("Elmento[%d]:",i);
            scanf("%d",&arr2[i]);
        }
        
    }else
    {
        printf("El tamanio es menor\n");
    }

    system("clear");

    for (int i = 0; i < m; i++)
    {
        printf("Elemento[%d]:%d\n",i,arr2[i]);
    }
    
    

    free(arr1);
    free(arr2);
    printf("Memoria liberada correctamente\n");
    

}