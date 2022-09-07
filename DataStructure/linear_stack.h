//
// Created by Shizumu on 2022/6/28.
//

#ifndef DATASTRUCTURE_LINEAR_STACK_H
#define DATASTRUCTURE_LINEAR_STACK_H

#include <stdlib.h>
typedef int ElementType;
typedef struct SNode *Stack;
struct SNode {
    ElementType *item;
    int sp;
    int size;
};

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
void Test();

#endif //DATASTRUCTURE_LINEAR_STACK_H
