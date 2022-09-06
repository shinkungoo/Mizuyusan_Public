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

int isFull(Stack s);
int isEmpty(Stack s);
Stack CreateStack(int size);
void Push(Stack s, ElementType x );
void Pop(Stack s);
ElementType Top(Stack s);
void Test();

#endif //DATASTRUCTURE_LINEAR_STACK_H
