//
// Created by Shizumu on 2022/6/28.
//

#ifndef DATASTRUCTURE_LINEAR_LIST_H
#define DATASTRUCTURE_LINEAR_LIST_H
#include <stdbool.h>
#define NOT_FOUND -1
#define BLOCK_SIZE 10
typedef int ElementType;
typedef struct LNode* List;

struct LNode{
    ElementType* head;
    int size;
    int max_length;
};

typedef struct{
    ElementType * index;
    int max_length;
}IndexBlockForLinearList;

// basic function
List MakeEmpty(int MaxLength);
int Search(List l, ElementType x);
bool Insert(List l, ElementType x, int p);
bool Append(List l, ElementType x);
bool Delete(List l, int p);
bool IsEmpty(List l);
bool IsFull(List l);
void PrintList(List l);
void Clear(List l);
void Free(List l);
//advanced function
int BinarySearch(List l, ElementType x);
int BinarySearchInRecursion(List l, ElementType x, int left, int right);
IndexBlockForLinearList InitForIndexBlockForLinearList(List l);
void UpdateIndexBlock(List l, IndexBlockForLinearList* list);
int BlockSearch(List l, ElementType x, IndexBlockForLinearList* list);
void FreeIndexBlock(IndexBlockForLinearList* list);
//Test
void Test();

#endif //DATASTRUCTURE_LINEAR_LIST_H
