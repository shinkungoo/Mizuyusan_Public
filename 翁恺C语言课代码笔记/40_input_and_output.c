//
// Created by Shizumu on 2021/8/7.
//
#include <stdio.h>

int main(int argc,char const *argv[])
{
    int ch;

    while((ch=getchar())!=EOF){
        putchar(ch);
    }
    printf("EOF\n");

    return 0;
}
