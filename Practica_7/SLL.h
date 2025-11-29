#ifndef SSL_h
#define SLL_h 
#include <stdio.h>
#include <stdlib.h>
#include  <assert.h>
#define Item_t int

typedef struct
{
    Item_t data;
    struct Node*next;
}Node;

typedef struct 
{
    Node*first;
    Node *last;
    Node*cursor;
    size_t len;
}SLL;

SLL *New();
void SLL_Delete(SLL **pThis);
void SLL_Push_front(SLL*this,Item_t x);

#endif