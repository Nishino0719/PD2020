#include "simplestack.h"

#define	MAXSTACK 100

/* スタックの抽象データ型の中核となるデータ構造（構造体）を宣言 */
typedef struct stack {
    int data[MAXSTACK];
    int index;
}STACK;

/* データ構造の定義
  このデータ構造は、全て下記の関数群で操作され、
  外部から直接操作されることはない */
STACK stk;

void stackInit(void)
{
    stk.index = 0;
}

void stackPush(int v)
{
    stk.data[stk.index++] = v;
/* 以下の様にも書ける
    stk.data[stk.index] = v ;
    stk.index += 1 ; // あとでインクリメントする
*/
}

int stackPop(void)
{
    return stk.data[--stk.index];
/* 以下の様にも書ける
    stk.index -= 1 ; // 先にデクリメントする
    return stk.data[stk.index] ;
*/
}

int stackElement(void)
{
    return stk.index;
}

int stackIsEmpty(void)
{
    if(stk.index == 0)
        return TRUE;
    else
        return FALSE;
}

int stackIsFull(void)
{
    if(stk.index >= MAXSTACK)
        return TRUE;
    else
        return FALSE;
}