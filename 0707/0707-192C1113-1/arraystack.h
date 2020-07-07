#def ine TRUE 1
#def ine FALSE 0

#def ine MAXSTACK 100

typedef struct stack{
    int data[MAXSTACK];
    int index;
}STACK;

STACK *newStack( void );
void stackPush(STACK *sp,int v);
int stackPop(STACK *sp );
int stackElement(STACK *sp);
int stackIsEmpty(STACK *sp);
int stackIsFull(STACK *sp);