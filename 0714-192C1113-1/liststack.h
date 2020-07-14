#define	TRUE 1
#define FALSE 0

/* スタックの利用者は、この構造体の中身を直接操作してはならない */
typedef struct node{
    struct node *next;
    int value;
} NODE;

/* スタックの利用者は、この構造体の中身を直接操作してはならない */
typedef struct stack{
    NODE *root;
} STACK;

STACK *newStack(void);
void stackPush(STACK *sp, int v);
int stackPop(STACK *sp);
int stackElement(STACK *sp);
int stackIsEmpty(STACK *sp);
int stackIsFull(STACK *sp);