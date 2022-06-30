//
// Created by Shizumu on 2022/6/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "link_list.h"

List MakeEmpty()
{
    List head;
    head = (List) malloc(sizeof(struct LNode));
    head->item = 0;
    head->next = NULL;

    return head;
}

Position Find(List l, ElementType x)
{
    Position ptr = l->next;
    while(ptr && ptr->item != x){
        ptr = ptr->next;
    }
    return ptr;
}

bool Insert(List l, ElementType x, Position ptr)
{
    bool isInsert = false;
    Position pre = l;
    for(; pre && pre->next != ptr ; pre = pre->next);
    if((pre == NULL && ptr != l) || ptr == NULL){
        return isInsert;
    }
    Position temp = (List) malloc(sizeof(struct LNode));
    if(temp != NULL){
        isInsert = true;
        temp->item = x;
        if(ptr == l){
            temp->next = ptr->next;
            ptr->next = temp;
        }else{
            temp->next = pre->next;
            pre->next = temp;
        }
    }

    return isInsert;
}

bool Append(List l, ElementType x)
{
    bool isAppend = false;
    Position ptr = l;
    for(; ptr->next; ptr = ptr->next);
    Position temp = (List) malloc(sizeof (struct LNode));
    if(temp != NULL){
        isAppend = true;
        temp->item = x;
        temp->next = NULL;
        ptr->next = temp;
    }

    return isAppend;
}

bool Delete(List l, Position ptr)
{
    bool isDelete = false;
    Position pre = l;
    for(; pre && pre->next != ptr; pre = pre->next);
    if(pre == NULL || ptr == NULL || ptr == l){
        return isDelete;
    }
    pre->next = ptr->next;
    free(ptr);
    isDelete = true;

    return isDelete;
}

bool IsEmpty(List l)
{
    return (l == NULL || l->next == NULL);
}

void PrintList(List l)
{
    if(l == NULL){
        return;
    }
    Position ptr = l->next;
    for(; ptr ; ptr = ptr->next){
        printf("%d ", ptr->item);
    }
}

void Clear(List l)
{
    Position ptr = l->next, temp = NULL;
    while(ptr){
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    l->next = NULL;
}

int Size(List l)
{
    int size = 0;
    Position ptr = l->next;
    for(; ptr; ptr = ptr->next, size ++);

    return size;
}

void Reverse(List l)
{
    if(l->next == NULL || l->next->next == NULL){
        return;
    }
    Position pre = NULL, curr = l->next, next = l->next->next;
    while(next){
        curr->next = pre;
        pre = curr;
        curr = next;
        next = next->next;
    }
    curr->next = pre;
    l->next = curr;
}

List Merge(List a, List b)
{
    if(a == NULL || a->next == NULL){
        return b;
    }else if(b == NULL || b->next == NULL){
        return a;
    }
    List ret = MakeEmpty();
    Position ptr1 = a->next, ptr2 = b->next, tail = ret, temp;
    while(ptr1 && ptr2){
        if(ptr1->item < ptr2->item){
            temp = (Position) malloc(sizeof (struct LNode));
            temp->next = NULL;
            temp->item = ptr1->item;
            tail->next = temp;
            tail = temp;
            ptr1 = ptr1->next;
        }else{
            temp = (Position) malloc(sizeof (struct LNode));
            temp->next = NULL;
            temp->item = ptr2->item;
            tail->next = temp;
            tail = temp;
            ptr2 = ptr2->next;
        }
    }
    if(ptr1 == NULL){
        for(; ptr2; ptr2 = ptr2->next){
            temp = (Position) malloc(sizeof (struct LNode));
            temp->next = NULL;
            temp->item = ptr2->item;
            tail->next = temp;
            tail = temp;
        }
    }else {
        for (; ptr1; ptr1 = ptr1->next) {
            temp = (Position) malloc(sizeof(struct LNode));
            temp->next = NULL;
            temp->item = ptr1->item;
            tail->next = temp;
            tail = temp;
        }
    }

    return ret;
}

List Sort(List l)
{
    if(l == NULL || l->next == NULL || l->next->next == NULL){
        return l;
    }
    Position slow = l, fast = l;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    Position head = (Position) malloc(sizeof (struct LNode));
    head->item = 0;
    head->next = fast;
    l = Sort(l);
    head = Sort(head);
    return Merge(l, head);
}

List RemoveDuplicate(List l)
{
    if(l == NULL || l->next == NULL || l->next->next == NULL){
        return l;
    }
    List ret = MakeEmpty();
    Position ptr1 = l->next, ptr2 = l->next->next, tail = ret, temp;
    while(ptr2){
        if(ptr1->item != ptr2->item){
            temp = (Position) malloc(sizeof (struct LNode));
            temp->next = NULL;
            temp->item = ptr1->item;
            tail->next = temp;
            tail = temp;
            ptr1 = ptr2;
        }
        ptr2 = ptr2->next;
    }
    temp = (Position) malloc(sizeof (struct LNode));
    temp->next = NULL;
    temp->item = ptr1->item;
    tail->next = temp;

    return ret;
}

List Clone(List l)
{
    if(l == NULL){
        return NULL;
    }
    List ret = MakeEmpty();
    ret->next = NULL;
    ret->item = 0;
    Position ptr = l->next, tail = ret, temp;
    for(; ptr; ptr = ptr->next){
        temp = (Position) malloc(sizeof (struct LNode));
        temp->next = NULL;
        temp->item = ptr->item;
        tail->next = temp;
        tail = temp;
    }

    return ret;
}

List Tailor(List l, Position begin, Position end)
{
    if(l == NULL){
        return NULL;
    }
    List ret = MakeEmpty();
    Position ptr = l;
    for(; ptr && ptr != begin; ptr = ptr->next);
    if(ptr == NULL){
        return NULL;
    }
    Position tail = ret, temp;
    for(; ptr && ptr != end; ptr = ptr->next){
        temp = (Position) malloc(sizeof (struct LNode));
        temp->next = NULL;
        temp->item = ptr->item;
        tail->next = temp;
        tail = temp;
    }

    return ret;
}

void Test()
{
    List a;
    a = MakeEmpty();
    if(IsEmpty(a)){
        printf("The a is empty!\n");
    }
    printf("The empty line:\n"),PrintList(a), printf("\n");
    int num[8] = {1, 1, 4, 5, 5, 10, 7, 3};
    for(int i = 0 ; i < 8; i ++){
        Insert(a, num[i], a);
    }
    PrintList(a), printf("\n");
    if(Find(a, 6)){
        printf("The 6 is in the a\n");
    }else{
        printf("The 6 is NOT in the a\n");
    }

    if(Find(a, 5)){
        printf("The 5 is in the a\n");
    }else{
        printf("The 5 is NOT in the a\n");
    }

    Insert(a, 80, Find(a, 4));
    Insert(a, 100, Find(a, 1));
    Append(a, 300);
    PrintList(a), printf("\n");
    Delete(a, Find(a, 10));
    Delete(a, Find(a, 20));
    PrintList(a), printf("\n");
    Clear(a);
    printf("The size of a is %d\n", Size(a));
    for(int i = 0 ; i < 8 ; i += 2){
        Append(a, i);
    }
    PrintList(a), printf("\n");
    List b = MakeEmpty();
    for(int i = 15 ; i >=0  ; i -= 2){
        Append(b, i);
    }
    Reverse(b);
    PrintList(b), printf("\n");
    List c = Merge(a, b);
    PrintList(c), printf("\n");
    List d = MakeEmpty();
    for(int i = 0 ; i < 8 ; i ++){
        Append(d, num[i]);
    }
    PrintList(d), printf("\n");
    List e = Sort(d);
    PrintList(e), printf("\n");
    List f = RemoveDuplicate(e);
    PrintList(f), printf("\n");
    List g = Clone(f);
    printf("The g is at %p while the f is at %p\n", g, f);
    PrintList(g), printf("\n");
    List h = Tailor(g, Find(g, 3), Find(g, 7));
    PrintList(h), printf("\n");
}