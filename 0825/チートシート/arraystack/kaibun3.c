#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "arraystack.h"

#define MAXLINE 200

int main(void)
{
    char buff[MAXLINE] ;
    int i, j, size ;
    STACK *stk ;

    stk = newStack() ;

    while (fgets(buff, MAXLINE, stdin) != NULL) {
	/* 英数字以外の文字を除いて文字を詰め直す:改行文字も除去 */
	for (i = 0, j = 0; buff[i] != '\0'; i++) {
	    if (isalnum((unsigned int)buff[i])) {
		/* 英字は大文字にして、数字はそのまま詰める */
		buff[j++] = toupper(buff[i]) ;
	    }
	}
	buff[j] = '\0' ;

	size = strlen(buff) ;

	/* 前半の文字をスタックに記録 */
	for (i = 0; i < size/2; i++)
	    stackPush(stk, buff[i]) ;

	if ((size % 2) == 1) /* 文字列が奇数の場合 */
	    i++ ;

	/* 後半の文字をスタックから取り出した逆順の文字と比較 */
	for (/* iは前のforループの続きから */ ; i < size; i++) {
	    if (stackPop(stk) != buff[i]) { /* 回文ではない */
		/* 処理の中断でスタックに残っている文字を除去 */
		while (!stackIsEmpty(stk))
		    stackPop(stk) ;

		printf("回文ではありません\n") ;
		break ;
	    }
	}
    }

    return 0 ;
}