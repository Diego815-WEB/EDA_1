#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define Item_T int

typedef struct
{
    Item_T *queue;
    size_t back;
    size_t front;
    size_t capacity;
}Queue;

Queue*QueueNew(size_t capacity)
{
    Queue*p=(Queue*)malloc(sizeof(Queue));
    if (p==NULL)
    {
        printf("Error al reservar memoria.\n");
        return NULL;
    }
    p->queue=(Item_T*)malloc(capacity*sizeof(Item_T));
    if ((p->queue==NULL))
    {
        printf("Error al reservar memoria.\n");
        free(p);
        return NULL;
    }
    p->front=0;
    p->back=0;
    p->capacity=capacity;
    return p;
}

void Queue_Delete(Queue**pp)
{
    assert(*pp);
    free((*pp)->queue);
    free(*pp);
    *pp=NULL;
}

void Queue_Enqueue(Queue*q,Item_T x)
{
    assert(q->queue);
    assert(q->back<q->capacity);

    q->queue[q->back]=x;
    q->back++;
}

int Queue_Dequeue(Queue*q)
{
    assert(q);
    assert(q->queue);
    assert(q->front<q->back);
    int aux=q->queue[q->front];
    q->front++;
    return aux;
}

void Queue_Print(Queue*q)
{
    assert(q );
    assert(q->queue);

    if (q->front == q->back) 
    {
        printf("La cola está vacía.\n");
        return;
    }
    printf("Cola:\n");
    for (Item_T i = q->front; i < q->back; i++)
    {
        printf("%d ", q->queue[i]);
    }
    
}

int main()
{
    Item_T n,valor,h;
    printf("Elementos de la cola\n");
    scanf("%d",&n);
    Queue*cola=QueueNew(n);
    for (Item_T i = 0; i < n; i++)
    {
        printf("Elemento[%d]: ",i);
        scanf("%d",&valor);
        Queue_Enqueue(cola,valor);
    }
    
    Queue_Print(cola);

    printf("\n");

    printf("Elementos a desencolar\n");
    scanf("%d",&h);
    if (h<n)
    {
        for (size_t i = 0; i < h; i++)
        {
            Queue_Dequeue(cola);
        }
    }
    else
    {
        printf("No se puede desencolar si %d es mayor a los elementos %d de la cola\n",h,n);
    }
    
    Queue_Print(cola);


    Queue_Delete(&cola);


}