//
// Created by Shizumu on 2022/2/19.
//

#ifndef LINK_STACK_STACK_H
#define LINK_STACK_STACK_H

#include <stdbool.h>

typedef int ElementType;
typedef struct SNode* Stack;
typedef struct SNode* Position;
struct SNode{
    ElementType item;
    Position Next;
};

Stack CreateStack();
bool IsEmpty(Stack s);
void push(Stack s, ElementType x);
ElementType pop(Stack s);
void PrintStack(Stack);

#endif //LINK_STACK_STACK_H
