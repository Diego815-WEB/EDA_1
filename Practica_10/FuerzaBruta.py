from string import ascii_letters, digits
from itertools import product 
from time import time

caracteres = ascii_letters + digits

def buscador(con):
    archivo = open("Combinaciones.txt", "w")

    if not (3 <= len(con) <= 10):
        print("Ingresa una contraseña de 3 a 10 caracteres")
        return
    
    
    for i in range(3, 11):
        for comb in product(caracteres, repeat=i):
            prueba = "".join(comb)

            archivo.write(prueba + "\n")

            if prueba == con:
                print("Tu contraseña es {}".format(prueba))
                archivo.close()
                return

    archivo.close()
    print("La contraseña no fue encontrada.")

t0 = time()
con = "ABCD"
buscador(con)
print("Tiempo de ejecución {}".format(round(time() - t0, 6)))