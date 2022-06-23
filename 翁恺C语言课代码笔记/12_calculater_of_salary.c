//
// Created by Shizumu on 2021/8/3.
//
#include <stdio.h>

int main(){
    const double RATE=8.25;
    const double STANDARD=40;
    double pay=0.0;
    int hours=0;

    printf("请输入您工作的小时数：");
    scanf("%d",&hours);

    if(hours>STANDARD){
        pay=STANDARD*RATE+(hours-STANDARD)*(RATE*1.5);
    }
    else{
        pay=hours*RATE;
    }
    printf("应付工资%f",pay);

    return 0;
}
