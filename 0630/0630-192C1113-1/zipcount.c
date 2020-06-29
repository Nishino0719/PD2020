#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "zipcount.h"


#define	MAXLINE	200
#define	MAXPREFNAME	20
#define MAXPREFNUM	100
#define	NOT_FOUND	-1

int main(void)
{   
    FILE *fp;
    char buff[MAXLINE];
    char prefname[MAXPREFNAME];
    struct pref_zip_count zip_count[MAXPREFNUM];
    int index, prefcount;

    if((fp = fopen("YUBIN.csv", "r")) == NULL){
	fprintf(stderr, "Error: File Open\n");
	exit(1);
    }

    prefcount = 0;
    while(fgets(buff, MAXLINE, fp) != NULL){
	/* 最初の2つのデータは読み飛ばす。エラーチェックを省略 */
	sscanf(buff, "%*d,%*[^,],%[^,]", prefname);

	/* 都道府県名の検索とデータの更新、あるいは新規登録 */
	if((index = zip_pref_search(zip_count, prefcount, prefname)) != NOT_FOUND){
	    /* 既に記録されていたら件数をインクリメント */
	    zip_count[index].zipcount++;
	}else{
	    /* まだ登録されていなければ都道府県を追加 */
	    zip_pref_add(zip_count, prefcount, prefname);
	    prefcount++; /* 登録されている都道府県数を更新 */
	}
    }

    fclose(fp);

    zip_pref_print(zip_count, prefcount);

    return 0;
}
