//
// Created by Shizumu on 2021/8/8.
//
#include <stdio.h>

struct date{
    int mouth;
    int date;
    int year;
};

int main(void)
{
    struct date today;
    today=(struct date){8,8,2021};

    struct date tomorrow;
    //struct date *pDate=&tomorrow;

    printf("Today is %i-%i-%i",today.mouth,today.date,today.year);

    return 0;
}
