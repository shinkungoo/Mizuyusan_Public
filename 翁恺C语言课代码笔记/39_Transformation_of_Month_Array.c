//
// Created by Shizumu on 2021/8/7.
//
#include <stdio.h>

int main()
{
    int x=0;
    char *a[]={
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December",
            };

    scanf("%d",&x);
    printf("%s",a[x-1]);
    //注意，printf在输出字符串时会输入字符串的地址，参考：
    //char *b="Hello World";
    //printf("%s",b);
    return 0;
}
/*
 char *a[]:
 	point         string in a certain position of RAM(far awary from int x)
	a[0]--------->balbal\0
	a[1]--------->bajasaljss\0
	a[2]--------->hasdjjdkaj\0
 char a[][n]:
 					n
	a[0]   sdasjkjadjjdja\0
	a[1]   adkasjdjlakakdadasda\0
	a[2]   jdkjasjdajdjkad\0
 */
