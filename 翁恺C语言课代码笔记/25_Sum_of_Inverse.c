//
// Created by Shizumu on 2021/8/4.
//
#include <stdio.h>

int main()
{
    int n=0,i=1;
    double sum=0.0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sum+=1.0/i;
    }
    printf("%f",sum);

    return 0;
}
