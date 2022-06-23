//
// Created by Shizumu on 2022/2/19.
//

#ifndef ARRAY_LIST_LIST_H
#define ARRAY_LIST_LIST_H
#define MAX 100
#define ERROR -1
#include <stdbool.h>
typedef int ElementType;
typedef int Position;
typedef struct LNode* List;
struct LNode{
    ElementType items[MAX];
    Position Last;
};

List MakeEmpty();
int Find(List l, ElementType x);
bool Insert(List l, Position p, ElementType x);
bool Delete(List l, Position p);
void PrintList(List l);

#endif //ARRAY_LIST_LIST_H
