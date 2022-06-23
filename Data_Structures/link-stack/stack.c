//
// Created by Shizumu on 2022/2/19.
//
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#define HEAD 0

Stack CreateStack()
{
    Stack temp;
    temp = (Stack) malloc(sizeof (struct SNode));
    temp->item = 0;
    temp->Next = NULL;

    return temp;
}

bool IsEmpty(Stack s)
{
    return (s->Next == NULL);
}

void push(Stack s, ElementType x)
{
    Stack temp = (Stack) malloc(sizeof (struct SNode));
    temp->item = x;
    temp->Next = s->Next;
    s->Next = temp;
}

ElementType pop(Stack s)
{
    Stack temp = s->Next;
    ElementType ret;
    ret = temp->item;
    s->Next = temp->Next;
    free(temp);

    return ret;
}

void PrintStack(Stack s)
{
    if(IsEmpty(s)){
        printf("________________\n");
        printf("________________\n");
        printf("Empty\n");
    }else{
        printf("________________<---%p\n", s);
        for(Position i = s->Next; i; i = i->Next){
            printf("%d\n", i->item);
            printf("________________\n");
        }
    }
}