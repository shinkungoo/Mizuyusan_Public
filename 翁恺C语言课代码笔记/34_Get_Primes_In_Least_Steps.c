//
// Created by Shizumu on 2021/8/5.
//
#include <stdio.h>
#define number 100
/*
这个定义不像 const一样是run-time时期变量，如果类型不匹配，就会报错
由于const是一种变量，运行时会被分配内存；
define是complie-time时期变量，编译时会全部替换，虽然不会做类型检查
（不安全），但是在运行时是不会占用内存的
*/
int isPrime(int x,int KnownPrimes[],int length);

int main()
{
    int prime[number]={2};
    int count=1,i=3;

    while(count<number){
        if(isPrime(i,prime,count)==1){
            prime[count++]=i;
        }
        i++;
    }
    for(i=0;i<number;i++){
        if((i+1)%5==0){
            printf("%d\n",prime[i]);
        }else{
            printf("%d\t",prime[i]);
        }
    }

    return 0;
}

int isPrime(int x,int KnownPrimes[],int length)
{
    int ret=1;
    int i=0;

    for(i=0;i<length;i++){
        if(x%KnownPrimes[i]==0){
            ret=0;
            break;
        }
    }

    return ret;
}