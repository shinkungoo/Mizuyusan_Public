//
// Created by Shizumu on 2021/8/8.
//
#include <stdio.h>
#include <stdbool.h>

struct day {
    int month;
    int date;
    int year;
};

bool isLeap(struct day *pDay);

bool isLast(struct day *pDay);

struct day *input(struct day *pDay);

void output(struct day d);

int main(void) {
    struct day today;
    struct day tomorrow;
    input(&today);
    if (isLast(&today) == false) {
        tomorrow.month = today.month;
        tomorrow.date = today.date + 1;
        tomorrow.year = today.year;
    } else if (today.month == 12) {
        tomorrow.month = 1;
        tomorrow.date = 1;
        tomorrow.year = today.year + 1;
    } else {
        tomorrow.month = today.month + 1;
        tomorrow.date = 1;
        tomorrow.year = today.year;
    }
    output(tomorrow);
    return 0;
}

bool isLeap(struct day *pDay) {
    bool ret = 0;
    if ((pDay->year % 4 == 0 && pDay->year % 100 != 0) || pDay->year % 400 == 0) {
        ret = true;
    } else {
        ret = false;
    }

    return ret;
}

bool isLast(struct day *pDay) {
    bool ret = 0;
    int lastday[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeap(pDay) == true) {
        lastday[1] = 29;
    }
    if (pDay->date == lastday[pDay->month - 1]) {
        ret = true;
    } else {
        ret = false;
    }

    return ret;
}

struct day *input(struct day *pDay) {
    scanf("%d", &pDay->month);
    scanf("%d", &pDay->date);
    scanf("%d", &pDay->year);
    return pDay;
}

void output(struct day d) {
    printf("%i-%i-%i", d.month, d.date, d.year);
}