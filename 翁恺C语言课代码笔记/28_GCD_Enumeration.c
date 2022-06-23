//
// Created by Shizumu on 2021/8/4.
//
#include <stdio.h>

int main()
{
    int x1=0,x2=0;
    int gcd=0,i;
    scanf("%d %d",&x1,&x2);
    if(x1<x2){
        i=x1;
    }else{
        i=x2;
    }

    for(;i>0;i--){
        if(x1%i==0){
            if(x2%i==0){
                gcd=i;
                break;
            }
        }
    }

    printf("%d",gcd);

    return 0;
}
