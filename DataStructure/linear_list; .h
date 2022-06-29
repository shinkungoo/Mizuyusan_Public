//
// Created by Shizumu on 2022/6/28.
//

#ifndef DATASTRUCTURE_LINEAR_LIST_H
#define DATASTRUCTURE_LINEAR_LIST_H
#include <stdbool.h>
typedef int ElementType;
typedef struct LNode* List;
typedef int Position;

struct LNode{
    ElementType* head;
    Position length;
};

// basic function
List MakeEmpty(int MaxLength);
Position Search(List l, ElementType x);
bool Insert(List l, ElementType x, Position p);
bool Delete(List l, Position p);
bool IsEmpty(List l);
bool IsFull(List l);
void PrintList(List l);
void Clear(List l);
//advanced function
Position BinarySearch(List l, ElementType x);
Position BinarySearchInRecursion(List l, ElementType x, Position begin, Position end);
Position HashSearch(List l, ElementType x);

#endif //DATASTRUCTURE_LINEAR_LIST_H
