//
// Created by Shizumu on 2021/8/4.
//
#include <stdio.h>

int main()
{
    /*int x=0,s=0,t=0;
	scanf("%d",&x);
	for(int i=1;i<100;i++){
		s=x%i;
		if(s==0){
			t++;
		}
	}
	if(t!=2){
		printf("不是素数");
	} else {
		printf("是素数");
	}*/
    //以上利用的是数学知识，没有涉及到循环控制，接下来会涉及

    int x=0;
    int isPrime=1;

    scanf("%d",&x);

    for(int i=2;i<x;i++){
        if(x%i==0){
            isPrime=0;
            break;
            //跳出循环，这个要区别于continue，continue是跳过该循环剩下语句并继续循环
        }
    }
    if(isPrime==1){
        printf("是素数");
    }else{
        printf("不是素数");
    }
    return 0;
    //区别在于，第一种代码可以判断1，第二种代码要改才能判断
}
