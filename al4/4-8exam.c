#include <stdio.h>

void input_multiple_scores(int);
int max_score(int);
float average(int);

int main(void){
    int score[10];
    input_multiple_scores(10);
    printf("平均点は%.1f点、最高点は%d点です。",average(10),max_score(10));
}

void input_multiple_scores(int num,int score[]){
    for(int i=0;i<num;i++){
        int input;
        printf("値を入力してください:");
        scanf("%d\n",&input);
        while(input<0|100<input){
            printf("値を再入力してください:");
            scanf("%d\n",&input);
        }
        *score[i]=input;
    }
}

int max_score(int num,int score[]){
    int max=0;
    for(int i=0;i<num;i++){
        max=max>*score[i]?max:score[i];
    }
    return max;
}

float average(int num, int score[]){
    float sum=0;
    for(int i=0;i<num;i++){
        sum+=*score[i];
    }
    return sum/num;
}