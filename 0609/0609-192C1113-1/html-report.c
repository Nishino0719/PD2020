#include<stdio.h>

#include "kion-htmlreport.h"
#include "kionstat.h"

#define DAYARRAY 24

/* HTMLによる気温表の出力 */
void html_report(struct kisyou array[], int size)
{
    double kion[DAYARRAY];
    int i, di;

    /* HTMLのヘッダー部分 */
    printf("<html>\n<head>\n");
    printf("<title>気温データ</title>\n");
    printf("</head>\n");
    /* 文書の本体の開始 */
    printf("<bodyY>\n");
    /* 見出しの表示 */
    printf("<h1>日別気温統計データ</h1>\n");
    /* 表のヘッダー部分の開始 */
    printf("<table border=1>\n");
    printf("<tr><th>月日</th><th>平均</th><th>最高</th><th>最低</th></tr>\n");

    /* 表の本体部分の出力 */
    for(i = 0; i < size; i += DAYARRAY){ /* 一日単位で処理 */
	for(di = 0; di < DAYARRAY; di++){
	    /* １日分の気温を統計計算用の配列に転記 */
	    kion[di] = array[i + di].kion;
	}

	/* 表の本体の１行出力 */
	printf("<tr><td>%d月%d日</td><td>%.1f</td><td>%.1f</td><td>%.1f</td></tr>\n",
			array[i].month, array[i].day, 
			kion_heikin(kion, DAYARRAY),
			kion_max(kion, DAYARRAY),
			kion_min(kion, DAYARRAY));
    }

    printf("</table>\n"); /* 表の終端 */
    printf("</body>\n"); /* 文書本体の終端 */
    printf("</html>\n"); /* HTMLの終端 */
}