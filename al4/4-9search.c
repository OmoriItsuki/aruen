#include <stdio.h>

void input_multiple_scores(int num,int *p);
int search(int num,int *p);

int main(void){
    int score[10];
    input_multiple_scores(10,score);
    printf("60点未満の人は%d名です。",search(10,score));
}

void input_multiple_scores(int num,int *p){
    for(int i=0;i<num;i++){
        int input;
        printf("値を入力してください:");
        scanf("%d\n",&input);
        while(input<0|100<input){
            printf("値を再入力してください:");
            scanf("%d\n",&input);
        }
        p[i]=input;
    }
}

int search(int num,int *p){
    int n=0;
    for(int i=0;i<num;i++){
        n=p[i]<60?n+1:n;
    }
    return n;
}
