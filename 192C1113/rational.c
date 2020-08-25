#include<stdio.h>
#include "rational.h"

RATIONAL newQueue(int n){
    RATIONAL a;
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









void queuePrint(RATIONAL v,int n){
    for(int i =0;i<n;i++){
        for(int j=0; j<n;j++){
        printf("(%d,%d) = %d\n",i+1,j+1,v.queue[i][j]);
        }
    }
}