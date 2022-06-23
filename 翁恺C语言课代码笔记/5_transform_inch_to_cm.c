//
// Created by Shizumu on 2021/8/2.
//
#include <stdio.h>

int main()
{
    double foot=0,inch=0;

    printf("请输入身高为几尺几寸");
    scanf("%lf %lf",&foot,&inch);

    printf("身高为%f米",((foot+inch/12)*0.3048));
    return 0;
}
