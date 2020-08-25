#include<stdio.h>
#include <string.h>
#include "rational.h"

int main(void){
    RATIONAL data;
    RATIONAL dataA;
    RATIONAL dataB;
    RATIONAL dataFin;
    int N;
    char *A = "A";
    char *B = "B";
    char *remul = "remul";
    char *add = "add";
    char *sub = "sub";
    char *mul = "mul";
    char select;


    printf("?*?行列にしますか\n");
    scanf("%d",&N);
    int array[N*N];


    dataA = newQueue(N);
    dataB = newQueue(N);
    printf("二つの行列を作りました。どの計算をしたいですか。remul,add,subどれかを入力してください(該当しない場合は乗算として計算。)");
    scanf("%s",&select);
    if(strcmp(remul,&select) == 0){
        printf("実数倍をします。A,Bどちらの行列を対象にしますか？\n");
        char dataSymbol;
        scanf("%s",&dataSymbol);
        if(strcmp(A,&dataSymbol) == 0){
            data = dataA;
        }else if(strcmp(B,&dataSymbol) == 0){
            data = dataB;
        }else{
            printf("そんな行列は存在しません。\n");
        }
        printf("実数倍をします。一番最初に入力した行列を何倍しますか？\n");
        int rem;
        scanf("%d",&rem);
        dataFin = raRemul(data,rem,N);
    }else if(strcmp(add,&select) == 0){
        printf("加算ですね、計算するまでしばらくお待ちください\n");
        dataFin = raAdd(dataA,dataB,N);
    }else if(strcmp(sub,&select) == 0){
        printf("減算ですね、計算するまでしばらくお待ちください\n");
        dataFin = raSub(dataA,dataB,N);
    }else{
        printf("乗算ですね、計算するまでしばらくお待ちください\n");
        dataFin = raMul(dataA,dataB,N);
    }

    // 行列の表示
    queuePrint(dataFin,N);
    return 0;

}