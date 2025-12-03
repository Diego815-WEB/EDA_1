#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    if (!nuevo) {
        printf("Error de memoria\n");
        return;
    }
    nuevo->dato = valor;

    if (*cabeza == NULL) 
    {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->siguiente = nuevo;
    } else 
    {
        nuevo->siguiente = *cabeza;
        (*ultimo)->siguiente = nuevo;
        *cabeza = nuevo;
    }

    printf("Insertado: %d\n", valor);
}

void recorrerCircular(struct Nodo *cabeza) {
    if (cabeza == NULL) 
    {
        printf("Lista vacía\n");
        return;
    }

    struct Nodo *temp = cabeza;
    printf("Lista circular: ");
    do 
    {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != cabeza);
    printf("(vuelve a inicio)\n");
}

void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL) 
    {
        printf("Lista vacía\n");
        return;
    }

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = *ultimo;
    do 
    {
        if (actual->dato == valor)
            break;

        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    if (actual->dato != valor) {
        printf("Valor no encontrado\n");
        return;
    }

    if (*cabeza == *ultimo && actual == *cabeza) 
    {
        *cabeza = NULL;
        *ultimo = NULL;
    }
    else if (actual == *cabeza) 
    {
        *cabeza = actual->siguiente;
        (*ultimo)->siguiente = *cabeza;
    }
    else 
    {
        anterior->siguiente = actual->siguiente;
        if (actual == *ultimo)
        {
            *ultimo = anterior;
        }
    }

    free(actual);
    printf("Eliminado: %d\n", valor);
}

void liberarCircular(struct Nodo *cabeza, struct Nodo *ultimo) {
    if (cabeza == NULL) {
        printf("Memoria liberada\n");
        return;
    }

    struct Nodo *temp = cabeza;

    do {
        struct Nodo *sig = temp->siguiente;
        free(temp);
        temp = sig;
    } while (temp != cabeza);

    printf("Memoria liberada correctamente\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int n, valor;

    printf("¿Cuántos valores desea insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarCircular(&cabeza, &ultimo, valor);
        recorrerCircular(cabeza);
    }

    recorrerCircular(cabeza);

    printf("Valor a eliminar: ");
    scanf("%d", &valor);
    eliminarCircular(&cabeza, &ultimo, valor);

    recorrerCircular(cabeza);

    liberarCircular(cabeza, ultimo);

    return 0;
}
