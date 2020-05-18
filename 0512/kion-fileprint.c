#include<stdio.h>
#include <stdlib.h>


int main(void){
    // ファイルポインタ
    FILE *fp;
    int month,day,hour;
    double data;
    // ファイルのオープン:ファイル名と入力用の利用を指定
    if((fp = fopen("kion-20180401.csv","r")) == NULL){
        // オープンできなかった時の処理
        fprintf(stderr,"Error:File Open\n");
        // プログラムの終了
        exit(1);
    }
    // ファイルの直後に(EOF)までの読み込み
    while(fscanf(fp,"%d,%d,%d,%lf",&month,&day,&hour,&data) != EOF){
        printf("%d月%d日%d時 %.lf\n",month,day,hour,data);
    }
    // ファイルのクローズ
    fclose(fp);
    return 0;
}
