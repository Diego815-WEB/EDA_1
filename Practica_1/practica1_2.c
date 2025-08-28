#include <stdio.h>
#define MAX 5
int main()
{
    int n, array[MAX];
    int suma=0,resta=0,max=array[0],min;
    int guardar_minimo,guardar_max;
    float promedio=0;
    for (int  i = 0; i < MAX; i++)
    {
        printf("Elemento[%d]:",i);
        scanf("%d",&array[i]);
        suma+=array[i];
        resta-=array[i];
        if (array[i]< min)
        {
            min=array[i];
            guardar_minimo=array[i];
        
        }
        if (max<array[i])
        {
            max=array[i];
            guardar_max=array[i];
        }
        
        
    }
    min=array[0];
    promedio=suma/MAX;
    
    printf("Promedio:%.2f\n",promedio);
    printf("Suma:%d\n",suma);
    printf("Resta:%d\n",resta);
    printf("Maximo. Elemento[%d]:%d\n",guardar_max,max);
    printf("Minimo.Elemento[%d]:%d\n",guardar_minimo,min);

    
}