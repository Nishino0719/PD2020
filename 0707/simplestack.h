#define	TRUE 1
#define FALSE 0

void stackInit(void); /* スタックの初期化 */
void stackPush(int v); /* データの保存 */
int stackPop(void); /* データの取り出し */
int stackElement(void); /* 保存されているデータ数 */
int stackIsEmpty(void); /* スタックが空 */
int stackIsFull(void); /* スタックがいっぱい */