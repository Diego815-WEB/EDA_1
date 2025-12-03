#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    if (!nuevo) {
        printf("Error al reservar memoria\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;

    printf("Insertado: %d\n", valor);
}
void recorrer(struct Nodo *cabeza) {
    printf("Lista: ");
    while (cabeza != NULL) {
        printf("%d -> ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}
void eliminar(struct Nodo **cabeza, int valor) {
    if (*cabeza == NULL) {
        printf("Lista vacía\n");
        return;
    }

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    if (actual->dato == valor) {
        *cabeza = actual->siguiente;
        free(actual);
        printf("Eliminado: %d\n", valor);
        return;
    }

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor no encontrado\n");
        return;
    }

    anterior->siguiente = actual->siguiente;
    free(actual);
    printf("Eliminado: %d\n", valor);
}
void liberar(struct Nodo *cabeza) {
    struct Nodo *temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
    printf("Memoria liberada correctamente\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    int n, valor;
    printf("¿Cuántos valores desea insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }
    printf("\nRecorrido final:\n");
    recorrer(cabeza);

    printf("Valor a eliminar: ");
    scanf("%d", &valor);
    eliminar(&cabeza, valor);
    recorrer(cabeza);
    liberar(cabeza);

    return 0;
}
/*
1. ¿Por qué las listas enlazadas no requieren tamaño fijo como los arreglos?
porque utilizan nodos  para enlazarse y cada nodo es propio, se pueden quitar o agregar y en un arreglo se define su tamaño al inicio.
2. ¿Qué diferencia hay entre mover la cabeza y modificar los punteros internos?
no borra ni inserta nada cuando se mueve la cabeza sin encambio cuando modifica los punteros internos es todo lo contrario

*/
