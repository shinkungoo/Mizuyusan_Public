//
// Created by Shizumu on 2021/8/3.
//
#include <stdio.h>

int main()
{
    int in=0,sum=0;
    double count=0;
    scanf("%d",&in);

    if(in!=-1){
        while(in!=-1){
            sum=sum+in;
            count++;
            scanf("%d",&in);
        }
        printf("%f",sum/count);
    }else{
        printf("%d",0);
    }
    //设置这个if是为了防止开局-1骑脸杀
    return 0;
}
