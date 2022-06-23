//
// Created by Shizumu on 2021/8/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int number = rand() % 100 + 1;
    int a = 0, count = 0;
    //printf("%d\n",number);
    do {
        scanf("%d", &a);
        count++;
        if (a > number) {
            printf("big\n");
        } else if (a < number) {
            printf("small\n");
        }
    } while (a != number);
    printf("bingo!you have tried %d times", count);

    return 0;

}
