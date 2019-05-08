#include <stdio.h>

int input_score(void){
    int n,max=0;
    do{
        printf("値を入力してください:");
        scanf("%d\n",&n);
        if(n<0|100<=n){
            printf("値を再入力してください:");
            scanf("%d\n",&n);
        }
        max=max>n?max:n;
    }while(n!=0);
    return max;
}

int main(void){
    int max=input_score();
    printf("入力された最大値は%dです。",max);
}