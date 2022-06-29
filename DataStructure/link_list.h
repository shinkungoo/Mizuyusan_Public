//
// Created by Shizumu on 2022/6/28.
//
#ifndef DATASTRUCTURE_LINK_LIST_H
#define DATASTRUCTURE_LINK_LIST_H
#include <stdbool.h>
typedef int ElementType;
typedef struct LNode* List;
typedef struct LNode* Ptr;
typedef struct LNode* Position;

struct LNode{
    ElementType item;
    Ptr Next;
};

// basic function
List MakeEmpty();
Position Find(List l, ElementType x);
bool Insert(List l, ElementType x, Position ptr);
bool Delete(List l, Position ptr);
bool IsEmpty(List l);
void PrintList(List l);
void Clear(List l);
//advanced function
void Reverse(List l);
void Sort(List l);
void RemoveDuplicate(List l);
List Clone(List l);
List Tailor(List l, int begin, int end);

#endif //DATASTRUCTURE_LINK_LIST_H
