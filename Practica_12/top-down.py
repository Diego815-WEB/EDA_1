def fibonacci_iterativo_v1(numero):
    f1=0
    f2=1
    tmp=0
    for i in range(1,numero-1):
        tmp=f1+f2
        f1=f2
        f2=tmp
    return f2
fibonacci_iterativo_v1(6)

def fibonacci_iterativo_v2(numero):
    f1=0
    f2=1
    tmp=0
    for i in range(1,numero-1):
        f1,f2=f2,f1+f2
    return f2
fibonacci_iterativo_v2(6)

memoria={1:0,2:1,3:1}

def fibonacci_top_down(numero):
    if numero in memoria:
        return memoria[numero]
    f = fibonacci_iterativo_v2(numero-1) + fibonacci_iterativo_v2(numero-2)
    memoria[numero]=f
    return memoria[numero]


print(fibonacci_top_down(12))
print(memoria)