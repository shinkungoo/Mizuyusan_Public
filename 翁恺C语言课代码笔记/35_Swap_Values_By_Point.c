//
// Created by Shizumu on 2021/8/6.
//
#include <stdio.h>

void swap(int *pa,int *pb);

int main()
{
    int a=5,b=6;
    swap(&a,&b);
    printf("a=%d,b=%d",a,b);

    return 0;
}

void swap(int *pa,int *pb)
{
    int t= *pa;
    *pa=*pb;
    *pb=t;

}
/*
当函数返回多个值，这些值只能通过指针返回
传入的参数是需要保存待会的变量的地址
 */
