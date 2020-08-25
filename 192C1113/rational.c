#include<stdio.h>
#include "rational.h"

RATIONAL newQueue(int n){
    RATIONAL a;
    printf("%d回文字を入力してください(連立方程式を求める場合はそれぞれの係数を2回ずつ入力)\n",n*n);
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

RATIONAL ansQueue(int n){
    RATIONAL a;
    printf("%d回文字を入力してください,それぞれの解\n",n);
    int input;
    printf("最初の式の解は");
    scanf("%d",&input);
    a.queue[0][0] = input;
    printf("二番目の式の解は");
    scanf("%d",&input);
    a.queue[1][1] = input;
    return a; 
}

RATIONAL raCramelQueue(int n,RATIONAL a,RATIONAL b){
    RATIONAL v;
    int m;
    if(n == 0){
        m = 1;
    }else{
        m = 0;
    }
        v.queue[n][n] = b.queue[n][n];
        v.queue[n][m] = a.queue[n][m];
        v.queue[m][n] = b.queue[m][m];
        v.queue[m][m] = a.queue[n][m];

    return v;
}

RATIONAL raRemul(RATIONAL a,double rem,int n){
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

// 逆行列を持つかの判定、2*2行列の場合は行列式の値が0であれば逆行列を持つ。
int raReverseJudge(RATIONAL a,int n){
    if(n == 2){
        if(((a.queue[0][0]*a.queue[1][1])-(a.queue[1][0]*a.queue[0][1])) != 0){
            return 1;
        }
    }else{
        printf("掃き出し法を使って逆行列を求めます。今回の課題の範囲外\n");
    }
    return 0;
}

RATIONAL raReverse(RATIONAL a,int n){
    RATIONAL v;
    int param = a.queue[0][0]*a.queue[1][1]-a.queue[1][0]*a.queue[0][1];
    if(n == 2){
        v.queue[0][0] = a.queue[1][1]/param;
        v.queue[0][1] = -a.queue[0][1]/param;
        v.queue[1][0] = -a.queue[1][0]/param;
        v.queue[1][1] = a.queue[0][0]/param;
    }else{
        printf("掃き出し法を使って逆行列を求めます。今回の課題の範囲外\n");
    }
    return v;
}

void displayAns(RATIONAL a,RATIONAL b){
    double X,Y;
    X = a.queue[0][0]*b.queue[0][0]+ a.queue[0][1]*b.queue[1][1];
    Y = a.queue[1][0]*b.queue[0][0]+ a.queue[1][1]*b.queue[1][1];

    printf("求める解は(x,y) = (%.2f,%.2f)\n",X,Y);
}

void displayResult(RATIONAL a,RATIONAL b){
    // ガウスの消去法で階段を作る
    double divi;
    divi = a.queue[1][0]/a.queue[0][0];
    for(int i=0;i<2;i++){
        a.queue[1][i] = a.queue[1][i] - divi*a.queue[0][i];
    }
       b.queue[1][1] = b.queue[1][1] - divi*b.queue[0][0];
    if(a.queue[1][0] == 0 && a.queue[1][1] == 0 && b.queue[1][1] == 0){
        printf("この連立方程式は解を無数にもつ\n");
    }else{
        printf("この連立方程式は解を持たない\n");
    }
}

int raInt(RATIONAL a,int n){
    return a.queue[0][0]*a.queue[1][1]-a.queue[1][0]*a.queue[0][1];
}

double raGetElement(RATIONAL a,int x,int y){
    return a.queue[x][y];
}




void queuePrint(RATIONAL v,int n){
    for(int i =0;i<n;i++){
        for(int j=0; j<n;j++){
        printf("(%d,%d) = %.2f\n",i+1,j+1,v.queue[i][j]);
        }
    }
}