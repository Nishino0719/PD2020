#include<stdio.h>
#include "rational.h"

RATIONAL newQueue(int a,int i,int j){
    RATIONAL v;
    v.queue[i][j] = a;
    printf("確かに確認しました。%d,%dに%dですね\n",i,j,v.queue[i][j]);
    return v;
}