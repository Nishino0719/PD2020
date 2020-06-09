#include<stdio.h>
#include "kion-htmlreport3.h"

void red_nitikakusa(double kion){

    if(kion > 15){
        printf("<td style='background:red'>%.1f</td></tr>\n", kion);
    }else{
        printf("<td>%.1f</td></tr>\n", kion);
    }
}