//
// Created by Shizumu on 2022/2/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

List MakeEmpty()
{
    List temp;
    temp = (List) malloc(sizeof(struct LNode));
    memset(temp->items, 0, sizeof (ElementType) * MAX);
    temp->Last = -1;

    return temp;
}

int Find(List l, ElementType x)
{
    Position ret = ERROR;
    for(int i = 0 ; i <= l->Last; i ++){
        if(l->items[i] == x){
            ret = i;
            break;
        }
    }

    return ret;
}

bool Insert(List l, Position p, ElementType x)
{
    bool ret = false;
    if(l->Last == MAX - 1 || p < 0 || p > l->Last + 1){
        ret = false;
    }else if(l->Last == -1){
        l->items[0] = x;
        l->Last ++;
    }else{
        for(int i = l->Last; i >= p; i --){
            l->items[i + 1] = l->items[i];
        }
        l->items[p] = x;
        l->Last ++;
        ret = true;
    }

    return ret;
}

bool Delete(List l, Position p)
{
    bool ret = false;
    if(l->Last == -1 || p < 0 || p > l->Last){
        ret = false;
    }else if(l->Last == 0){
        l->items[0] = 0;
        l->Last --;
    }else{
        for(int i = p; i <= l->Last; i ++){
            l->items[i] = l->items[i + 1];
        }
        l->items[l->Last + 1] = 0;
        l->Last --;
        ret = true;
    }

    return ret;
}

void PrintList(List l)
{
    for(int i = 0; i <= l->Last; i ++){
        printf("%d%c", l->items[i], i == l->Last ? '\n' : ' ');
    }
}