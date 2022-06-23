//
// Created by Shizumu on 2021/8/4.
//
#include <stdio.h>

int main() {
    int x1 = 0, x2 = 0, t = 0;
    int gcd = 0;
    scanf("%d %d", &x1, &x2);
    while (x2 > 0) {
        t = x1 % x2;
        x1 = x2;
        x2 = t;
    }
    gcd = x1;
    printf("%d", gcd);

    return 0;
}
