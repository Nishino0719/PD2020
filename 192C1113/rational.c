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

RATIONAL raRemul(RATIONAL a,int rem,int n){
    RATIONAL v;
    for(int i =0;i<n;i++){
        for(int j=0; j<n;j++){
        v.queue[i][j] = rem*(a.queue[i][j]);
        }
    }
    return v;
}
RATIONAL raAdd(RATIONAL a, RATIONAL b,int n){
    RATIONAL v;
    for(int i =0;i<n;i++){
        for(int j=0; j<n;j++){
        v.queue[i][j] = a.queue[i][j] + b.queue[i][j];
        }
    }
    return v;
}
RATIONAL raSub(RATIONAL a, RATIONAL b,int n){
    RATIONAL v;
    for(int i =0;i<n;i++){
        for(int j=0; j<n;j++){
        v.queue[i][j] = a.queue[i][j] - b.queue[i][j];
        }
    }
    return v;
}
RATIONAL raMul(RATIONAL a, RATIONAL b,int n){
    RATIONAL v;
    for(int i =0;i<n;i++){
        for(int j=0; j<n;j++){
            v.queue[i][j] = 0;
            for(int k=0;k<n;k++){
                v.queue[i][j] += a.queue[i][k]*b.queue[k][j];
            }
        }
    }
    return v;
}









void queuePrint(RATIONAL v,int n){
    for(int i =0;i<n;i++){
        for(int j=0; j<n;j++){
        printf("(%d,%d) = %d\n",i+1,j+1,v.queue[i][j]);
        }
    }
}