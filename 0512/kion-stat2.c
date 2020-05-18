#include<stdio.h>
#define ARRAYSIZE 24


void datetemprPrint(double array[],int size){
    for(int i=0;i<size;i++){
     printf("%d時は%lf\n",i,array[i]);
    }
}

double datetemprAve(double array[],int size){

        double sum=0;
    for(int i=0;i<size;i++){
        sum+=array[i];
    }
    return sum/size;
}

double datetemprMax(double array[],int size){

    double max=array[0];

    for(int i=1;i<size;i++){
        if(max<array[i]){
            max=array[i];
        }
    }
    return max;
}
double datetemprMin(double array[],int size){

    double min=array[0];
    for(int i=1;i<size;i++){
        if(min>array[i]){
            min = array[i];
        }
    }
    return min;
}

int main(void){

    double datetempr[ARRAYSIZE] = {
        12.8,12.0,11.4,11.2,10.6,10.6,10.3,10.6,13.1,16.9,20.1,22.2,21.9,22.5,23.9,
24.1,22.9,21.9,20.1,18.9,17.6,17.0,16.4,15.7,
    };

        datetemprPrint(datetempr,ARRAYSIZE);
        printf("_____________________\n");
        printf("平均気温は%.1lf\n",datetemprAve(datetempr,ARRAYSIZE));
        printf("_____________________\n");
        printf("最高気温は%.1lf\n",datetemprMax(datetempr,ARRAYSIZE));
        printf("_____________________\n");
        printf("最低気温は%.1lf\n",datetemprMin(datetempr,ARRAYSIZE));
    
    return 0;
}