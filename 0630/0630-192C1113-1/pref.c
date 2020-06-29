#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "zipcount.h"

#define	NOT_FOUND	-1

int zip_pref_search(struct pref_zip_count data[], int size, char prefname[])
{
    int i;

    for(i = 0; i < size; i++){ /* 都道府県名の検索 */
	if(strcmp(prefname, data[i].pref_name) == 0){
	    return i;
	}
    }

    return NOT_FOUND; /* 見つからない */
}

/* 都道府県名を配列に登録する */
void zip_pref_add(struct pref_zip_count data[], int pos, char prefname[])
{
    strcpy(data[pos].pref_name, prefname); /* 都道府県名の登録 */
    data[pos].zipcount = 1; /* 郵便番号数の初期化 */
}

/* 配列に記録されている郵便番号数と都道府県名の組を出力する */
void zip_pref_print(struct pref_zip_count data[], int size)
{
    int i, prefcount;

    for(i = 0; i < size; i++){ /* 郵便番号数と都道府県名を表示 */
	printf("%d: %s\n", data[i].zipcount, data[i].pref_name);
    }
}