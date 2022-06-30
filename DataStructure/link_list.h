//
// Created by Shizumu on 2022/6/28.
//
#ifndef DATASTRUCTURE_LINK_LIST_H
#define DATASTRUCTURE_LINK_LIST_H
#include <stdbool.h>
#include <stdio.h>
typedef int ElementType;
typedef struct LNode* List;
typedef struct LNode* Ptr;
typedef struct LNode* Position;

struct LNode{
    ElementType item;
    Ptr next;
};

// basic function
List MakeEmpty();
Position Find(List l, ElementType x);
bool Insert(List l, ElementType x, Position ptr);
bool Delete(List l, Position ptr);
bool Append(List l, ElementType x);
bool IsEmpty(List l);
void PrintList(List l);
void Clear(List l);
//advanced function
int Size(List l);
void Reverse(List l);
List Merge(List a, List b);
List Sort(List l);
List RemoveDuplicate(List l);
List Clone(List l);
List Tailor(List l, Position begin, Position end);
// test function
void Test();
#endif //DATASTRUCTURE_LINK_LIST_H
