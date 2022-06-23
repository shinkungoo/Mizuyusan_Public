//
// Created by Shizumu on 2021/8/3.
//
#include <stdio.h>

int main()
{
    int n=0,fact=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        //仅有c99可以在for的括号中定义变量，正常情况需要在外部定义变量
        fact*=i;
    }

    printf("%d",fact);

    return 0;
}
