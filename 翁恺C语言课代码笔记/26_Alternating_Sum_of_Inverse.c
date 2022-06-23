//
// Created by Shizumu on 2021/8/4.
//
#include <stdio.h>

int main()
{
    int n=0,i=1;
    double sign=1.0,sum=0.0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sum+=sign/i;
        sign=-sign;
    }
    printf("%f",sum);

    return 0;
}
