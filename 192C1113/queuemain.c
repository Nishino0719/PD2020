#include<stdio.h>
#include "rational.h"

int main(void){
    RATIONAL data;
    int N;


    printf("?*?行列にしますか\n");
    scanf("%d",&N);
    int array[N*N];

    newQueue(data,N);
    printf("%d%d%d%dですです",data.queue[0][0],data.queue[0][1],data.queue[1][0],data.queue[1][1]);
    return 0;

}