#include<stdio.h>
#include<string.h>
#include "arraystack.h"


#define MAXLINE 200

int main(void){
    STACK *sp;
    char buff[MAXLINE];
    int i, size;

    sp = newStack();

    while(fgets(buff,MAXLINE, stdin)!= NULL){
        size = strlen(buff);
        size--;

        for(i = 0;i < size/2; i++){
            stackPush(sp,buff[i]);

            if((size%2) == 1){
                i++;
            }

            for(;i<size;i++){
                if(stackPop(sp) != buff[i]){
                    while(!stackIsEmpty(sp)){
                        stackPop(sp);

                        printf("回文ではない\n");
                        break;
                    }
                }
            }
        }
    }
    return 0;
}