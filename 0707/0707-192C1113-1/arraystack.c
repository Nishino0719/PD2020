#include <s t d l i b . h>
#include "arraystack.h"

STACK *newStack(void)
{
  STACK *sp;

    sp = (STACK *)malloc(sizeof(STACK));
    sp−>inde x = 0;

    return sp;
}


void stackPush(STACK *sp , int v)
{
 sp−>data[sp−>inde x++] = v;
}


int stackPop(STACK *sp)
{
//こ こ に 処 理 を 記 述 し な さ い
}


int stackElement(STACK *sp)
{
//こ こ に 処 理 を 記 述 し な さ い 
}


int stackIsEmpty(STACK *sp)
{
//こ こ に 処 理 を 記 述 し な さ い
}


int stackIsFull(STACK *sp)
{
//  こ こ に 処 理 を 記 述 し な さ い
}