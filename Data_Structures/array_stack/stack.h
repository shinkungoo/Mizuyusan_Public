//
// Created by Shizumu on 2022/2/19.
//

#ifndef ARRAY_STACK_STACK_H
#define ARRAY_STACK_STACK_H

#include <stdbool.h>
typedef int Position;
typedef int ElementType;
typedef struct SNode* Stack;
struct SNode{
    ElementType *items;
    Position top;
    int MaxSize;
};

Stack CreateStack(int MaxSize);
bool IsFull(Stack s);
bool IsEmpty(Stack s);
bool push(Stack s, ElementType x);
ElementType pop(Stack s);
void PrintStack(Stack s);

#endif //ARRAY_STACK_STACK_H
