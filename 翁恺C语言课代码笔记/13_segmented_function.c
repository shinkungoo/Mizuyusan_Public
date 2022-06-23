//
// Created by Shizumu on 2021/8/3.
//
#include <stdio.h>

int main()
{
    int x=0;
    scanf("%d",&x);
    int f=0;

    if(x<0){
        f=-1;
    }else if(x==0){
        f=0;
    }else{
        f=2*x;
    }

    printf("%d",f);

    return 0;
}

