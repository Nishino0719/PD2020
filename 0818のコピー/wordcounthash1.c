#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordcount.h"
#define HASH_TABLE_SIZE 4441

typedef struct wordcountlist{
  struct wordcountlist *next;
  WORDCOUNT info;
}WORDCOUNTLIST;


WORDCOUNTLIST *HashTable[HASH_TABLE_SIZE];
WORDCOUNTLIST *WCLCurrent;

/* 初期化 */
void wordcountInit(void)
{
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
      HashTable[i] = NULL;
    }
}
unsigned int hash(char *s){
  unsigned int v;

  for(v = 0; *s != '\0';s++){
    v = (v << 2) + *s;
  }
  return v % HASH_TABLE_SIZE;
}

/* 単語の検索 */
WORDCOUNT *wordcountSearch(char *word)
{
    unsigned int hash_value;
    WORDCOUNTLIST *wcl;


    hash_value = hash(word);

    if(HashTable[hash_value] != NULL){
       for(wcl = HashTable[hash_value];wcl != NULL;wcl = wcl->next){
         if(strcmp(wcl->info.word,word) == 0){
           return &(wcl->info);
         }
       }
	  }

    return NULL;
}

/* 単語の登録 */
void wordcountRegister(char *word)
{
    WORDCOUNT *id;
    WORDCOUNTLIST *wcl;
    WORDCOUNTLIST *top;
    unsigned int hash_value;


    if ((id = wordcountSearch(word)) != NULL) {
	/* 単語が見つかったら出現回数を更新 */
	   id->count++;
    } else {
        wcl = (WORDCOUNTLIST *)malloc(sizeof(WORDCOUNTLIST));
        strcpy(wcl->info.word, word);
        wcl->info.count = 1;

        hash_value = hash(word);
        if(HashTable[hash_value] == NULL){
          HashTable[hash_value] = wcl;
        }else{
          top = HashTable[hash_value];
          while(top->next != NULL){
            top = top->next;
          }
          top->next = wcl;
        }

    }
}
void wordcountStatics(void){

  WORDCOUNTLIST *wcl;
  WORDCOUNT *wcp;
  for(int i=0;i < HASH_TABLE_SIZE;i++){
    for(wcl = HashTable[i];wcl != NULL;wcl = wcl->next)
      wcp = &(wcl->info);
      printf("%5d: %s\n",wcGetCount(wcp),wcGetWord(wcp));
  }
}
/* WORDCOUNTから単語を取得 */
char *wcGetWord(WORDCOUNT *wcp)
{
    return wcp->word;
}
/* WORDCOUNTから単語の出現回数を取得 */
int wcGetCount(WORDCOUNT *wcp)
{
    return wcp->count;
}