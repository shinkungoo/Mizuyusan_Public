//
// Created by Shizumu on 2021/8/2.
//
#include <stdio.h>

int main()
{
    int x=0;
    scanf("%d",&x);
    double amount=x*(1+0.033)*(1+0.033)*(1+0.033);
    printf("%f",amount);

    return 0;
}
