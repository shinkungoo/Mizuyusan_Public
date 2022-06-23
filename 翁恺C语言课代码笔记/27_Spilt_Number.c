//
// Created by Shizumu on 2021/8/4.
//
#include <stdio.h>

int main()
{
    /*先逆序再逆序可以处理大部分问题，但是对于700等，就无能无力了
	因此，以下方法可避免*/
    int x=0,n=0;
    int figure=0,dec=1;
    scanf("%d",&x);
    n=x;
    while(x>=10){
        x/=10;
        figure++;
        dec*=10;
    }

    for(figure++;figure>0;figure--){
        printf("%d ",n/dec);
        n%=dec;
        dec/=10;
    }
    return 0;
}
