#include <stdio.h>
int main()
{

    
    int x = 7;
    int *p = &x;
    int y = *p + 3;

    printf("1) x = %d\n", x);//imprime el valor de x que en este caso vale 7
    printf("2) *p = %d\n", *p);//imprime el valor de 7 al cual se le asigno al puntero por el &x
    printf("3) p = %p\n", (void*)p);//imprime la direccion de memoria del pointer
    printf("4) &x = %p\n", (void*)&x);//imprime la direccion de x
    printf("5) y = %d\n", y);//regresa un valor entero que indica la suma del valor que contiene el pointer y el numero 3 por lo que regresa 10

    *p = 42;//cambia el valor que de x atraves del pointer  pasaria de valer 7 a x=42

    printf("6) x = %d, *p = %d\n", x, *p);//imprime x y *p ambos valen 42
    return 0;
    
}