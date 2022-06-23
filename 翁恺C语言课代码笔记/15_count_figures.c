//
// Created by Shizumu on 2021/8/3.
//
#include <stdio.h>

int main()
{
    int x=0,n=0;
    scanf("%d",&x);
    /*
    while(x>0){
		n++;
		x/=10;
	}
	printf("%d",n);
	问题在于，0被判断为了0位数，这是不正确的，因此不能直接开始循环，应改为：
	*/
    /*
    n++;
	x/=10;
	while(x>0){
		n++;
		x/=10;
	}
	printf("%d",n);*/

    do{
        x/=10;
        n++;
    }while(x>0);
    printf("%d",n);

    return 0;
}
