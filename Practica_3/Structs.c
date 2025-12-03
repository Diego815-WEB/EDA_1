#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[40];
    char producers[10][20];
    int num_producers;
    int year;

}Movie;

void Movie_Data(Movie*this,int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Name[%d]:",i+1);
        scanf("%s",(this+i)->name);
    
    do{
        printf("Year[%d]:",i+1);
        scanf("%d",&(this+i)->year);
        if ((this+i)->year<1900 || (this+i)->year>2025)
        {
            printf("El anio debe estar entre 1900 y 2025\n");
        }else
        {
            break;
        } 
    }while (1);
      
    do{
        printf("Numero de productores de la pelicula %s: ",(this+i)->name);
        scanf("%d",&(this+i)->num_producers);
        if ((this+i)->num_producers<1)
        {
            printf("El numero de productores debe ser mayor a 1\n");
        }
        else
        {
            break;
        }
    }while (1);
    
        for (int j = 0; j < (this+i)->num_producers; j++)
        {
            printf("Producer [%d] name : ",j+1);
            scanf("%s",(this+i)->producers[j]);
        }
    }
}

void Movie_Print(Movie*this,int n)
{
    for (int i=n-1; i >=0; i--)
    {
        printf("Movie[%d].Name:%s\n",i+1,(this+i)->name);
        printf("Movie[%d].Year:%d\n",i+1,(this+i)->year);

        for (int j = 0; j < (this+i)->num_producers; j++)
        {
            printf("Movie[%d].Producers:%s\n",i+1,(this+i)->producers[j]);
        }
    }
}

void Movie_Search(Movie*this,int n,char *data)
{
    for (int i = 0; i < n; i++)
    {
        if(strcmp((this+i)->name,data)==0)
        {
            printf("Pelicula encontrada\n");
            Movie_Print(this+i,n);
        }
    }
}

int main()
{
    Movie pelicula[10];
    printf("***Buscador de peliculas***\n");
    Movie_Data(pelicula,3);
    
    system("clear");

    printf("Lista de peliculas\n");
    Movie_Print(pelicula,3);
    
    char d[100];
    printf("Busca una pelicula\n");
    printf("Ingresa el nombre de la pelicula:");
    scanf("%s",d);
    Movie_Search(pelicula,3,d);
}