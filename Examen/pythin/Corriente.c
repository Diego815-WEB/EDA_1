#include <stdio.h>
#define  MAX 50
int main()
{
    int n,Resistencia[MAX][MAX],voltaje[MAX];
    float corriente[MAX];
    printf("Ingrese la dimension de su matriz\n");
    scanf("%d",&n);

    if (n>2)
    {
        //matriz de resistencia
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("Valor[%d][%d]=",i+1,j+1);
                scanf("%d",&Resistencia[i][j]);
            }
        
        }
    }
    //vector voltaje
    for (int k = 0; k < n; k++)
    {
        printf("Valor[%d]=",k+1);
        scanf("%d",&voltaje[k]);
    }
    
    for (int i = 0; i < n; i++)
    {
        corriente[i]=0;
        for (int j = 0; j < n; j++)
        {

            corriente[i]+=Resistencia[i][j]*voltaje[j];
        }
    }

    printf("\nCorrientes:\n");
    for (int i = 0; i < n; i++) {
        printf("I%d = %.2f\n", i+1, corriente[i]);
    }

    return 0;
    
    
}