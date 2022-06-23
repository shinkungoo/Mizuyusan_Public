//
// Created by Shizumu on 2021/8/8.
//
#include <stdio.h>
#include <string.h>

char *mycat(char *dst,const char *src)
{
    /*int idx1=0;
    while(dst[idx1]!='\0'){
        idx1++;
    }
    int idx2=0;
    while(src[idx2]!='\0'){
        dst[idx1++]=src[idx2++];
    }
    dst[idx1]='\0';

    return dst;
    */
    char *ret=dst;
    while(*dst!='\0'){
        *dst++;
    }
    while(*src!='\0'){
        *dst++=*src++;
    }
    *dst='\0';

    return ret;

}

int main(int argc, const char *argv[])
{
    char s1[8];
    char s2[20]="This is a ";
    char s3[30]="But this is also a ";
    scanf("%7s",s1);
    strcat(s2,s1);
    mycat(s3,s1);
    printf("%s\n",s1);
    printf("%s\n",s2);
    printf("%s\n",s3);
    return 0;
}
