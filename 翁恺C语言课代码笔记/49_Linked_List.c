//
// Created by Shizumu on 2021/8/15.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
} Node;

Node *add(Node *head,int number);

int main(void)
{
    Node *head=NULL;
    int number;
    do{
        scanf("%d",&number);
        if(number!=-1){
            add(head,number);
        }
    }while(number!=-1);
}

Node *add(Node *head,int number)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->value=number;
    p->next=NULL;
    Node *last=head;
    if(last){
        while(last->next){
            last=last->next;
        }
        last->next=p;
    }else{
        head=p;
    }
    return
}