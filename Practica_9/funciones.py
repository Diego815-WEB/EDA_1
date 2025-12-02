#las funciones pueden recibir n numero de parametros , no se necesita indicar el tipo
def imprime_nombre(nombre):
    print("Hola "+nombre)
imprime_nombre("JJ")

#funcion que regrese el cuadrado de un numero
def cuadrado(x):
    return x**2
x=5
print("El cuadrado de {} es {}".format(x,cuadrado(x)))

#funcion que regrese mas de un valor 
def varios(x):
    return x**2,x**3,x**4
val1, val2,val3=varios(2)
print("{} {} {}".format(val1,val2,val3))

#funcion  con un parametro con un valor por defecto
def cuadrado_default(x=3):
    return x**2
cuadrado_default()