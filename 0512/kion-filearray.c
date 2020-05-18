#include<stdio.h>
#include <stdlib.h>

#define ARRAYSIZE 10000


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

    for(int i=0;i<size;i++){
        printf("temper[%d]: %.lf\n",i,temper[i]);
    }
    return 0;
}
