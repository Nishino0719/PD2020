#include <stdlib.h>
#include "liststack.h"

STACK *newStack(void)
{
    STACK *sp;

    sp = (STACK *)malloc(sizeof(STACK));
    sp->root = NULL; /* 最初はノードなし */

    return sp;
}

void stackPush(STACK *sp, int v)
{
    NODE *np;

    /* ノードの確保と値の設定 */
    np = (NODE *)malloc(sizeof(NODE));
    np->value = v;

    /* ノードの挿入 */
    np->next = sp->root;
    sp->root = np;
}

int stackPop(STACK *sp)
{
    int v;
    NODE *np;

    /* ノードの除去 */
    np = sp->root;
    sp->root = np->next;

    v = np->value; /* ノードの開放前に値を確保 */
    free(np); /* ノードの開放 */

    return v;
}

int stackElement(STACK *sp)
{
    int n ;
    NODE *np ;

    /* ノードをたどって要素数を数える */
    for (n = 0, np = sp->root; np != NULL; np = np->next)
        n++ ;

    return n ;
}

int stackIsEmpty(STACK *sp)
{
    if (sp->root == NULL)
        return TRUE ;
    else
        return FALSE ;
}

int stackIsFull(STACK *sp)
{
    return FALSE ; /* あふれることはない */
}