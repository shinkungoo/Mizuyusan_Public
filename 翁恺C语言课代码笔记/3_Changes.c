//
// Created by Shizumu on 2021/8/2.
//
#include <stdio.h>

int main() {
    int price = 0;
    const int amount = 100;

    printf("请输入价格（元）：");
    scanf("%d", &price);

    int change = amount - price;

    printf("找给您%d元\n", change);

    return 0;
}
