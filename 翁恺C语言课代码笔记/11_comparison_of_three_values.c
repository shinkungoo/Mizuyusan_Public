//
// Created by Shizumu on 2021/8/3.
//
#include <stdio.h>

int main()
{
    int a=0,b=0,c=0;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b){
        if(a>c){
            printf("%d",a);
        }
        else{
            printf("%d",c);
        }
    }
    else{
        if(b>c){
            printf("%d",b);
        }
        else{
            printf("%d",c);
        }
    }

    return 0;
}

