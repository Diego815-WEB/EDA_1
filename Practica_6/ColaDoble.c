#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define Item_T int

typedef struct
{
    int *queue; 
    size_t front; 
    size_t back; 
    size_t capacity;
    size_t len;

} DQueue;

DQueue* DQueue_New( size_t capacity )
{
    DQueue* p = (DQueue*)malloc(sizeof(DQueue));
    if (p == NULL)
    {
        printf("Error in memory\n");
        return NULL;
    }

    p->queue = (Item_T*)malloc(capacity * sizeof(Item_T));
    if (p->queue == NULL)
    {
        printf("Error in memory\n");
        free(p); 
        return NULL;
    }

    p->front = 0;
    p->back = 0;
    p->capacity = capacity;
    p->len = 0;

    return p;
}

void DQueue_Delete( DQueue** pThis )
{
	assert(*pThis);
	free((*pThis)->queue);
	free(*pThis);
	*pThis=NULL;
}

bool DQueue_IsFull( DQueue* this )
{
   return this->len == this->capacity;
}

bool DQueue_IsEmpty( DQueue* this )
{
   return this->len == 0;
}

void DQueue_Enqueue( DQueue* this, Item_T val )
{
	if(DQueue_IsFull(this))
	{
		printf("Queue is Full\n");
	}
	this->queue[this->back]=val;
	++this->back;
	this->back %=this->capacity;
	++this->len;

}

Item_T DQueue_Dequeue( DQueue* this )
{
	if(DQueue_IsEmpty(this))
	{
		printf("Queue is empty\n");
	}
	Item_T tmp =this->queue[this->front];
	++this->front;
	this->front %=this->capacity;
	--this->len;

	return tmp;
}


void DQueue_Enqueue_prio( DQueue* this, Item_T val )
{
	if(DQueue_IsFull(this))
	{
		printf("Queue is full\n");
	}
	if(DQueue_IsEmpty(this))
	{
		this->front=0;
		this->back=0;
	}
	this->front=(this->front-1+this->capacity)%this->capacity;
	this->queue[this->front]=val;
	++this->len;

}

Item_T DQueue_Dequeue_prio( DQueue* this )
{
	if (DQueue_IsEmpty(this))
	{
		printf("Queue is empty\n");
	}
	Item_T tmp=this->queue[this->front];
	this->front=(this->front+1)%this->capacity;
	--this->len;

	if (DQueue_IsEmpty(this))
	{
		this->front=0;
		this->back=0;
	}
	return tmp;
}

Item_T DQueue_Peek( DQueue* this )
{
	if (DQueue_IsEmpty(this))
	{
		printf("Queue is empty\n");
		return -1;
	}
	return this->queue[this->front];
	
}

Item_T DQueue_PeekBack( DQueue* this )
{
	if (DQueue_IsEmpty(this))
	{
		printf("Queue is empty\n");
		return -1;
	}
	return this->queue[(this->back-1+this->capacity)%this->capacity];
}

void DQueue_Print(DQueue* this)
{
    if (DQueue_IsEmpty(this))
    {
        printf("DQueue is empty\n");
        return;
    }

    printf("DQueue = [ ");

    size_t i = this->front;
    for (size_t count = 0; count < this->len; count++)
    {
        printf("%d ", this->queue[i]);
        i = (i + 1) % this->capacity;   
    }
    printf("]\n");
}

int main()
{
    DQueue*cola=DQueue_New(7);
    DQueue_Enqueue(cola,10);
    DQueue_Print(cola);
    DQueue_Enqueue_prio(cola,15);
    DQueue_Print(cola);
    DQueue_Enqueue_prio(cola,20);
    DQueue_Print(cola);
    DQueue_Enqueue(cola,30);
    DQueue_Print(cola);
    
    printf("\n");
    DQueue_Dequeue(cola);
    DQueue_Print(cola);
    DQueue_Dequeue_prio(cola);
    DQueue_Print(cola);
    DQueue_Dequeue_prio(cola);
    DQueue_Print(cola);

    DQueue_Delete(&cola);
}