//
// Created by Shizumu on 2021/8/8.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,const char *argv[])
{
    char s[]="Hello";
    char *p=strchr(s,'l');
    char *t=(char*)malloc(sizeof(p)+1);
    strcpy(t,p);
    printf("%s\n",t);
    free(t);
    char *u=(char*)malloc(sizeof(s)+1);
    char c=*p;
    *p='\0';
    strcpy(u,s);
    printf("%s\n",u);
    free(u);
    *p=c;
    printf("%s",s);



    return 0;
}
