#include <stdio.h>

int *max_element(int *ary,int n){
    int p=0;
    for(int i=0;i<n;i++){
        p=ary[p]>ary[i]?p:i;
    }
    return &ary[p];
}

int main(void){
    int ary[10]={72,74,50,71,77,84,61,90,73,75};
    printf("%d\n",*max_element(ary,10));
}
