#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct 
{
    int *stack;
    size_t top;
    size_t capacity;
}Stack;

Stack*NewStack(size_t capacity)
{
    Stack*s=(Stack*)malloc(sizeof(Stack));
    if (s==NULL)
    {
        printf("Error in memory\n");
        return NULL;
    }
    s->stack=(int*)malloc(capacity*sizeof(int));
    if(s->stack==NULL)
    {
        printf("Error in memory\n");
        free(s);
        return NULL;
    }
    s->capacity=capacity;
    s->top=0;
    return s;
}

void Stack_Delete(Stack**pThis)
{
    assert(*pThis);
    free((*pThis)->stack);
    free(*pThis);
    *pThis=NULL;
}


void Stack_Push(Stack*s,int x)
{
    if(s->top==s->capacity)
    {
        printf("Error: Pila llena\n");
    }
    s->stack[s->top]=x;
    s->top++;
}

int Stack_Pop(Stack*s)
{
    if (s->top==0)
    {
        printf("Error: pila vacía\n");
        return -1;    
    }
    int aux=s->stack[s->top-1];
    s->stack[s->top-1]=0;
    s->top--;
    return aux;
    
}
void Stack_Print(Stack *s) {
    if (s->top == 0) {
        printf("Pila vacía\n");
        return;
    }
    printf("Pila:\n");
    for (size_t i = s->top; i > 0; i--) {
        printf("%d\n", s->stack[i - 1]);
    }
}


int main()
{
    int n,valor,h;
    printf("Cuantos elementos desea apilar\n");
    scanf("%d",&n);
    Stack*pila=NewStack(n);
    for (size_t i = 0; i < n; i++)
    {
        printf("Elemento[%d]: ",i);
        scanf("%d",&valor);
        Stack_Push(pila,valor);
    }
    Stack_Print(pila);

    printf("\n");

    printf("Elementos para desapilar\n");
    scanf("%d",&h);
    if(h<=pila->top)
    {
        for (size_t i = 0; i < h; i++)
        {
            int valor = Stack_Pop(pila);
            printf("Elemento desapilado: %d\n", valor);
        }
    }
    else
    {
        printf("los elementos a desapilar %d deben ser menores a %d",h,n);
    }
    Stack_Print(pila);


    Stack_Delete(&pila);
}