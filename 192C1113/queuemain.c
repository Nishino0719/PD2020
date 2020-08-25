#include<stdio.h>
#include "rational.h"

int main(void){
    RATIONAL test;
    int N;


    printf("?*?行列にしますか\n");
    scanf("%d",&N);
    int array[N*N];

    printf("%d回文字を入力してください\n",N*N);
    int input;
    for(int i =0;i<N;i++){
        for(int j=0; j<N;j++){
        printf("(%d,%d) = ",i+1,j+1);
        scanf("%d",&input);
        test = newQueue(input,i,j);
        }
    }
    

    return 0;

}