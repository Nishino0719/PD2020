#include<stdio.h>
#include <string.h>
#include "rational.h"

int main(void){
    RATIONAL data;
    RATIONAL dataA;
    RATIONAL dataB;
    RATIONAL ReverceA;

    RATIONAL dataAns;
    RATIONAL dataFin;
    int N;
    char *A = "A";
    char *B = "B";
    char *remul = "remul";
    char *add = "add";
    char *sub = "sub";
    char *yes = "yes";
    char select;


    printf("?*?行列にしますか(連立方程式を求める場合は2を入力しなければならない)\n");
    scanf("%d",&N);
    int array[N*N];
    if(N==2){
        printf("連立方程式の解を求めますか？求める場合はyesを入力\n");
        char rep;
        scanf("%s",&rep);
        if(strcmp(yes,&rep) == 0){
            dataA = newQueue(N);
            dataAns = ansQueue(N);
            if(raReverseJudge(dataA,N)){
                double X,Y;
                printf("この連立方程式はただ一つの解を持つ\n");
                ReverceA = raReverse(dataA,N);
                double answer[2];
                displayAns(ReverceA,dataAns);
            }else{
                displayResult(dataA,dataAns);
            }
        }
    }

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

    // 行列要素取得機能
    printf("AとBどちらの行列の要素を取得しますか。\n");
        // char dataSymbol;
        scanf("%s",&dataSymbol);
        if(strcmp(A,&dataSymbol) == 0){
            data = dataA;
        }else if(strcmp(B,&dataSymbol) == 0){
            data = dataB;
        }else{
            printf("そんな行列は存在しません。\n");
        }
    printf("どの要素を取得したいですか？空白を開けて入力してください[?][?]");
    int x,y;
    scanf("%d %d",&x,&y);
    if(x > 0 && x < N+1 && y > 0 && y < N+1){
        printf("[%d][%d] = %.2f\n",x,y,raGetElement(data,x-1,y-1));
    }else{
        printf("行列の範囲外です\n");
    }





    // 行列の表示機能
    // queuePrint(dataFin,N);
    return 0;

}