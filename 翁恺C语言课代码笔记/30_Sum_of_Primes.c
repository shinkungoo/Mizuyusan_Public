//
// Created by Shizumu on 2021/8/5.
//
#include <stdio.h>

int isPrime(int i);

int main()
{
    int m=0,n=0,sum=0,i=0;
    scanf("%d %d",&m,&n);
    if(m==1){
        m=2;
    }
    for(i=m;i<=n;i++){
        if(isPrime(i)==1){
            sum+=i;
        }
    }
    printf("%d",sum);

    return 0;
}

int isPrime(int i)
{
    int ret=1;
    int k;
    for(k=2;k<i-1;k++){
        if(i%k==0){
            ret=0;
            break;
        }
    }
    return ret;
}