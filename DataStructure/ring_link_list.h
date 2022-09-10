#ifndef DATASTRUCTURE_RING_LINK_LIST_H
#define DATASTRUCTURE_RING_LINK_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef int ElementType;
typedef struct RLNode* RList;
typedef struct RLNode* Ptr;
typedef struct RLNode* Position;

struct RLNode{
    ElementType item;
    Ptr next;
    Ptr pre;
};

RList MakeEmpty(int init)
{
    RList head;
    head = (RList) malloc(sizeof(struct RLNode));
    head->item = init;
    head->next = head, head->pre = head;

    return head;
}

Position Find(RList l, ElementType x)
{
    if(l == NULL){
        return NULL;
    }

    Position ptr = l->next;
    for(;ptr != l && ptr->item != x; ptr = ptr->next);
    if(ptr->item == x){
        return ptr;
    }else{
        return NULL;
    }
}

Position Append(RList l, ElementType x)
{
    if(l == NULL){
        Position temp = (RList) malloc(sizeof (struct RLNode));
        temp->item = x;
        temp->next = temp, temp->pre = temp;
        return temp;
    }
    Position ptr = l;
    for(; ptr->next != l; ptr = ptr->next);
    Position temp = (RList) malloc(sizeof (struct RLNode));
    temp->item = x;
    temp->next = ptr->next;
    temp->pre = ptr;
    ptr->next->pre = temp;
    ptr->next = temp;
    return l;
}

Position Insert(RList l, ElementType x, Position ptr)
{
    if(l == NULL || ptr == NULL){
        return l;
    }
    Position head = NULL;
    Position p = l->next;
    for(; p != l && p != ptr; p = p->next);
    if(p == ptr){
        Position temp = (RList) malloc(sizeof(struct RLNode));
        temp->item = x;
        temp->next = p->next;
        temp->pre = p;
        p->next = temp;
        temp->next->pre = temp;
        head = l;
    }

    return head;
}

Position Delete(RList l, Position ptr)
{
    if(l == NULL || ptr == NULL){
        return l;
    }
    Position head = NULL;
    if(ptr == l){
        l->pre->next = l->next;
        l->next->pre = l->pre;
        head = l->next;
        free(ptr);
        ptr = NULL;
        return head;
    }
    Position p = l ->next;
    for(; p != l && p->next != ptr; p = p->next);
    if(p == ptr){
        p->pre->next = p->next;
        p->next->pre = p->pre;
        free(p);
        p = NULL;
        head = l;
    }

    return head;
}

bool IsEmpty(RList l)
{
    return l == NULL;
}

void PrintListInOrder(RList l)
{
    if(l == NULL){
        return;
    }
    Position ptr = l;
    printf("%d ", ptr->item);
    ptr = ptr->next;
    for(; ptr != l ; ptr = ptr->next){
        printf("%d ", ptr->item);
    }
}

void PrintListInReverse(RList l)
{
    if(l == NULL){
        return;
    }
    Position ptr = l;
    printf("%d ", ptr->item);
    ptr = ptr->pre;
    for(; ptr != l ; ptr = ptr->pre){
        printf("%d ", ptr->item);
    }
}


void Test()
{
    RList a = MakeEmpty(10);
    for(int i = 0 ; i < 10 ;i ++){
        a = Insert(a, i, Find(a, 10));
    }
    PrintListInOrder(a), printf("\n");
    PrintListInReverse(a), printf("\n");
    a = Delete(a, Find(a, 100));
    a = Delete(a, Find(a, 10));
    PrintListInOrder(a), printf("\n");
    PrintListInReverse(a), printf("\n");
    a = Insert(a, 17, Find(a, 4));
    PrintListInOrder(a), printf("\n");
    PrintListInReverse(a), printf("\n");

    for(int i = 100; i <120; i ++){
        a = Append(a, i);
    }
    PrintListInOrder(a), printf("\n");
    PrintListInReverse(a), printf("\n");
}

#endif //DATASTRUCTURE_RING_LINK_LIST_H
