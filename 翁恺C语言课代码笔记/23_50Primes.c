//
// Created by Shizumu on 2021/8/4.
//
#include <stdio.h>

int main()
{
    int x=0,i=0,cnt=0;
    for(x=2;cnt<50;x++){
        int p=1;
        for(i=2;i<x;i++){
            if(x%i==0){
                p=0;
                break;
            }
        }
        if(p==1){
            printf("%d\t",x);
            cnt++;
            if(cnt%5==0){
                printf("\n");
            }
        }
    }

    return 0;
}
