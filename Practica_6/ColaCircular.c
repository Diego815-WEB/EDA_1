#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define Item_T int

typedef struct 
{
    Item_T*cqueue;
    size_t front;
    size_t back;
    size_t capacity;
}CQueue;

CQueue *CQueueNew(size_t capacity)
{
    CQueue*q=malloc(sizeof(CQueue));
    if (q !=NULL)
    {
        q->cqueue=malloc(capacity*sizeof(Item_T));
        if (q->cqueue==NULL)
        {
            printf("Error al reservar memoria\n.");
            free(q);
            return NULL;
        }
        q->front=0;
        q->back=0;
        q->capacity=capacity;
        return q;
    }
    else
    {
        printf("ERROR AL LIBERAR MEMORIA\n.");
        return NULL;
    }
}

void CQueueDelete(CQueue**pp)
{
    assert(*pp);
    free((*pp)->cqueue);
    free(*pp);
    *pp=NULL;
}

void CQueueEnqueue(CQueue*q,Item_T x)
{
    assert(q);
    if ((q->back+1)%q->capacity==q->front)
    {
        printf("La cola esta llena\n.");
        return;
    }
    q->cqueue[q->back]=x;
    q->back=(q->back+1)%q->capacity;
}

Item_T CQueueDequeue(CQueue*q)
{
    assert(q);
    if (q->front==q->back)
    {
        printf("La cola esta vacia\n");
        return -1;
    }
    int aux=q->cqueue[q->front];
    q->front=(q->front+1)%q->capacity;
    return aux;
}

Item_T CQueue_IsEmpty(CQueue*q)
{
    assert(q);
    return q->front==q->back;
}

Item_T CQueue_IsFull(CQueue*q)
{
    assert(q);
    return (q->back+1)%q->capacity==q->front;
}

Item_T CQueue_Peek(CQueue*q)
{
    assert(q);
    if (q->front==q->back)
    {
        printf("La cola esta vacia\n");
        return -1;
    }
    return q->cqueue[q->front];
}

void CQueuePrint(CQueue* q)
{
    assert(q);
    if (q->front==q->back)
    {
        printf("La cola esta vacia\n");
        return ;
    }
    size_t i = q->front;
    printf("Cola: [ ");
    while (i != q->back)
    {
        printf("%d", q->cqueue[i]);
        i = (i + 1) % q->capacity;
        if (i != q->back)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}

int main()
{
    CQueue*cola=CQueueNew(7);
    CQueueEnqueue(cola,5);
    CQueueEnqueue(cola,10);
    CQueueEnqueue(cola,15);
    CQueuePrint(cola);

    printf("\n");
    CQueueDequeue(cola);
    CQueuePrint(cola);

    printf("\n");
    CQueueEnqueue(cola,20);
    CQueueEnqueue(cola,25);
    CQueueEnqueue(cola,30);
    CQueuePrint(cola);

    CQueueDelete(&cola);

}