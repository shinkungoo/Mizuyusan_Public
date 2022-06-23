//
// Created by Shizumu on 2021/8/8.
#include <stdio.h>

enum color {Red,Green,Blue,NumofColors};

int main(void)
{
    int color=-1;
    char *ColorNames[NumofColors]={"Red","Green","Blue"};
    char *colorname=NULL;

    printf("Please type your favorite color's code:");
    scanf("%d",&color);
    if(color>=0&&color<=2){
        colorname=ColorNames[color];
        printf("%s",colorname);
    }else{
        printf("Unknown");
    }

    return 0;
}