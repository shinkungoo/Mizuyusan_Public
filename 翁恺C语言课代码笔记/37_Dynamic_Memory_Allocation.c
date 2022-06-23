//
// Created by Shizumu on 2021/8/6.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int *a;
    int i;

    printf("type the number:");
    scanf("%d",&number);

    a= (int*)malloc(number*sizeof(int));

    for(i=0;i<number;i++){
        scanf("%d",&a[i]);
    }
    for(i=number-1;i>=0;i--){
        printf("%d ",a[i]);
    }

    free(a);

    return 0;
}
