//
// Created by Shizumu on 2021/8/7.
//
#include <stdio.h>

int main() {
    int hour1 = 0, minute1 = 0;
    int hour2 = 0, minute2 = 0;

    scanf("%d %d", &hour1, &minute1);
    scanf("%d %d", &hour2, &minute2);

    int t1 = hour1 * 60 + minute1;
    int t2 = hour2 * 60 + minute2;

    int t = t2 - t1;

    printf("Ïà²î%dÊ±%d·Ö", t / 60, t % 60);

    return 0;
}
