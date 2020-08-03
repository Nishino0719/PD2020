#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordcount.h"


typedef struct wordcountlist{
    struct wordcountlist *next;
    WORDCOUNT info; 
}WORDCOUNTLIST;

WORDCOUNTLIST *root;
WORDCOUNTLIST *WCLCurrent;


void wordcountInit(void)
{
    root = NULL;
}


WORDCOUNT *wordcountSearch(char *word)
{
    WORDCOUNTLIST *wcl;

    for (wcl = root; wcl != NULL; wcl = wcl->next) {
	

	if(strcmp(word, wcl->info.word) == 0) {
	    return &wcl->info;
	}
    }

    return NULL;
}


void wordcountRegister(char *word)
{
    WORDCOUNT *id;
    WORDCOUNTLIST *wcl;

    if ((id = wordcountSearch(word)) != NULL) {

	id->count++;


       
	wcl->info.count++;
    } else {

	wcl = (WORDCOUNTLIST *)malloc(sizeof(WORDCOUNTLIST));
	strcpy(wcl->info.word, word);
	wcl->info.count = 1;
	wcl->next = root;
	root = wcl;
	
	
    }
}


void wordcountStatistics(void)
{
    WORDCOUNTLIST *wcl;

    for (wcl = root; wcl != NULL; wcl = wcl->next) {
	printf("%5d: %s\n", wcl->info.count, wcl->info.word);
    }
    free(wcl);
}
WORDCOUNT *wordcountGetFirst(void){
    WORDCOUNT *wcp;
    WCLCurrent = root;

    if(WCLCurrent != NULL){
        wcp = &(WCLCurrent->info);
        WCLCurrent = WCLCurrent->next;
        return wcp;
    }else{
        return NULL;
    }
}
// 次の単語のデータを取得
WORDCOUNT *wordcountGetNext(void){
    WORDCOUNT *wcp;

    if(WCLCurrent != NULL){
        wcp = &(WCLCurrent->info);
        WCLCurrent = WCLCurrent->next;
        return wcp;
    }else{
        return NULL;
    }
}

char *wcGetWord(WORDCOUNT *wcp){
    // 文字列を返す処理を記述
    return wcp->word;
}

int wcGetCount(WORDCOUNT *wcp){
    // WORDCOUNTから単語の出現回数を返す処理を記述
    return wcp->count;
}



