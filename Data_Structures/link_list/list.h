//
// Created by Shizumu on 2022/2/19.
//

#ifndef LINK_LIST_LIST_H
#define LINK_LIST_LIST_H
#include <stdbool.h>
#define ERROR -1
#define HEAD 0

typedef int ElementType;
typedef struct LNode* List;
typedef struct LNode* Ptr;
typedef struct LNode* Position;

struct LNode{
    ElementType item;
    Ptr Next;
};

List MakeEmpty();
Position Find(List l, ElementType x);
bool Insert(List l, ElementType x, Position ptr);
bool Delete(List l, Position ptr);
void PrintList(List l);
#endif //LINK_LIST_LIST_H
