#include<stdio.h>
#include<stdlib.h>

#include"kion-htmlreport.h"
#include"kionstat.h"

#define DAYARRAY 24

/* HTMLによる気温表の出力 */
void html_report(struct kisyou array[], int size)
{   
    FILE *fp;
    double kion[DAYARRAY];
    int i, di;
    double vmax, vmin;
    char *str;
    char filename[] = "report.html";

    if((fp = fopen(filename, "w")) == NULL){
        fprintf(stderr, "Error:出力ファイルのオープンエラー %s\n", filename);
        exit(1);
    }

    /* HTMLのヘッダー部分 */
    fprintf(fp,"<html>\n<head>\n");
    fprintf(fp,"<title>気温データ</title>\n");
    fprintf(fp,"</head>\n");
    /* 文書の本体の開始 */
    fprintf(fp,"<body>\n");
    /* 見出しの表示 */
    fprintf(fp,"<h1>日別気温統計データ</h1>\n");
    /* 表のヘッダー部分の開始 */
    fprintf(fp,"<table border=1>\n");
    fprintf(fp,"<tr><th>月日</th><th>平均</th><th>最高</th><th>最低</th><th>日較差</th></tr>\n");

    /* 表の本体部分の出力 */
    for(i = 0; i < size; i += DAYARRAY){ /* 一日単位で処理 */
	for(di = 0; di < DAYARRAY; di++){
	    /* １日分の気温を統計計算用の配列に転記 */
	    kion[di] = array[i + di].kion;
	}

	vmax = kion_max(kion, DAYARRAY);
	vmin = kion_min(kion, DAYARRAY);

	if(vmax - vmin >= 15){
	    str = " bgcolor=red";
	}else{
	    str = "";
	}
	/* 表の本体の１行出力 */
	fprintf(fp,"<tr%s><td>%d月%d日</td><td>%.1f</td><td>%.1f</td><td>%.1f</td><td>%.1f</td></tr>\n",
			str,
			array[i].month, array[i].day, 
			kion_heikin(kion, DAYARRAY),
			vmax,
			vmin,
			vmax - vmin );
    }

    fprintf(fp,"</table>\n"); /* 表の終端 */
    fprintf(fp,"</body>\n"); /* 文書本体の終端 */
    fprintf(fp,"</html>\n"); /* HTMLの終端 */
    fclose(fp);
}
