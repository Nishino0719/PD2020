#include <stdio.h>
#include <stdlib.h> /* exit関数が定義されている */

#define	MAXFILENAME 100 /* ファイル名の最大長 */
#define ARRAYSIZE 1000

struct kisyou {
    int month;
    int day;
    int hour;
    double kion;
};

int readfile(char filename[], int amex){
    FILE *fp ; /* ファイルポインタ（ファイルの識別子） */
    int month, day, hour ;
    double data ;
    int size;
    struct kisyou kisyoudata[ARRAYSIZE];

    if ((fp = fopen(filename, "r")) == NULL) {
	/* 以下の２行はファイルがオープンできなかった時の処理 */
	fprintf(stderr, "Error: File Open\n") ;
	exit(1) ; /* プログラムをここで終了させる */
    }
    size = 0;
    /* ファイルの最後 EOF(End of File) までの読み込み */
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
	if(size >= ARRAYSIZE){
        fprintf(stderr,"Error:配列の容量不足\n");
        exit(2);
    }
        kisyoudata[size].month = month;
        kisyoudata[size].day = day;
        kisyoudata[size].hour = hour;
        kisyoudata[size].kion = data;
        size++;
    }

    /* ファイルのクローズ */
    fclose(fp) ;

    return size;
}

int main(void)
{
    char filename[MAXFILENAME] ;
    struct kisyou kisyoudata[ARRAYSIZE];
    int size,i;

    /* プロンプトの出力とファイル名の入力 */
    fprintf(stderr, "データファイル名：") ;
    scanf("%s", filename) ; /* 端末からファイル名を入力 */

    size = readfile(filename,ARRAYSIZE);

    for(i = 0;i < size; i++){
        printf("%d月%d日%d時　：%.1f\n",
            kisyoudata[i].month,kisyoudata[i].day,
            kisyoudata[i].hour,kisyoudata[i].kion);
    }
    return 0 ;
}
