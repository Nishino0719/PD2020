#include<stdio.h>
#include "simplestack.h"

#define MAXLINE 200

int main(void)
{
    char buff[MAXLINE];
    int i;

    stackInit();

    while(fgets(buff, MAXLINE, stdin) != NULL){
	for(i = 0; buff[i] !='\0'; i++)
	    stackPush(buff[i]);

	while(!stackIsEmpty())
	    printf("%c", stackPop());
        printf("\n");
    }

    return 0;
}