//
// Created by Shizumu on 2021/8/8.
//
#include <stdio.h>
#include <string.h>

int mycmp(const char *s1,const char *s2);

int main(int argc,const char *argv[])
{
    char s1[]="abc";
    char s2[]="Abc";
    //printf("%d",s1==s2);
    //Array comparison always evaluates to false，因为我们比较的是s1和s2地址，然而地址不可能相等
    printf("%d\n",strcmp(s1,s2));
    printf("%d\n", mycmp(s1,s2));

    return 0;
}

int mycmp(const char *s1,const char *s2)
{
    int idx=0;
    while(s1[idx]==s2[idx]&&s1[idx]!='\0'){
        idx ++;
    }
    return s1[idx]-s2[idx];
    /*另外，可以用指针移动：
     while(*s1==*s2&&*s1!='\0'){
     s1++;
     s2++;
     }
     return *s1-*s2;
    */
}
