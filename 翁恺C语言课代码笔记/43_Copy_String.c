//
// Created by Shizumu on 2021/8/8.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mycpy(char *dst,const char *src)
{
    /*int idx=0;
    while(src[idx]!=0){
        dst[idx]=src[idx];
        idx++;
    }
    dst[idx]='\0';
    */
    char *ret=dst;
    //不是赋值，而是ret与dst两个指针指向了同一个字符串
    while(*src!=0){
        *dst++=*src++;
    }
    *dst='\0';

    return ret;
}

int main(int argc,const char *argv[])
{
    char *src="hello world";
    char *dst1=(char*)malloc(strlen(src)+1);
    char *dst2=(char*)malloc(strlen(src)+1);
    strcpy(dst1,src);
    mycpy(dst2,src);
    printf("%s\n",dst1);
    printf("%s\n",dst2);

    free(dst1);
    free(dst2);

    return 0;
}
