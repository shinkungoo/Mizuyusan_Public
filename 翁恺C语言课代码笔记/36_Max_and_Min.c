//
// Created by Shizumu on 2021/8/6.
//
#include <stdio.h>

void maxmin(int a[],int len,int *max,int *min);

int main()
{
    int a[]={1,3,5,4,8,2,1,5,8,0,6,3,12,51,20,14,};
    int max=0,min=0;
    maxmin(a,sizeof(a)/sizeof(a[0]),&max,&min);
    printf("max=%d,min=%d",max,min);

    return 0;
}

void maxmin(int a[],int len,int *max,int *min)
{
    int i=1;
    *max=*min=a[0];
    for(i=1;i<len;i++){
        if(a[i]<*min){
            *min=a[i];
        }
        if(a[i]>*max){
            *max=a[i];
        }
    }
}
