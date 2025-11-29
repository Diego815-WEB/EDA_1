#include "SLL.h"
#include <stdio.h>
#include <stdlib.h>

static Node*newnode(Item_t data)
{
    Node*n=malloc(sizeof(Node));
    if (n !=NULL)
    {
        n->data=data;
        n->next=NULL;
    }
    return n;
}

SLL *New()
{
    SLL*l=malloc(sizeof(SLL));
    if (l !=NULL)
    {
        l->cursor=l->first=l->last=NULL;
        l->len=0;
    }else
    {
        return NULL;
    }
    return l;
}

void SLL_Delete(SLL **pThis)
{
    assert(*pThis);
}

void SLL_Push_front(SLL*this,Item_t x)
{
    assert(this);
    Node*n=newnode(x);
    assert(n);
    if (this->len==0)
    {
        this->last=n;
    }
    n->next=this->first;
    this->first=n;
    this->len++;
}



