//
// Created by Shizumu on 2021/8/4.
//
#include <stdio.h>

int main()
{
    int x=0,i=0;
    for(x=1;x<=100;x++){
        int p=1;
        for(i=2;i<x;i++){
            if(x%i==0){
                p=0;
                break;
            }
        }
        if(p==1){
            printf("%d ",x);
        }
    }

    return 0;
}
