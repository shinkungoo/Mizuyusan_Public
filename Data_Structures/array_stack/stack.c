//
// Created by Shizumu on 2022/2/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack CreateStack(int MaxSize)
{
    Stack temp = (Stack) malloc(sizeof (struct SNode));
    temp->items = (ElementType *) malloc(sizeof (ElementType) * MaxSize);
    temp->top = -1;
    temp->MaxSize = MaxSize;

    return temp;
}

bool IsFull(Stack s)
{
    return (s->top == s->MaxSize - 1);
}

bool IsEmpty(Stack s)
{
    return (s->top == -1);
}

bool push(Stack s, ElementType x)
{
    bool ret = false;
    if(IsFull(s)){
        ret = false;
    }else{
        s->items[++s->top] = x;
        ret = true;
    }

    return ret;
}

ElementType pop(Stack s)
{
    ElementType ret;
    if(IsEmpty(s)){
        ret = -1;
    }else{
        ret = s->items[s->top--];
    }

    return ret;
}

void PrintStack(Stack s)
{
    if(IsEmpty(s)){
        printf("________________\n");
        printf("________________\n");
        printf("Empty\n");
    }else{
        printf("________________<---%d\n", s->top);
        for(int i = s->top; i >= 0; i --){
            printf("%d\n", s->items[i]);
            printf("________________\n");
        }
    }
}

