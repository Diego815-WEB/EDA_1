def quicksort(lista):
    quicksort_aux(lista, 0, len(lista)-1)

def quicksort_aux(lista, inicio, fin):
    if inicio < fin:
        pivote = particion(lista, inicio, fin)
        quicksort_aux(lista, inicio, pivote - 1)
        quicksort_aux(lista, pivote + 1, fin)

def particion(lista, inicio, fin):
    pivote = lista[inicio]
    izquierda = inicio + 1
    derecha = fin

    while True:
        while izquierda <= derecha and lista[izquierda] <= pivote:
            izquierda += 1

        while derecha >= izquierda and lista[derecha] >= pivote:
            derecha -= 1

        if derecha < izquierda:
            break
        else:
            lista[izquierda], lista[derecha] = lista[derecha], lista[izquierda]

    lista[inicio], lista[derecha] = lista[derecha], lista[inicio]

    return derecha

lista = [21, 10, 0, 11, 9, 24, 20, 14, 1]
print("Lista desordenada {}".format(lista))
quicksort(lista)
print("Lista ordenada {}".format(lista))