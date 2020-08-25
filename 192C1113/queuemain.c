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
    char select;


    printf("?*?行列にしますか\n");
    scanf("%d",&N);
    int array[N*N];


    dataA = newQueue(N);
    dataB = newQueue(N);


    // 行列の演算機能
    printf("二つの行列を作りました。どの計算をしたいですか。remul,add,subどれかを入力してください(該当しない場合は乗算として計算。)\n");
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
    queuePrint(dataFin,N);

    // 逆行列を持つかの判定機能
    printf("逆行列を持つかの判定をします。AとBどちらの行列を確認しますか。(2*2行列以外にはまだ対応していません。)\n");
        char dataSymbol;
        scanf("%s",&dataSymbol);
        if(strcmp(A,&dataSymbol) == 0){
            data = dataA;
        }else if(strcmp(B,&dataSymbol) == 0){
            data = dataB;
        }else{
            printf("そんな行列は存在しません。\n");
        }
        if(raReverseJudge(data,N)){
            printf("%sは逆行列を持ちます。\n",&dataSymbol);
        }else{
            printf("%sは逆行列を持ちません。\n",&dataSymbol);
        }

    // 逆行列生成機能
    if(raReverseJudge(data,N)){
        printf("逆行列は\n");
        dataFin = raReverse(data,N);
        queuePrint(dataFin,N);
    }



    // 行列の表示機能
    // queuePrint(dataFin,N);
    return 0;

}