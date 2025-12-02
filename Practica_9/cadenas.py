#inicializando cadenas
cadena1="Hola "
cadena2="Mundo"

print(cadena1)
print(cadena2)

concat_cadenas=cadena1+cadena2
print(concat_cadenas)

#para concatenar  un numero y una cadena  se puede usar str()
num_cadena=concat_cadenas +' ' + str(3)
print(num_cadena)

#para concatenar cadenas  se recomienda format() en lugar del operador '+'
num_cadena="{} {} {}".format(cadena1,cadena2, 3)
print(num_cadena)

#cambiar el orden en que s eimprimen las variables
num_cadena="Cambio el orden :{1} {2} {0} #".format(cadena1,cadena2,3)
print(num_cadena)