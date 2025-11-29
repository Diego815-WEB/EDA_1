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
    
    //Paso 4
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
        printf("El tamanio es menor no se agregan mas elementos\n");
    }

    system("clear");

    printf("Valores del arreglo\n");
    for (int i = 0; i < m; i++)
    {
        printf("Elemento[%d]:%d\n",i,arr2[i]);
    }
    
    
    //paso 5
    free(arr1);
    free(arr2);
    printf("Memoria liberada correctamente\n");
    
    #if 0
    1-¿Qué diferencia observaron entre los valores iniciales con malloc y calloc?

        En mi caso  cunado imprimi los valores  para calloc y malloc me daba cero aunque 
        en la practica decia que en malloc deberia salir basura me imprimia los elementos en 0 ya inicializados
    
    2. ¿Qué sucede si en realloc piden un tamaño más grande que el original? ¿y máspequeño?

        Pues cuando pide un tamaño mas grande lo que hace es que expande la memoria para que 
        se agreguen los siguientes elementos al arreglo, crea un nuevo bloque y copia los anteriores datos al nuevo bloque 
        algo que hace que realloc se vuelva un poco lento.
        Para el tamaño mas pequeño simplemente en loq eu hace mi programa es decirle al usuario que la memoria es menor
        a la que se habia reservado asi que ya estaban ocupados las posiciones y ya no trata de agrandarlo.
    
    3. ¿Qué pasa si olvidan llamar a free?
        ocurre una fuga de memoria , lo que pasa cuando se utiliza memoria dinamica se utiliza de la memoria de la ram entonces
        cuando el codigo corre esa parte reservada de la memoria se mantiene en el proceso asignado y no se puede
        utilizar.
    #endif

}