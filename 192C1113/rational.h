// 行列処理のヘッダーファイル

typedef struct rational {
    double queue[5][5];
} RATIONAL;

/* 有理数の生成 */
RATIONAL newQueue(int n);
RATIONAL ansQueue(int n);

// /* 有理数の簡約処理 */
double raGetElement(RATIONAL a,int x,int y);

// /* 四則演算 */
RATIONAL raRemul(RATIONAL a,int rem,int n);
RATIONAL raAdd(RATIONAL a, RATIONAL b,int n);
RATIONAL raSub(RATIONAL a, RATIONAL b,int n);
RATIONAL raMul(RATIONAL a, RATIONAL b,int n);

RATIONAL raCramelQueue(int n,RATIONAL a,RATIONAL b);
// 逆行列生成
RATIONAL raReverse(RATIONAL a,int n);
// 行列式の値を返す
int raInt(RATIONAL a,int n);
// 連立方程式の解を表示する
void displayAns(RATIONAL a,RATIONAL b);
void displayResult(RATIONAL a,RATIONAL b);
// /* 判別 */
int raReverseJudge(RATIONAL a,int n);

// /* 有理数の表示 */
void queuePrint(RATIONAL v,int n);
