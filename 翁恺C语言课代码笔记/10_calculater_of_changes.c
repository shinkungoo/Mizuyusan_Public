//
// Created by Shizumu on 2021/8/3.
//
#include <stdio.h>

int main()
{
    int bill=0,price=0;
    //初始化
    printf("请输入金额（元）：");
    scanf("%d",&price);
    printf("请输入票面（元）");
    scanf("%d",&bill);
    //读入金额与票面
    if(bill>=price){
        printf("找给您%d元\n",bill-price);//找零
    }
    else{
        printf("您的钱不够"); //钱不够
    }

    return 0;
}
