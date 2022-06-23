//
// Created by Shizumu on 2022/2/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

List MakeEmpty()
{
    List head, node;
    head = (List) malloc(sizeof (struct LNode));
    node = (List) malloc(sizeof (struct LNode));
    head->item = HEAD;
    node->item = 0;
    head->Next = node;
    node->Next = NULL;
    return head;
}

Position Find(List l, ElementType x)
{
    Position ptr = l;
    if(ptr->Next != NULL){
        while(ptr && ptr->item != x){
            ptr = ptr->Next;
        }
    }

    return ptr;
}

bool Insert(List l, ElementType x, Position ptr)
{
    bool ret;
    Position temp, pre;
    for(pre = l; pre && pre->Next != ptr; pre = pre->Next);
    if(pre == NULL){
        ret = false;
    }else{
        temp = (List) malloc(sizeof (struct LNode));
        temp->item = x;
        temp->Next = ptr;
        pre->Next = temp;
        ret = true;
    }

    return ret;
}

bool Delete(List l, Position ptr)
{
    bool ret;
    Position pre;
    for(pre = l; pre && pre->Next != ptr; pre = pre->Next);
    if(pre == NULL || ptr == NULL){
        ret = false;
    }else{
        pre->Next = ptr->Next;
        free(ptr);
        ret = true;
    }

    return ret;
}

void PrintList(List l)
{
    Position ptr = l->Next;
    while(ptr){
        printf("%d ", ptr->item);
        ptr = ptr->Next;
    }
    printf("\n");
}
