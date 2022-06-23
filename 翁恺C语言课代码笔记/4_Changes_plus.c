//
// Created by Shizumu on 2021/8/2.
//
#include <stdio.h>

int main()
{
    int amount=0,price=0;

    printf("请输入金额和票面（元）");
    scanf("%d %d",&price,&amount);

    printf("找给您%d-%d=%d元",amount,price,amount-price);

    return 0;
}
