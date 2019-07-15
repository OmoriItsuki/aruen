#include <stdio.h>
#include <math.h>

double average(int ary[],int n){
    double ave=0;
    for(int i=0;i<n;i++){
        ave+=ary[i];
    }
    return ave/n;
}

double deviation(int ary[],int n){
    double ave=average(ary,n);
    double dev=0;
    for(int i=0;i<n;i++){
        dev+=(ary[i]-ave)*(ary[i]-ave);
    }
    dev/=10;
    return sqrt(dev);
}

int main(void){
    // Your code here!
    int ary[10] ={72,74,50,71,77,84,61,90,73,75};
    printf("平均は%.1f、標準偏差は%.3fです。\n",average(ary,10),deviation(ary,10));
}
