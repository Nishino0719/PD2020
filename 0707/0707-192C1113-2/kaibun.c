#include<stdio.h>
#include<string.h>
#include "arraystack.h"


#define MAXLINE 200

int main(void){
    char buff[MAXLINE];
    int i, size;

    stackInit();

    while(fgets(buff,MAXLINE, stdin)!= NULL){
        size = strlen(buff);
        size--;

        for(i = 0;i < size/2; i++){
            stackPush(buff[i]);

            if((size%2) == 1){
                i++;
            }

            for(;i<size;i++){
                if(stackPop() != buff[i]){
                    while(!stackIsEmpty()){
                        stackPop();

                        printf("回文ではない\n");
                        break;
                    }
                }
            }
        }
    }
    return 0;
}