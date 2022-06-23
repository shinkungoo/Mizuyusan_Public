//
// Created by Shizumu on 2021/8/7.
//
#include <stdio.h>
#include <string.h>

int mylen(const char*s)
{
    int idx=0;
    while(s[idx]!='\0'){
        idx++;
    }

    return idx;
}

int main(int argc, char const *argv[])
{
    char line[]="Hello"	;
    printf("strlen=%d\n",strlen(line));
    printf("mylen=%d\n",mylen(line));
    printf("sizeof=%d\n",sizeof(line));

    return 0;


}
