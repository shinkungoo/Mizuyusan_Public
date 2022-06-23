//
// Created by Shizumu on 2021/8/2.
//
#include <stdio.h>

int main()
{
    int a = 5,b = 6;
    int c = 0;
    scanf("%d %d", &a, &b);

    c = a;
    a = b;
    b = c;
    printf("%d %d", a, b);

    return 0;
}
