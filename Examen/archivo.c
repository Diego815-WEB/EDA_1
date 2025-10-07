#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    float prom=0,sum=0;
    printf("Ingrese cantidad de alumnos: ");
    scanf("%d",&n);

    float *alu=(float*)malloc(n*sizeof(float));
    if(alu==NULL)
    {
        printf("Error in memory\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Calificacion del estudiante[%d]: ",i+1);
        scanf("%f",&alu[i]);
        sum+= alu[i];
    }
    
    printf("===Calificaciones registradas===\n");
    for (int i = 0; i < n; i++)
    {
        printf("Estudiante[%d]:%.2f\n",i+1,alu[i]);
    }
    prom=sum/n;

    printf("El promedio es: %.2f\n",prom);


    printf("Ingrese nuevo numero de estudiantes mayores a %d, si no lo deseas coloca 1: ",n);
    scanf("%d",&m);

    if (m==1)
    {
        m=n;
    }

    alu=(float*)realloc(alu,m*sizeof(float));
    if (alu==NULL)
    {
        printf("Error in memory\n");
        return 1;
    }
    if (m>n)
    {
        
        for (int i = n; i < m; i++)
        {
            printf("Calificacion del estudiante[%d]: ",i+1);
            scanf("%f",&alu[i]);
        }
    }
    else
    {
        printf("No se agregaron mas estudiantes\n");
    }

    sum=0;
    for (int i = 0; i < m; i++)
    {
        sum+= alu[i];
    }
    prom=sum/m;


    printf("===Calificaciones registradas===\n");
    for (int i = 0; i < m; i++)
    {
        printf("Estudiante[%d]:%.2f\n",i+1,alu[i]);
    }

    printf("El promedio es: %.2f",prom);
    
    

    free(alu);

}