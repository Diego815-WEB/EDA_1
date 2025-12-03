def max_recursivo(lista):
    
    if len(lista) == 0:
        return 0  
    if len(lista) == 1:
        return lista[0]
    
    
    medio = len(lista) // 2
    izquierda = lista[:medio]
    derecha = lista[medio:]
    

    
    max_izq = max_recursivo(izquierda)
    max_der = max_recursivo(derecha)
    
    
    if max_izq >= max_der:
        return max_izq
    else:
        return max_der



n = int(input("Tamaño:"))
if n <= 0:
    print("Debe ser positivo")
    exit()
        
lista = []
for i in range(n):
    num = int(input(f"Elemento {i}:"))
    lista.append(num)
        
if len(lista) > 0:
    res = max_recursivo(lista)
    print(f"El máximo es {res}")
else:
    print("Lista vacía")
        
