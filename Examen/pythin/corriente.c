#include <stdio.h>
#define MAX 50

int main() {
    int n, i, j, k;
    float Resistencia[MAX][MAX], voltaje[MAX], corriente[MAX], factor, pivote;

    printf("Ingrese la dimension de su matriz: ");
    scanf("%d", &n);

    printf("Ingrese la matriz de resistencias R[%d][%d]:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("R[%d][%d] = ", i+1, j+1);
            scanf("%f", &Resistencia[i][j]);
        }
    }


    printf("Ingrese los voltajes V[%d]:\n", n);
    for (i = 0; i < n; i++) {
        printf("V[%d] = ", i+1);
        scanf("%f", &voltaje[i]);
    }

    for (i = 0; i < n; i++) {
        pivote = Resistencia[i][i];
        if (pivote == 0) {
            printf("Error: pivote cero en fila %d\n", i+1);
            return 1; 
        }

        for (j = 0; j < n; j++)
            Resistencia[i][j] /= pivote;
        voltaje[i] /= pivote;

        
        for (k = 0; k < n; k++) {
            if (k == i) continue; 
            factor = Resistencia[k][i];
            for (j = 0; j < n; j++)
                Resistencia[k][j] -= factor * Resistencia[i][j];
            voltaje[k] -= factor * voltaje[i];
        }
    }

    for (i = 0; i < n; i++)
        corriente[i] = voltaje[i];

    
    printf("\nCorrientes:\n");
    for (i = 0; i < n; i++)
        printf("I%d = %.2f A\n", i+1, corriente[i]);

    return 0;
}