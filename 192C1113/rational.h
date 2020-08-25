// 有理数処理のヘッダーファイル

typedef struct rational {
    double queue[2][2];
} RATIONAL;

/* 有理数の生成 */
RATIONAL newQueue(int n);

// /* 有理数の簡約処理 */
// RATIONAL raReduce(RATIONAL v);
double raGetElement(RATIONAL a,int x,int y);

// /* 四則演算 */
RATIONAL raRemul(RATIONAL a,int rem,int n);
RATIONAL raAdd(RATIONAL a, RATIONAL b,int n);
RATIONAL raSub(RATIONAL a, RATIONAL b,int n);
RATIONAL raMul(RATIONAL a, RATIONAL b,int n);

// 逆行列生成
RATIONAL raReverse(RATIONAL a,int n);

// /* 判別 */
int raReverseJudge(RATIONAL a,int n);
// int raGt(RATIONAL a, RATIONAL b);
// int raLt(RATIONAL a, RATIONAL b);

// /* 有理数の表示 */
void queuePrint(RATIONAL v,int n);
// void raPrintNl(RATIONAL v);
// /* char *raString(char buff[], RATIONAL v) ; */