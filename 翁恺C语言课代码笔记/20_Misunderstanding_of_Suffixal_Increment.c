//
// Created by Shizumu on 2021/8/3.
//
#include <stdio.h>

int main()
{
    for(int i=10;i>1;i/=2){
        printf("%d ",i++);
    }
    printf("\n");
    //output:10 5 3 2
    for(int i=10;i>1;i/=2){
        printf("%d ",i=i+1);
    }
    printf("\n");
    //output:11 6 4 3
    for(int i=10;i>1;i/=2){
        printf("%d ",i);
        i++;
    }
    printf("\n");
    //output:10 5 3 2
    for(int i=10;i>1;i/=2){
        printf("%d ",++i);
    }
    printf("\n");
    //output:11 6 4 3
}
