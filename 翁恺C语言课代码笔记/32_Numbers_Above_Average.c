//
// Created by Shizumu on 2021/8/5.
//
#include <stdio.h>

int main()
{
    int number[100];
    int in=0,count=0;
    double sum=0;
    scanf("%d",&in);

    while(in!=-1){
        number[count]=in;
        sum+=in;
        count++;
        scanf("%d",&in);
    }
    if(count>0){
        printf("%f\n",sum/count);
        int i;
        for(i=0;i<count;i++){
            if(number[i]>sum/count){
                printf("%d ",number[i]);
            }
        }
    }

    return 0;
}
