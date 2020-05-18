#include<stdio.h>
#include <stdlib.h>

#define ARRAYSIZE 10000


void temperPrint(double array[],int size){
    for(int i=0;i<size;i++){
        printf("temper[%d]: %.1lf\n",i,array[i]);
    }
}

double temperAve(double array[],int size){
    double sum=0;

    for(int i=0;i<size;i++){
        sum+=array[i];
    }

    return sum/size;
}
double temperMax(double array[],int size){
    double max=array[0];

    for(int i=1;i<size;i++){
        if(max<array[i]){
            max=array[i];
        }
    }

    return max;

}
double temperMin(double array[],int size){
    double min=array[0];

    for(int i=1;i<size;i++){
        if(min > array[i]){
            min=array[i];
        }
    }

    return min;
}


int main(void){
    // ファイルポインタ
    FILE *fp;
    int month,day,hour;
    double data;
    double temper[ARRAYSIZE];
    int size=0;
    // ファイルのオープン:ファイル名と入力用の利用を指定
    if((fp = fopen("kion-20180401.csv","r")) == NULL){
        // オープンできなかった時の処理
        fprintf(stderr,"Error:File Open\n");
        // プログラムの終了
        exit(1);
    }
    // ファイルの直後に(EOF)までの読み込み
    while(fscanf(fp,"%d,%d,%d,%lf",&month,&day,&hour,&data) != EOF){
        // printf("%d月%d日%d時 %.lf\n",month,day,hour,data);
        temper[size] = data;
        size++;
    }
    // ファイルのクローズ
    fclose(fp);

    temperPrint(temper,size);
    printf("_____________\n");
    printf("平均気温: %.1lf\n",temperAve(temper,size));
    printf("最高気温: %.1lf\n",temperMax(temper,size));
    printf("最低気温: %.1lf\n",temperMin(temper,size));
    return 0;
}
