//
// Created by Shizumu on 2021/8/5.
//
#include <stdio.h>

int main()
{
    /*	int in[100];
        int count[100];
        int i=0,j=0,cnt=0;
        scanf("%d",&in[0]);
        while(in[i]!=-1){
            i++,cnt++;
            scanf("%d",&in[i]);
        }
        for(i=0;i<=cnt;i++){
            count[i]=1;
            for(j=i+1;j<=cnt;j++){
                if(in[i]==in[j]&&in[i]!=-1){
                    count[i]++;
                    in[j]=-1;
                }
            }
            if(in[i]!=-1){
                printf("数字%d出现了%d次\n",in[i],count[i]);
            }
        }
        以上数数原理是首先把输入的数字收成列表，这些数字已经被输入的值初始化
        接下来，利用变量cnt保证不会遍历到之后未被使用的数组
        然后，利用for循环数数
        为了防止第二次遇到同样数后重复遍历，在完成一个数的确定后将其替换为无效的-1
        可是，这样子并不精简
    */

    const int number =10;
    int x=0,i=0;
    int count[10];

    for(i=0;i<number;i++){
        count[i]=0;
    }
    scanf("%d",&x);
    while(x!=-1){
        if(x>=0&&x<=9){
            count[x]++;
        }
        scanf("%d",&x);
    }

    for(i=0;i<number;i++){
        printf("数字%d出现了%d次\n",i,count[i]);
    }
    /*以上方案精简，而且排序，又很优美，经典例子！！！！*/
    return 0;
}
