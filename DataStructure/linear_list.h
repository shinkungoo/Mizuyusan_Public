//
// Created by Shizumu on 2022/6/28.
//

#ifndef DATASTRUCTURE_LINEAR_LIST_H
#define DATASTRUCTURE_LINEAR_LIST_H
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
List MakeEmpty(int MaxLength)
{
    if(MaxLength < 1){
        return NULL;
    }
    List ret;
    ret = (List) malloc(sizeof (struct LNode));
    ret->head = (ElementType *) malloc(sizeof (ElementType) * MaxLength);
    memset(ret->head, 0, sizeof(ElementType) * MaxLength);
    ret->size = 0;
    ret->max_length = MaxLength;

    return ret;
}

int Search(List l, ElementType x)
{
    int ret = -1;
    for(int i = 0 ; i < l->size; i ++){
        if(l->head[i] == x){
            ret = i;
            break;
        }
    }

    return ret;
}

bool Insert(List l, ElementType x, int p)
{
    bool isInsert = false;
    if(l->size == l->max_length || p < 0 || (p >= l->size && l->size != 0)){
        return isInsert;
    }
    for(int i = l->size - 1; i >= p; i --){
        l->head[i + 1] = l->head[i];
    }
    l->head[p] = x;
    l->size ++;
    isInsert = true;

    return isInsert;
}

bool Append(List l, ElementType x)
{
    bool isAppend = false;
    if(l->size == l->max_length){
        return isAppend;
    }
    l->head[l->size] = x;
    l->size ++;
    isAppend = true;

    return isAppend;
}

bool Delete(List l, int p)
{
    bool isDelete = false;
    if(p >= l->size || p < 0){
        return isDelete;
    }
    for(int i = p; i < l->size - 1; i ++){
        l->head[i] = l->head[i + 1];
    }
    l->head[l->size - 1] = 0;
    l->size --;
    isDelete = true;

    return isDelete;
}

bool IsEmpty(List l)
{
    return (l->size == 0);
}

bool IsFull(List l)
{
    return (l->size == l->max_length);
}

void PrintList(List l)
{
    for(int i = 0 ; i < l->size; i ++){
        printf("%d ", l->head[i]);
    }
}

void Clear(List l)
{
    memset(l->head, 0, sizeof(ElementType) * l->max_length);
    l->size = 0;
}

void Free(List l)
{
    free(l->head);
    l->size = -1, l->max_length = -1;
}
//advanced function

int BinarySearch(List l, ElementType x)
{
    int ret = -1;
    int left = 0, right = l->size, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(x == l->head[mid]){
            ret = mid;
            break;
        }else if(x < l->head[mid]){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    return ret;
}

int BinarySearchInRecursion(List l, ElementType x, int left, int right)
{
    if(left >= right){
        return -1;
    }
    int mid = (left + right) / 2;
    if(x == l->head[mid]){
        return mid;
    }else if(x < l->head[mid]){
        return BinarySearchInRecursion(l, x, left, mid - 1);
    }else{
        return BinarySearchInRecursion(l, x, mid + 1, right);
    }
}

IndexBlockForLinearList InitForIndexBlockForLinearList(List l)
{
    IndexBlockForLinearList ret;
    ret.max_length = l->max_length / BLOCK_SIZE;
    if(l->max_length % BLOCK_SIZE != 0){
        ret.max_length ++;
    }
    ret.index = (ElementType *) malloc(sizeof (ElementType) * ret.max_length);
    int max = 0;
    for(int i = 0, cnt = 0, j = 0; i < l->size; i ++){
        if(cnt == BLOCK_SIZE){
            ret.index[j ++] = max;
            cnt = 0, max = 0;
        }
        if(l->head[i] > max){
            max = l->head[i];
        }
        cnt ++;
    }
    ret.index[ret.max_length - 1] = max;

    return ret;
}

void UpdateIndexBlock(List l, IndexBlockForLinearList* list)
{
    free(list->index);
    list->max_length = l->max_length / BLOCK_SIZE;
    if(l->max_length % BLOCK_SIZE != 0){
        list->max_length ++;
    }
    list->index = (ElementType *) malloc(sizeof (ElementType) * list->max_length);
    int max = 0;
    for(int i = 0, cnt = 0, j = 0; i < l->size; i ++){
        if(cnt == BLOCK_SIZE){
            list->index[j ++] = max;
            cnt = 0, max = 0;
        }
        if(l->head[i] > max){
            max = l->head[i];
        }
        cnt ++;
    }
    list->index[list->max_length - 1] = max;
}

// Here use search in order
int BlockSearch(List l, ElementType x, IndexBlockForLinearList* list)
{
    int ret = -1;
    int isInBlock = 0, idx = 0;
    for(int i = 0; i < list->max_length; i ++){
        if(x <= list->index[i]){
            idx = i * BLOCK_SIZE;
            isInBlock = 1;
            break;
        }
    }
    if(isInBlock){
        for(int i = idx; i < idx + BLOCK_SIZE; i ++){
            if(x == l->head[i]){
                ret = i;
                break;
            }
        }
    }

    return ret;
}

void FreeIndexBlock(IndexBlockForLinearList* list)
{
    free(list->index);
    list->max_length = 0;
}
//Test

void Test()
{
    List a;
    a = MakeEmpty(100);
    if(IsEmpty(a)){
        printf("The a is empty!\n");
    }
    printf("The empty line:\n"),PrintList(a), printf("\n");
    int num[8] = {1, 1, 4, 5, 5, 10, 7, 3};
    for(int i = 0 ; i < 8; i ++){
        Insert(a, num[i], 0);
    }
    PrintList(a), printf("\n");
    if(Search(a, 6) != NOT_FOUND){
        printf("The 6 is in the a\n");
    }else{
        printf("The 6 is NOT in the a\n");
    }

    if(Search(a, 5) != NOT_FOUND){
        printf("The 5 is in the a\n");
    }else{
        printf("The 5 is NOT in the a\n");
    }

    Insert(a, 80, Search(a, 4));
    Insert(a, 100, Search(a, 1));
    Append(a, 300);
    PrintList(a), printf("\n");
    Delete(a, Search(a, 10));
    Delete(a, Search(a, 20));
    PrintList(a), printf("\n");
    Clear(a);
    for(int i = 0 ; i < 200 ; i += 1){
        Append(a, i);
    }
    if(IsFull(a)){
        printf("The a is full\n");
    }else{
        printf("The a is not full\n");
    };
    PrintList(a), printf("\n");
    printf("the 100 is at %d\n", BinarySearch(a, 100));
    printf("the 99 is at %d\n", BinarySearch(a, 99));
    printf("the 18 is at %d\n", BinarySearch(a, 18));
    printf("the 0 is at %d\n", BinarySearch(a, 0));
    printf("-----------------------------------------------\n");
    printf("the 100 is at %d\n", BinarySearchInRecursion(a, 100, 0, a->size));
    printf("the 99 is at %d\n", BinarySearchInRecursion(a, 99, 0, a->size));
    printf("the 18 is at %d\n", BinarySearchInRecursion(a, 18, 0, a->size));
    printf("the 0 is at %d\n", BinarySearchInRecursion(a, 0, 0, a->size));

    IndexBlockForLinearList la1 = InitForIndexBlockForLinearList(a);
    printf("the 100 is at %d\n", BlockSearch(a, 100, &la1));
    printf("the 48 is at %d\n", BlockSearch(a, 48, &la1));
    Delete(a, Search(a, 48));
    Append(a, 100);
    UpdateIndexBlock(a, &la1);
    printf("the 100 is at %d\n", BlockSearch(a, 100, &la1));
    printf("the 48 is at %d\n", BlockSearch(a, 48, &la1));

    Free(a);
    FreeIndexBlock(&la1);
}

#endif //DATASTRUCTURE_LINEAR_LIST_H
