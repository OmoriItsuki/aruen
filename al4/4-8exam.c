#include <stdio.h>

void input_multiple_scores(int num,int *p);
int max_score(int num,int *p);
float average(int num,int *p);

int main(void){
    int score[10];
    input_multiple_scores(10,score);
    printf("平均点は%.1f点、最高点は%d点です。",average(10,score),max_score(10,score));
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

int max_score(int num,int *p){
    int max=0;
    for(int i=0;i<num;i++){
        max=max>p[i]?max:p[i];
    }
    return max;
}

float average(int num, int *p){
    float sum=0;
    for(int i=0;i<num;i++){
        sum+=p[i];
    }
    return sum/num;
}
