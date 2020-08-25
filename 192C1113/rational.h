// 有理数処理のヘッダーファイル

typedef struct rational {
    int queue[2][2];
} RATIONAL;

/* 有理数の生成 */
RATIONAL newQueue(int n);

// /* 有理数の簡約処理 */
// RATIONAL raReduce(RATIONAL v);

// /* 四則演算 */
// RATIONAL raAdd(RATIONAL a, RATIONAL b);
// RATIONAL raSub(RATIONAL a, RATIONAL b);
// RATIONAL raMul(RATIONAL a, RATIONAL b);
// RATIONAL raDiv(RATIONAL a, RATIONAL b);

// /* 比較 */
// int raEq(RATIONAL a, RATIONAL b);
// int raGt(RATIONAL a, RATIONAL b);
// int raLt(RATIONAL a, RATIONAL b);

// /* 有理数の表示 */
void queuePrint(RATIONAL v,int n);
// void raPrintNl(RATIONAL v);
// /* char *raString(char buff[], RATIONAL v) ; */