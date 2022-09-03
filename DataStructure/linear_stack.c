#include "linear_stack.h"


int isFull(Stack s){ return s->sp == s->size;}
int isEmpty(Stack s){ return s->sp == 0;}
Stack CreateStack(int size)
{
    Stack s = (Stack)malloc(sizeof(struct SNode));
    s->item = (ElementType *)malloc(size * sizeof(ElementType));
    s->sp = 0;
    s->size = size;
    return s;
}

void Push(Stack s, ElementType x )
{
    if(!isFull(s)){
        s->item[s->sp ++] = x;
    }
}

void Pop(Stack s)
{
    if(!isEmpty(s)){
        s->item[--s->sp];
    }
}

ElementType Top(Stack s)
{
    if(!isEmpty(s)){
        return s->item[s->sp - 1];
    }else{
        return 0;
    }
}

void Test()
{
    ;
}

