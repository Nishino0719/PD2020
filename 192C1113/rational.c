#include<stdio.h>
#include "rational.h"

RATIONAL newQueue(RATIONAL a,int n){
    printf("%d回文字を入力してください\n",n*n);
    int input;
    for(int i =0;i<n;i++){
        for(int j=0; j<n;j++){
        printf("(%d,%d) = ",i+1,j+1);
        scanf("%d",&input);
        a.queue[i][j] = input;
        }
    }
    return a;
}